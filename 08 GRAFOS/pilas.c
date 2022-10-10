#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void construir_pila(Pila *tad){
	construir_lista_elemento_pila(&tad->contenido);
}

void destruir_pila(Pila *tad){
	destruir_lista_elemento_pila(&tad->contenido);
}

int es_pila_vacia(Pila tad){
	return es_lista_de_elemento_pila_vacia(tad.contenido);
}

void apilar(Pila *tad, ElementoPila elemento){
	insertar_elemento_pila_al_inicio(&tad->contenido, elemento);
}

ElementoPila desapilar(Pila *tad){	
    if (es_pila_vacia(*tad)){
    	printf("La pila está vacía, por lo tanto no se puede desapilar.\n");
    	exit(41);
    }
    ElementoPila elemento=cima(*tad);
    elimina_cabeza_elemento_pila(&tad->contenido);
    return elemento;
}

ElementoPila cima(Pila tad){
	if (es_pila_vacia(tad)){
    	printf("La pila está vacía, por lo tanto no posee cima.\n");
    	exit(42);
    }
    return retorna_cabeza_elemento_pila(tad.contenido);
}