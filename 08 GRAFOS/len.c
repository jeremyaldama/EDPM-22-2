#include <stdio.h>
#include <stdlib.h>
#include "len.h"

void construir_lista_entero(ListaEntero *tad){
    tad->cabeza=NULL;
    tad->longitud=0;
}

int es_lista_de_enteros_vacia(ListaEntero tad){
    return tad.cabeza==NULL;
}

NodoListaEntero *crear_nuevo_nodo_entero(ElementoListaEntero elemento, NodoListaEntero* sig){
    NodoListaEntero* nuevo_nodo = (NodoListaEntero*)malloc(sizeof(NodoListaEntero));
    if (nuevo_nodo==NULL){
        printf("Error al crear un nuevo nodo en la lista. No ha sido posible asignar memoria dinámica.\n");
        exit(21);
    }
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->sig=sig;
    return nuevo_nodo;
}

void insertar_entero_al_inicio(ListaEntero *tad, ElementoListaEntero elemento){
    NodoListaEntero *nuevo_nodo=crear_nuevo_nodo_entero(elemento, tad->cabeza);
    tad->cabeza=nuevo_nodo;
    tad->longitud++;
}

void insertar_entero_al_final(ListaEntero *tad, ElementoListaEntero elemento){
    NodoListaEntero *nuevo_nodo = crear_nuevo_nodo_entero(elemento, NULL);
    NodoListaEntero *ultimo_nodo = obtener_ultimo_nodo_entero(*tad);    
    if (ultimo_nodo==NULL)
        tad->cabeza=nuevo_nodo;
    else    
        ultimo_nodo->sig=nuevo_nodo;
    tad->longitud++; 
}

NodoListaEntero *obtener_ultimo_nodo_entero(ListaEntero tad){
    NodoListaEntero* ultimo=NULL;
    NodoListaEntero* recorrido = tad.cabeza;
    while(recorrido != NULL){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    return ultimo;
}

int longitud_lista_enteros(ListaEntero tad){
    return tad.longitud;
}

void imprime_lista_enteros(ListaEntero tad){
    NodoListaEntero* recorrido = tad.cabeza;
    int esta_imprimiendo_la_cabeza=1;
    printf("[");
    while(recorrido != NULL){
        if (!esta_imprimiendo_la_cabeza)
            printf(", ");
        esta_imprimiendo_la_cabeza=0;
        printf("%d", recorrido->elemento);      
        recorrido = recorrido->sig;
    }
    printf("]\n");
}

int se_encuentra_entero(ListaEntero tad, ElementoListaEntero llave){
    NodoListaEntero* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento!=llave){        
        recorrido = recorrido->sig;
    }
    return recorrido!=NULL;        
}

ElementoListaEntero retorna_cabeza_entero(ListaEntero tad){
    if (es_lista_de_enteros_vacia(tad)){
        printf("No existe la cabeza por que la lista de enteros está vacía.\n");
        exit(22);
    }
    return tad.cabeza->elemento;
}

void elimina_cabeza_entero(ListaEntero *tad){
    if (es_lista_de_enteros_vacia(*tad)){
        printf("No se puede eliminar la cabeza pues la lista de enteros está vacía.\n");
        exit(23);
    }
    NodoListaEntero *nodo_a_eliminar=tad->cabeza;    
    tad->cabeza=tad->cabeza->sig;
    free(nodo_a_eliminar); 
    tad->longitud--;          
}

void elimina_nodo_entero(ListaEntero *tad, ElementoListaEntero elemento){
    NodoListaEntero *ultimo=NULL;
    NodoListaEntero *recorrido = tad->cabeza;
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

void destruir_lista_entero(ListaEntero *tad){    
    NodoListaEntero* recorrido = tad->cabeza;
    while(recorrido != NULL){
        NodoListaEntero *nodo_a_eliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodo_a_eliminar);
    }
    tad->cabeza=NULL;
    tad->longitud=0;
}
