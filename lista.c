#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

struct Lista{

    NodoPtr primero;

};

ListaPtr crearLista(){

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};


void insertarPrimero(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;


};


void insertarUltimo(ListaPtr lista, DatoPtr dato){

    int tam = obtenerTamanio(lista); //Obtengo el tamanio para el for
    NodoPtr nuevoNodo = crearNodo(dato,NULL);
    NodoPtr actual = lista->primero; //Me va a servir para avanzar en la lista

    if(actual == NULL){
        lista->primero = nuevoNodo; //Si el primer dato es NULL, quiere decir que la lista esta vacía
    }else{

        for(int i = 0; i<tam-1; i++){
            actual = getNodoSiguiente(actual); //Me muevo por la lista hasta el ultimo
        }
    setNodoSiguiente(actual,nuevoNodo); //Inserto el dato en el siguiente del actual (que seria el nuevo ultimo)
    }
};

void insertarPosicion(ListaPtr lista, DatoPtr dato, int pos){

    int t = obtenerTamanio(lista);

    if (pos> t){
        printf("\n\nError, no se puede insertar en pos %d por que no existe!!!", pos);
    }else{
        if (pos < 0){
            printf("\n\nError, no se puede insertar en una pos negativa!!!");
        }else{
            if (pos == 0){
                insertarPrimero(lista,dato);
            }else{
                if(pos ==t){
                    insertarUltimo(lista,dato);
                }else{
                    if(pos>0 && pos<t){
                        NodoPtr actual = lista->primero;

                        for (int i=0;i<pos-1;i++){
                            actual= getNodoSiguiente(actual);
                        }
                        NodoPtr nuevoNodo = crearNodo(dato,getNodoSiguiente(actual));
                        setNodoSiguiente(actual,nuevoNodo);
                    }
                }
            }
        }
    }
}

DatoPtr obtenerPrimero(ListaPtr lista){

    DatoPtr dato;
    dato = getDato(lista->primero);
    return dato;

};

DatoPtr obtenerUltimo(ListaPtr lista){

    int tam = obtenerTamanio(lista);
    DatoPtr dato;
    NodoPtr actual = lista->primero;

    if(actual == NULL){
        printf("\nNo hay datos en la lista\n");
    }else{
        for(int i = 0; i<tam-1; i++){
            actual = getNodoSiguiente(actual);
        }
        dato = getDato(actual);
    }
    return dato;
};


DatoPtr obtenerPosicion(ListaPtr lista, int posicion){

    DatoPtr dato;
    int tam = obtenerTamanio(lista);

    if(posicion > tam+1){
        printf("\n\nERROR, no se puede obtener en la pos %d porque no existe",posicion);
    }else{
        if(posicion < 0){
            printf("\n\nERROR, no se puede obtener en una posicion negativa");
        }else{
            if(posicion == 0){
                dato = obtenerPrimero(lista);
            }else{
                if(posicion == tam){
                    dato = obtenerUltimo(lista);
                }else{
                    if(posicion > 0 && posicion < tam){
                        NodoPtr actual = lista->primero;
                        for(int i = 0; i<posicion; i++){
                            actual = getNodoSiguiente(actual);
                        }
                        dato = getDato(actual);
                    }
                }
            }
        }
    }
    return dato;
};

DatoPtr eliminarPrimero(ListaPtr lista){

    NodoPtr actual = lista->primero;
    DatoPtr dato = getDato(actual);
    lista->primero = getNodoSiguiente(actual);
    liberarNodo(actual);

    return dato;
};

DatoPtr eliminarUltimo(ListaPtr lista){

    NodoPtr actual = lista->primero;
    DatoPtr dato;

    if(getNodoSiguiente(actual) == NULL){
            dato = eliminarPrimero(lista);
    }else{
        int tam = obtenerTamanio(lista);
        for (int i = 0; i<tam-2; i++){
            actual = getNodoSiguiente(actual);
        }
        dato = getDatoSiguiente(actual);
        liberarNodo(getNodoSiguiente(actual));
        setNodoSiguiente(actual,NULL);
    }
    return dato;
}

DatoPtr eliminarPosicion(ListaPtr lista, int posicion){

    int tam = obtenerTamanio(lista);
    DatoPtr dato;

    if (posicion > tam){
        printf("\n\nERROR, no se puede eliminar en una posicion que no existe...");
    }else{
        if (posicion < 0){
            printf("\n\nERROR, no se puede eliminar en una posicion negativa");
        }else{
            if (posicion == 0){
                dato = eliminarPrimero(lista);
            }else{
                if(posicion == tam){
                    dato = eliminarUltimo(lista);
                }else{
                    NodoPtr actual = lista->primero;
                    NodoPtr anterior = NULL;

                    for (int i = 0; i<posicion; i++){
                        anterior = actual;
                        actual = getNodoSiguiente(actual);
                    }
                    dato = getDato(actual);
                    setNodoSiguiente(anterior,getNodoSiguiente(actual));
                    liberarNodo(actual);
                }
            }
        }
    }
    return dato;
};

int obtenerTamanio(ListaPtr lista){

    NodoPtr actual = lista->primero;
    int tam = 0;

    while(actual != NULL){
        tam++;
        actual = getNodoSiguiente(actual);
    }
    return tam;
};

void ordenarLista(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr)){

    DatoPtr aux;

    NodoPtr actual = lista->primero;
    int tam = obtenerTamanio(lista);

    for(int i = 0; i<tam; i++){
        for(int j = 0; j<tam-1; j++){
            if(funcionComparar(getDato(actual),getDatoSiguiente(actual))){
                aux = getDato(actual);
                setDato(actual,getDatoSiguiente(actual));
                setDatoSiguiente(actual,aux);
            }
            actual = getNodoSiguiente(actual);
        }
        actual = lista->primero;
    }
};

NodoPtr getNodoPos(ListaPtr lista, int pos){

    NodoPtr actual = lista->primero;
    int i = 0;

    while(i < pos){
        actual = getNodoSiguiente(actual);
        i++;
    }

    return actual;
};

void ordenarListaSeleccion(ListaPtr lista, int (*funcionComparar)(DatoPtr,DatoPtr)){

    DatoPtr aux;
    int min;
    NodoPtr actual = lista->primero;

    for (int i = 0; i<obtenerTamanio(lista); i++){
        min = i;

        for (int j=i+1;j<obtenerTamanio(lista);j++){
            if (funcionComparar(obtenerPosicion(lista,min),obtenerPosicion(lista,j))){
                min = j;
            }
        }

        aux = obtenerPosicion(lista,min);
        setDato(getNodoPos(lista,min),getDato(actual));
        setDato(actual,aux);

        actual = getNodoSiguiente(actual);
    }
};

void ordenarListaInsercion(ListaPtr lista, int (*funcionComparar)(DatoPtr,DatoPtr)){

    int x,y,m,izq,der;
    DatoPtr aux;

    for(x = 1; x < obtenerTamanio(lista); x++){
        aux = obtenerPosicion(lista,x);
        izq = 0;
        der = x-1;
        while(izq <= der){
            m = (izq + der)/2;
            if(funcionComparar(obtenerPosicion(lista,m),aux)){
                der = m-1;
            }else{
                izq = m + 1;
            }
        }
        y = x - 1;
        while( y >= izq){
            setDato(getNodoPos(lista,y+1),obtenerPosicion(lista,y));
            y = y - 1;
        }
        setDato(getNodoPos(lista,izq),aux);
    }
};

ListaPtr ordenarListaCopia(ListaPtr lista, int(*funcionComparar)(DatoPtr,DatoPtr)){

    ListaPtr copia = duplicarLista(lista);
    ordenarLista(copia, funcionComparar);

    return copia;
};

ListaPtr duplicarLista(ListaPtr lista){

    ListaPtr listaDuplicada = crearLista();
    NodoPtr actual = lista->primero;

    while(actual != NULL){
        insertarUltimo(listaDuplicada, getDato(actual));
        actual = getNodoSiguiente(actual);
    }
    return listaDuplicada;
};


int buscarElemento(ListaPtr lista, DatoPtr datoBuscado, int (*funcionComparar)(DatoPtr, DatoPtr)){

    NodoPtr actual = lista->primero;
    int i = 0;
    int pos = -1;
    int tam = obtenerTamanio(lista);

    while(pos == -1 && i<tam){
        if(funcionComparar(getDato(actual),datoBuscado)){
            pos = i;
        }
        i++;
        actual = getNodoSiguiente(actual);
    }
    return pos;
};

int busquedaBinaria(ListaPtr lista, DatoPtr datoBuscado, int (*funcionComparar)(DatoPtr, DatoPtr), int (*funcionIgualar)(DatoPtr, DatoPtr)){

    int sup = obtenerTamanio(lista)-1;
    int inf = 0;
    int centro = 0;

    while(inf <= sup){
        centro = (inf+sup)/2;
        if(funcionIgualar(obtenerPosicion(lista,centro),datoBuscado)){
            return centro;
        }
        if(funcionComparar(obtenerPosicion(lista,centro),datoBuscado)){
            sup = centro - 1;
        }else{
            inf = centro + 1;
        }
    }
    return -1;
};

void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*funcionComparar)(DatoPtr,DatoPtr)){

    NodoPtr actual = lista->primero;
    int pos = -1;
    int t = obtenerTamanio(lista);
    int i = 0;
    while(pos == -1 && i<t){
        if(funcionComparar(getDato(actual),dato)){
            pos = i;
        }
        actual = getNodoSiguiente(actual);
        i++;
    }
    if(pos!=-1){
        insertarPosicion(lista,dato,pos);
    }else{
        insertarUltimo(lista,dato);
    }
};

void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr)){

    NodoPtr actual = lista->primero;

    while (actual != NULL){
        mostrar(getDato(actual));
        actual = getNodoSiguiente(actual);
    }
    printf("\n");


};

void liberarLista(ListaPtr lista) {

    NodoPtr actual = lista->primero;

    while(actual != NULL){

        free(actual);
        actual = getNodoSiguiente(actual);
    };
};

NodoPtr getPrimero(ListaPtr lista){
    return lista->primero;
};
