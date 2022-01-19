/* main_submenus.c */

/* Por ADRIAN RIEKER GONZALEZ */

/* V2 Actualizada 29/04/2021 17:31.Se ha borrado el experimento de tiempos parciales 
por que no aportaba nada y fallaba mucho*/

/* Este fichero contiene el codigo en c de los submenus usados en el programa 
principal contenido en main.c. Estos submenus (funcione) estan explicados en
main_submenus.h */

/* El fichero de encabezamiento asociado a este fichero es main.submenus.h */

#include<stdio.h>

/*Tipos tiponum, tipo_tiempo, tipo_comp y tipo_llamada definidos en tipos.h */
#include "tipos.h"

/*Funciones de experimentos definidas en experimentos.h*/
#include "experimentos.h"


/* --- Funciones --- */

	void submenu_info(){
		printf("La opcion introduducir intervalo sirve para seleccionar los extremos del intervalo\n\nLa ");
		printf("funcion esprimo iterativo/recursiva sirve para indicar si se desea calcular los numeros primos de manera recursiva ");
		printf("o iterativa\n\nEn el submenu de los experimentos pueden encontrarse 4 opciones: \n  1. Calcular tiempo total: ");
		printf("imprime el tiempo total que ha tardado el algoritmo\n  2.- Imprimir tiempo parcial: Imprime la suma de los tiempos que han tardado las funciones esprimo AL FINAL NO SE HA USADO.");
		printf("\n  3.-  mostrar numero de comparaciones: Muestra el numero de veces que se ejecuta una division con una");
		printf("\nposterior comparacion\n  4.- Mostrar numero de llamadas: Se muestra el numero de veces que se llama a la funcion esprimo\n\n\n");
	}
	
	
	/* Submenu de seleccion de experimento */
	void submenu_experimentos(int modo, tiponum a, tiponum b){
		
		/*Declaracion de variables */
		char seleccion_experimento; /*Variable de seleccion de experimento*/
		
		
		/*Submenu*/
		printf("  |  Que quieres hacer?  |  \n _________________________ \n\n  A.- Mostrar tiempo total transcurrido\n  ");
		printf("B.- Mostrar numero de comparaciones\n  C.- Mostrar numero de llamadas\n  D.- Atras\n _________________________ \n\n");
		/*Se pide por teclado que el usuario introduzca su seleccion */
		scanf(" %c", &seleccion_experimento);
		
		/*Las distintas opciones en funcion de seleccion_experimento */
		switch(seleccion_experimento){
			
			
			/* Los case se repiten para que sea válida la introduccion sea mayuscula o minuscula */
			case 'a':
			case 'A':
				printf("\nHas seleccionado: Mostrar tiempo total transcurrido\n\n");
				experimento_tiempo(modo,a,b);
				break;
			case 'b':
			case 'B':
				printf("\nHas seleccionado: Mostrar numero de comparaciones\n\n");
				experimento_comparaciones(modo,a,b);
				break;
			case 'c':
			case 'C':
				printf("\nHas seleccionado: Mostrar numero de llamadas\n\n");
				experimento_llamada(modo,a ,b );
				break;
			case 'd':
			case 'D':
				break;
			
			
			/*Impresion de un error por pantalla en caso de que usuario introduzca 
			opcion no valida */
			default: 
				printf("ERROR: Opcion no valida\n\n");
				break;
				
				
		}
	}
	
	/* Funcion que pide por teclado el intervalo [a,b] */
	void submenu_introducir_intervalo(tiponum*x, tiponum*y){
		
		/* Do while para asegurar que se introduzca a y b tal que a > b */
		do{
			printf("  |  Introducir dos enteros [a,b]  |  \n\n");
			printf("a = \n");
			scanf("%u", x);
			printf("\nb = \n");
			scanf("%u", y);
			printf("\n Has introducido [ %u , %u ] \n\n",*x,*y);
		}while(*x > (*y));
	}