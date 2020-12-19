//
// Created by Utilizador on 12/12/2020.
//

#ifndef PROJETOLPAED_PROJETO_H
#define PROJETOLPAED_PROJETO_H
#define MAX200 200


typedef struct dias {
    int dia;
    int mes;
    int ano;

    struct evento *evento;
} DIAS;

typedef struct estudio {
    int id_estudio;
    int numero;
    int edificio;
    char configuracao[2];
    int area;
    int totalRegras;
    int *codigo;
    int totalDias;
    int ocupaçao;
    DIAS *array_dias;
} ESTUDIO;

typedef struct estudio_array {
    int n_estudios;
    int size_estudios;
    ESTUDIO *pestudios; //ARRAY DE ESTUDIOS
} ESTUDIO_ARRAY;

//LISTA LIGADA DE EDIFICIOS
typedef struct edificio {
    int id_edificio;
    char nome[MAX200];
    double latitude;
    double longitude;
    char morada[MAX200];
    double preco_m2;
    //int totalEstudios;
    struct edificio *next;
    ESTUDIO_ARRAY array_estudios;
    //ESTUDIO *array_estudio;
} EDIFICIO;




typedef struct listaedificios {
    EDIFICIO *pedificios;
} LISTAEDIFICIOS;


//LISTA LIGADA DE EVENTOS
typedef struct evento {
    int id_evento, id_cliente;
    char *nome_cliente;
    char *nome_evento;
    double horas_minutos;
    struct evento *nextEvento;
} EVENTO;

typedef struct regras {
    int id;
    char *regra;
    int preços;
} REGRAS;

typedef struct historicoEstadias {
    int id_estadia;
    char *nome_evento;
    int preço;
    double hora_minuto;
    DIAS data;
    struct historicoEstadias *pnext_estadia;
} HISTORICOESTADIAS;

typedef struct hospede {
    int id_cliente;
    char *nome_cliente;
    HISTORICOESTADIAS *pprimeiraEstadia;
    struct hospede *pnext;
} HOSPEDE;

LISTAEDIFICIOS create_lista_edificio(int ID_edificios[], int size);

void insert_edificio(LISTAEDIFICIOS *pg, int id_edificio, char nome[MAX200], double latitude, double longitude,
                     char morada[MAX200], float preco_m2);


void create_dynarray_edificio(EDIFICIO *pcs, int initsize);

int main_projeto(int argc, const char *argv[]);

#endif //PROJETOLPAED_PROJETO_H
