#include <stdio.h>
#include <stdlib.h>
#include "lce.h"

void construir_lista(Lista *tad){
    tad->cabeza=NULL;
    tad->longitud=0;
}

int es_lista_vacia(Lista tad){
    return tad.cabeza==NULL;
}

Nodo *crear_nuevo_nodo(ElementoLista elemento, Nodo* sig){
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->sig=sig;
    return nuevo_nodo;
}

void insertar_al_inicio(Lista *tad, ElementoLista elemento){
    Nodo *nuevo_nodo = crear_nuevo_nodo(elemento, tad->cabeza);
    if (tad->cabeza==NULL){        
        nuevo_nodo->sig=nuevo_nodo;        
    }
    else{
        Nodo *ultimo=obtener_ultimo_nodo(*tad);
        ultimo->sig=nuevo_nodo;        
    }
    tad->cabeza=nuevo_nodo;
    tad->longitud++;
}

void insertar_en_orden(Lista *tad, ElementoLista elemento){
    Nodo *nuevo_nodo=crear_nuevo_nodo(elemento, NULL);
    Nodo *nodo_anterior=obtener_nodo_anterior(*tad, elemento);
    if (nodo_anterior==NULL){
        Nodo *ultimo_nodo=obtener_ultimo_nodo(*tad);
        nuevo_nodo->sig=tad->cabeza;        
        if (ultimo_nodo!=NULL)
            ultimo_nodo->sig=nuevo_nodo;
        else
            nuevo_nodo->sig=nuevo_nodo;
            tad->cabeza=nuevo_nodo;
    }else{
        nuevo_nodo->sig=nodo_anterior->sig;
        nodo_anterior->sig=nuevo_nodo;
    }
    tad->longitud++;
}

Nodo *obtener_nodo_anterior(Lista tad, ElementoLista elemento){//solo si está ordenada
    if (es_lista_vacia(tad))
        return NULL;
    Nodo *anterior=NULL;
    Nodo *recorrido=tad.cabeza;
    do{
        if (recorrido->elemento<elemento){
            anterior=recorrido;
            recorrido=recorrido->sig;
        }
    } while(recorrido!=tad.cabeza && recorrido->elemento<elemento);
    return anterior;
}

Nodo *obtener_ultimo_nodo(Lista tad){
    if (es_lista_vacia(tad))
        return NULL;
    Nodo *ultimo=NULL;
    Nodo *recorrido=tad.cabeza;
    do{
        ultimo=recorrido;
        recorrido=recorrido->sig;
    }while(recorrido!=tad.cabeza);
    return ultimo;
}

int longitud(Lista tad){
    return tad.longitud;
}

void imprime(Lista tad){
    Nodo* recorrido = tad.cabeza;
    int esta_imprimiendo_la_cabeza=1;
    printf("[");
    if (recorrido != NULL)
        do {
            if (!esta_imprimiendo_la_cabeza)
                printf(", ");
            esta_imprimiendo_la_cabeza=0;
            printf("%d", recorrido->elemento);        
            recorrido = recorrido->sig;
        } while(recorrido != tad.cabeza);
    printf("]\n");
}

void destruir_lista(Lista *tad){
    Nodo* recorrido = tad->cabeza;
    if (recorrido==NULL)
        return;
    do{
        Nodo* nodo_a_eliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodo_a_eliminar);
    } while(recorrido != tad->cabeza);
    tad->cabeza=NULL;
    tad->longitud=0;
}

void insertarAlFinal(Lista *pL, ElementoLista elemento){
    Nodo*pNuevoNodo, *pUltimo;
    pNuevoNodo = crear_nuevo_nodo(elemento, pL->cabeza);
    pUltimo = obtener_ultimo_nodo(*pL);
    
    if (pUltimo==NULL){
        pL->cabeza = pNuevoNodo;
        pNuevoNodo->sig = pNuevoNodo;
    }
    else pUltimo->sig = pNuevoNodo;
}

Nodo* obtenerNodo(Lista l, ElementoLista valor){
    Nodo *pNodo;
    if (!es_lista_vacia(l)){
        pNodo = l.cabeza;
        do{
            if (valor == pNodo->elemento) return pNodo;
            pNodo = pNodo->sig;
        }while (pNodo != l.cabeza);
    }
    return NULL;
}

void eliminarNodo(Lista*pL, ElementoLista valor){
    Nodo*pNodoEliminar, *pAnterior, *pUltimo;
    pNodoEliminar = obtenerNodo(*pL, valor);
    if (pNodoEliminar == NULL){
        printf("%d no esta en la lista\n", valor);
    }
    else{
        pAnterior = obtener_nodo_anterior(*pL, valor);
        if (pAnterior == NULL){
            pUltimo = obtener_ultimo_nodo(*pL);
            if (pNodoEliminar == pUltimo)
                pL->cabeza = NULL;
            else{
                pL->cabeza = pNodoEliminar->sig;
                pUltimo->sig = pL->cabeza;
            }
        }
        else{
            pAnterior->sig = pNodoEliminar->sig;
            printf("%d\n",pAnterior->elemento);
        }
        free(pNodoEliminar);
    }
}