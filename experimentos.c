 /*experimentos.c*/
 
 /*CELIA IBANEZ*/
 
 /*v.4 29/04/2021 13:20*/
 /*v.5 29/04/2021 16.21*/

/* Este fichero contiene el código en C de las funciones experimento experimento_tiempo, experimento_tiempo_parcial, 
experimento_comparaciones para el calculo de forma recursiva e iterativa y experimento_llamada para el numero
de llamadas del alforitmo recursivo
Imprime por pantalla los resultados correspondientes de los experimentos*/

/*El fichero de encabezamiento asociado a este fichero es experimentos.h*/
/*Tipos tiponum, tipo_tiempo, tipo_comp y tipo_llamada definidos en tipos.h */

#include "experimentos.h"

#include "esprimo_iterativo.h"
#include "esprimo_recursivo.h"

#include <stdio.h>

#include <sys/time.h>
#include <time.h>
#include "tipos.h"



	
	/*Funcion experimento_tiempo mide el tiempo total que tarda el programa en hallar todos los numeros primos 
	del intervalo pedido */

	void experimento_tiempo(int iterativo_recursivo, tiponum a, tiponum b){
	
		tiponum i = 0; /* Variable de tipo tiponum que hara de contador */
	
		int cont_primos = 0; /* Variable de tipo long int que mide el numero de numeros 
							primos hallados*/
	
		/*Variables de tipo struct en las que se almacenan los tiempos inicial y final */
		struct timeval ini, fin; 
		
		tipo_tiempo segundos,microsegundos,transcurrido;
		
		/*Comprobamos que el orden en el que se han introducido los numeros es correcto y que no se trata 
		de un intervalo de un solo elemento*/
		if(a<b){
		
			/* ____ EMPIEZA A MEDIR TIEMPO ___ */
			
			/*Funcion definida en <sys/time.h> que almacena el valor del reloj del
			sistema en el struct de tiempo inicial*/
			gettimeofday(&ini, 0); 
			/* _______________________________ */	
		
		
			/* Si se pide de forma recursiva*/
			if(iterativo_recursivo){
				
				for(i=a;i<=b;i++){
					/*Llamada a la funcion esprimo_recursivo que devuelve 1 si el numero es primo 
					si lo es suma uno al contador */
					if(esprimo_recursivo(i)) 
						cont_primos++;
				}
			}
				
			/* Si se pide de forma iterativa*/
			else{
				
				for(i=a;i<=b;i++){
					/*Llamada a la funcion esprimo_iterativo que devuelve 1 si el numero es primo 
					si lo es suma uno al contador */
					if(esprimo_iterativo(i)) 
						cont_primos++;
				}
			}
		
			/* ____ TERMINA MEDIR TIEMPO ___ */	
		
			/*Funcion definida en <sys/time.h> que almacena el valor del reloj del
			sistema en el struct de tiempo inicial*/
			gettimeofday(&fin, 0);
			segundos = fin.tv_sec - ini.tv_sec;
			microsegundos = fin.tv_usec - ini.tv_usec;
			transcurrido = segundos*1000000 + microsegundos;
			printf("Tiempo transcurido = %lu microsegundos.\n", transcurrido);
			
		  /* _______________________________ */
			
			
			/*Imprime por pantalla el numero de primos*/
			printf("El numero de primos en el intervalo es %d: \n", cont_primos); 
		
		}
	
			
	}	

	/*Funcion experimento_comparaciones cuenta las comparaciones que se han realizado para 
	hallar los numeros primos del intervalo pedido */

	void experimento_comparaciones(int iterativo_recursivo, tiponum a, tiponum b){
				
		tiponum i = 0; /* Variable de tipo tiponum que hara de contador */
		
		/* Variable de tipo tipo_comp que almacena las comparaciones
		realizadas para saber si un numero es primo o no*/	
		tipo_comp comp = 0;
		
		/* Variable de tipo tipo_comp que almacena el numero total de comparaciones
		realizadas para calcular todos los numeros primos del intervalo		*/
		tipo_comp total=0;
		
		/*Delacaracion contador de numeros primos*/
		int cont_primos = 0;
		
		
		/*Comprobamos que el orden en el que se han introducido los numeros es correcto y que no se trata 
		de un intervalo de un solo elemento*/			
		if(a<b){
			
			/* Si se pide de forma recursiva*/
			
			if(iterativo_recursivo){
				
				for(i=a;i<=b;i++){
					
					/*Llamada a la funcion esprimo_iterativo_comparaciones que guarada el numero de comparaciones
					en la variable comp pasada por direccion y devuelve 1 si el numero es primo 
					si lo es suma uno al contador */
					if(esprimo_recursivo_comparaciones(i,&comp) ) 
						cont_primos++;
					
					total = total + comp; /* Suma el numero de comparaciones para calcular un 
					numero al total */
				}
				printf("El numero de comparaciones realizadas en el intervalo [%u , %u] es %lu\n",a,b,total);
			}
				
			/* Si se pide de forma iterativa*/
				
			else{
				
				for(i=a;i<=b;i++){
					
					/*Llamada a la funcion esprimo_iterativo_comparaciones que guarada el numero de comparaciones
					en la variable comp pasada por direccion y devuelve 1 si el numero es primo 
					si lo es suma uno al contador */
					if(esprimo_iterativo_comparaciones(i,&comp)) 
						cont_primos++;
					
					total = total + comp; /* Suma el numero de comparaciones para calcular un 
					numero al total*/
				}
				printf("El numero de comparaciones realizadas en el intervalo [%u , %u] es %lu\n",a,b,total);
			}
			
			
			/*Imprime por pantalla el numero de primos*/
			printf("El numero de primos en el intervalo es %d: \n", cont_primos); 
		
		}
		
				
	}	
	
	
	/*Funcion experimento_llamada imprime por pantalla el numero de veces que se ha llamado
	a la funcion esprimo_recursiva para hallar los numeros primos del intervalo pedido */

	void experimento_llamada(int iterativo_recursivo, tiponum a, tiponum b){
				
		tiponum i = 0; /*Variable de tipo tiponum que hara de contador */
		
		/* Variable de tipo tipo_comp que almacena el numero total de llamadas a la funcion recursiva
		realizadas para calcular todos los numeros primos del intervalo		*/
		tipo_comp total = 0;

		/* Variable de tipo tipo_comp que almacena el numero de llamadas a la funcion recursiva
		para cada numero	*/
		tipo_comp llam = 0; 
		
		/*Delacaracion contador de numeros primos*/
		int cont_primos = 0;
		
		
		/*Comprobamos que el orden en el que se han introducido los numeros es correcto y que no se trata 
		de un intervalo de un solo elemento*/			
		if(a<b){
			
			/* Si se pide de forma recursiva*/
			if(iterativo_recursivo){
			
				for(i=a;i<=b;i++){
					
					/*Llamada a la funcion esprimo_recursivo_llamada que guarada el numero de comparaciones
					en la variable llam pasada por direccion devuelve 1 si el numero es primo 
					si lo es suma uno al contador */
					if(esprimo_recursivo_llamadas(i,&llam) )
						cont_primos++;
				
				total = total + llam; /* Suma el numero de llamadas al total*/
				}
			}
			
			/* Si se pide de forma iterativa el numero de llamadas a la funcion 
			coincide con la dimension del intervalo*/
				
				/*Por como se ha definido la funcion que devuelve las llamadas falta 
				sumar el contador*/
				total = total + (b - a);
				
				/*Imprime por pantalla el numero de llamadas a la funcion recursiva*/
				printf("El numero de llamadas realizadas en el intervalo [%u , %u] es %lu\n",a,b,total);
				
				/*Imprime por pantalla el numero de primos en el intervalo*/
				printf("El numero de primos en el intervalo es %d: \n", cont_primos); 
			}
				
			
		
		}	