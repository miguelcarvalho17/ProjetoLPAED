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
    int custo;
    int totalRegras;
    int *codigo;
    int totalDias;
    int ocupaçao;
    DIAS *array_dias;
} ESTUDIO;

typedef struct edificio {
    int id_edificio;
    int totalEstudios;
    struct edificio *next;
    ESTUDIO *array_estudio;
}EDIFICIO ;

typedef struct evento {
    int id_evento, id_cliente;
    char *nome_cliente;
    char *nome_evento;
    double horas_minutos;
    struct evento *nextEvento;
}EVENTO;

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

typedef struct hospede{
    int id_cliente;
    char *nome_cliente;
    HISTORICOESTADIAS *pprimeiraEstadia;
    struct hospede *pnext;
}HOSPEDE;



void create_dynarray_edificio(EDIFICIO *pcs, int initsize);

int main_projeto(int argc, const char *argv[]);

#endif //PROJETOLPAED_PROJETO_H
