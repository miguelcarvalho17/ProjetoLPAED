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



typedef struct edificio *nodeEdificio; //Define nodeEdificio as pointer of data type struct edificio

/* nodeEdificio createNode(){
    nodeEdificio temp; //
    temp = (nodeEdificio)malloc(sizeof(struct edificio));
    temp->next = NULL;
    return temp;
}

nodeEdificio addNode(nodeEdificio head, int id){
    nodeEdificio temp,p; //  declarar 2 nodes temp e p
    temp = createNode(); // retorna um node com a data=id e apontar para NULL
    temp->id_edificio = id; //  id to id_edificio
    if(head == NULL){
        head = temp;     //lista ligada vazia
    }
    else{
        p  = head; // apontar p a cabeça
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp;//Point the previous last node to the new node created.
    }
    return head;
}
*/