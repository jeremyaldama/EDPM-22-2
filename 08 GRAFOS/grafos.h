#ifndef GRAFO_H
#define GRAFO_H
#include "lve.h"

typedef struct {
    ListaVertice lista_vertice;
    int longitud;
} Grafo;

void construir_grafo(Grafo *);
void destruir_grafo(Grafo *);
int es_grafo_vacio(Grafo);
int longitud_grafo(Grafo);
int se_encuentra_vertice(Grafo, Vertice);
void anhadir_vertice(Grafo *, Vertice);
void eliminar_vertice(Grafo *, Vertice);
int se_encuentra_arista(Grafo, Vertice, Vertice);
void anhadir_arista(Grafo, Vertice, Vertice);
void eliminar_arista(Grafo, Vertice, Vertice);
ListaEntero adyacentes(Grafo, Vertice);
void profundidad_recursivo(Grafo, Vertice, int [], int *);
void profundidad_iterativo(Grafo, Vertice, int []);
void amplitud_iterativo(Grafo, Vertice, int []);

#endif