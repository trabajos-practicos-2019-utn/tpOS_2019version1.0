#include <stdio.h>
#include <stdlib.h>
#include "FUNC.h"

void msj(){
    printf("hola soy avion");

}

void abrirArchivoAviones(ST_AVION avion,FILE *pf){

    pf= fopen("tpAVIONES.dat", "r+");
    if(pf==NULL){
        printf("ERROR al abrir el archivo");
    }
    fclose(pf);
}
