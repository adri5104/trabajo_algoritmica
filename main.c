/* main.c */

/* Por ADRIAN RIEKER GONZALEZ */
/* V2 Actualizada 29/04/2021 17:34 */

/* Este fichero contiene el programa principal del trabajo y la interfaz que se muestra por consola.
Se pedira al usuario que introduzca dos numeros enteros a y b. Estos formaran el intervalo de numeros en el que 
se van a calcular los numeros primos. A continuacion se seleccionara que se desea que se muestre 
por pantalla(que esperimento)*/

/* Su archivo de encabezamiento correspondiente es main.h */

/*Tipos tiponum, tipo_tiempo, tipo_comp y tipo_llamada definidos en tipos.h */
#include "tipos.h"

#include <stdio.h>

#include "mostrar_primos.h"
#include "main_submenus.h"

int main(){
	
	/* --- Declaracion de variables --- */
		
		/*Variables de tipo tiponum que almacenaran el inicio y fin
		del intervalo*/
	tiponum a,  b; /*variables del tipo tiponum definido en tipos.h.*/
	
		/*Variables auxiliares de seleccion de menus*/
	char seleccion = 'x';  /*seleccion de submenu*/
	int bandera_intervalo = 0,  /*1 si se ha seleccionado, 0 en caso contrario*/
		bandera_modo = 3; /*Bandera para la seleccion recursivo (1) o iterativo (0). 3 si
		no se ha seleccionado */
		
	
	
	
	/* --- Cuadro de texto inicial */
	
		/* Solo se muestra cuando se ejecuta el programa */
	
	printf("\n\n[En este programa se podran calcular los numeros primos en un intervalo [a,b] y realizar distintos experimentos]\n\nPor:\n  Celia Ibanez Martin\n  Jorge Martinez de la Mata\n  Adrian Rieker Gonzalez\n\n\n");

	
	/* --- Menu principal --- */
	

	/* Do while para que se permanezca en el programa a no se que se pulse salir */
	do{
		
		/* Se imprime por pantalla el menu de opciones */
		printf("  | Que quieres hacer? | \n _________________________ \n\n  A.- Info\n  B.- Experimentos\n  C.- Mostrar primos\n  D.- ");
		printf("Introducir intervalo [a,b]\n  E.- Modo Iterativo/Recursivo\n  F.- Salir\n ________________________ \n\n ");
		
		/*Se pide por teclado que el usuario introduzca su seleccion */
		scanf(" %c",&seleccion);
		
		/*Las distintas opciones en funcion de seleccion_experimento */
		switch(seleccion){
			
			/* Los case se repiten para que sea valida la introduccion sea mayuscula o minuscula */
			case 'a':
			case 'A':
				printf("\nHas seleccionado: Info\n\n");
				submenu_info();
				break;
			case 'b':
			case 'B':
				printf("\nHas seleccionado: Experimentos\n\n");
				
				/*Se comprueba que previamente se haya introducido un intervalo [a,b] y se 
				haya seleccionado el modo de esprimo. 
				En caso de que alguna de las cosas falte se imprime por pantalla 
				el mensaje de error correspondiente*/
				if(bandera_intervalo && bandera_modo != 3){
						submenu_experimentos(bandera_modo,a,b);
						break;
				}
				else{ 
					if(!bandera_intervalo){
						printf("ERROR: No has introducido un intervalo [a,b]\n\n");
						break;
					}
					else{
						printf("ERROR: No has seleccionado modo iterativo/ recursivo\n\n");
						break;
					}
				}
			case 'c':
			case 'C':
				printf("\nHas seleccionado: Mostrar primos\n\n");
				
				/*Se comprueba que previamente se haya introducido un intervalo [a,b] y 
				se haya seleccionado el modo de esprimo. 
				En caso de que alguna de las cosas falte se imprime por pantalla 
				el mensaje de error correspondiente*/
				if(bandera_intervalo && bandera_modo != 3){
						mostrar_primos(bandera_modo,a,b);
						break;
				}
				else{ 
					if(!bandera_intervalo){
						printf("ERROR: No has introducido un intervalo [a,b]\n\n");
						break;
					}
					else{
						printf("ERROR: No has seleccionado modo iterativo/ recursivo\n\n");
						break;
					}
				}
			case 'd':	
			case 'D':
				printf("\nHas seleccionado: Introducir intervalo\n\n");
				submenu_introducir_intervalo(&a,&b);
				/* Se cambia bandera_intervalo a 1 para saber que ya se ha introducido 
				un intervalo */
				bandera_intervalo = 1;
				break;
			case 'e':
			case 'E':
				printf("\nHas seleccionado: Modo Iterativo/Recursivo\n\n");
				printf("  |  Quieres usar esprimo() recursivo o iterativo?  |  \n\n  1.- Recursivo\n  0.- Iterativo\n\n");
				scanf("%d",&bandera_modo);
				
				/* La bandera seguira en 3 en caso de que no se introduzca una opcion valida */
				if((bandera_modo != 1) && bandera_modo != 0){
					bandera_modo = 3; /* El valor 3 se ha asignado a un error. */
					break;
				}
				break;
			case 'f':
			case 'F': 
				break;
			default: 
				printf("ERROR: opcion no valida\n\n");
				break;
		}
	}while((seleccion != 'F') && (seleccion != 'f'));
	
	return 0;
}


