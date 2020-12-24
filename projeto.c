#include "projeto.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//pr10,11,12,13
//tp 10,11,12

int main_projeto(int argc, const char *argv[]) {

    LISTAEDIFICIOS *e = create_lista_edificio();

    /** Criação dos edificios e seus estudios */
    insert_edificio(e, 1, "PF Boavista", 41.162392, -8.655714, "Avenida da Boavista", 1.5, 3);

    insert_estudio(e, 1, 1, 1, "t2", 50);
    insert_estudio(e, 1, 2, 1, "t2", 50);
    insert_estudio(e, 1, 3, 2, "t2", 50);
    insert_estudio(e, 1, 5, 4, "t2", 50);
    insert_estudio(e, 1, 4, 3, "t2", 50);


    insert_edificio(e, 2, "PF Maia", 41.162392, -8.655714, "Avenida da Boavista", 1.5, 5);

    insert_estudio(e, 2, 6, 5, "t2", 50);
    insert_estudio(e, 2, 7, 6, "t2", 50);
    insert_estudio(e, 2, 8, 7, "t2", 50);


    /** Imprimir lista */
    print_listaEdificio(e);

/*
    // Find estudio
    ESTUDIO *printestudio = find_estudio_dynarray_arrayestudios(e, 5);
    printf("%d, %d, %s, %d\n", printestudio->id_estudio, printestudio->numero, printestudio->configuracao,
           printestudio->area);


    // Remove estudio
    remove_estudio_dynarray_arrayestudios(e, 1);
    remove_estudio_dynarray_arrayestudios(e, 7);

    // Remove edificio
    remove_edificio(e, "PF Maia");

    // Editar edificio
    edit_edificio(e, 1, "Ribeira", 41.162392, -8.655714, "Ribeira", 1.5, 3);

    // Editar estudio
    edit_estudio(e,8,31,"T3",150);
*/
    return 0;
}

LISTAEDIFICIOS *create_lista_edificio() {
    LISTAEDIFICIOS *le = (LISTAEDIFICIOS *) calloc(1, sizeof(LISTAEDIFICIOS));
    le->pedificios = NULL;

    return le;
}

void insert_edificio(LISTAEDIFICIOS *pg, int id_edificio, char nome[MAX200], double latitude, double longitude,
                     char morada[MAX200], double preco_m2, int size_estudios) {
    //TEMOS A LISTA EDIFICIOS A APONTAR PARA NULL
    //QUEREMOS COLOCAR A LISTA A APONTAR PARA OS EDIFICIOS
    //EDIFICIO CRIADO
    EDIFICIO *s = (EDIFICIO *) malloc(sizeof(EDIFICIO));
    s->id_edificio = id_edificio;
    strcpy(s->nome, nome);
    s->latitude = latitude;
    s->longitude = longitude;
    strcpy(s->morada, morada);
    s->preco_m2 = preco_m2;
    ESTUDIO_ARRAY *estudiosarray = create_dynarray_array_estudios(size_estudios);
    s->array_estudios = *estudiosarray;
    s->next = NULL;
    //SE FOR FIRST FAZEMOS ISTO
    if (pg->pedificios == NULL) {
        pg->pedificios = s;
        return;
    }
    EDIFICIO *pant = NULL, *pcurrent = pg->pedificios;
    while (pcurrent != NULL && pcurrent->id_edificio != id_edificio) {
        pant = pcurrent;
        pcurrent = pcurrent->next;
    }
    //INSERÇAO A CABEÇA
    if (pcurrent == pg->pedificios) {
        s->next = pg->pedificios;
        return;
    }
    //INSERÇÃO A MEIO OU NO FIM
    s->next = pcurrent;
    pant->next = s;
}


void edit_edificio(LISTAEDIFICIOS *pg, int id_edificio, char nome[MAX200], double latitude, double longitude,
                   char morada[MAX200], double preco_m2, int size_estudios) {
    EDIFICIO *pe = find_edificio(pg, id_edificio);
    if (pe != NULL) {
        pe->id_edificio = id_edificio;
        strcpy(pe->nome, nome);
        pe->latitude = latitude;
        pe->longitude = longitude;
        strcpy(pe->morada, morada);
        pe->preco_m2 = preco_m2;
        pe->array_estudios.size_estudios = size_estudios;
    }
}


void insert_estudio(LISTAEDIFICIOS *pg, int edificio, int id_estudio, int numero, char configuracao[], int area) {
    //FUNÇAO AUXILIAR
    EDIFICIO *pedificio = find_edificio(pg, edificio);

    if (pedificio != NULL) {

        if (pedificio->array_estudios.n_estudios >= pedificio->array_estudios.size_estudios) {
            if (pedificio->array_estudios.size_estudios == 0) {
                pedificio->array_estudios.size_estudios = 2;
            } else {
                pedificio->array_estudios.size_estudios *= 2;
            }
            pedificio->array_estudios.pestudios = (ESTUDIO *) realloc(pedificio->array_estudios.pestudios,
                                                                      sizeof(ESTUDIO) *
                                                                      pedificio->array_estudios.size_estudios);
        }
        ESTUDIO *pestudio = pedificio->array_estudios.pestudios + pedificio->array_estudios.n_estudios;
        pestudio->id_estudio = id_estudio;
        pestudio->numero = numero;

        strcpy(pestudio->configuracao, configuracao);
        pestudio->area = area;


        pedificio->array_estudios.n_estudios++;
    }
}


ESTUDIO_ARRAY *create_dynarray_array_estudios(int initsize) {
    ESTUDIO *pestudios = (ESTUDIO *) calloc(initsize, sizeof(ESTUDIO));
    ESTUDIO_ARRAY *estudiosarray = (ESTUDIO_ARRAY *) calloc(1, sizeof(ESTUDIO_ARRAY));
    estudiosarray->pestudios = pestudios;
    estudiosarray->n_estudios = 0;
    estudiosarray->size_estudios = initsize;

    return estudiosarray;
}

void insert_estudio_dynarray_array_estudio(ESTUDIO_ARRAY *pcs, int id, int numero, char configuracao[], int area) {
    int i;
    ESTUDIO *pestudio = pcs->pestudios;
    for (i = 0; i < pcs->n_estudios; ++i) {
        if (pestudio->id_estudio == 0) {
            strcpy(pestudio->configuracao, configuracao);
            pestudio->numero = numero;
            pestudio->id_estudio = id;
            pestudio->area = area;
            return;
        }
        pestudio++;
    }
    if (i == pcs->n_estudios) {
        int oldsize = pcs->n_estudios;
        int newsize = pcs->n_estudios + 10;
        pcs->pestudios = (ESTUDIO *) realloc(pcs->pestudios, newsize * sizeof(ESTUDIO));
        for (i = oldsize; i < newsize; ++i) {
            pestudio->area = 0;
            pestudio->numero = 0;
            pestudio->id_estudio = 0;
            strcpy(pestudio->configuracao, "");
        }
        pestudio = pcs->pestudios + oldsize;
        strcpy(pestudio->configuracao, configuracao);
        pestudio->numero = numero;
        pestudio->id_estudio = id;
        pestudio->area = area;
    }
}

ESTUDIO remove_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_estudio) {
    EDIFICIO *pedificio = pg->pedificios;

    ESTUDIO st = {0, 0, "0", 0};
    while (pedificio != NULL) {
        ESTUDIO *pst = find_estudio_dynarray_arrayestudios(pg, id_estudio);
        if (pst != NULL) {
            while (pst < (pedificio->array_estudios.pestudios + pedificio->array_estudios.n_estudios - 1) &&
                   pst->id_estudio != 0) {
                *pst = *(pst + 1);
                pst++;
            }
            if (pst == pedificio->array_estudios.pestudios + pedificio->array_estudios.n_estudios - 1) {
                pst->id_estudio = 0;
                pst->numero = 0;
                strcpy(pst->configuracao, "");
                pst->area = 0;
            }
        }
        pedificio = pedificio->next;
    }
    return st;
}


void remove_edificio(LISTAEDIFICIOS *pg, char name[]) {
    //NAO REMOVEMOS NADA SE A LISTA ESTIVER VAZIA
    if (pg->pedificios == NULL) {
        printf("Esse edificio nao existe.");
        return;
    }
    EDIFICIO *pant = NULL, *pcurrent = pg->pedificios;
    while (pcurrent != NULL && strcmp(name, pcurrent->nome) != 0) {
        pant = pcurrent;
        pcurrent = pcurrent->next;
    }
    //SE O NOME NAO EXISTIR
    if (pcurrent == NULL) {
        return;
    }
    //REMOÇÃO A CABEÇA
    if (pcurrent == pg->pedificios) {
        pg->pedificios = pcurrent->next;
        pg->num_edificios--;
        free(pcurrent);
        return;
    }
    pant->next = pcurrent->next;
    free(pcurrent);
    //DECREMENTAR O NUMERO DE EDIFICIOS
    pg->num_edificios--;
}

ESTUDIO *find_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_estudio) { // BINARY SEARCH
    EDIFICIO *pedificio = pg->pedificios;

    while (pedificio != NULL) {
        ESTUDIO *pst = pedificio->array_estudios.pestudios;
        int l = 0;
        int r = pedificio->array_estudios.n_estudios - 1;

        if (pst == NULL) {
            printf("* find_student_dynarray_classstudents(): Array estudios encontra-se vazio!\n");
            return pst;
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (pst[m].id_estudio == id_estudio) {
                return &pst[m];
            }
            if (pst[m].id_estudio < id_estudio) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        pedificio = pedificio->next;
    }
    return NULL;
}

void print_dynarray_array_estudios(ESTUDIO_ARRAY cs) {
    ESTUDIO *pestudio = cs.pestudios;
    for (int i = 0; i < cs.n_estudios; ++i) {
        printf("print_dynarray_classstudents: Estudio [%d] =ID: %d,Numero porta %d,Configuracao: %s, Area: %d\n", i + 1,
               pestudio->id_estudio, pestudio->numero,
               pestudio->configuracao, pestudio->area);
        pestudio++;
    }
}

EDIFICIO *find_edificio(LISTAEDIFICIOS *pg, int id) {

    EDIFICIO *pst = pg->pedificios;
    while (pst != NULL) {
        if (pst->id_edificio == id) {
            return pst;
        }
        pst = pst->next;
    }
    return NULL;
}

void print_listaEdificio(const LISTAEDIFICIOS *g) {
    EDIFICIO *pp = g->pedificios;
    while (pp != NULL) {
        if (pp->id_edificio != 0) {
            printf("EDIFICIO: %d, %s, %lf, %lf, %s, %lf\n", pp->id_edificio, pp->nome, pp->latitude, pp->longitude,
                   pp->morada, pp->preco_m2);
        }
        ESTUDIO *pc = pp->array_estudios.pestudios;

        for (int i = 0; i < pp->array_estudios.n_estudios && pc->numero != 0; ++i) {

            printf("\tEstudio:ID-> %d,Numero porta-> %d,Configuracao-> %s,Area-> %d\n", pc->id_estudio, pc->numero,
                   pc->configuracao, pc->area);
            pc++;
        }
        pp = pp->next;
    }
}


void edit_estudio(LISTAEDIFICIOS *pg, int id_estudio, int numero, char configuracao[], int area){
    ESTUDIO *pe = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    if (pe != NULL) {
        pe->id_estudio = id_estudio;
        strcpy(pe->configuracao, configuracao);
        pe->numero = numero;
        pe->area = area;
    }
}