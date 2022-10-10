#ifndef LAR_H
#define LAR_H
#include "len.h"

typedef int Vertice;
typedef Vertice ElementoListaArista;

typedef struct nodoListaArista {
    ElementoListaArista elemento;    
    struct nodoListaArista *sig;
} NodoListaArista;

typedef struct {
    int longitud;
    NodoListaArista *cabeza;
} ListaArista;

void construir_lista_arista(ListaArista *);
void destruir_lista_arista(ListaArista *);
int longitud_lista_arista(ListaArista);
int se_encuentra_arista_en_lista_arista(ListaArista, ElementoListaArista);
NodoListaArista *crear_nuevo_nodo_arista(ElementoListaArista, NodoListaArista *);
NodoListaArista *obtener_ultima_arista(ListaArista);
void insertar_arista_al_final(ListaArista *, Vertice);
void eliminar_arista_en_lista(ListaArista *, Vertice);
void insertar_vertices_adyacentes(ListaEntero *, ListaArista);
#endif