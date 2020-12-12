//
// Created by Utilizador on 12/12/2020.
//

#include "projeto.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main_projeto(int argc, const char *argv[]) {

    return 0;
}


void create_dynarray_edificio(EDIFICIO *pcs, int initsize) {
    ESTUDIO *pestudio = (ESTUDIO *) calloc(initsize, sizeof(ESTUDIO));
    pcs->pestudio = pestudio;
    pcs->nestudios = initsize;
}
