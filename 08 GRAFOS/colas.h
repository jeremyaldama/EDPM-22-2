#ifndef COLAS_H
#define COLAS_H
#include "len.h"

typedef ElementoListaEntero ElementoCola;

typedef struct {
	ListaEntero contenido;    
} Cola;

void construir_cola(Cola *);
int es_cola_vacia(Cola);
void pide_vez(Cola *, ElementoCola);
ElementoCola avanzar(Cola *tad);
void destruir_cola(Cola *tad);

#endif