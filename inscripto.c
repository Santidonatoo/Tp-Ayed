#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inscripto.h"
#include "matAprobadas.h"

struct Inscripto{

    char nombre[15];
    char apellido[15];
    int dni;
    float promGeneral;
    ListaPtr materiasAprobadas;

};

InscriptoPtr crearInscripto(char n[15],char a[15], int d){

    InscriptoPtr ins = (InscriptoPtr) malloc(sizeof(struct Inscripto));

    strcpy(ins->nombre,n);
    strcpy(ins->apellido,a);
    ins->dni = d;
    ins->materiasAprobadas = crearLista(); //Creo la lista de materias aprobadas sin nada

    return ins;
};

void mostrarInscripto(void * dato){

    InscriptoPtr ins = *(InscriptoPtr*)dato;

    printf("\n|---ALUMNO---|\n");
    printf("Nombre: %s\n",ins->nombre);
    printf("Apellido: %s\n",ins->apellido);
    printf("DNI: %d\n",ins->dni);
    if(ins->promGeneral != 0){
    printf("Promedio General: %.2f\n\n",ins->promGeneral);
    }
    if(getPrimero(ins->materiasAprobadas) == NULL){ //Si la lista de materias aprobradas esta vacia
        printf("El alumno no registra materias aprobadas...\n");
    }else{ //Si posee materias aprobadas
        printf("Materias aprobadas:\n");
        mostrarListaGenerica(ins->materiasAprobadas, mostrarMatAprobada);
    }
};

void calcularPromedioGeneral(InscriptoPtr ins){

    int i = 0; //Iterador para contar la cantidad de materias totales
    float acu = 0; //Acumulador donde voy a guardar todas las notas
    MateriaAprobadaPtr aux; //Lo uso para obtener el dato de la lista
    NodoPtr actual = getPrimero(ins->materiasAprobadas);  //Me paro en el primer nodo de la lista de matAprobadas

    while(actual != NULL){
        aux = *(MateriaAprobadaPtr*)getDato(actual); //Guardo la materia en un auxiliar para acceder a la nota
        acu = acu + getNota(aux);
        actual = getNodoSiguiente(actual);
        i++;
    }
    if(acu != 0){
        acu = acu/i; //Promedio
    }

    ins->promGeneral = acu; //Lo cargo a la struct
};

int compararPorMatAprobadasYPromedio(void * dato1, void * dato2){

    InscriptoPtr ins1 = *(InscriptoPtr*)dato1;
    InscriptoPtr ins2 = *(InscriptoPtr*)dato2;
    int comparacion;

    //Comparo la cantidad de materias y si es igual la cantidad de materias, comparo por promedio general
    if((obtenerTamanio(ins1->materiasAprobadas)< obtenerTamanio(ins2->materiasAprobadas)) ||
       (obtenerTamanio(ins1->materiasAprobadas) == obtenerTamanio(ins2->materiasAprobadas) &&
        ins1->promGeneral < ins2->promGeneral)){
            comparacion = 1;
        }else{
            comparacion = 0;
        }
    return comparacion;
};

int igualarDni(void * dato1, void * dato2){

    InscriptoPtr ins = *(InscriptoPtr*)dato1;
    int dni = *(int*)dato2;

    return ins->dni == dni;
};

int compararDni(void * dato1, void * dato2){

    InscriptoPtr ins1 = *(InscriptoPtr*)dato1;
    InscriptoPtr ins2 = *(InscriptoPtr*)dato2;

    return ins1->dni < ins2->dni;
};

ListaPtr getListaAprobadas(InscriptoPtr ins){
    return ins->materiasAprobadas;
};

char* getNombreInscripto(InscriptoPtr ins){
    return ins->nombre;
};
