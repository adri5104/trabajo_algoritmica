/* main_submenus.h */

/* Por ADRIAN RIEKER GONZALEZ */

/*Version v2 actualizada 30/04/2021 15:18*/

/*Esto es el fichero de encabezamiendo del fichero main_submenus.c */
/*Este fichero contiene los prototipos de las funciones escritas en main_submenus.c, que son
los submenus del menu del programa principal contenido en main.c */



/* --- Prototipos de funciones */

	/* Se imprime por pantalla informacion sobre como funciona el programa */
	void submenu_info();
	
	/* Submenu para seleccionar un experimento */
	void submenu_experimentos(int, tiponum, tiponum);
	
	/* Submenu (funcion) para pedir por pantalla extremos del intervalo [a,b]
	y guardarlos en variables dadas por direccion*/
	void submenu_introducir_intervalo(tiponum*, tiponum*);
	
	