#include <stdio.h>
#include <stdlib.h>

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

void construirPila( Pila *pP )
{
    pP->cima = NULL;
    pP->longitud = 0;
}

int esPilaVacia( Pila P )
{
    return P.cima == NULL;
    // return C.longitud == 0;
}

Nodo* crearNuevoNodo( ElementoPila elemento, Nodo *sig )
{
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}

void apilar( Pila *pP, ElementoPila elemento)
{
    Nodo *pNuevoNodo;
    pNuevoNodo = crearNuevoNodo( elemento, pP->cima );
    pP->cima = pNuevoNodo;
    pP->longitud++;
}

void mostrar( Pila P )
{
    Nodo *pNodo;
    if ( esPilaVacia(P) )
        printf("La pila esta vacia\n");
    else
    {
        pNodo = P.cima;
        while ( pNodo != NULL )
        {
            printf("%d\n", pNodo->elemento );
            pNodo = pNodo->sig;
        }
        printf("\n\n");
    }
}

int obtenerLongitud( Pila P )
{
    return P.longitud;    
}

ElementoPila desapilar( Pila *pP )
{
    Nodo *pNodo;
    ElementoPila elemento;
    pNodo = pP->cima;
    elemento = pNodo->elemento;
    pP->cima = pNodo->sig;
    pP->longitud--;
    free(pNodo);
    return elemento;
}

int main()
{ 
    Pila S;
    int longS;
    ElementoPila e;
    construirPila( &S );
    mostrar( S );
    apilar( &S, 10 );
    mostrar( S );
    apilar( &S, 20 );
    mostrar( S );
    apilar( &S, 30 );
    mostrar( S );
    longS = obtenerLongitud( S);
    printf("La pila tiene %d elementos\n",longS );
    while( !esPilaVacia(S) )
    {
        e = desapilar( &S );
        printf("Elemento desapilado: %d\n",e);
        mostrar( S );
    }
    longS = obtenerLongitud( S);
    printf("La pila tiene %d elementos\n",longS );
    return 0;
}
