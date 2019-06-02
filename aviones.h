#ifndef AVIONES_H_INCLUDED
#define AVIONES_H_INCLUDED

/********************************************!
*@struct ST_AVION
********************************************/
typedef struct {
    int id;
    char modelo [20];
    int capMax;
    int cantCombustible;
    char estado;
}ST_AVION;


/********************************************!
*@fn strtoi
********************************************/
char strtoi (int N);


/********************************************!
*@fn * enteroACadena
********************************************/
char * enteroACadena (int valor, char * cadena);



#endif // AVIONES_H_INCLUDED
