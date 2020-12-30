//
// Created by Utilizador on 12/12/2020.
//

#ifndef PROJETOLPAED_PROJETO_H
#define PROJETOLPAED_PROJETO_H
#define MAX200 200
#define MAX20 20


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

typedef struct politica {
    char nome[MAX200];
    REGRAS_ARRAY regras;
}POLITICA;

typedef struct plataforma {
    char nome[MAX20];
    POLITICA politicas[MAX20];
}PLATAFORMA;

typedef struct plataformas_array{
    int n_plataformas;
    int size_plataformas;
    PLATAFORMA *pplataforma;
}PLATAFORMAS_ARRAY;

typedef struct dias {
    int dia;
    int mes;
    int ano;

    struct listaeventos *listaeventos;
} DIAS;

typedef struct dias_array {
    int n_dias;
    int size_dias;
    DIAS *pdias; //ARRAY DE DIAS
} DIAS_ARRAY;

typedef struct agendas{
    int id_agenda;
    char plataforma[MAX20];
    DIAS_ARRAY array_dias;
}AGENDAS;

typedef struct agendas_array{
    int n_agendas;
    int size_agendas;
    AGENDAS *pagenda;
}AGENDAS_ARRAY;

typedef struct estudio {
    int id_estudio;
    int numero;
    char configuracao[2];
    int area;
    float preco_diaria;
    float preco_mensal;
    float preco_final;
    AGENDAS_ARRAY array_agendas;
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
    struct edificio *next;
    ESTUDIO_ARRAY array_estudios;
} EDIFICIO;


typedef struct listaedificios {
    int num_edificios;
    EDIFICIO *pedificios;
} LISTAEDIFICIOS;



//LISTA LIGADA DE EVENTOS
typedef struct evento {
    int id_evento;
    char tipo[MAX20];
    DIAS datafim;
    int id_cliente;
    struct evento *nextEvento;
} EVENTO;

typedef struct listaeventos {
    int num_eventos;
    EVENTO *peventos;
} LISTAEVENTOS;

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


int main_projeto(int argc, const char *argv[]);

/** Criar lista ligada de edificios */
LISTAEDIFICIOS *create_lista_edificio();

LISTAEVENTOS *create_lista_eventos();

/** Imprimir toda a informação dos edificios */
void print_listaEdificio(const LISTAEDIFICIOS* g);

/** Funções de inserir */
void insert_edificio(LISTAEDIFICIOS *pg, char nome[MAX200], double latitude, double longitude,
                     char morada[MAX200], double preco_m2, int size_estudios);

ESTUDIO_ARRAY *create_dynarray_array_estudios(int initsize);

void insert_estudio(LISTAEDIFICIOS *pg, int id, int numero, char configuracao[], int area, float preco_diario, float preco_mensal, int size_agendas);

AGENDAS_ARRAY *create_dynarray_array_agendas(int initsize);

void insert_agenda(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio, char plataforma[], int size_dias);

void insert_dia(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio,int id_agenda, int dia, int mes, int ano);

void insert_evento(LISTAEDIFICIOS *pg, char tipo[], DIAS datafim,
                   int id_cliente,int id_agenda, int dia, int mes, int ano);

DIAS_ARRAY *create_dynarray_array_dias(int initsize);

/** Funções de remover */

void remove_edificio(LISTAEDIFICIOS *pg, char name[]);

//void remove_estudio_dynarray_arrayestudios(EDIFICIO *edificio, ESTUDIO *aremover);

void remove_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio);


/** Funções de find */
EDIFICIO *find_edificio(LISTAEDIFICIOS *pg, int id);

ESTUDIO *find_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_estudio);

AGENDAS *find_agenda_dynarray_arrayagendas(LISTAEDIFICIOS *pg, int id_agenda);

DIAS *find_dia_dynarray_arraydias(LISTAEDIFICIOS *pg,int id_agenda, int dia, int mes, int ano);

/** Funções de editar */

void edit_edificio(LISTAEDIFICIOS *pg, int id_edificio, char nome[MAX200], double latitude, double longitude,
                   char morada[MAX200], double preco_m2, int size_estudios);

void edit_estudio(LISTAEDIFICIOS *pg, int id_estudio, int numero, char configuracao[], int area, float preco_diario, float preco_mensal);

void gravar_edificios(LISTAEDIFICIOS *g);

void read_edificios_txt(LISTAEDIFICIOS *g);

void read_dyn_array_estudios_txt(LISTAEDIFICIOS *g);

#endif //PROJETOLPAED_PROJETO_H