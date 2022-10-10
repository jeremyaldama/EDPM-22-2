#ifndef LSE_H
#define LSE_H
#include "ab.h"

typedef ArbolBinario ElementoLista;

typedef struct nodoLista {
    ElementoLista elemento;    
    struct nodoLista *sig;
} NodoLista;

typedef struct {
    NodoLista *cabeza;
    int longitud;
} Lista;

void construirLista(Lista *);
int esListaVacia(Lista);
NodoLista *crearNuevoNodo(ElementoLista, NodoLista *);
void insertarAlInicio(Lista *tad, ElementoLista);
void insertarAlFinal(Lista *tad, ElementoLista);
void insertarEnOrden(Lista *tad, ElementoLista);
int longitud(Lista);
void imprime(Lista);
NodoLista *obtenerUltimoNodo(Lista);
NodoLista *obtenerNodoAnterior(Lista, ElementoLista);
NodoLista* seEncuentra(Lista, ElementoLista);
ElementoLista retornaCabeza(Lista);
void eliminaCabeza(Lista *);
void eliminaCola(Lista *);
void eliminaNodo(Lista *, ElementoLista);
void destruirLista(Lista *);

#endif