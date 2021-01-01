#include "projeto.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//pr10,11,12,13
//tp 10,11,12

int id_edificio = 1;
int id_estudio = 1;
int id_agenda = 1;
int id_evento = 1;


int main_projeto(int argc, const char *argv[]) {

    LISTAEDIFICIOS *e = create_lista_edificio();

    /** Criação dos edificios e seus estudios */

     insert_edificio(e, "PF Maia", 41.162392, -8.655714, "Avenida da Maia", 1.5, 5);
     insert_estudio(e, 1, 1, "t2", 50, 30, 600, 4);
     insert_estudio(e, 1, 1, "t2", 50, 30, 600, 4);
     insert_estudio(e, 1, 2, "t2", 50, 30, 600, 4);
     insert_estudio(e, 1, 3, "t2", 50, 30, 600, 4);
     insert_estudio(e, 1, 4, "t2", 50, 30, 600, 4);
     insert_edificio(e, "PF Boavista", 41.162392, -8.655714, "Avenida da Boavista", 1.5, 5);
     insert_estudio(e, 2, 5, "t2", 50, 30, 600, 4);
     insert_estudio(e, 2, 6, "t2", 50, 30, 600, 4);
     insert_estudio(e, 2, 7, "t2", 50, 30, 600, 4);
     insert_estudio(e, 2, 3, "t2", 50, 30, 600, 4);
     insert_estudio(e, 2, 3, "t2", 50, 30, 600, 4);
     insert_estudio(e, 2, 3, "t2", 50, 30, 600, 4);
     insert_estudio(e, 2, 3, "t2", 50, 30, 600, 4);
     insert_estudio(e, 2, 5, "t2", 50, 30, 600, 4);
     insert_agenda(e, 1, 1, "MASTER", 7);
     insert_agenda(e, 1, 1, "AIRBNB", 7);
     insert_agenda(e, 1, 1, "AIRBNC", 7);
     insert_agenda(e, 1, 1, "AIRBNE", 7);
     insert_agenda(e, 1, 2, "MASTER", 7);
     insert_agenda(e, 1, 2, "AIRBNB", 7);
     insert_agenda(e, 1, 2, "AIRBNC", 7);
     insert_agenda(e, 1, 2, "AIRBNE", 7);
     insert_agenda(e, 1, 4, "MASTER", 7);
     insert_agenda(e, 2, 7, "MASTER", 7);
     insert_agenda(e, 2, 10, "MASTER", 7);
     insert_agenda(e, 2, 12, "MASTER", 7);
     insert_agenda(e, 2, 12, "AIRBNB", 7);
     insert_agenda(e, 2, 12, "AIRBNC", 7);
     insert_agenda(e, 2, 12, "AIRBNE", 7);
     insert_dia(e, 1, 1, 1, 1, 1, 1);
     insert_dia(e, 1, 1, 1, 2, 2, 2);
     insert_dia(e, 1, 1, 2, 1, 1, 1);
     insert_dia(e, 1, 1, 3, 3, 3, 3);
     insert_dia(e, 1, 1, 4, 4, 4, 4);
     insert_dia(e, 1, 2, 5, 5, 5, 5);
     insert_dia(e, 1, 2, 6, 6, 6, 6);
     insert_dia(e, 1, 2, 7, 7, 7, 7);
     insert_dia(e, 1, 2, 8, 8, 8, 8);
     insert_dia(e, 1, 4, 9, 9, 9, 9);
     insert_dia(e, 2, 7, 10, 10, 10, 10);
     insert_dia(e, 2, 10, 11, 11, 11, 11);
     DIAS datafim = {29,12,2020};
     insert_evento(e,"Limpeza",datafim,-1,1,1,1,1);
     insert_evento(e,"Manutencao",datafim,-1,1,1,1,1);
     insert_evento(e,"Manutencao",datafim,-1,1,2,2,2);
     insert_evento(e,"Manutencao",datafim,-1,2,1,1,1);
    //EVENTO *fevento = find_evento(e,2,4);
    //printf("%d\n", fevento->id_evento);
    //insert_dia(e, 2, 10, 10, 22, 3, 2021);


    /** Imprimir lista */
    //print_listaEdificio(e);
    printf("----------------------------------\n\n");

    //DIAS fim = {31,12,2020};
    //edit_evento(e,2,4,"Alojamento", fim,1);
    //print_listaEdificio(e);

    //DIAS *printdia = find_dia_dynarray_arraydias(e,2, 1, 1, 1);
    //printf("%d, %d, %d\n", printdia->dia, printdia->mes, printdia->ano);
    //  escrever_agendas_txt(e);
     //gravar_edificios(e);

    read_edificios_txt(e);
    //  print_listaEdificio(e);


/*
    // Find estudio
    ESTUDIO *printestudio = find_estudio_dynarray_arrayestudios(e, 5);
    printf("%d, %d, %s, %d\n", printestudio->id_estudio, printestudio->numero, printestudio->configuracao,
           printestudio->area);
*/

    /*  remove_estudio_dynarray_arrayestudios(e,2,11);
      print_listaEdificio(e);
      printf("...............\n");
      remove_estudio_dynarray_arrayestudios(e,2,9);
      print_listaEdificio(e);
      printf("...............\n");
      remove_estudio_dynarray_arrayestudios(e,1,1);*/
    //print_listaEdificio(e);
    //print_listaEdificio(e);
    // Remove edificio
    //remove_edificio(e, "PF Boavista");
    //print_listaEdificio(e);


    // Editar edificio
    //edit_edificio(e, 1, "Ribeira", 41.162392, -8.655714, "Ribeira", 1.5, 3);

    gravar_edificios(e);
    // Editar estudio
    //edit_estudio(e,8,31,"T3",150,50, 950);

    return 0;
}

LISTAEDIFICIOS *create_lista_edificio() {
    LISTAEDIFICIOS *le = (LISTAEDIFICIOS *) calloc(1, sizeof(LISTAEDIFICIOS));
    le->pedificios = NULL;

    return le;
}

LISTAEVENTOS *create_lista_eventos() {
    LISTAEVENTOS *leventos = (LISTAEVENTOS *) calloc(1, sizeof(LISTAEVENTOS));
    leventos->peventos = NULL;

    return leventos;
}

void insert_edificio(LISTAEDIFICIOS *pg, char nome[MAX200], double latitude, double longitude,
                     char morada[MAX200], double preco_m2, int size_estudios) {
    //TEMOS A LISTA EDIFICIOS A APONTAR PARA NULL
    //QUEREMOS COLOCAR A LISTA A APONTAR PARA OS EDIFICIOS
    //EDIFICIO CRIADO
    EDIFICIO *s = (EDIFICIO *) malloc(sizeof(EDIFICIO));
    s->id_edificio = id_edificio++;
    strcpy(s->nome, nome);
    s->latitude = latitude;
    s->longitude = longitude;
    strcpy(s->morada, morada);
    s->preco_m2 = preco_m2;
    ESTUDIO_ARRAY *estudiosarray = create_dynarray_array_estudios(size_estudios);
    s->array_estudios = *estudiosarray;
    s->next = NULL;

    EDIFICIO *pant = NULL, *pcurrent = pg->pedificios;
    while (pcurrent != NULL && id_edificio > pcurrent->id_edificio) {
        pant = pcurrent;
        pcurrent = pcurrent->next;
    }
    //INSERÇAO A CABEÇA
    if (pcurrent == pg->pedificios) {
        s->next = pg->pedificios;
        pg->pedificios = s;
        pg->num_edificios++;
        return;
    }
    //INSERÇÃO A MEIO OU NO FIM
    s->next = pcurrent;
    pant->next = s;
    pg->num_edificios++;
}

void insert_evento(LISTAEDIFICIOS *pg, const char *tipo, DIAS datafim,
                   int id_cliente, int id_agenda, int dia, int mes, int ano) {
    //TEMOS A LISTA EDIFICIOS A APONTAR PARA NULL
    //QUEREMOS COLOCAR A LISTA A APONTAR PARA OS EDIFICIOS
    //EDIFICIO CRIADO
    // EDIFICIO *pedificio = find_edificio(pg, id_edificio);
    // ESTUDIO *pestudio = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    AGENDAS *pagenda = find_agenda_dynarray_arrayagendas(pg, id_agenda);
    DIAS *pdias = find_dia_dynarray_arraydias(pg, id_agenda, dia, mes, ano);

    if (pagenda != NULL && pdias != NULL) { // Check whether pagenda and pdias were actually found or not
        EVENTO *s = (EVENTO *) malloc(sizeof(EVENTO));
        s->id_evento = id_evento++;
        strcpy(s->tipo, tipo);
        s->id_cliente = id_cliente;
        s->datafim.dia = datafim.dia;
        s->datafim.mes = datafim.mes;
        s->datafim.ano = datafim.ano;

        s->nextEvento = NULL;

        if (pdias->listaeventos == NULL) {
            pdias->listaeventos = create_lista_eventos(); // Create event list if missing
        }
        LISTAEVENTOS *plista = pdias->listaeventos; // Pick pointer to event list


        //*(pdias->listaeventos->peventos) = *s;

        EVENTO *pant = NULL, *pcurrent = plista->peventos;
        while (pcurrent != NULL && id_evento > pcurrent->id_evento) {
            pant = pcurrent;
            pcurrent = pcurrent->nextEvento;
        }
        //INSERÇAO A CABEÇA
        if (pcurrent == plista->peventos) {
            s->nextEvento = plista->peventos;
            plista->peventos = s;
            plista->num_eventos++;
            return;
        }
        //INSERÇÃO A MEIO OU NO FIM
        s->nextEvento = pcurrent;
        pant->nextEvento = s;
        plista->num_eventos++;
    }
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


void insert_estudio(LISTAEDIFICIOS *pg, int id, int numero, char configuracao[], int area,
                    float preco_diario, float preco_mensal, int size_agendas) {
    //FUNÇAO AUXILIAR
    EDIFICIO *pedificio = find_edificio(pg, id);

    if (pedificio != NULL) {

        if (pedificio->array_estudios.n_estudios >= pedificio->array_estudios.size_estudios) {
            if (pedificio->array_estudios.size_estudios == 0) {
                pedificio->array_estudios.size_estudios = 2;
            } else {
                pedificio->array_estudios.size_estudios += 2;
            }
            pedificio->array_estudios.pestudios = (ESTUDIO *) realloc(pedificio->array_estudios.pestudios,
                                                                      sizeof(ESTUDIO) *
                                                                      pedificio->array_estudios.size_estudios);
        }
        ESTUDIO *pestudio = pedificio->array_estudios.pestudios + pedificio->array_estudios.n_estudios;
        pestudio->id_estudio = id_estudio++;
        pestudio->numero = numero;

        strcpy(pestudio->configuracao, configuracao);
        pestudio->area = area;
        pestudio->preco_diaria = preco_diario;
        pestudio->preco_mensal = preco_mensal;
        AGENDAS_ARRAY *agendasarray = create_dynarray_array_agendas(size_agendas);
        pestudio->array_agendas = *agendasarray;

        pedificio->array_estudios.n_estudios++;
    }
}


void insert_agenda(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio, char plataforma[], int size_dias) {
    EDIFICIO *pedificio = find_edificio(pg, id_edificio);
    ESTUDIO *pestudio = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    if (pedificio != NULL && pestudio != NULL) {
        AGENDAS *pagenda = pestudio->array_agendas.pagenda + pestudio->array_agendas.n_agendas;

        pagenda->id_agenda = id_agenda++;

        strcpy(pagenda->plataforma, plataforma);

        DIAS_ARRAY *diasarray = (DIAS_ARRAY *) create_dynarray_array_agendas(size_dias);
        pagenda->array_dias = *diasarray;

        pestudio->array_agendas.n_agendas++;
    }
}


void insert_dia(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio, int id_agenda, int dia, int mes, int ano) {
    EDIFICIO *pedificio = find_edificio(pg, id_edificio);
    ESTUDIO *pestudio = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    AGENDAS *pagenda = find_agenda_dynarray_arrayagendas(pg, id_agenda);

    if (pedificio != NULL && pestudio != NULL && pagenda != NULL) {
        DIAS *pdias = pagenda->array_dias.pdias + pagenda->array_dias.n_dias;
        pdias->dia = dia;

        pdias->mes = mes;

        pdias->ano = ano;

        pagenda->array_dias.n_dias++;

        LISTAEVENTOS *clistaeventos = create_lista_eventos();
        pagenda->array_dias.pdias->listaeventos = clistaeventos;
    }

}

AGENDAS *find_agenda_dynarray_arrayagendas(LISTAEDIFICIOS *pg, int id_agenda) { // BINARY SEARCH
    EDIFICIO *edificio = pg->pedificios;
    while (edificio != NULL) {
        ESTUDIO *pestudio = edificio->array_estudios.pestudios;
        for (int i = 0; i < edificio->array_estudios.n_estudios; i++) {
            AGENDAS *pst = pestudio->array_agendas.pagenda;
            int l = 0;
            int r = pestudio->array_agendas.n_agendas - 1;

            if (pst == NULL) {
                printf("* find_student_dynarray_arraydias(): Array dias encontra-se vazio!\n");
                return pst;
            }
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (pst[m].id_agenda == id_agenda) {

                    return &pst[m];
                }
                if (pst[m].id_agenda < id_agenda) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            pestudio++;
        }
        edificio = edificio->next;
    }

    return NULL;
}

DIAS *find_dia_dynarray_arraydias(LISTAEDIFICIOS *pg, int id_agenda, int dia, int mes, int ano) {
    EDIFICIO *edificio = pg->pedificios;
    while (edificio != NULL) {
        ESTUDIO *pestudio = edificio->array_estudios.pestudios;
        for (int i = 0; i < edificio->array_estudios.n_estudios; i++) {
            AGENDAS *pst = pestudio->array_agendas.pagenda;
            for (int k = 0; k < pestudio->array_agendas.n_agendas; k++) {
                if (pst->id_agenda == id_agenda) {
                    DIAS *pdia = pst->array_dias.pdias;
                    int l = 0;
                    int r = pst->array_dias.n_dias - 1;

                    if (pdia == NULL) {
                        printf("* find_student_dynarray_arraydias(): Array dias encontra-se vazio!\n");
                        return pdia;
                    }
                    while (l <= r) {
                        int m = l + (r - l) / 2;
                        if (pdia[m].dia == dia && pdia[m].mes == mes && pdia[m].ano == ano) {

                            return &pdia[m];
                        }
                        if (pdia[m].dia < dia && pdia[m].mes < mes && pdia[m].ano < ano) {
                            l = m + 1;
                        } else {
                            r = m - 1;
                        }
                    }
                }
                pst++;
            }

            pestudio++;
        }
        edificio = edificio->next;
    }

    return NULL;
}


DIAS_ARRAY *create_dynarray_array_dias(int initsize) {
    DIAS *pdias = (DIAS *) calloc(initsize, sizeof(DIAS));
    DIAS_ARRAY *diasarray = (DIAS_ARRAY *) calloc(1, sizeof(DIAS_ARRAY));
    diasarray->pdias = pdias;
    diasarray->n_dias = 0;
    diasarray->size_dias = initsize;

    return diasarray;
}


ESTUDIO_ARRAY *create_dynarray_array_estudios(int initsize) {
    ESTUDIO *pestudios = (ESTUDIO *) calloc(initsize, sizeof(ESTUDIO));
    ESTUDIO_ARRAY *estudiosarray = (ESTUDIO_ARRAY *) calloc(1, sizeof(ESTUDIO_ARRAY));
    estudiosarray->pestudios = pestudios;
    estudiosarray->n_estudios = 0;
    estudiosarray->size_estudios = initsize;

    return estudiosarray;
}

void remove_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio) {

    EDIFICIO *edificio = find_edificio(pg, id_edificio);
    ESTUDIO *aremover = find_estudio_dynarray_arrayestudios(pg, id_estudio);

    if (aremover != NULL) {
        aremover->numero = 0;
        aremover->area = 0;
        strcpy(aremover->configuracao, "");

    }
    for (int i = 0; i < edificio->array_estudios.n_estudios; ++i) {
        *aremover = *(aremover + 1);
        aremover++;
    }
    edificio->array_estudios.n_estudios--;
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
            printf("* find_student_dynarray_arrayestudios(): Array estudios encontra-se vazio!\n");
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
        printf("EDIFICIO: %d, %s, %lf, %lf, %s, %.2f\n", pp->id_edificio, pp->nome, pp->latitude, pp->longitude,
               pp->morada, pp->preco_m2);

        ESTUDIO *pc = pp->array_estudios.pestudios;
        for (int i = 0; i < pp->array_estudios.n_estudios; i++) {
            printf("\tEstudio:ID-> %d,Numero porta-> %d,Configuracao-> %s,Area-> %d, Preco diaria-> %.2f, Preco mensal->%.2f\n",
                   pc->id_estudio, pc->numero, pc->configuracao, pc->area, pc->preco_diaria, pc->preco_mensal);

            AGENDAS *pa = pc->array_agendas.pagenda;
            for (int j = 0; j < pc->array_agendas.n_agendas; j++) {
                printf("\t\tID agenda-> %d,Plataforma-> %s\n", pa->id_agenda, pa->plataforma);

                DIAS *pd = pa->array_dias.pdias;
                //LISTAEVENTOS *plista = pd->listaeventos;
                for (int k = 0; k < pa->array_dias.n_dias; k++) {
                    printf("\t\t\tData -> %d / %d / %d\n", pd->dia, pd->mes, pd->ano);

                    if (pd->listaeventos != NULL) {
                        EVENTO *pe = pd->listaeventos->peventos;
                        while (pe != NULL) {
                            printf("\t\t\t\tEVENTO: %d,%s, %d-%d-%d, %d-%d-%d, %d \n", pe->id_evento, pe->tipo, pd->dia,
                                   pd->mes, pd->ano, pe->datafim.dia, pe->datafim.mes, pe->datafim.ano, pe->id_cliente);
                            pe = pe->nextEvento;
                        }
                    }
                    pd++;
                }
                pa++;
            }
            pc++;
        }
        pp = pp->next;
    }
}

void edit_estudio(LISTAEDIFICIOS *pg, int id_estudio, int numero, char configuracao[], int area, float preco_diario,
                  float preco_mensal) {
    ESTUDIO *pe = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    if (pe != NULL) {
        pe->id_estudio = id_estudio;
        strcpy(pe->configuracao, configuracao);
        pe->numero = numero;
        pe->area = area;
        pe->preco_diaria = preco_diario;
        pe->preco_mensal = preco_mensal;
    }
}


void gravar_edificios(LISTAEDIFICIOS* g) {
    EDIFICIO* pp = g->pedificios;
    FILE* fp = (fopen("C:\\Users\\Utilizador\\CLionProjects\\ProjetoLPAED\\edificios.txt", "w"));

    if (fp != NULL) {
        fprintf(fp, "Numero de edificios:%d\n", g->num_edificios);
        while (pp != NULL) {
            fprintf(fp, "%d,%s,%s,%f,%f,%f\n", pp->id_edificio, pp->nome, pp->morada, pp->preco_m2,
                    pp->latitude,
                    pp->longitude);
            ESTUDIO* pc = pp->array_estudios.pestudios;
            fprintf(fp, "Numero de estudios:%d\n", pp->array_estudios.n_estudios);
            for (int i = 0;
                 i < pp->array_estudios.n_estudios; i++) {
                fprintf(fp, "%d,%d,%d,%s,%d,%f,%f,%d\n", pc->id_estudio, pc->numero, pp->id_edificio,
                        pc->configuracao, pc->area, pc->preco_diaria, pc->preco_mensal, pc->array_agendas.size_agendas);
                pc++;
            }
            pp = pp->next;
        }
        fclose(fp);
    }
    else {
        printf("Erro na abertura do ficheiro\n");
    }
}

void escrever_agendas_txt(LISTAEDIFICIOS *g) {

    EDIFICIO *pp = g->pedificios;
    ESTUDIO_ARRAY *ea = &pp->array_estudios;
    ESTUDIO *pe = ea->pestudios;
    AGENDAS_ARRAY *pa = &pe->array_agendas;
    AGENDAS *aa = pa->pagenda;

    FILE *fp = (fopen("C:\\Users\\Utilizador\\CLionProjects\\ProjetoLPAED\\agendas.txt", "w"));

    if (fp != NULL) {

        while (pp != NULL) {

            ESTUDIO *pe = pp->array_estudios.pestudios;

            for (int i = 0; i < pp->array_estudios.n_estudios; i++) {

                AGENDAS *aa = pe->array_agendas.pagenda;
                for (int j = 0; j < pe->array_agendas.n_agendas; j++) {
                    fprintf(fp, "%d , %s\n", aa->id_agenda, aa->plataforma);
                    DIAS *pd = aa->array_dias.pdias;
                    for (int k = 0; k < aa->array_dias.n_dias; k++) {
                        fprintf(fp, "%d , %d, %d\n", pd->dia, pd->mes, pd->ano);
                        EVENTO *pev = pd->listaeventos->peventos;
                        while (pev != NULL) {
                            fprintf(fp, "%d,%s,%d-%d-%d, %d\n", pev->id_evento, pev->tipo, pev->datafim.dia,
                                    pev->datafim.mes, pev->datafim.ano, pev->id_cliente);
                            pev = pev->nextEvento;
                        }
                        pd++;
                    }
                    aa++;
                }
                pe++;
            }
            pp = pp->next;
        }
    } else {
        printf("Erro na abertura do ficheiro\n");
    }

}

LISTAEDIFICIOS* read_edificios_txt() {
    LISTAEDIFICIOS* g = create_lista_edificio();

    FILE* fp;

    if ((fp = fopen("C:\\Users\\Utilizador\\CLionProjects\\ProjetoLPAED\\edificios.txt", "r")) == NULL) {
        printf("File not opened!\n");
        return NULL;
    }

    id_edificio = 1;
    id_estudio = 1;
    id_agenda = 1;
    id_evento = 1;

    int num_edificios = 0;
    fscanf(fp, "%*[^:]:%d\n", &num_edificios);

    for (int i = 0; i < num_edificios; i++) {
        char morada[MAX200], nome[MAX200];
        int n_estudios = 0;
        float latitude, longitude, preco_m2;

        fscanf(fp, "%*d,%[^,],%[^,],%f,%f,%f\n", nome, morada, &preco_m2, &latitude, &longitude);
        fscanf(fp, "%*[^:]:%d\n", &n_estudios);

        insert_edificio(g, nome, latitude, longitude, morada, preco_m2, n_estudios);

        EDIFICIO* fe = g->pedificios;
        while (fe->next != NULL) fe = fe->next;

        for (int j = 0; j < n_estudios; j++) {
            int numero, area, size_agendas;
            float preco_diaria, preco_mensal;
            char configuracao[30];

            fscanf(fp, "%*d,%d,%*d,%[^,],%d,%f,%f,%d\n", &numero, configuracao, &area, &preco_diaria, &preco_mensal, &size_agendas);
            insert_estudio(g, fe->id_edificio, numero, configuracao, area, preco_diaria, preco_mensal, size_agendas);
        }
    }

    fclose(fp);

    print_listaEdificio(g);

    return g;
}

AGENDAS_ARRAY *create_dynarray_array_agendas(int initsize) {
    AGENDAS *pagendas = (AGENDAS *) calloc(initsize, sizeof(AGENDAS));
    AGENDAS_ARRAY *agendasarray = (AGENDAS_ARRAY *) calloc(1, sizeof(AGENDAS_ARRAY));
    agendasarray->pagenda = pagendas;
    agendasarray->n_agendas = 0;
    agendasarray->size_agendas = initsize;

    return agendasarray;
}

void remove_evento(LISTAEDIFICIOS *pg, int id_agenda, int id_evento) {
    AGENDAS *pagenda = find_agenda_dynarray_arrayagendas(pg, id_agenda);
    //NAO REMOVEMOS NADA SE A LISTA ESTIVER VAZIA
    if (pagenda->array_dias.pdias->listaeventos->peventos == NULL) {
        printf("Esse evento nao existe.");
        return;
    }
    EVENTO *pant = NULL, *pcurrent = pagenda->array_dias.pdias->listaeventos->peventos;
    while (pcurrent != NULL && pcurrent->id_evento != id_evento) {
        pant = pcurrent;
        pcurrent = pcurrent->nextEvento;
    }
    //SE O EVENTO NAO EXISTIR
    if (pcurrent == NULL) {
        return;
    }
    //REMOÇÃO A CABEÇA
    if (pcurrent == pagenda->array_dias.pdias->listaeventos->peventos) {
        pagenda->array_dias.pdias->listaeventos->peventos = pcurrent->nextEvento;
        pagenda->array_dias.pdias->listaeventos->num_eventos--;
        free(pcurrent);
        return;
    }
    pant->nextEvento = pcurrent->nextEvento;
    free(pcurrent);
    //DECREMENTAR O NUMERO DE EVENTOS
    pagenda->array_dias.pdias->listaeventos->num_eventos--;
}

EVENTO *find_evento(LISTAEDIFICIOS *pg, int id_agenda, int id_evento) {

    EDIFICIO *edificio = pg->pedificios;
    while (edificio != NULL) {
        ESTUDIO *pestudio = edificio->array_estudios.pestudios;
        for (int i = 0; i < edificio->array_estudios.n_estudios; i++) {
            AGENDAS *pst = pestudio->array_agendas.pagenda;
            for (int k = 0; k < pestudio->array_agendas.n_agendas; k++) {
                if (pst->id_agenda == id_agenda) {
                    //DIAS* pdia = pst->array_dias.pdias;
                    EVENTO *pevento = pst->array_dias.pdias->listaeventos->peventos;
                    while (pevento != NULL) {
                        if (pevento->id_evento == id_evento) {
                            return pevento;
                        }
                        pevento = pevento->nextEvento;
                    }
                }
                pst++;
            }
            pestudio++;
        }
        edificio = edificio->next;
    }
    return NULL;
}

void edit_evento(LISTAEDIFICIOS *pg, int id_agenda, int id_evento, char tipo[], DIAS datafim, int id_cliente) {
    EVENTO *pevento = find_evento(pg, id_agenda, id_evento);
    if (pevento != NULL) {
        pevento->id_evento = id_evento;
        strcpy(pevento->tipo, tipo);
        pevento->datafim.dia = datafim.dia;
        pevento->datafim.mes = datafim.mes;
        pevento->datafim.ano = datafim.ano;
        pevento->id_cliente = id_cliente;
    }
}