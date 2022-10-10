#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

void construirLista(Lista *tad){
    tad->cabeza=NULL;
    tad->longitud=0;
}

int esListaVacia(Lista tad){
    return tad.cabeza==NULL;
}

NodoLista *crearNuevoNodo(ElementoLista elemento, NodoLista* sig){
    NodoLista* nuevoNodo = (NodoLista*)malloc(sizeof(NodoLista));
    if (nuevoNodo==NULL){
        printf("No ha sido posible asignar memoria dinámica.\n");
        exit(1);
    }
    nuevoNodo->elemento=elemento;
    nuevoNodo->sig=sig;
    return nuevoNodo;
}

void insertarAlInicio(Lista *tad, ElementoLista elemento){
    NodoLista *nuevoNodo = crearNuevoNodo(elemento, tad->cabeza);
    tad->cabeza=nuevoNodo;
    tad->longitud++;
}

int longitud(Lista tad){
    return tad.longitud;
}

void imprime(Lista tad){
    NodoLista* recorrido = tad.cabeza;
    int estaImprimiendoLaCabeza=1;
    printf("[");
    while(recorrido != NULL){
        if (!estaImprimiendoLaCabeza)
            printf(", ");
        estaImprimiendoLaCabeza=0;
        printf("%d", recorrido->elemento);        
        recorrido = recorrido->sig;
    }
    printf("]\n");
}

void insertarAlFinal(Lista *tad, ElementoLista elemento){
    NodoLista *nuevoNodo = crearNuevoNodo(elemento, NULL);
    NodoLista *ultimoNodo = obtenerUltimoNodo(*tad);    
    if (ultimoNodo==NULL)
        tad->cabeza=nuevoNodo;
    else    
        ultimoNodo->sig=nuevoNodo;
    tad->longitud++; 
}

NodoLista *obtenerUltimoNodo(Lista tad){
    NodoLista* ultimo=NULL;
    NodoLista* recorrido = tad.cabeza;
    while(recorrido != NULL){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    return ultimo;
}

void insertarEnOrden(Lista *tad, ElementoLista elemento){
    NodoLista *nuevoNodo = crearNuevoNodo(elemento, NULL);
    NodoLista *nodoAnterior = obtenerNodoAnterior(*tad, elemento);    
    if (nodoAnterior==NULL){
        nuevoNodo->sig=tad->cabeza;
        tad->cabeza=nuevoNodo;
    }else{    
        nuevoNodo->sig=nodoAnterior->sig;
        nodoAnterior->sig=nuevoNodo;
    }
    tad->longitud++;
}

NodoLista *obtenerNodoAnterior(Lista tad, ElementoLista elemento){
    NodoLista* anterior=NULL;
    NodoLista* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento<elemento){
        anterior = recorrido;        
        recorrido = recorrido->sig;
    }
    return anterior;
}

NodoLista* seEncuentra(Lista tad, ElementoLista llave){
    NodoLista* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento!=llave){        
        recorrido = recorrido->sig;
    }
    return recorrido;        
}

void destruirLista(Lista *tad){    
    NodoLista* recorrido = tad->cabeza;
    while(recorrido != NULL){
        NodoLista *nodoAEliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodoAEliminar);
    }
    tad->cabeza=NULL;
    tad->longitud=0;
}

ElementoLista retornaCabeza(Lista tad){
    if (esListaVacia(tad)){
        printf("No existe la cabeza por que la lista está vacía.\n");
        exit(4);
    }
    return tad.cabeza->elemento;
}

void eliminaCabeza(Lista *tad){
    if (esListaVacia(*tad)){
        printf("No se puede eliminar la cabeza pues la lista está vacía.\n");
        exit(2);
    }
    NodoLista *nodoAEliminar=tad->cabeza;    
    tad->cabeza=tad->cabeza->sig;
    free(nodoAEliminar); 
    tad->longitud--;          
}

void eliminaCola(Lista *tad){
    if (esListaVacia(*tad)){
        printf("No se puede eliminar la cola pues la lista está vacía.\n");
        exit(3);
    }
    NodoLista *ultimo=NULL, *penultimo=NULL;
    NodoLista *recorrido = tad->cabeza;
    while(recorrido != NULL){
        if (ultimo!=NULL)
            penultimo=ultimo;
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }    
    if (penultimo==NULL)
        tad->cabeza=NULL;            
    else
        penultimo->sig=NULL;
    free(ultimo);
    tad->longitud--;                  
}

void eliminaNodo(Lista *tad, ElementoLista elemento){
    NodoLista *ultimo=NULL;
    NodoLista *recorrido = tad->cabeza;
    while(recorrido != NULL && recorrido->elemento!=elemento){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    if (recorrido != NULL){
        if (ultimo==NULL)
            tad->cabeza=recorrido->sig;
        else    
            ultimo->sig=recorrido->sig;
        free(recorrido);
        tad->longitud--;
    }
}