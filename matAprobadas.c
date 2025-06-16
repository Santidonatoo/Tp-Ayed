#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matAprobadas.h"

struct MateriaAprobada{

    char nombre[50];
    float promedio;
};

MateriaAprobadaPtr crearMatAprobada(char n[50], float p){

    MateriaAprobadaPtr m = (MateriaAprobadaPtr) malloc(sizeof(struct MateriaAprobada));

    strcpy(m->nombre,n);
    m->promedio = p;

    return m;
};

void mostrarMatAprobada(void * dato){

    MateriaAprobadaPtr m = *(MateriaAprobadaPtr*)dato;

    printf("Nombre: %s\n",m->nombre);
    printf("Promedio: %.2f\n\n",m->promedio);
};

int compararAprobadaPorNota(void * dato1, void * dato2){

    MateriaAprobadaPtr m1 = *(MateriaAprobadaPtr*)dato1;
    MateriaAprobadaPtr m2 = *(MateriaAprobadaPtr*)dato2;

    return m1->promedio > m2->promedio;
};

float getNota(MateriaAprobadaPtr m){
    return m->promedio;
};
