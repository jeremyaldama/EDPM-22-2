#ifndef COLAS_H
#define COLAS_H
#include "lse.h"

typedef ElementoLista ElementoCola;

typedef struct {
    Lista contenido;    
} Cola;

void construirCola(Cola *);
int esColaVacia(Cola);
void encolar(Cola *, ElementoCola);
ElementoCola desencolar(Cola *tad);
void destruirCola(Cola *tad);
void imprimir(Cola);

#endif