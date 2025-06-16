#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "materia.h"
#include "inscripto.h"

struct Materia{

    char nombre[50];
    int codigo;
    int cupo;
    ListaPtr inscriptos;
    ColaPtr espera;
};

MateriaPtr crearMateria(char n[50],int cod, int c){

    MateriaPtr m = (MateriaPtr) malloc(sizeof(struct Materia));

    strcpy(m->nombre,n);
    m->codigo = cod;
    m->cupo = c;
    m->inscriptos = crearLista();
    ColaPtr aux = crearCola();
    m->espera = aux; //Creo la lista y la cola vacia y no las uso por el momento

    return m;
};

void mostrarMateria(void * dato){

    MateriaPtr m = *(MateriaPtr*)dato;
    int cantInscriptos = obtenerTamanio(m->inscriptos);

    printf("\n--------------------- MATERIA ---------------------\n");
    printf("%s || Codigo: %d\n",m->nombre,m->codigo);
    printf("Cantidad de inscriptos: %d\n",cantInscriptos);

    if(estaVacia(m->espera) == 1){ //Si la cola esta vacia
        printf("Todavia queda espacio para ingresantes!\n");
    }else{ //Si la cola tiene elementos en ella
        printf("Ya no hay mas cupo, se creo una cola de espera\n");
    }
    //La cola no se muestra
};

int chequearCupo(void * dato){

    MateriaPtr m = (MateriaPtr)dato;
    int cantIngresantes = obtenerTamanio(m->inscriptos);

    if(cantIngresantes == m->cupo){
        return 0; //0 = se alcanzo el cupo
    }else{
        return 1; //1 = todavia hay espacio para mas ingresantes
    }
};

void listaACola(ListaPtr lista, ColaPtr cola){ //Paso una lista a una cola

    DatoPtr aux;
    NodoPtr actual = getPrimero(lista);

    while(actual != NULL){
        aux = getDato(actual); //Obtengo el dato
        encolar(cola,aux); //Encolo el dato
        actual = getNodoSiguiente(actual); //Avanzo por la lista
    }
};

void insertarPorCupo(MateriaPtr m, DatoPtr dato){

    int cupoDisp = chequearCupo(m);

    if(cupoDisp == 1){ //Hay cupo para inscribir
        insertarEnOrden(getListaInscriptos(m),dato,compararPorMatAprobadasYPromedio);
    }else{ //No hay más cupo para inscribir
        if(estaVacia(m->espera) == 1){ //La cola esta vacía
            encolar(m->espera,dato);
        }else{ //Hay elementos en la cola, entonces tengo que desencolarlos y volver a encolarlos
            ListaPtr auxOrdenada = crearLista(); //Creo la lista aux para guardar los datos de la cola y ordenarlo
            insertarEnOrden(auxOrdenada,dato,compararPorMatAprobadasYPromedio); //Inserto primero el dato que ingrese
            DatoPtr aux;
            while(estaVacia(m->espera) != 1){ //Mientras la cola NO esté vacía
                aux = desencolar(m->espera); //Saco todos los datos de la cola
                insertarEnOrden(auxOrdenada,aux,compararPorMatAprobadasYPromedio); //Los inserto en orden en la lista aux
            }
            listaACola(auxOrdenada,m->espera); //Paso la lista ordenada a la cola de espera de nuevo
        }
    }
};

void desmatricular(MateriaPtr m){

    int busco;
    printf("\nIngrese el dni del inscripto que desea ingresar:");
    scanf("%d", &busco);
    system("cls");
    int pos = buscarElemento(m->inscriptos,&busco,igualarDni); //Busco la posicion donde esta el alumno
    if(pos!=-1){ // != -1 significa que lo encontro
        DatoPtr dato = eliminarPosicion(m->inscriptos,pos); //Elimino
        InscriptoPtr eliminado = *(InscriptoPtr*)dato; //Guardo el dato en una struct inscripto
        printf("*Se elimino exitosamente a: %s\n\n",getNombreInscripto(eliminado)); //Muestro al eliminado
        if(estaVacia(m->espera) == 0){ // == 0 significa que hay elementos en la cola de espera
            dato = desencolar(m->espera); //Lo saco de la cola de espera
            InscriptoPtr nuevo = *(InscriptoPtr*)dato; //Lo guardo en una struct inscripto
            insertarEnOrden(m->inscriptos,dato,compararPorMatAprobadasYPromedio); //Inserto al nuevo inscripto
            printf("*Como se libero un cupo, se pudo ingresar a: %s\n\n\n",getNombreInscripto(nuevo));
        }
    }else{ //No lo encontro
        printf("No se encontro ningun inscripto con el dni %d\n",busco);
    }
};

//Getters
ListaPtr getListaInscriptos(MateriaPtr m){
    return m->inscriptos;
};

ColaPtr getColaEspera(MateriaPtr m){
    return m->espera;
};

int getCodigoMateria(MateriaPtr m){
    return m->codigo;
};

char* getNombreMateria(MateriaPtr m){
    return m->nombre;
};

//Extra
int igualarMateriaCodigo(void * dato1, void * dato2){

    MateriaPtr m = *(MateriaPtr*)dato1;
    int cod = *(int*)dato2;

    return m->codigo == cod;
};

int compararMateriaCodigo(void * dato1, void * dato2){

    MateriaPtr m1 = *(MateriaPtr*)dato1;
    MateriaPtr m2 = *(MateriaPtr*)dato2;

    return m1->codigo > m2->codigo;
};
