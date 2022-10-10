#include <stdio.h>
#include <stdlib.h>
#include "lar.h"

void construir_lista_arista(ListaArista *tad){
    tad->cabeza=NULL;
    tad->longitud=0;
}

void destruir_lista_arista(ListaArista *tad){    
    NodoListaArista* recorrido = tad->cabeza;
    while(recorrido != NULL){
        NodoListaArista *nodo_a_eliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodo_a_eliminar);
    }
    tad->cabeza=NULL;
    tad->longitud=0;
}

int longitud_lista_arista(ListaArista tad){
     return tad.longitud;
 }

int se_encuentra_arista_en_lista_arista(ListaArista tad, ElementoListaArista llave){
    NodoListaArista *recorrido=tad.cabeza;
    while(recorrido!=NULL && recorrido->elemento!=llave){        
        recorrido=recorrido->sig;
    }
    return recorrido!=NULL;    
}

NodoListaArista *crear_nuevo_nodo_arista(ElementoListaArista elemento, NodoListaArista *sig){
    NodoListaArista *nuevo_nodo = (NodoListaArista*)malloc(sizeof(NodoListaArista));
    if (nuevo_nodo==NULL){
        printf("Error al crear nodo para almacenar la arista. No ha sido posible asignar memoria dinámica.\n");
        exit(1);
    }
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->sig=sig;
    return nuevo_nodo;
}

NodoListaArista *obtener_ultima_arista(ListaArista tad){
    NodoListaArista* ultimo=NULL;
    NodoListaArista* recorrido = tad.cabeza;
    while(recorrido != NULL){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    return ultimo;
}

void insertar_arista_al_final(ListaArista *tad, Vertice vertice){
    NodoListaArista *nuevo_nodo = crear_nuevo_nodo_arista(vertice, NULL);
    NodoListaArista *ultimo_nodo = obtener_ultima_arista(*tad);    
    if (ultimo_nodo==NULL)
        tad->cabeza=nuevo_nodo;
    else    
        ultimo_nodo->sig=nuevo_nodo;
    tad->longitud++; 
}

void eliminar_arista_en_lista(ListaArista *tad, Vertice vertice){
    NodoListaArista *ultimo=NULL;
    NodoListaArista *recorrido = tad->cabeza;
    while(recorrido!=NULL && recorrido->elemento!=vertice){
        ultimo=recorrido;        
        recorrido=recorrido->sig;
    }
    if (recorrido!=NULL){
        if (ultimo==NULL)
            tad->cabeza=recorrido->sig;
        else    
            ultimo->sig=recorrido->sig;        
        free(recorrido);
        tad->longitud--;
    }
}

void insertar_vertices_adyacentes(ListaEntero *lista_adyacentes, ListaArista lista_arista){
    NodoListaArista *recorrido=lista_arista.cabeza;
    while(recorrido != NULL){
        insertar_entero_al_final(lista_adyacentes, recorrido->elemento);
        recorrido=recorrido->sig;
    }
}