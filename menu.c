#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "materia.h"
#include "inscripto.h"

void continuar(){

    char continuar[10] = " ";
    printf("\nPresione * Enter * para continuar");
    fflush(stdin);
    gets(continuar);
    system("cls");
};

void volver(int opcion, int numOpcion, char cont[10]){

    if(opcion != numOpcion){
        printf("Ingrese cualquier cosa para volver\n");
        fflush(stdin);
        gets(cont);
        system("cls");
    }
};

void borrar(int opcion, int numOpcion){

    if(opcion == numOpcion){
        system("cls");
    }else{
        printf("\n\n");
    }
};

void verYModificarAlumnos(ListaPtr mat){

    printf("Ingrese el codigo materia desea ver:");
    int busco;
    scanf("%d",&busco);
    system("cls");
    int posMatBuscada = buscarElemento(mat,&busco,igualarMateriaCodigo); //Busco la materia
    if(posMatBuscada != -1){ //Si la encuentra...
        MateriaPtr aux = *(MateriaPtr*)obtenerPosicion(mat,posMatBuscada); //Guardo el dato de la pos encontrada
        printf("* Se encuentra en la materia: %s *\n",getNombreMateria(aux)); //En que materia estoy
        if(estaVacia(getColaEspera(aux)) == 0){ //Si hay elementos en la cola
            printf("(Los cupos estan llenos, existe una cola de espera)\n");
        }
        mostrarListaGenerica(getListaInscriptos(aux),mostrarInscripto);

        int eleccion;
        do{
        printf("Que desea hacer?\n");
        printf("1 -> Eliminar a un alumno\n");
        printf("2 -> Volver atras...\n");
        printf("OPCION:");
        scanf("%d",&eleccion);

            switch(eleccion){
                case 1: desmatricular(aux);
                    break;
                case 2:
                    break;
                default: printf("Error! La opcion que intentas ingresar no existe...");
                    break;
            }
        }while(eleccion != 2);

    }else{
        printf("Error!, no se encontro ninguna materia con ese codigo...\n\n");
    }
};
