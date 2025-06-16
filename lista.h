#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;
typedef struct Lista * ListaPtr;

ListaPtr crearLista();

//Funciones insertar
void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);

//Funciones obtener
DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);

//Funciones eliminar
DatoPtr eliminarPrimero(ListaPtr lista);
DatoPtr eliminarUltimo(ListaPtr lista);
DatoPtr eliminarPosicion(ListaPtr lista, int posicion);

int obtenerTamanio(ListaPtr lista);

//Metodos de ordenamiento
void ordenarLista(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr));
void ordenarListaSeleccion(ListaPtr lista, int (*funcionComparar)(DatoPtr,DatoPtr));
void ordenarListaInsercion(ListaPtr lista, int (*funcionComparar)(DatoPtr,DatoPtr));
ListaPtr ordenarListaCopia(ListaPtr lista, int(*funcionComparar)(DatoPtr,DatoPtr));
ListaPtr duplicarLista(ListaPtr lista);

//Busqueda
int buscarElemento(ListaPtr lista, DatoPtr datoBuscado, int (*funcionComparar)(DatoPtr, DatoPtr));
int busquedaBinaria(ListaPtr lista, DatoPtr datoBuscado, int (*funcionComparar)(DatoPtr, DatoPtr), int (*funcionIgualar)(DatoPtr, DatoPtr));

//Insertar sin desordenar(PRE: La lista tiene que estar ordenada)
void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*funcionComparar)(DatoPtr,DatoPtr));

//Mostrar generico
void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr));

//Destructor
void liberarLista(ListaPtr lista);

//Getters
NodoPtr getPrimero(ListaPtr lista);

//Setters

#endif // LISTA_H_INCLUDED
