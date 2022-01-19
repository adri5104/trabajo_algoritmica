/* esprimo_recursivo.c */

/* Por ADRIAN RIEKER GONZALEZ */

/* V2 Actualizada 29/04/2021 17:31.Se ha borrado la _tiempo por que no aportaba nada*/

/* Este fichero contiene el código en C de la función esprimo() y todas sus variantes implementada 
de forma recursiva.
La función esprimo() devuelve el numero 1 si el número dado como parametro es primo y 0 
en el caso contrario */

/*El fichero de encabezamiento asociado a este fichero es esprimo_iterativo.h*/
/*Tipos tiponum, tipo_tiempo, tipo_comp y tipo_llamada definidos en tipos.h */

#include "esprimo_recursivo.h"
#include "tipos.h"

#include<stdio.h>
#include <time.h>
#include <sys/time.h>

/*NOTA: en todas las variantes de la función se ha usado la variable estatica
temp. Antes de cada return esta variable se tiene que poner a 0 ya que al ser 
una variable estatica no se destruira hasta salir del programa. */





	int esprimo_recursivo(tiponum x){
		
		static int temp = 0; /* Variable estatica en la que se almacenara el valor original de x*/
	
		/* Si x = 1, se considera primo */
		if( x == 1 ) {
			temp = 0;
			return 1;
		}
		
		/* El siguiente if solo se ejecuta la primera vez que se llama a la funcion y 
		almacena el valor original de x en temp. Ademas se decrementa x ya que sera la variable 
		que recorra los posibles divisores distintos de x y no tendria sentido compararlos 
		ya que un numero siempre es divisor de si mismo*/
  
		if( !temp ) {
			temp = x;
			x--;
		}
	
		/* 'x' hace la funcion de contador descendente y temp almecena su valor original.
		La variable x va recorriendo los posibles divisores de temp distintos de 0 que no sean 1. Si 
		lo encuentra, la variable original x no es un numero primo y se devuelve el valor 0*/
		if( !( temp % x ) ){ 
			temp = 0;
			return 0;
		}	
		
		/* Se decrementa x y a continuacion se vuelve a llamar a la funcion. 
		Esto se ejecutara hasta que x =1 o se encuentro un divisor 
		distinto de 1 */
		
		return esprimo_recursivo( -- x );
		
	}


	int esprimo_recursivo_comparaciones(tiponum x,	tipo_comp * comparaciones){
		
		static int temp = 0; /* Variable estatica en la que se almacenara el valor original de x*/
		
		/* Si x = 1, se considera primo */
		if( x == 1 ) {
			temp = 0;
			return 1;
		}
		
		/* El siguiente if solo se ejecuta la primera vez que se llama a la funcion y 
		almacena el valor original de x en temp.
		Ademas se decrementa x ya que sera la variable que recorra los posibles divisores
		distintos de x y no tendria sentido compararlos ya que un numero siempre es divisor 
		de si mismo*/
  
		if( !temp ) {
			*comparaciones = 1; /* inicializamos el contador de comparaciones a 0; */
			temp = x;
			x--;
		}
	
		/* 'x' hace la funcion de contador descendente y temp almecena su valor original.
		La variable x va recorriendo los posibles divisores de temp distintos de 0 que no sean 1. Si 
		lo encuentra, la variable original x es un numero primo y se devuelve el valor 1 */
		/* Se incrementa el contador de comparaciones (temp % x) */
		
		(*comparaciones)++;
		if( !( temp % x ) ) {
			temp = 0;
			return 0;
		}
		
		/* Se decrementa x y a continuacion se vuelve a llamar a la funcion.
		Esto se ejecutara hasta que x =1 o se encuentro un divisor 
		distinto de 1 */
		
	
		return esprimo_recursivo_comparaciones( -- x , comparaciones);
		
	}


	int esprimo_recursivo_llamadas(tiponum x,	tipo_llamada * llamadas){
		
		static int temp = 0; /* Variable estatica en la que se almacenara el valor original de x*/
		
		
		
		/* Si x = 1, se considera primo */
		if( x == 1 ) {
			
			temp = 0;
			return 1;
		}
 
		/* El siguiente if solo se ejecuta la primera vez que se llama a la funcion y 
		almacena el valor original de x en temp.
		Ademas se decrementa x ya que sera la variable que recorra los posibles divisores
		distintos de x y no tendria sentido compararlos ya que un numero siempre es divisor 
		de si mismo*/
  
		if( !temp ) {
			*llamadas = 1; /* inicializamos el contador de llamadas a 0; */
			temp = x;
			--x;
		}
	
		/* 'x' hace la funcion de contador descendente y temp almecena su valor original.
		La variable x va recorriendo los posibles divisores de temp distintos de 0 que no sean 1. 
		Si lo encuentra, la variable original x es un numero primo y se devuelve el valor 1 */
		if( !( temp % x ) ) {
			
			temp = 0;
			return 0;
		}
		
		/* Se decrementa x y a continuacion se vuelve a llamar a la funcion.
		Esto se ejecutara hasta que x =1 o se encuentro un divisor 
		distinto de 1. Antes se incrementa el contador de llamadas. */
		(*llamadas)++;
		return esprimo_recursivo_llamadas( --x , llamadas);
	}
	