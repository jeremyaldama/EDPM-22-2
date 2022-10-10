#include <stdio.h>
#include <stdlib.h>
#include "lep.h"

void construir_lista_elemento_pila(ListaElementoPila *tad){
    tad->cabeza=NULL;
    tad->longitud=0;
}

int es_lista_de_elemento_pila_vacia(ListaElementoPila tad){
    return tad.cabeza==NULL;
}

NodoListaElementoPila *crear_nuevo_nodo_elemento_pila(ElementoPila elemento, NodoListaElementoPila *sig){
    NodoListaElementoPila* nuevo_nodo = (NodoListaElementoPila*)malloc(sizeof(NodoListaElementoPila));
    if (nuevo_nodo==NULL){
        printf("Error al crear un nuevo nodo en la lista de elementos para la pila. No ha sido posible asignar memoria dinámica.\n");
        exit(31);
    }
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->sig=sig;
    return nuevo_nodo;
}

void insertar_elemento_pila_al_inicio(ListaElementoPila *tad, ElementoPila elemento){
    NodoListaElementoPila *nuevo_nodo=crear_nuevo_nodo_elemento_pila(elemento, tad->cabeza);
    tad->cabeza=nuevo_nodo;
    tad->longitud++;
}

ElementoPila retorna_cabeza_elemento_pila(ListaElementoPila tad){
    if (es_lista_de_elemento_pila_vacia(tad)){
        printf("No existe la cabeza por que la lista de elementos pila está vacía.\n");
        exit(32);
    }
    return tad.cabeza->elemento;
}

void elimina_cabeza_elemento_pila(ListaElementoPila *tad){
    if (es_lista_de_elemento_pila_vacia(*tad)){
        printf("No se puede eliminar la cabeza pues la lista de elementos de la pila está vacía.\n");
        exit(33);
    }
    NodoListaElementoPila *nodo_a_eliminar=tad->cabeza;    
    tad->cabeza=tad->cabeza->sig;
    free(nodo_a_eliminar); 
    tad->longitud--;          
}

void destruir_lista_elemento_pila(ListaElementoPila *tad){
    NodoListaElementoPila* recorrido = tad->cabeza;
    while(recorrido != NULL){
        NodoListaElementoPila *nodo_a_eliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodo_a_eliminar);
    }
    tad->cabeza=NULL;
    tad->longitud=0;
}
