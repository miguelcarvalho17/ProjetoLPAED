//
// Created by Utilizador on 12/12/2020.
//

#include "projeto.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main_projeto(int argc, const char *argv[]) {
    int ids[] = {1, 2, 3, 4};
    LISTAEDIFICIOS e = create_lista_edificio(ids, 4);
    insert_estudio(&e, 1, 1, "t2", 50);
    print_listaEdificio(e);

    //USAR ISTO
    //e.pedificios->array_estudios.pestudios;

    return 0;
}


LISTAEDIFICIOS create_lista_edificio(int ID_edificios[], int size) {
    LISTAEDIFICIOS e1 = {NULL};
        insert_edificio(&e1, ID_edificios[0], "PF Boavista", 41.162392, -8.655714, "Avenida da Boavista", 1.5);
        insert_edificio(&e1, ID_edificios[1], "PF Maia", 41.162392, -8.655714, "Avenida da Boavista", 1.5);
    return e1;
}

void insert_edificio(LISTAEDIFICIOS *pg, int id_edificio, char nome[MAX200], double latitude, double longitude,
                     char morada[MAX200], double preco_m2) {
    //TEMOS UM JOGO A APONTAR PARA NULL
    //QUEREMOS COLOCAR O JOGO A APONTAR PARA OS JOGADORES
    //PLAYER CRIADO
    EDIFICIO *s = (EDIFICIO *) malloc(sizeof(EDIFICIO));
    s->id_edificio = id_edificio;
    strcpy(s->nome, nome);
    s->latitude = latitude;
    s->longitude = longitude;
    strcpy(s->morada, morada);
    s->preco_m2 = preco_m2;
    ESTUDIO_ARRAY estudio = {0, 0, NULL};
    s->array_estudios = estudio;
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

void insert_estudio(LISTAEDIFICIOS *pg, int id, int numero, char configuracao[], int area) {
    //FUNÇAO AUXILIAR
    EDIFICIO *pedificio = find_edificio(pg, id);

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
        pestudio->id_estudio = id;
        pestudio->numero = numero;
        strcpy(pestudio->configuracao, configuracao);
        pestudio->area = area;


        pedificio->array_estudios.n_estudios++;
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

void print_listaEdificio(LISTAEDIFICIOS g) {
    EDIFICIO *pp = g.pedificios;
    while (pp != NULL) {
        printf("EDIFICIO: %d, %s, %lf, %lf, %s, %lf\n", pp->id_edificio, pp->nome, pp->latitude, pp->longitude, pp->morada, pp->preco_m2);
        ESTUDIO *pc = pp->array_estudios.pestudios;
        for (int i = 0; i < pp->array_estudios.n_estudios; ++i) {
            printf("\tEstudio:%d, %d, %s, %d\n", pc->id_estudio, pc->numero, pc->configuracao, pc->area);
            pc++;
        }
        pp = pp->next;
    }
}
