#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct{
    char indentificadorAVION[20];
    char modeloAVION[20];
    long int cantCombustiAvion;


}ST_AVION;
/*--------------------------------------------*/
/*
    @Registracion: Permitira que un avion se
    registre en un aeropuerto.
*/

/*--------------------------------------------*/
/*
    @SolicitarPista: Permitira a un avion solicitar
    la pista para despegar o aterrizar en caso de que el
    avion se encuentre en vuelo
*/

/*--------------------------------------------*/
/*
    @Despegar: permitira al avion que posea el uso de la
    pista realizar el dspegue y pasar a estar en vuelo
*/

/*--------------------------------------------*/
/*
    @Aterrizar: permitira a un avion, previa solicitud de la pista,
    aterrizar en el aeropuerto.
*/

/*--------------------------------------------*/
/*
    @Estado: Esta accion permitira ver el estado en el que
    se encuentra, el combustible restante.
*/

void msj();

#endif // FUNC_H_INCLUDED
