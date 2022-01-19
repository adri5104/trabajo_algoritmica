/* esprimo_recursivo.h */

/* Por ADRIAN RIEKER GONZALEZ */

/* V2 Actualizada 29/04/2021 17:31.Se ha borrado la _tiempo por que no aportaba nada*/

/* Esto es el fichero de encabezamiento del fichero esprimo_recursivo.c */

/* Este fichero contiene los prototipos de las funciones esprimo_recursivo (y sus variantes), 
que estan explicadas a continuacion */

/*Compilacion condicional para que no se incluya mas de una vez */
#ifndef PATATA
	
	#define PATATA


/*Tipos tiponum, tipo_tiempo, tipo_comp y tipo_llamada definidos en tipos.h */
#include "tipos.h"


/* funcion esprimo recursiva sin parametros de mediciones */
int esprimo_recursivo(tiponum); 



/* funcion esprimo recursiva con parametro de comparaciones dado por direccion
 donde se guardara el numero de veces
que se realiza la comparacion !(algo%algo) = 0 */
int esprimo_recursivo_comparaciones(tiponum, tipo_comp* );


/* funcion esprimo recursiva con parametro de llamadas dado por direccion
 donde se guardara el numero de veces que la funcion se llama a si misma */
int esprimo_recursivo_llamadas(tiponum,	tipo_llamada * );


	#endif