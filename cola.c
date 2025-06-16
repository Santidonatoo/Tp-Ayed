#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cola.h"

struct Cola{

    NodoPtr primero;
    NodoPtr ultimo;

};

ColaPtr crearCola(){

    ColaPtr cola = malloc(sizeof(struct Cola));

    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;
};

void encolar(ColaPtr cola, DatoPtr dato){

    NodoPtr actual = cola->ultimo;

    NodoPtr nuevoNodo = crearNodo(dato,NULL);

    if(actual == NULL){
        cola->primero = nuevoNodo;
    }else{
        setNodoSiguiente(actual,nuevoNodo);
    }
    cola->ultimo = nuevoNodo;
};

DatoPtr desencolar(ColaPtr cola){

    NodoPtr actual = cola->primero; //Creo un nodo con el primer nodo de la cola
    DatoPtr dato = getDato(actual); //Agarro el dato del nodo para retornarlo después
    cola->primero = getNodoSiguiente(actual); //Asgino al segundo como el nuevo primero
    if(getNodoSiguiente(actual) == NULL){
        cola->ultimo = NULL;
    }
    liberarNodo(actual);

    return dato; //Retorno al dato
};

ColaPtr duplicarCola(ColaPtr cola){

    ColaPtr colaDuplicada = crearCola();
    ColaPtr colaAux = crearCola();
    DatoPtr dato;

    while(cola->primero != NULL){
        dato = desencolar(cola);
        encolar(colaAux,dato);
        encolar(colaDuplicada,dato);
    }

    cola->ultimo = NULL; //Asigno el cola->ultimo como nulo, ya que cuando la desencolo en el primer while
                         //queda sin nodos, ya que los libero, entonces falla el encolar por primera vez

    while(colaAux->primero != NULL){
        dato = desencolar(colaAux);
        encolar(cola,dato);
    }

    return colaDuplicada;
};

void liberarCola(ColaPtr cola) {

    while(cola->primero != NULL){
        desencolar(cola);
    }
    free(cola);
};

int estaVacia(ColaPtr cola){

    int vacia;

    if(cola->primero == NULL){
        vacia = 1; // La cola está vacía
        return vacia;
    }else{
        vacia = 0; //Hay algun elemento en la cola
        return vacia;
    }

};
