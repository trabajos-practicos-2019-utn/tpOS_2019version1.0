#include "consola.h"
#include "avion.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define tamanioBufferMensaje 100

/*******************************!
*@fn abrirConsola
*@param c1 int cliente
*@param c2 puntero char IP
*@param c3 puntero char puerto
*@param @struct ST_AVION *avion
********************************/
void abrirConsola(int cliente, char * IP, char * puerto,  ST_AVION *avion){
    printf("\n Bienvenido al sistema de control del avion\n");
    printf ("\nEl ID del avion es %s", avion->id);
    printf ("\nEl modelo del avion es %s", avion->modelo);
    printf ("\nLa capacidad maxima de combustible del avion es %i", avion->capMax);
    printf ("\nEl estado del avion es %c", avion->estado);
    printf ("\nLa cantidad de combustible del avion es %i", avion->cantCombustible);
    printf("\n[1] - Registrar avion");
    printf("\n[2] - Solicitar pista");
    printf("\n[3] - Despegar");
    printf("\n[4] - Aterrizar");
    printf("\n[5] - Mostrar estado");
    printf("\n[6] - Salir\n");
    int N=0;
    scanf("%d",&N);
        //char letra = strtoi(N);
		//send(cliente, &letra, sizeof(letra), 0);
    switch (N){
        case 1:
        system("clear");
        char* msj1 = armarMensaje(cliente,IP,puerto, avion, 1);
        send(cliente, msj1, tamanioBufferMensaje, 0);

        abrirConsola(cliente, IP, puerto, avion);
        break;
        case 2:
        system("clear");
        char* msj2 = armarMensaje(cliente,IP,puerto, avion, 2);
        send(cliente, msj2, tamanioBufferMensaje, 0);

        abrirConsola(cliente, IP, puerto, avion);
        break;
        case 3:
        system("clear");
        char* msj3 = armarMensaje(cliente,IP,puerto, avion, 3);
        send(cliente, msj3, tamanioBufferMensaje, 0);

        abrirConsola(cliente, IP, puerto, avion);
        break;
        case 4:
        system("clear");
        char* msj4 = armarMensaje(cliente,IP,puerto, avion, 4);
        send(cliente, msj4, tamanioBufferMensaje, 0);

        abrirConsola(cliente, IP, puerto, avion);
        break;
        case 5:
        system("clear");
        mostrarEstadoAvion(avion);
        abrirConsola(cliente, IP, puerto, avion);
        break;
    }
}


/*
void abrirConsola(int cliente, ST_AVION *avion){
    printf("\n Bienvenido al sistema de control del avion\n");
    printf ("\nEl ID del avion es %s", avion->id);
    printf ("\nEl modelo del avion es %s", avion->modelo);
    printf ("\nLa capacidad maxima de combustible del avion es %i", avion->capMax);
    printf ("\nEl estado del avion es %c", avion->estado);
    printf ("\nLa cantidad de combustible del avion es %i", avion->cantCombustible);
    printf("\n[1] - Registrar avion");
    printf("\n[2] - Solicitar pista");
    printf("\n[3] - Despegar");
    printf("\n[4] - Aterrizar");
    printf("\n[5] - Mostrar estado");
    printf("\n[6] - Salir\n");
    int N=0;
    scanf("%d",&N);
    char letra = strtoi(N);
		send(cliente, &letra, sizeof(letra), 0);
    switch (N){
        case 1:
        system("clear");
        //registrarAvion(cliente, avion);
        system("clear");
        abrirConsola(cliente, avion);
        break;
        case 2:
        printf("Hola");
        abrirConsola(cliente, avion);
        break;
        case 3:
        printf("Hola");
        abrirConsola(cliente, avion);
        break;
        case 4:
        printf("Hola");
        abrirConsola(cliente, avion);
        break;
        case 5:
        system("clear");
        mostrarEstadoAvion(avion);
        abrirConsola(cliente, avion);
        break;
    }
} */

