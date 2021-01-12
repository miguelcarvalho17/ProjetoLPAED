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

typedef struct regras_array {
    int n_regras;
    int size_regras;
    REGRAS *pregras;
} REGRAS_ARRAY;

typedef struct politica {
    char nome[MAX200];
    REGRAS_ARRAY regras;
} POLITICA;

typedef struct plataforma {
    char *nome;
    POLITICA politicas[MAX20];
} PLATAFORMA;

typedef struct plataformas_array {
    int n_plataformas;
    int size_plataformas;
    PLATAFORMA *pplataforma;
} PLATAFORMAS_ARRAY;

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

typedef struct agendas {
    int id_agenda;
    char plataforma[MAX20];
    DIAS_ARRAY array_dias;
} AGENDAS;

typedef struct agendas_array {
    int n_agendas;
    int size_agendas;
    AGENDAS *pagenda;
} AGENDAS_ARRAY;

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
    char nome_cliente[MAX200];
    float preco;
    DIAS dataEntrada;
    DIAS dataSaida;
    struct historicoEstadias *pnext_estadia;
} HISTORICOESTADIAS;

typedef struct listaHistoricoEstadias {
    int num_estadias;
    HISTORICOESTADIAS *pHestadias;
} LISTAHISTORICOESTADIAS;

typedef struct hospede {
    int id_cliente;
    char nome_cliente[MAX20];
    LISTAHISTORICOESTADIAS *pprimeiraEstadia;
    struct hospede *pnext;
} HOSPEDE;

typedef struct listahospedes {
    int num_hospedes;
    HOSPEDE *phospede;
} LISTAHOSPEDES;


int main_projeto(int argc, const char *argv[]);

/** Criar lista ligada de edificios */
LISTAEDIFICIOS *create_lista_edificio();

LISTAEVENTOS *create_lista_eventos();

LISTAHOSPEDES *create_lista_hospedes();

/** Imprimir toda a informação dos edificios */
void print_listaEdificio(const LISTAEDIFICIOS *g);

void print_listaHospedes(const LISTAHOSPEDES *h);

void print_listaHistorico(const LISTAHISTORICOESTADIAS * he);

/** Funções de inserir */
void insert_edificio(LISTAEDIFICIOS *pg, char nome[MAX200], double latitude, double longitude,
                     char morada[MAX200], double preco_m2, int size_estudios);

ESTUDIO_ARRAY *create_dynarray_array_estudios(int initsize);

void insert_estudio(LISTAEDIFICIOS *pg, int id, int numero, char configuracao[], int area, float preco_diario,
                    float preco_mensal, int size_agendas);

AGENDAS_ARRAY *create_dynarray_array_agendas(int initsize);

void insert_agenda(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio, char plataforma[], int size_dias);

void insert_dia(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio, int id_agenda, int dia, int mes, int ano);

void insert_evento(LISTAEDIFICIOS *pg, const char *tipo, DIAS datafim,
                   int id_cliente, int id_agenda, int dia, int mes, int ano);

void insert_hospede(LISTAEDIFICIOS *pg,LISTAHOSPEDES *pl, const char nome[],int id_agenda, int id_evento, int id_cliente);

void insert_historicoEstadias(LISTAEDIFICIOS *pg,LISTAHOSPEDES *pl, LISTAHISTORICOESTADIAS *he, const char nome[],int id_estudio,int id_agenda,int dia, int mes, int ano, int id_evento, int id_hospede);

DIAS_ARRAY *create_dynarray_array_dias(int initsize);

/** Funções de remover */

void remove_edificio(LISTAEDIFICIOS *pg, char name[]);

//void remove_estudio_dynarray_arrayestudios(EDIFICIO *edificio, ESTUDIO *aremover);

void remove_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio);

void remove_evento(LISTAEDIFICIOS *pg, int id_agenda, int id_evento);

void remove_hospede(LISTAEDIFICIOS *pg,LISTAHOSPEDES *pl, int id_agenda, int id_evento, int id_cliente);


/** Funções de find */
EDIFICIO *find_edificio(LISTAEDIFICIOS *pg, int id);

ESTUDIO *find_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_estudio);

AGENDAS *find_agenda_dynarray_arrayagendas(LISTAEDIFICIOS *pg, int id_agenda);

DIAS *find_dia_dynarray_arraydias(LISTAEDIFICIOS *pg, int id_agenda, int dia, int mes, int ano);

EVENTO *find_evento(LISTAEDIFICIOS *pg, int id_agenda, int id_evento);

HOSPEDE *find_hospede(LISTAHOSPEDES *pl, int id);

PLATAFORMA *find_plataforma_dynarray_arrayplataformas(PLATAFORMAS_ARRAY *pa, char nome[]);

REGRAS *find_regra_dynarray_arrayregras(REGRAS_ARRAY *pra, int id_regra);

/** Funções de editar */

void edit_edificio(LISTAEDIFICIOS *pg, int id_edificio, char nome[MAX200], double latitude, double longitude,
                   char morada[MAX200], double preco_m2, int size_estudios);

void edit_estudio(LISTAEDIFICIOS *pg, int id_estudio, int numero, char configuracao[], int area, float preco_diario,
                  float preco_mensal);

void edit_evento(LISTAEDIFICIOS *pg, int id_agenda, int id_evento, char tipo[], DIAS datafim,
                 int id_cliente);

void edit_hospede(LISTAHOSPEDES *pl, int id_cliente, char nome[]);

void edit_regra(REGRAS_ARRAY *pra, int id, char tipo[], double taxa);

void escrever_edificios(LISTAEDIFICIOS* g);
void escrever_edificios_bin(LISTAEDIFICIOS* le, const char* fname);
void escrever_hospedes_txt(LISTAHOSPEDES *g);

void escrever_agenda_bin(LISTAEDIFICIOS *le, const char *fn, int agenda);

void escrever_agenda_txt(LISTAEDIFICIOS *g, int agenda);

LISTAEDIFICIOS *read_edificios_txt();
void ler_edificios_bin(LISTAEDIFICIOS* le, const char* fname);

void read_dyn_array_estudios_txt(LISTAEDIFICIOS *g);

void read_agenda_txt(LISTAEDIFICIOS* g, int edificio, int estudio);

LISTAHISTORICOESTADIAS *create_lista_historico_estadias();


DIAS diferenca_dias(int d1, int m1, int ano1, int d2, int m2, int ano2);

PLATAFORMAS_ARRAY *create_dyn_array_plataformas(int initsize);

void insert_plataforma(PLATAFORMAS_ARRAY *pa, char nome[],char politica[]);

void insert_regra(REGRAS_ARRAY *pra, int id, char tipo[], double taxa);

REGRAS_ARRAY *create_dyn_array_regras(int initsize);

int get_timestamp(int day, int month, int year);

float get_studio_occupancy(LISTAEDIFICIOS *pe, int edificio, int from, int to);

int is_between(DIAS date, int from, int to);

int is_estudio_occupied(ESTUDIO* es, int from, int to);

float get_total_estudios_occupancy(LISTAEDIFICIOS *pe, int from, int to);

void read_agenda_bin(LISTAEDIFICIOS *le, const char *agendabin, int edificio, int estudio);

LISTAHOSPEDES *read_hospedes_txt(LISTAEDIFICIOS *e, LISTAHOSPEDES *h, int id_agenda, int id_evento);

LISTAHISTORICOESTADIAS *read_historico_txt(LISTAEDIFICIOS *pg, LISTAHOSPEDES *pl,LISTAHISTORICOESTADIAS *he, int id_estudio, int id_agenda, int id_evento, int id_hospede);

void escrever_historico_estadias(LISTAHISTORICOESTADIAS *he);

#endif //PROJETOLPAED_PROJETO_H