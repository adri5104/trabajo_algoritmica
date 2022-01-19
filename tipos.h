/* tipos.h */

/*Version v4 Actualizada el 29/04/2021 */

/* Fichero que incluye la definicion de los tipos usados en el resto del programa.
Esto se ha hecho de esta manera ya que son susceptibles de ser cambiados
para ver cuales funcionan mejor o peor y asi poderlos cambiar rapido */

/*Por Adrian Rieker Gonzalez */

/*COompilacion condicional para que no se incluya mas de una vez */
#ifndef _TIPOS_

	#define _TIPOS_



	/* Tipo para el numero que quiere saberse si es primo o no. Esp formato %u */
	typedef unsigned int tiponum;

	/* Tipo para las mediciones de tiempo. %U */
	typedef long unsigned int tipo_tiempo;

	/* Tipo para las mediciones de numero de comparaciones. %U */
	typedef long unsigned int tipo_comp;

	/* Tipo para las mediciones de numero de llamadas a funcion / %U*/
	typedef long unsigned  int tipo_llamada;



	#endif
