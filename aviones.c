#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "aviones.h"

/********************************************!
*@fn  strtoi
combierte una cifra entera en un char
*@param int N
*@return una variable char
********************************************/

   char strtoi (int N){
        char salida;
        salida = N + 48;
        return salida;
    }

/********************************************!
*@fn  * enteroACadena
combierte un nuemero en una cadena
*@param int valor
*@param puntero char cadena
*@return una cadena
********************************************/
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

