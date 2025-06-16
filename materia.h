#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

#include "lista.h"
#include "cola.h"

struct Materia;
typedef struct Materia * MateriaPtr;

//Primitivas
MateriaPtr crearMateria(char n[50],int cod, int c);
void mostrarMateria(void * dato);

int chequearCupo(void * dato);
void listaACola(ListaPtr lista, ColaPtr cola);
void insertarPorCupo(MateriaPtr m, DatoPtr dato);
void desmatricular(MateriaPtr m);

//Getters
ListaPtr getListaInscriptos(MateriaPtr m);
ColaPtr getColaEspera(MateriaPtr m);
int getCodigoMateria(MateriaPtr m);
char* getNombreMateria(MateriaPtr m);

//Setters


//Extra
int igualarMateriaCodigo(void * dato1, void * dato2);
int compararMateriaCodigo(void * dato1, void * dato2);

#endif // MATERIA_H_INCLUDED
