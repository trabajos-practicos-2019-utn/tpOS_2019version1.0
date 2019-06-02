#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

/*******************************!
*@struct ST_AVION
********************************/
typedef struct {
    char id [9];
    char modelo [20];
    int capMax;
    int cantCombustible;
    char estado;
}ST_AVION;

/*******************************!
*@fn parsearTextoParametro
********************************/
void parsearTextoParametro (const char * argv1, char * IP, char* strPuerto, int * puerto, char * ID, char * modelo, int * cantMaxComb );

/*******************************!
*@fn crearAvion
********************************/
void crearAvion (ST_AVION * avion);

/*******************************!
*@fn mostrarEstadoAvion
********************************/
void mostrarEstadoAvion (ST_AVION *avion);

/*******************************!
*@fn * armarMensaje
********************************/
char * armarMensaje(int cliente, char * IP, char * puerto, ST_AVION * avion, int charOpcion);

/*******************************!
*@fn recibirMensaje
********************************/
int recibirMensaje (int cliente, char * IP, char * puerto, ST_AVION * avion, int opcion, char * buffer);

/*******************************!
*@fn strtoi
********************************/
char strtoi (int N);

#endif // AVION_H_INCLUDED
