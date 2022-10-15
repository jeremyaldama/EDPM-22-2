/* 
 * File:   pila.h
 * Author: Danie
 *
 * Created on 15 de octubre de 2022, 0:30
 */

#ifndef PILA_H
#define PILA_H

typedef int ElementoPila;

typedef struct nodo
{
    ElementoPila elemento;
    struct nodo *sig;
} Nodo;

typedef struct pila
{
    Nodo *cima;
    int longitud;
} Pila;

void construirPila( Pila *);
int esPilaVacia( Pila );
Nodo* crearNuevoNodo( ElementoPila , Nodo * );
void apilar( Pila *, ElementoPila );
void mostrar( Pila );
int obtenerLongitud( Pila );
ElementoPila desapilar( Pila *);

#endif /* PILA_H */

