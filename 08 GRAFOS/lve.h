#ifndef LVE_H
#define LVE_H
#include "lar.h"
#include "len.h"

typedef Vertice ElementoListaVertice;

typedef struct nodoListaVertice {
    ElementoListaVertice elemento;    
    struct nodoListaVertice *sig;
    ListaArista lista_arista;
} NodoListaVertice;

typedef struct {
    int longitud;
    NodoListaVertice *cabeza;
} ListaVertice;

void construir_lista_vertice(ListaVertice *);
void destruir_lista_vertice(ListaVertice *);
int es_lista_vertice_vacia(ListaVertice);
int longitud_lista_vertices(ListaVertice);
NodoListaVertice *crear_nuevo_nodo_vertice(ElementoListaVertice, NodoListaVertice *);
NodoListaVertice *obtener_ultimo_vertice(ListaVertice);	
NodoListaVertice *obtener_nodo_vertice(ListaVertice, Vertice);
int se_encuentra_vertice_en_lista(ListaVertice, Vertice);
void insertar_vertice_al_final(ListaVertice *, Vertice);
void eliminar_vertice_en_lista(ListaVertice *, Vertice);
void insertar_en_lista_de_aristas(ListaVertice, Vertice, Vertice);
void eliminar_de_lista_de_aristas(ListaVertice tad, Vertice, Vertice);
int se_encuentra_arista_en_lista_vertices(ListaVertice, Vertice, Vertice);
void obtener_vertices_adyacentes(ListaEntero *, ListaVertice, Vertice);

#endif