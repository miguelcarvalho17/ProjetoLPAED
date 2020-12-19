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

    return 0;
}


LISTAEDIFICIOS create_lista_edificio(int ID_edificios[], int size) {
    LISTAEDIFICIOS e1 = {NULL};
    for (int i = 0; i < size; ++i) {
        insert_edificio(&e1, ID_edificios[i],"PF Boavista",41.162392,-8.655714,"Avenida da Boavista", 1.5);
    }
    return e1;
}

void insert_edificio(LISTAEDIFICIOS *pg, int id_edificio, char nome[MAX200],double latitude, double longitude, char morada[MAX200], float preco_m2) {
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

void insert_estudio(LISTAEDIFICIOS *pg, const char player[], char id, char suit, int points) {
    //FUNÇAO AUXILIAR
    PLAYER *pp = find_player(pg, player);

    if (pp != NULL) {

        if (pp->deck.n_cards >= pp->deck.size_cards) {
            if (pp->deck.size_cards == 0) {
                pp->deck.size_cards = 2;
            } else {
                pp->deck.size_cards *= 2;
            }
            pp->deck.pcards = (CARD *) realloc(pp->deck.pcards, sizeof(CARD) * pp->deck.size_cards);
        }
        CARD *pc = pp->deck.pcards + pp->deck.n_cards;
        pc->cardId = id;
        pc->cardSuit = suit;
        pc->cardPoints = points;

        pp->deck.n_cards++;
    }

}

/*
 * TEMOS DE ACABAR O PRINTF!!!!
void print_lista_edificios(LISTAEDIFICIOS e) {
    EDIFICIO *pedificio = e.pedificios;

    while (pedificio != NULL) {
        printf("Edificio:ID-> %d,Nome-> %s,Latitude %lf, Longitude-> %lf, Morada %s, Preco m2-> %lf \n", pedificio->id_edificio, pedificio->nome, pedificio->latitude, pedificio->longitude, pedificio->morada, pedificio->preco_m2);
        ESTUDIO *pestudio = pedificio->array_estudios.pestudios;
        for (int i = 0; i < pedificio->array_estudios.n_estudios; ++i) {
            printf("\tEstudio:%c, %c, %d\n", pestudio->id_estudio, pestudio->numero, pc->cardPoints);
            pestudio++;
        }
        pedificio = pedificio->next;
    }
*/
