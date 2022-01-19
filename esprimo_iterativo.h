/* esprimo_iterativo.h */

/* Por ADRIAN RIEKER GONZALEZ */
/* V2 Actualizada 29/04/2021 17:31.Se ha borrado la _tiempo por que no aportaba nada*/

/* Esto es el fichero de encabezamiento del fichero esprimo_iterativo.c */

/* Este fichero contiene los prototipos de las funciones esprimo_iterativo (y sus variantes), que estan 
explicadas a continuacion */

/*Compilacion condicional para que no se incluya mas de una vez */

#ifndef _ESPRIMO_ITERATIVO_
	
	#define _ESPRIMO_ITERATIVO_


/*Tipos tiponum, tipo_tiempo, tipo_comp y tipo_llamada definidos en tipos.h */
#include "tipos.h"


/* funcion esprimo iterativa sin parametros de mediciones */
int esprimo_iterativo(tiponum); 



/* funcion esprimo iterativa con parametro de comparaciones dado por direccion
 donde se guardara el numero de veces
que se realiza la comparacion !(algo%algo) = 0 */
int esprimo_iterativo_comparaciones(tiponum,	tipo_comp * );


	#endif