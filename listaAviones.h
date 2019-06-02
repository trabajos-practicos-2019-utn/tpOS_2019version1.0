#ifndef LISTAAVIONES_H_INCLUDED
#define LISTAAVIONES_H_INCLUDED

#include "aviones.h"


/********************************************!
*@struct ST_LISTAAVIONES
********************************************/
typedef struct listaAviones {
    ST_AVION avion;
    struct listaAviones * ste;
}ST_LISTAAVIONES;



/********************************************!
*@fn crearLista
********************************************/
void crearLista (ST_LISTAAVIONES**cabecera);


/********************************************!
*@fn insertarOrdenado
********************************************/
void insertarOrdenado (ST_LISTAAVIONES ** cabecera, ST_AVION avion);


/********************************************!
*@fn mostrarLista
********************************************/
void mostrarLista (ST_LISTAAVIONES**cabecera);


/********************************************!
*@fn ST_LISTAAVIONES * buscarIDEnLista
********************************************/
ST_LISTAAVIONES * buscarIDEnLista (int ID, ST_LISTAAVIONES ** cabecera);


/********************************************!
*@fn eliminarDeLista
********************************************/
void  eliminarDeLista (int ID, ST_LISTAAVIONES ** cabecera);


/********************************************!
*@fn recibirMensaje
*********************************************/
void recibirMensaje (ST_LISTAAVIONES ** lista, ST_AVION * avion, int cliente, char * buffer);

#endif // LISTAAVIONES_H_INCLUDED
