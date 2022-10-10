#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

void construir_lista(Lista *tad){
    tad->cabeza=NULL;
    tad->longitud=0;
}

int es_lista_vacia(Lista tad){
    return tad.cabeza==NULL;
}

Nodo *crearNuevoNodo(ElementoLista elemento, Nodo* sig, Nodo* ant){
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->elemento=elemento;
    nuevo_nodo->sig=sig;
    nuevo_nodo->ant=ant;
    return nuevo_nodo;
}

void insertarAlInicio(Lista *tad, ElementoLista elemento){
    Nodo *nuevo_nodo=crearNuevoNodo(elemento, tad->cabeza, NULL);
    if (tad->cabeza != NULL)
        tad->cabeza->ant=nuevo_nodo;
    tad->cabeza=nuevo_nodo;
    tad->longitud++;
}

int longitud(Lista tad){
    return tad.longitud;
}

void imprime(Lista tad){
    Nodo* recorrido = tad.cabeza;
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

Nodo *obtener_ultimo_nodo(Lista tad){
    Nodo* ultimo=NULL;
    Nodo* recorrido = tad.cabeza;
    while(recorrido != NULL){
        ultimo = recorrido;        
        recorrido = recorrido->sig;
    }
    return ultimo;
}

void imprime_desde_el_final(Lista tad){
    Nodo* recorrido = obtener_ultimo_nodo(tad); //el recorrido inicia en la cola.
    int esta_imprimiendo_la_cola=1;
    printf("[");
    while(recorrido != NULL){
        if (!esta_imprimiendo_la_cola)
            printf(", ");
        esta_imprimiendo_la_cola=0;
        printf("%d", recorrido->elemento);        
        recorrido = recorrido->ant; //se va al predecesor
    }
    printf("]\n");
}

void destruir_lista(Lista *tad){
    Nodo* recorrido = tad->cabeza;
    while(recorrido != NULL){
        Nodo* nodo_a_eliminar=recorrido;        
        recorrido = recorrido->sig;
        free(nodo_a_eliminar);
    }
    tad->cabeza=NULL;
    tad->longitud=0;
}

Nodo* se_encuentra(Lista tad, ElementoLista llave){
    Nodo* recorrido = tad.cabeza;
    while(recorrido != NULL && recorrido->elemento!=llave){
        recorrido = recorrido->sig;
    }
    return recorrido;
}

void elimina_cabeza(Lista *tad){
    Nodo *nodo_a_eliminar=tad->cabeza;
    if (nodo_a_eliminar==NULL){
        printf("No se puede eliminar la cabeza dado que la lista está vacía.\n");
        exit(1);
    }
    tad->cabeza=tad->cabeza->sig;
    if (tad->cabeza!=NULL) //hago esta verificación por que luego de la eliminación, la lista puede estar vacía
        tad->cabeza->ant=NULL;
    free(nodo_a_eliminar);
    tad->longitud--;
}

void insertarAlFinal(Lista*tad, ElementoLista elemento){
    Nodo *pNuevoNodo, *pUltimo;
    pUltimo = obtener_ultimo_nodo(*tad);
    pNuevoNodo = crearNuevoNodo(elemento, NULL, pUltimo);
    
    if (!pUltimo) tad->cabeza = pNuevoNodo;
    else{
        pUltimo->sig = pNuevoNodo;
    }
}

Nodo *obtenerNodo(Lista tad, ElementoLista elemento){
    Nodo*pNodo;
    pNodo = tad.cabeza;
    while (pNodo!=NULL){
        if (elemento == pNodo->elemento) break;
        pNodo = pNodo->sig;
    }
    return pNodo;
}

void eliminarNodo(Lista*tad, ElementoLista elemento){
    Nodo*pNodoEliminar, *pAnterior, *pSig;
    pNodoEliminar = obtenerNodo(*tad, elemento);
    if (pNodoEliminar==NULL) printf("%d no esta en la lista\n", elemento);
    else{
        pAnterior = pNodoEliminar->ant;
        pSig = pNodoEliminar->sig;
        
        if (pAnterior==NULL) tad->cabeza = pSig;
        else    pAnterior->sig = pSig;
        if (pSig) pSig->ant = pAnterior;
        free(pNodoEliminar);
        printf("Nodo eliminado\n");
    }
}
