/* mostrar_primos.c */

/* Por ADRIAN RIEKER GONZALEZ */

/* Version v1 */

/* Este fichero contiene el codigo en c de la funcion
mostrar_primos.c */

#include "tipos.h"
#include "esprimo_iterativo.h"
#include "esprimo_recursivo.h"
#include <stdio.h>



void mostrar_primos(int n, tiponum a, tiponum b){
	
	/*Contador que va recorriendo los numeros del intervalo */
	tiponum i;
	
	/*n valdra 1 si el usuario ha seleccionado modo recursivo */
	if(n)
		for(i = a; i<=b ;i++){
			/* Esprimo devuelve el valor 1 si el numero dado como parametro
			es primo*/
			if(esprimo_recursivo(i)) printf("%d es primo\n\n", i);
	}
	/*Si el usuario ha seleccionado modo iterativo*/
	else {
	
	for(i = a; i<=b; i++){
			if(esprimo_iterativo(i)) printf("%d es primo\n\n", i);
	}}

printf("\n\n");

}