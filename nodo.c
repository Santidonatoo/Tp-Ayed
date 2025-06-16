#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nodo.h"
#include "lista.h"

struct Nodo {

    DatoPtr dato;
    NodoPtr siguiente;

};

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){

    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;
};


void mostrarNodoInt(NodoPtr nodo){

    printf("{ %d }", *(int *)nodo->dato);
};

void mostrarNodoFloat(NodoPtr nodo){

    printf("{ %.2f }",*(float *)nodo->dato);
};

void mostrarNodoChar(NodoPtr nodo){

    printf("{ %s }",(char *)nodo->dato);
};

NodoPtr getNodoSiguiente(NodoPtr n){

    return n->siguiente;
};

DatoPtr getDato(NodoPtr n){
    return n->dato;
};

DatoPtr getDatoSiguiente(NodoPtr n){

    return n->siguiente->dato;
};

void setNodoSiguiente(NodoPtr act, NodoPtr nuevo){

    act->siguiente = nuevo;

};

void setDato(NodoPtr act, DatoPtr nuevoDato){

    act->dato = nuevoDato;
};

void setDatoSiguiente(NodoPtr act, DatoPtr nuevoDato){

    act->siguiente->dato = nuevoDato;
};

void liberarNodo(NodoPtr nodo){

    free(nodo);
};
