//
// Created by Utilizador on 12/12/2020.
//

#ifndef PROJETOLPAED_PROJETO_H
#define PROJETOLPAED_PROJETO_H
#define MAX200 200


typedef struct estudio {
    int configuraçao; //numero de quartos


} ESTUDIO;


typedef struct edificio {
    char morada; // array
    float latitude;
    float longitude;
    char name[MAX200];
    ESTUDIO *pestudio;
    int nestudios;
} EDIFICIO;


void create_dynarray_edificio(EDIFICIO *pcs, int initsize);
int main_projeto(int argc, const char *argv[]);

#endif //PROJETOLPAED_PROJETO_H
