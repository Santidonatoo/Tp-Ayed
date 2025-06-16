#ifndef MATAPROBADAS_H_INCLUDED
#define MATAPROBADAS_H_INCLUDED

struct MateriaAprobada;
typedef struct MateriaAprobada * MateriaAprobadaPtr;

//Primitivas
MateriaAprobadaPtr crearMatAprobada(char n[50], float p);
void mostrarMatAprobada(void * dato);

//Getters
float getNota(MateriaAprobadaPtr m);

//Setters


//Extra
int compararAprobadaPorNota(void * dato1, void * dato2);

#endif // MATAPROBADAS_H_INCLUDED
