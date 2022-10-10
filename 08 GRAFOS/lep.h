#ifndef LEP_H
#define LEP_H
#include "len.h"

typedef struct {
    int vertice;
    ListaEntero lista_adyacentes;
} ElementoPila;

typedef struct nodoListaElementoPila {
    ElementoPila elemento;    
    struct nodoListaElementoPila *sig;
} NodoListaElementoPila;

typedef struct {
    int longitud;
    NodoListaElementoPila *cabeza;
} ListaElementoPila;

void construir_lista_elemento_pila(ListaElementoPila *);
int es_lista_de_elemento_pila_vacia(ListaElementoPila);
NodoListaElementoPila *crear_nuevo_nodo_elemento_pila(ElementoPila, NodoListaElementoPila *);
void insertar_elemento_pila_al_inicio(ListaElementoPila *, ElementoPila);
ElementoPila retorna_cabeza_elemento_pila(ListaElementoPila);
void elimina_cabeza_elemento_pila(ListaElementoPila *);
void destruir_lista_elemento_pila(ListaElementoPila *);

#endif