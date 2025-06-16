#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;
typedef struct Nodo * NodoPtr;

typedef void * DatoPtr;

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);
void mostrarNodoInt(NodoPtr nodo);
void mostrarNodoFloat(NodoPtr nodo);
void mostrarNodoChar(NodoPtr nodo);

//GETTERS
NodoPtr getNodoSiguiente(NodoPtr n);
DatoPtr getDato(NodoPtr n);
DatoPtr getDatoSiguiente(NodoPtr n);

//SETTERS
void setNodoSiguiente(NodoPtr act, NodoPtr nuevo);
void setDato(NodoPtr act, DatoPtr nuevoDato);
void setDatoSiguiente(NodoPtr act, DatoPtr nuevoDato);

void liberarNodo(NodoPtr nodo);

#endif // NODO_H_INCLUDED
