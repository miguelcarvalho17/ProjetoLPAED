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

    struct evento *evento;//  TEM DE MUDAR PARA UMA LISTA LIGADA DE EVENTOS
} DIAS;

typedef struct regras {
    int id;
    char tipo[MAX200];
    double taxa;
} REGRAS;

typedef struct regras_array{
    int n_regras;
    int size_regras;
    REGRAS *pregras;
}REGRAS_ARRAY;

typedef struct POLITICA {
    char nome[MAX200];
    REGRAS_ARRAY regras;
}POLITICA;

typedef struct estudio {
    int id_estudio;
    int numero;
    char configuracao[2];
    int area;
    int n_politicas;
    int *codigo;
    int totalDias;
    POLITICA politicas[MAX200];
    DIAS *array_dias;// vai entrar nas agendas, nao aqui, ARRAY DE AGENDAS
} ESTUDIO;

typedef struct estudio_array {
    int n_estudios;
    int size_estudios;
    ESTUDIO *pestudios; //ARRAY DE ESTUDIOS
} ESTUDIO_ARRAY;

//LISTA LIGADA DE EDIFICIOS
typedef struct edificio {
    int id_edificio;
    char nome[MAX200];// usar com *
    double latitude;
    double longitude;
    char morada[MAX200];
    double preco_m2;
    //int totalEstudios;
    struct edificio *next;
    ESTUDIO_ARRAY array_estudios;
} EDIFICIO;


typedef struct listaedificios {
    int num_edificios;
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

typedef struct historicoEstadias {
    int id_estadia;
    char *nome_evento;
    int preco;
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

LISTAEDIFICIOS *create_lista_edificio();

ESTUDIO remove_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_estudio);

void insert_edificio(LISTAEDIFICIOS *pg, int id_edificio, char nome[MAX200], double latitude, double longitude,
                     char morada[MAX200], double preco_m2, int size_estudios);

void insert_estudio_dynarray_array_estudio(ESTUDIO_ARRAY *pcs,int id, int numero, char configuracao[], int area);

//ESTUDIO remove_estudio_dynarray_arrayestudios(ESTUDIO_ARRAY *pcs, int id_estudio);

ESTUDIO *find_estudio_dynarray_arrayestudios(ESTUDIO_ARRAY cs, int id_estudio);

void print_dynarray_array_estudios(ESTUDIO_ARRAY cs);

void print_listaEdificio(const LISTAEDIFICIOS* g);

EDIFICIO *find_edificio(LISTAEDIFICIOS *pg, int id);

void insert_estudio(LISTAEDIFICIOS *pg, int id,int id_estudio, int numero, char configuracao[], int area);

ESTUDIO_ARRAY *create_dynarray_array_estudios(int initsize);


int main_projeto(int argc, const char *argv[]);

#endif //PROJETOLPAED_PROJETO_H