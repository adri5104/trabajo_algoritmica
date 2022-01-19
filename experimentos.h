/* Este es el archivo de encabezamiento del fichero experimentos.c*/

/* Prototipos de las funciones */

/*CELIA IBANEZ*/
/*v.2 29/04/2021 13:23*/
	
/*Tipos tiponum, tipo_tiempo, tipo_comp y tipo_llamada definidos en tipos.h */	
#include "tipos.h"
 

	/*FUNCIONES DE LOS EXPERIMENTOS*/
	
	/*Funcion de tipo void que recibe por parametro un valor int que 
	indica si se quiere realizar el calculo de forma recursiva o iterativa (0 para iterativa, 1 para recursiva)
	y dos variables tiponum (definidas en el fichero tipos.h) que definen el intervalo en el que se desean
	hacer los calculos. Esta funcion imprime por pantalla el tiempo total que se ha tardado en calcular todos 
	los numeros primos del intervalo elegido*/
	
	void experimento_tiempo(int, tiponum, tiponum);
	
	
	/*Funcion de tipo void que recibe por parametro un valor int que 
	indica si se quiere realizar el calculo de forma recursiva o iterativa (0 para iterativa, 1 para recursiva)
	y dos variables tiponum (definidas en el fichero tipos.h) que definen el intervalo en el que se desean
	hacer los calculos. Esta funcion imprime por pantalla el numero de comparaciones que se han realizado para 
	calcular todos los numeros primos del intervalo elegido*/

	void experimento_comparaciones(int, tiponum, tiponum);
	
	
	

	
	

	/*Funcion de tipo void que recibe por parametro dos variables tiponum (definidas en el fichero tipos.h)
	que definen el intervalo en el que se desean hacer los calculos. 
	Esta funcion imprime por pantalla el numero de veces que se ha llamado a la funcion esprimo_recursiva*/

	void experimento_llamada(int, tiponum, tiponum);
