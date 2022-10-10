#ifndef AB_H
#define AB_H

typedef int ElementoArbol;

typedef struct nodoArbol {
    ElementoArbol elemento;    
    struct nodoArbol *hijoIzq;
    struct nodoArbol *hijoDer;
} NodoArbol;

typedef NodoArbol* ArbolBinario;

void construirArbolBinario(ArbolBinario *);
void plantarArbolBinario(ArbolBinario *, ArbolBinario, ElementoArbol, ArbolBinario);
NodoArbol *crearNuevoNodoArbol(ArbolBinario, ElementoArbol, ArbolBinario);
int esArbolVacio(ArbolBinario);
ElementoArbol raiz(ArbolBinario);
ArbolBinario hijoDer(ArbolBinario);
ArbolBinario hijoIzq(ArbolBinario);
void imprimeRaiz(ArbolBinario);
int altura(ArbolBinario);
int maximo(int, int);
int numeroNodos(ArbolBinario);
int numeroHojas(ArbolBinario);
ArbolBinario especular(ArbolBinario);
ArbolBinario copiaArbolBinario(ArbolBinario);
void destruirArbolBinario(ArbolBinario *);
int esEquilibrado(ArbolBinario);
int esHoja(ArbolBinario);
void esZurdo(ArbolBinario, int *, int *);
void preOrden(ArbolBinario);
void enOrden(ArbolBinario);
void postOrden(ArbolBinario);
void preOrdenIterativo(ArbolBinario);
void enOrdenIterativo(ArbolBinario);
void recorridoPorNivel(ArbolBinario);

#endif
