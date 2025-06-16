#ifndef INSCRIPTO_H_INCLUDED
#define INSCRIPTO_H_INCLUDED

#include "lista.h"

struct Inscripto;
typedef struct Inscripto * InscriptoPtr;

//Primitivas
InscriptoPtr crearInscripto(char n[15],char a[15], int d);
void mostrarInscripto(void * dato);

void calcularPromedioGeneral(InscriptoPtr ins);
int compararPorMatAprobadasYPromedio(void * dato1, void * dato2);
int igualarDni(void * dato1, void * dato2);

int compararDni(void * dato1, void * dato2);

//Getters
ListaPtr getListaAprobadas(InscriptoPtr ins);
char* getNombreInscripto(InscriptoPtr ins);

//Setters

#endif // INSCRIPTO_H_INCLUDED
