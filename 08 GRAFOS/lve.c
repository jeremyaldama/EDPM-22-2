#include <stdio.h>
#include <stdlib.h>
#include "lve.h"

void construir_lista_vertice(ListaVertice *tad){
    tad->cabeza=NULL;
    tad->longitud=0;
}

void destruir_lista_vertice(ListaVertice *tad){    
    NodoListaVertice* recorrido = tad->cabeza;
    while(recorrido != NULL){
    	destruir_lista_arista(&recorrido->lista_arista);
        NodoListaVertice *nodo_a_eliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodo_a_eliminar);
    }
    tad->cabeza=NULL;
    tad->longitud=0;
}

int es_lista_vertice_vacia(ListaVertice tad){
	return tad.cabeza==NULL;
}

int longitud_lista_vertices(ListaVertice tad){
	return tad.longitud;
}

NodoListaVertice *crear_nuevo_nodo_vertice(ElementoListaVertice elemento, NodoListaVertice *sig){
    NodoListaVertice* nuevo_nodo = (NodoListaVertice*)malloc(sizeof(NodoListaVertice));
    if (nuevo_nodo==NULL){
        printf("Error al crear nodo para almacenar el vértice. No ha sido posible asignar memoria dinámica.\n");
        exit(11);
    }
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->sig=sig;
    construir_lista_arista(&nuevo_nodo->lista_arista);
    return nuevo_nodo;
}

NodoListaVertice *obtener_ultimo_vertice(ListaVertice tad){
    NodoListaVertice *ultimo=NULL;
    NodoListaVertice *recorrido = tad.cabeza;
    while(recorrido != NULL){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    return ultimo;
}

void insertar_vertice_al_final(ListaVertice *tad, Vertice vertice){	
    NodoListaVertice *nuevo_nodo = crear_nuevo_nodo_vertice(vertice, NULL);
    NodoListaVertice *ultimo_nodo = obtener_ultimo_vertice(*tad);    
    if (ultimo_nodo==NULL)
        tad->cabeza=nuevo_nodo;
    else    
        ultimo_nodo->sig=nuevo_nodo;
    tad->longitud++;
}

int se_encuentra_vertice_en_lista(ListaVertice tad, Vertice llave){
	NodoListaVertice* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento!=llave){        
        recorrido = recorrido->sig;
    }
    return recorrido != NULL;        
}

void eliminar_vertice_en_lista(ListaVertice *tad, Vertice vertice){
    NodoListaVertice *ultimo=NULL;
    NodoListaVertice *recorrido = tad->cabeza;
    while(recorrido!=NULL && recorrido->elemento!=vertice){
        ultimo=recorrido;        
        recorrido=recorrido->sig;
    }
    if (recorrido!=NULL){
        if (ultimo==NULL)
            tad->cabeza=recorrido->sig;
        else    
            ultimo->sig=recorrido->sig;
        destruir_lista_arista(&recorrido->lista_arista);
        free(recorrido);
        tad->longitud--;
    }
}

NodoListaVertice *obtener_nodo_vertice(ListaVertice tad, Vertice llave){
	NodoListaVertice* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento!=llave){        
        recorrido = recorrido->sig;
    }
    return recorrido;        
}

void insertar_en_lista_de_aristas(ListaVertice tad, Vertice vertice_origen, Vertice vertice_destino){
	NodoListaVertice *nodo_vertice_origen=obtener_nodo_vertice(tad, vertice_origen);
	if (nodo_vertice_origen==NULL){
		printf("Error al insertar la lista de arista. No se ha encontrado el vértice %d.\n", vertice_origen);
        exit(12);
	}
	if (!se_encuentra_arista_en_lista_arista(nodo_vertice_origen->lista_arista, vertice_destino))
		insertar_arista_al_final(&nodo_vertice_origen->lista_arista, vertice_destino);
}

int se_encuentra_arista_en_lista_vertices(ListaVertice tad, Vertice vertice_origen, Vertice vertice_destino){
	NodoListaVertice *nodo_vertice_origen=obtener_nodo_vertice(tad, vertice_origen);
	if (nodo_vertice_origen==NULL)
		return 0;
	return se_encuentra_arista_en_lista_arista(nodo_vertice_origen->lista_arista, vertice_destino);
}

void eliminar_de_lista_de_aristas(ListaVertice tad, Vertice vertice_origen, Vertice vertice_destino){
	NodoListaVertice *nodo_vertice_origen=obtener_nodo_vertice(tad, vertice_origen);
	if (nodo_vertice_origen!=NULL)
		eliminar_arista_en_lista(&nodo_vertice_origen->lista_arista, vertice_destino);
}

void obtener_vertices_adyacentes(ListaEntero *lista_adyacentes, ListaVertice lista_vertice, Vertice vertice){
    NodoListaVertice *nodo_vertice=obtener_nodo_vertice(lista_vertice, vertice);
    if (nodo_vertice!=NULL)
        insertar_vertices_adyacentes(lista_adyacentes, nodo_vertice->lista_arista);
}