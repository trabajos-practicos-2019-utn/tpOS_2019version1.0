#include "avion.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define longComb 10
#define tamanioMaxLinea 50
#define tamanioBufferMensaje 100

/*******************************!
*@fn strtoi es una funcion que transaforma un valor entero en char
*@param un argunmento entero
*@return un char
********************************/
   char strtoi (int N){
        char salida;
        salida = N + 48;
        return salida;
    }

/*******************************!
*@fn enteroACadena es una funcion que transaforma un valor entero a cadena
*@param un argunmento entero y un puntero char
*@return la cadena
********************************/
    char * enteroACadena (int valor, char * cadena){
        int cont = 0;
        char cad [10];
        int aux = valor;
        char numero;
        while ((aux/10)!=0){
            cont ++;
            aux = aux/10;
        }
        cad[cont+1] = '\0';
        while ((valor/10)!=0){
            numero = (valor%10) + 48;
            cad[cont] = numero;
            valor = valor/10;
            cont--;
        }
        numero = (valor%10) + 48;
        cad[cont] = numero;
        strcpy(cadena,cad);
        return cadena;
    }
/*******************************!
*@fn armarMensaje
*@param c1 argunmento entero
*@param c2 dos puntero char
*@struct ST_AVION * avion
*@return bufferMensaje
********************************/
    char* armarMensaje(int cliente, char * IP, char * puerto, ST_AVION * avion, int charOpcion){
        char * bufferMensaje = (char*)malloc(tamanioBufferMensaje);
        memset(bufferMensaje, '\0', tamanioBufferMensaje);
        char charCliente = strtoi(cliente);
        strncat(bufferMensaje, &charCliente, 1);
        strcat(bufferMensaje, ";");
        strcat(bufferMensaje, IP);
        strcat(bufferMensaje, ";");
        strcat(bufferMensaje, puerto);
        strcat(bufferMensaje, ";");
        strcat(bufferMensaje, avion->id);
        strcat(bufferMensaje, ";");
        char opcion;
        opcion = strtoi(charOpcion);
        strncat(bufferMensaje, &opcion, 1);
        strcat(bufferMensaje, ";");
        if (charOpcion == 1){
            strcat(bufferMensaje, avion ->modelo);
            strcat(bufferMensaje, ";");
            strncat(bufferMensaje, &avion ->estado, 1);
            strcat(bufferMensaje, ";");
            char * cantMaxComb = (char*)malloc (longComb);
            strcpy(cantMaxComb, enteroACadena(avion->capMax, cantMaxComb));
            strcat(bufferMensaje, cantMaxComb);
            strcat(bufferMensaje, ";");
            char * cantComb = (char*)malloc (longComb);
            strcpy(cantComb, enteroACadena(avion->cantCombustible, cantComb));
            strcat(bufferMensaje, cantComb);
            strcat(bufferMensaje, ";");
            free(cantMaxComb);
            free(cantComb);
        }
        printf("Mensaje: %s", bufferMensaje);
        return bufferMensaje;

    }
/*******************************!
*@fn parsearLinea del tipo  void
*@file c1 puntero a un archivo
*@param c2 puntero del tipo char
********************************/
    void parsearLinea (FILE* pArchivo, char * variable){
        char lineaArchivo [tamanioMaxLinea];
        fgets(lineaArchivo, sizeof(lineaArchivo), pArchivo);
        strtok (lineaArchivo, ":");
        strcpy(variable, strtok (NULL, ";"));
    }
/*******************************!
*@fn parsearTextoParametro
*@param c1 puntero constante char
*@param c2 puntero char
*@param c3 puntero char
*@param c4 puntero int
*@param c5 puntero char
*@param c6 puntero char
*@param c7 puntero int
********************************/
void parsearTextoParametro (const char * argv1, char * IP, char* strPuerto, int * puerto, char * ID, char * modelo, int * cantMaxComb ){
    FILE * pArchivo = fopen(argv1, "r+");
    parsearLinea(pArchivo, IP);
    parsearLinea(pArchivo, strPuerto);
    (*puerto)=atoi(strPuerto);
    parsearLinea(pArchivo, ID);
    parsearLinea(pArchivo, modelo);
    char cantMaxCombust [8];
    parsearLinea(pArchivo, cantMaxCombust);
    *cantMaxComb = atoi(cantMaxCombust);
    fclose (pArchivo);
}
/*******************************!
*@fn ingresarEstado
*@struct ST_AVION * avion
********************************/
    void ingresarEstado (ST_AVION * avion){
        scanf("%c", &avion->estado);
        if ((avion->estado!='h')&&(avion->estado!='v')){
            printf("El estado ingresado no es vàlido");
            ingresarEstado(avion);
        }
    }
/*******************************!
*@fn crearAvion
*@struct ST_AVION * avion
********************************/
    void crearAvion (ST_AVION * avion){
        printf("\n Ingrese el estado actual en el que se encuentra el avion ('h' para 'En Hangar' y 'v' para 'En Vuelo') \n");
        ingresarEstado(avion);
        printf("Ingrese la cantidad de combustible del avion \n");
        scanf("%i", &avion->cantCombustible);
    }
/*******************************!
*@fn recibirMensaje
*@param c1 int cliente
*@param c2 puntero char
*@param c3 puntero char
*@struct ST_AVION * avion
*@param c4 int opcion
*@param c5 puntero char
*@return 1 si recibio el mensaje
*@return error
********************************/
    int recibirMensaje (int cliente, char * IP, char * puerto, ST_AVION * avion, int opcion, char * buffer){
                int bytesRecibidos = recv(cliente, buffer, sizeof(buffer), 0);
                if (bytesRecibidos <= 0) {
                    perror("El chabón se desconectó o bla.");
                    }
                     return 1;
                int intAux;
                char aux;
                strcpy (&aux, strtok(buffer,";"));
                intAux = atoi(aux);
                if (cliente != intAux){
                    perror("El cliente no coincide.");
                }
                if (strcmp(strtok (NULL,";"),IP)!=0){
                    perror("La direccion IP no coincide.");
                }
                if (strcmp(strtok (NULL,";"),puerto)!=0){
                    perror("El puerto no coincide.");
                }
                if (strcmp(strtok (NULL,";"),avion->id)!=0){
                    perror("El ID del avion no coincide.");
                }
                strcpy(&aux,strtok(NULL,";"));
                intAux = atoi(&aux);
                switch (intAux){
                    case 1:
                    strcmp(strtok(NULL,";"),"0");
                    printf("El avion se registro correctamente.\n");
                    break;
                    case 2:
                    break;
                    case 3:
                    break;
                    case 4:
                    break;
                }
        }

/*******************************!
*@fn mostrarEstadoAvion
*@struct ST_AVION * avion
********************************/
void mostrarEstadoAvion (ST_AVION *avion){
    printf("\n Estados: 'h' = 'En Hangar'; 'a' = 'Aterrizando'; 'e' = 'Espera/Aterrizar'; 'v' = 'En Vuelo'; 'd' = 'Despegando'; 'g' = 'Listo/Hangar'; 'l' = 'Listo/Despegar' \n");
    printf("\nEl ID del avion es %s\n", avion->id);
    printf("\nEl estado del avion es %c\n", avion->estado);
    printf("\nLa cantidad de combustible del avion es %i\n", avion->cantCombustible);

}

