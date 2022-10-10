#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

void construirCola(Cola *tad){
    construirLista(&tad->contenido);
}

void destruirCola(Cola *tad){
    destruirLista(&tad->contenido);	
}

int esColaVacia(Cola tad){
    return esListaVacia(tad.contenido);
}

void encolar(Cola *tad, ElementoCola elemento){
    insertarAlFinal(&tad->contenido, elemento);
}

ElementoCola desencolar(Cola *tad){	
    if (esColaVacia(*tad)){
        printf("La cola está vacía, no se puede desencolar en ella.\n");
        exit(11);
    }
    ElementoCola elemento = retornaCabeza(tad->contenido);
    eliminaCabeza(&tad->contenido);	
    return elemento;
}

void imprimir(Cola tad){
    if (esColaVacia(tad)) printf("La cola esta vacia\n");
    else{
        Lista lista = tad.contenido;
        imprime(lista);
    }
}