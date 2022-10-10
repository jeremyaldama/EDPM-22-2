#include <stdio.h>
#include <stdlib.h>
#include "ab.h"
#include "pilas.h"
#include "colas.h"

void construirArbolBinario(ArbolBinario *tad){
    *tad=NULL;
}

NodoArbol *crearNuevoNodoArbol(ArbolBinario arbolIzq, ElementoArbol elemento,
                                ArbolBinario arbolDer){
    NodoArbol* nuevoNodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevoNodo->elemento=elemento;
    nuevoNodo->hijoIzq=arbolIzq;    
    nuevoNodo->hijoDer=arbolDer;
    return nuevoNodo;
}

void plantarArbolBinario(ArbolBinario *tad, ArbolBinario arbolIzq,
                         ElementoArbol elemento, ArbolBinario arbolDer){
    NodoArbol *nuevoNodo=crearNuevoNodoArbol(arbolIzq, elemento, arbolDer);
    *tad=nuevoNodo;
}

int esArbolVacio(ArbolBinario tad){
    return tad==NULL;
}

ElementoArbol raiz(ArbolBinario tad){
    if (esArbolVacio(tad)){
        printf("No se puede obtener la raíz de un árbol vacío.\n");
        exit(41);
    }
    return tad->elemento;
}

ArbolBinario hijoDer(ArbolBinario tad){
    if (esArbolVacio(tad)){
        printf("No se puede obtener el hijo derecho de un árbol vacío.\n");
        exit(42);
    }
    return tad->hijoDer;
}

ArbolBinario hijo_izq(ArbolBinario tad){
    if (esArbolVacio(tad)){
        printf("No se puede obtener el hijo izquierdo de un árbol vacío.\n");
        exit(43);
    }
    return tad->hijoIzq;
}

void imprimeRaiz(ArbolBinario tad){
    printf("%d", tad->elemento);
}

int maximo(int a, int b){
    return a>=b?a:b;
}

int altura(ArbolBinario tad){
    if (esArbolVacio(tad))
        return 0;
    else
        return 1 + maximo(altura(tad->hijoIzq), altura(tad->hijoDer));
}

int numeroNodos(ArbolBinario tad){
    if (esArbolVacio(tad))
        return 0;
    else
        return 1 + numeroNodos(tad->hijoIzq) + numeroNodos(tad->hijoDer);
}

int numeroHojas(ArbolBinario tad){
    if (esArbolVacio(tad))
        return 0;
    else if (esArbolVacio(tad->hijoIzq) && esArbolVacio(tad->hijoDer))
        return 1;
    else 
        return numeroHojas(tad->hijoIzq) + numeroHojas(tad->hijoDer);
}

ArbolBinario especular(ArbolBinario tad){
    ArbolBinario arbolEspecular;
    if (esArbolVacio(tad))
        construirArbolBinario(&arbolEspecular);
    else{
        ArbolBinario hijoIzq=especular(tad->hijoDer);
        ArbolBinario hijoDer=especular(tad->hijoIzq);
        plantarArbolBinario(&arbolEspecular, hijoIzq, tad->elemento, hijoDer);
    }
    return arbolEspecular;
}

ArbolBinario copiaArbolBinario(ArbolBinario tad){
    ArbolBinario arbolCopia;
    if (esArbolVacio(tad))
        construirArbolBinario(&arbolCopia);
    else{
        ArbolBinario hijoIzq=copiaArbolBinario(tad->hijoIzq);
        ArbolBinario hijoDer=copiaArbolBinario(tad->hijoDer);
        plantarArbolBinario(&arbolCopia, hijoIzq, tad->elemento, hijoDer);
    }
    return arbolCopia;
}

void destruirArbolBinario(ArbolBinario *tad){
    if (!esArbolVacio(*tad)){
        destruirArbolBinario(&(*tad)->hijoIzq);
        destruirArbolBinario(&(*tad)->hijoDer);
        free(*tad);
        *tad=NULL;
    }
}

int esEquilibrado(ArbolBinario tad){
    if (esArbolVacio(tad))
        return 1;
    else{
        int alturaHijoIzq=altura(tad->hijoIzq);
        int alturaHijoDer=altura(tad->hijoDer);
        int diferencia=abs(alturaHijoIzq-alturaHijoDer);
        return diferencia<=1 && esEquilibrado(tad->hijoIzq) && esEquilibrado
                                                               (tad->hijoDer);
    }        
}


int esHoja(ArbolBinario tad){
    if (esArbolVacio(tad))
        return 0;
    else
        return esArbolVacio(tad->hijoIzq) && esArbolVacio(tad->hijoDer);
}

void esZurdo(ArbolBinario tad, int *esZurdoArbol, int *numeroDescendientes){
    if (esArbolVacio(tad)){
        *esZurdoArbol=1;
        *numeroDescendientes=0;
    }
    else if (esHoja(tad)){
        *esZurdoArbol=1;
        *numeroDescendientes=1;
    }
    else{
        int esZurdoHijoIzq, esZurdoHijoDer, numeroDescendientesIzq, 
            numeroDescendientesDer;
        esZurdo(tad->hijoIzq, &esZurdoHijoIzq, &numeroDescendientesIzq);
        esZurdo(tad->hijoDer, &esZurdoHijoDer, &numeroDescendientesDer);
        *esZurdoArbol=esZurdoHijoIzq && esZurdoHijoDer && 
                      numeroDescendientesIzq>numeroDescendientesDer;
        *numeroDescendientes=1+numeroDescendientesIzq+numeroDescendientesDer;
    }
}

void preOrden(ArbolBinario tad){
    if (!esArbolVacio(tad)){
        printf("%d ", tad->elemento);
        preOrden(tad->hijoIzq);
        preOrden(tad->hijoDer);
    }
}

void enOrden(ArbolBinario tad){
    if (!esArbolVacio(tad)){
        enOrden(tad->hijoIzq);
        printf("%d ", tad->elemento);        
        enOrden(tad->hijoDer);
    }
}

void postOrden(ArbolBinario tad){
    if (!esArbolVacio(tad)){        
        postOrden(tad->hijoIzq);
        postOrden(tad->hijoDer);
        printf("%d ", tad->elemento);
    }
}

void preOrdenIterativo(ArbolBinario tad){
    Pila pila;
    construirPila(&pila); 
    if (!esArbolVacio(tad)){
        apilar(&pila, tad);
        while(!esPilaVacia(pila)){
            ArbolBinario arbol=desapilar(&pila);
            printf("%d ", arbol->elemento);
            if(!esArbolVacio(arbol->hijoDer))
                apilar(&pila, arbol->hijoDer);
            if(!esArbolVacio(arbol->hijoIzq))
                apilar(&pila, arbol->hijoIzq);
        }
    }
    destruirPila(&pila); 
}


void enOrdenIterativo(ArbolBinario tad){
    Pila pila;
    construirPila(&pila);
    int fin=0;
    do{
        while (!esArbolVacio(tad)){
            apilar(&pila, tad);
            tad=tad->hijoIzq;
        }
        if (esPilaVacia(pila))
            fin=1;
        else{
            tad = desapilar(&pila);
            printf("%d ", tad->elemento);
            tad=tad->hijoDer;
        }
    } while(fin==0);
    destruirPila(&pila);
}

void recorridoPorNivel(ArbolBinario tad){//preorden
    Cola cola;
    construirCola(&cola);
    if (!esArbolVacio(tad)){
        encolar(&cola, tad);
        while(!esColaVacia(cola)){
            ArbolBinario tad=desencolar(&cola);
            printf("%d ", tad->elemento);
            if (!esArbolVacio(tad->hijoIzq))
                encolar(&cola, tad->hijoIzq);
            if (!esArbolVacio(tad->hijoDer))
                encolar(&cola, tad->hijoDer);
        }
    }
    destruirCola(&cola);   
}
