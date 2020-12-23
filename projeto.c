//
// Created by Utilizador on 12/12/2020.
//

#include "projeto.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//pr10,11,12,13
//tp 10,11,12

int main_projeto(int argc, const char *argv[]) {
    LISTAEDIFICIOS *e = create_lista_edificio();

    insert_edificio(e, 1, "PF Boavista", 41.162392, -8.655714, "Avenida da Boavista", 1.5, 3);
    insert_edificio(e, 2, "PF Maia", 41.162392, -8.655714, "Avenida da Boavista", 1.5, 5);

    insert_estudio(e, 1, 1, 1, "t2", 50);
    insert_estudio(e, 2, 2, 1, "t2", 50);
    insert_estudio(e, 1, 3, 2, "t2", 50);
    insert_estudio(e, 2, 4, 3, "t2", 50);
    insert_estudio(e, 2, 5, 4, "t2", 50);
    //ESTUDIO *ps = find_estudio_dynarray_arrayestudios(e->pedificios->array_estudios, 6);

    //printf("%d\n", ps->id_estudio);
    print_listaEdificio(e);
    printf("..............\n");
    remove_estudio_dynarray_arrayestudios(e, 2);

    print_listaEdificio(e);
    printf("..............\n");
    //remove_edificio(e, 2);
    remove_edificio(e, "xd");

    print_listaEdificio(e);



    //USAR ISTO
    //e.pedificios->array_estudios.pestudios;

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

        //VER ISTO, TENTAR DAR FIX!
        //pestudio->edificio = pg->pedificios->array_estudios.pestudios;

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
        ESTUDIO *pst = find_estudio_dynarray_arrayestudios(pedificio->array_estudios, id_estudio);
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

/*EDIFICIO remove_edificio(LISTAEDIFICIOS *pg, int id_edificio) {
    EDIFICIO *pedificio = pg->pedificios;
    EDIFICIO ed = {0, "", 0, 0, "", 0, NULL};
    while (pedificio != NULL) {
        EDIFICIO *pst = find_edificio(pg, id_edificio);
        if (pst != NULL) {
            while (pst < (pg->pedificios) &&
                   pst->id_edificio != 0) {
                *pst = *(pst + 1);
                pst++;
            }
            if (pst->id_edificio == pg->pedificios->id_edificio) {
                pst->id_edificio = 0;
                strcpy(pst->nome, "");
                pst->latitude = 0;
                pst->longitude = 0;
                strcpy(pst->morada, "");
                pst->preco_m2 = 0;
            }
        }
        pedificio = pedificio->next;
    }
    return ed;
}*/

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

ESTUDIO *find_estudio_dynarray_arrayestudios(ESTUDIO_ARRAY cs, int id_estudio) {
    ESTUDIO *pst = cs.pestudios;

    if (pst == NULL) {
        printf("* find_student_dynarray_classstudents(): Array estudios encontra-se vazio!\n");
        return pst;
    }
    for (int i = 0; i < cs.n_estudios && pst->id_estudio != id_estudio; ++i) {
        pst++;
    }
    return (pst->id_estudio == id_estudio ? pst : NULL);
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

        for (int i = 0; i < pp->array_estudios.n_estudios && pp->id_edificio != 0; ++i) {

            printf("\tEstudio:ID-> %d,Numero porta-> %d,Configuracao-> %s,Area-> %d\n", pc->id_estudio, pc->numero,
                   pc->configuracao, pc->area);
            pc++;
        }
        pp = pp->next;
    }
}