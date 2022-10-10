#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

void construir_cola(Cola *tad){
	construir_lista_entero(&tad->contenido);
}

void destruir_cola(Cola *tad){
	destruir_lista_entero(&tad->contenido);
}

int es_cola_vacia(Cola tad){
	return es_lista_de_enteros_vacia(tad.contenido);
}

void pide_vez(Cola *tad, ElementoCola elemento){
	insertar_entero_al_final(&tad->contenido, elemento);
}

ElementoCola avanzar(Cola *tad){
	if (es_cola_vacia(*tad)){
    	printf("La cola está vacía, no es posible desencolar un elemento.\n");
		exit(51);	
    }
    ElementoCola elemento = retorna_cabeza_entero(tad->contenido);
	elimina_cabeza_entero(&tad->contenido);
    return elemento;
}

