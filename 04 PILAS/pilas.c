#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void construirPila(Pila *tad){
    //El constructor de la lista espera como parámetro Lista *tad
    //El párametro de esta función es Pila *tad
    //	typedef struct {
    //		Lista contenido;    
    //	} Pila;
    //
    //como a partir de Pila *tad se llega a la lista
    //	tad->contenido es del tipo de dato Lista
    //la dirección de la lista sería (Lista *)
    //	&tad->contenido
    construirLista(&tad->contenido);
}

void destruirPila(Pila *tad){
    destruirLista(&tad->contenido);
}

int esPilaVacia(Pila tad){
    return esListaVacia(tad.contenido);
}

void apilar(Pila *tad, ElementoPila elemento){
	insertarAlInicio(&tad->contenido, elemento);
}

ElementoPila desapilar(Pila *tad){	
    if (esPilaVacia(*tad)){
    	printf("La pila está vacía, por lo tanto no se puede desapilar.\n");
    	exit(11);
    }
    ElementoPila elemento=cima(*tad);
    eliminaCabeza(&tad->contenido);
    return elemento;
}

ElementoPila cima(Pila tad){
    if (esPilaVacia(tad)){
    	printf("La pila está vacía, por lo tanto no posee cima.\n");
    	exit(12);
    }
    //return tad.contenido.cabeza->elemento; //NO SE DEBE HACER	
    return retornaCabeza(tad.contenido);
}

void mostrar(Pila tad){
    NodoLista *pNodo;
    if (esPilaVacia(tad))
        printf("La pila esta vacia\n");
    else{
        Lista tadL = tad.contenido;
        imprime(tadL);
    }
}