#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "materia.h"
#include "matAprobadas.h"
#include "inscripto.h"
#include "menu.h"

//Alumno: Santino Donato - DNI: 46.638.634 - Algoritmos y estructuras de datos - Comisión Lunes TM - TP FINAL
int main()
{
    //Creo todas las materias
    MateriaPtr m1 = crearMateria("Programacion concurrente",8614,4);
    MateriaPtr m2 = crearMateria("Proyecto de software",8619,9);
    MateriaPtr m3 = crearMateria("Matematica 3",8613,10);
    MateriaPtr m4 = crearMateria("Sistemas Operativos",8626,5);
    MateriaPtr m5 = crearMateria("Redes y Comunicaciones",8622,6);
    MateriaPtr m6 = crearMateria("Orientacion a objetos 2",8616,8);
    MateriaPtr m7 = crearMateria("Ingenieria de Software 2",8615,20);

    //Inserto todas las materias en una lista en orden por codigo
    ListaPtr materias = crearLista();
    insertarEnOrden(materias,&m1,compararMateriaCodigo);
    insertarEnOrden(materias,&m2,compararMateriaCodigo);
    insertarEnOrden(materias,&m3,compararMateriaCodigo);
    insertarEnOrden(materias,&m4,compararMateriaCodigo);
    insertarEnOrden(materias,&m5,compararMateriaCodigo);
    insertarEnOrden(materias,&m6,compararMateriaCodigo);
    insertarEnOrden(materias,&m7,compararMateriaCodigo);

    //Cargo al inscripto n1
    InscriptoPtr a1 = crearInscripto("Santino","Donato",46638634);
    MateriaAprobadaPtr aprob1 = crearMatAprobada("Matematica 1",7);
    MateriaAprobadaPtr aprob2 = crearMatAprobada("Arquitectura de computadoras",10);
    insertarEnOrden(getListaAprobadas(a1),&aprob1,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a1),&aprob2,compararAprobadaPorNota);

    //Cargo al inscripto n2
    InscriptoPtr a2 = crearInscripto("Javier","Vescio",65381920);
    MateriaAprobadaPtr aprob3 = crearMatAprobada("Programacion de computadoras",9);
    MateriaAprobadaPtr aprob4 = crearMatAprobada("Matematica 2",8);
    insertarEnOrden(getListaAprobadas(a2),&aprob3,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a2),&aprob4,compararAprobadaPorNota);

    //Cargo al inscripto n3
    InscriptoPtr a3 = crearInscripto("Nicolas","Perez",21547898);
    MateriaAprobadaPtr aprob5 = crearMatAprobada("Ingles 1",9);
    MateriaAprobadaPtr aprob6 = crearMatAprobada("Ingenieria de Software 1",10);
    MateriaAprobadaPtr aprob7 = crearMatAprobada("Ingles 2",10);
    insertarEnOrden(getListaAprobadas(a3),&aprob5,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a3),&aprob6,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a3),&aprob7,compararAprobadaPorNota);

    //Cargo al inscripto n4
    InscriptoPtr a4 = crearInscripto("Enzo","Perez",30215478);
    MateriaAprobadaPtr aprob8 = crearMatAprobada("Programacion de computadoras",8);
    MateriaAprobadaPtr aprob9 = crearMatAprobada("Matematica 1",6);
    MateriaAprobadaPtr aprob10 = crearMatAprobada("Organizacion de computadoras",10);
    MateriaAprobadaPtr aprob11 = crearMatAprobada("Expresion de problemas y algoritmos",9);
    insertarEnOrden(getListaAprobadas(a4),&aprob8,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a4),&aprob9,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a4),&aprob10,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a4),&aprob11,compararAprobadaPorNota);

    //Cargo al inscripto n5
    InscriptoPtr a5 = crearInscripto("Juanfer","Quintero",95478512);
    MateriaAprobadaPtr aprob12 = crearMatAprobada("Matematica 2",4);
    MateriaAprobadaPtr aprob13 = crearMatAprobada("Arquitectura de computadoras",6);
    MateriaAprobadaPtr aprob14 = crearMatAprobada("Ingles 3",8);
    insertarEnOrden(getListaAprobadas(a5),&aprob12,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a5),&aprob13,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a5),&aprob14,compararAprobadaPorNota);

    //Cargo al inscripto n6
    InscriptoPtr a6 = crearInscripto("Adrian","Martinez",62103486);
    MateriaAprobadaPtr aprob15 = crearMatAprobada("Programacion de computadoras",7);
    MateriaAprobadaPtr aprob16 = crearMatAprobada("Expresion de problemas y algoritmos",9);
    insertarEnOrden(getListaAprobadas(a6),&aprob15,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a6),&aprob16,compararAprobadaPorNota);

    //Cargo al inscripto n7
    InscriptoPtr a7 = crearInscripto("Maximiliano","Salas",14579255);
    MateriaAprobadaPtr aprob17 = crearMatAprobada("Programacion de computadoras",5);
    insertarEnOrden(getListaAprobadas(a7),&aprob17,compararAprobadaPorNota);

    //Cargo al inscripto n8
    InscriptoPtr a8 = crearInscripto("Gaston","Martirena",46910375);
    insertarEnOrden(getListaAprobadas(a8),&aprob4,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a8),&aprob8,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a8),&aprob1,compararAprobadaPorNota);

    //Cargo al inscripto n9
    InscriptoPtr a9 = crearInscripto("Gabriel","Arias",45716954);
    insertarEnOrden(getListaAprobadas(a9),&aprob1,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a9),&aprob10,compararAprobadaPorNota);

    //Cargo al inscripto n10
    InscriptoPtr a10 = crearInscripto("Braian","Romero",42658894);
    insertarEnOrden(getListaAprobadas(a10),&aprob16,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a10),&aprob7,compararAprobadaPorNota);

    //Cargo al inscripto n11
    InscriptoPtr a11 = crearInscripto("Brenda","Lopez",30021578);
    insertarEnOrden(getListaAprobadas(a11),&aprob17,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a11),&aprob9,compararAprobadaPorNota);

    //Cargo al inscripto n12
    InscriptoPtr a12 = crearInscripto("Gabriel","Rojas",27389120);
    insertarEnOrden(getListaAprobadas(a12),&aprob11,compararAprobadaPorNota);

    //Cargo al inscripto n13
    InscriptoPtr a13 = crearInscripto("Agustin","Almendra",28179023);

    //Cargo al inscripto n14
    InscriptoPtr a14 = crearInscripto("Baltazar","Rodriguez",27384910);
    insertarEnOrden(getListaAprobadas(a14),&aprob14,compararAprobadaPorNota);

    //Cargo al inscripto n15
    InscriptoPtr a15 = crearInscripto("Facundo","Mura",52718643);
    insertarEnOrden(getListaAprobadas(a15),&aprob15,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a15),&aprob2,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a15),&aprob1,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a15),&aprob7,compararAprobadaPorNota);

    //Cargo al inscripto n16
    InscriptoPtr a16 = crearInscripto("Juan","Nardoni",43817009);
    insertarEnOrden(getListaAprobadas(a16),&aprob6,compararAprobadaPorNota);
    insertarEnOrden(getListaAprobadas(a16),&aprob1,compararAprobadaPorNota);

    //Añado el promedio general a los estudiantes
    calcularPromedioGeneral(a1);
    calcularPromedioGeneral(a2);
    calcularPromedioGeneral(a3);
    calcularPromedioGeneral(a4);
    calcularPromedioGeneral(a5);
    calcularPromedioGeneral(a6);
    calcularPromedioGeneral(a7);
    calcularPromedioGeneral(a8);
    calcularPromedioGeneral(a9);
    calcularPromedioGeneral(a10);
    calcularPromedioGeneral(a11);
    calcularPromedioGeneral(a12);
    calcularPromedioGeneral(a13);
    calcularPromedioGeneral(a14);
    calcularPromedioGeneral(a15);
    calcularPromedioGeneral(a16);

    //Ingreso los inscriptos a las materias
    //Inscripto a1:
    insertarPorCupo(m1,&a1);
    insertarPorCupo(m2,&a1);
    insertarPorCupo(m3,&a1);
    insertarPorCupo(m6,&a1);
    //Inscripto a2:
    insertarPorCupo(m1,&a2);
    insertarPorCupo(m4,&a2);
    insertarPorCupo(m7,&a2);
    //Inscripto a3:
    insertarPorCupo(m5,&a3);
    insertarPorCupo(m2,&a3);
    //Inscripto a4:
    insertarPorCupo(m3,&a4);
    insertarPorCupo(m7,&a4);
    insertarPorCupo(m5,&a4);
    insertarPorCupo(m2,&a4);
    //Inscripto a5:
    insertarPorCupo(m1,&a5);
    //Inscripto a6:
    insertarPorCupo(m1,&a6);
    insertarPorCupo(m3,&a6);
    insertarPorCupo(m5,&a6);
    //Inscripto a7:
    insertarPorCupo(m4,&a7);
    insertarPorCupo(m5,&a7);
    insertarPorCupo(m6,&a7);
    //Inscritpo a8:
    insertarPorCupo(m6,&a8);
    insertarPorCupo(m1,&a8);
    insertarPorCupo(m3,&a8);
    //Inscripto a9:
    insertarPorCupo(m2,&a9);
    insertarPorCupo(m3,&a9);
    //Inscripto a10:
    insertarPorCupo(m1,&a10);
    insertarPorCupo(m5,&a10);
    insertarPorCupo(m7,&a10);
    insertarPorCupo(m6,&a10);
    //Inscripto a11:
    insertarPorCupo(m4,&a11);
    insertarPorCupo(m7,&a11);
    insertarPorCupo(m2,&a11);
    //Inscripto a12:
    insertarPorCupo(m5,&a12);
    insertarPorCupo(m7,&a12);
    //Inscripto a13:
    insertarPorCupo(m4,&a13);
    insertarPorCupo(m7,&a13);
    insertarPorCupo(m5,&a13);
    insertarPorCupo(m2,&a13);
    //Inscripto a14:
    insertarPorCupo(m4,&a14);
    //Inscripto a15:
    insertarPorCupo(m1,&a15);
    insertarPorCupo(m2,&a15);
    insertarPorCupo(m3,&a15);
    insertarPorCupo(m4,&a15);
    insertarPorCupo(m5,&a15);
    //Inscripto a16:
    insertarPorCupo(m4,&a16);
    insertarPorCupo(m3,&a16);

    printf("Bienvenido al sistema Siu Guarani\n\n");
    char cont[10];
    int opcion;

    continuar(); //Funcion para continuar(Estetica)

    do{
        printf("Se encuentra en la carrera: Licenciatura en sistemas\n\n");
        printf("Que desea hacer?\n");
        printf("1 -> Ver las materias\n");
        printf("2 -> Salir del sistema...\n");
        printf("OPCION:");
        scanf("%d",&opcion);
        system("cls");

        int op;
        switch(opcion){
            case 1:
            do{
                mostrarListaGenerica(materias,mostrarMateria); //Muestro las materias y ofrezco opciones a ejecutar
                printf("\nQue desea hacer?\n");
                printf("1 -> Ver los alumnos de cada materia\n");
                printf("2 -> Volver al menu principal\n");
                printf("OPCION:");
                scanf("%d",&op);
                borrar(op,2); //Si la opcion es distinta a 2, no hago system("cls") para que
                //Se sigan viendo los codigos de las materias

                switch(op){
                    case 1: verYModificarAlumnos(materias); //Muestro los alumnos y despues doy la opcion de eliminar
                        break;
                    case 2:
                        break;
                    default: printf("Error! La opcion que intentas ingresar no existe...");
                        break;
                }
                volver(op,2,cont); //Funcion para volver (Estetica)
            }while(op != 2);
                break;
            case 2:
                break;
            default: printf("Error! La opcion que intentas ingresar no existe...");
                break;
        }
        volver(opcion,2,cont);
    }while(opcion != 2);

    return 0;
}
