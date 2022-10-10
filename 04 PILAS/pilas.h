#ifndef PILAS_H
#define PILAS_H
#include "lse.h"

typedef ElementoLista ElementoPila;

typedef struct {
    Lista contenido;    
} Pila;

void construirPila(Pila *);
int esPilaVacia(Pila);
void apilar(Pila *, ElementoPila);
ElementoPila desapilar(Pila *);
ElementoPila cima(Pila);
void destruirPila(Pila *);
void mostrar(Pila);

#endif