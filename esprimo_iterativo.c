/* esprimo_iterativo.c */

/* Por ADRIAN RIEKER GONZALEZ */
/* V2 Actualizada 29/04/2021 17:31.Se ha borrado la _tiempo por que no aportaba nada*/


/* Este fichero contiene el código en C de la función esprimo() y todas sus variantes implementada 
de forma iterativa.
La función esprimo() devuelve el numero 1 si el número dado como parametro es primo y 0 
en el caso contrario */

/*El fichero de encabezamiento asociado a este fichero es esprimo_iterativo.h*/
/*Tipos tiponum, tipo_tiempo, tipo_comp y tipo_llamada definidos en tipos.h */

#include "esprimo_iterativo.h"
#include "tipos.h"

#include<stdio.h>
#include<time.h>
#include <sys/time.h>


int esprimo_iterativo(tiponum x){
			
		
	tiponum i; /*Contador con el mismo tipo que la variable que se quiere saber si es primo o no.*/
	
		/* Si el numero es 1 o ,2 es primo. */
	if(x<=2) return 1;
	
		/* Se recorren los posibles divisores de x */
	for(i =x-1; i>1; i--){
		
		/* Si hay algun divisor distinto de 1 el numero no es primo */
		if(!(x%i)){ 
		
		
	return 0;}
		}
		
		
		/* Si se ha llegado aqui es que no se ha encontrado ningun divisor 
		distinto de 1 o si mismo, por lo que es primo */
		return 1;
	}
	
	
	
	

	
int esprimo_iterativo_comparaciones(tiponum x, tipo_comp* comparaciones){

		
		/* Definicion de variables */
		
		tiponum i; /*Contador con el mismo tipo que la variable que se quiere saber si es
					primo o no.*/
		*comparaciones = 0; /*Contador que almacena el numero de veces que se 
								comprueba si un numero es divisor.*/
		
		/* Si el numero es 1 o ,2 es primo. */
		if(x<=2){ 
			*comparaciones = 1;
			return 1;}
	
		/* Se recorren los posibles divisores de x */
		for(i =x-1; i>1; i--){
		
		/* Si hay algun divisor distinto de 1 el numero no es primo.
		Tambien se incrementa la variable de las comparaciones*/
		if((*comparaciones)++,!(x%i)){
			return 0;
	
		
			}		
		}
	
		return 1;
	}	