#include <stdio.h>
#include <stdlib.h>

typedef int ElementoCola;

typedef struct nodo
{
    ElementoCola elemento;
    struct nodo *sig;
} Nodo;

typedef struct cola
{
    Nodo *cabeza;
    Nodo *final;
    int longitud;
} Cola;

void construirCola( Cola *pC )
{
    pC->cabeza = NULL;
    pC->final = NULL;
    pC->longitud = 0;
}

int esColaVacia( Cola C )
{
    return C.cabeza == NULL;
    // return C.longitud == 0;
}

Nodo* crearNuevoNodo( ElementoCola elemento )
{
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = NULL;
    return pNuevoNodo;
}

void encolar( Cola *pC, ElementoCola elemento )
{
    Nodo *pNuevoNodo, *pFinal;
    pNuevoNodo = crearNuevoNodo( elemento);
    if ( esColaVacia(*pC) )
        pC->cabeza = pNuevoNodo;
    else
    {
        pFinal = pC->final;
        pFinal->sig = pNuevoNodo;
    }
    pC->final = pNuevoNodo;
    pC->longitud++;
}

void mostrar( Cola C )
{
    Nodo *pNodo;
    if ( esColaVacia(C) )
        printf("La cola esta vacia\n");
    else
    {
        pNodo = C.cabeza;
        while ( pNodo != NULL )
        {
            printf("%d ", pNodo->elemento );
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}

int obtenerLongitud( Cola C )
{
    return C.longitud;
}

ElementoCola desencolar( Cola *pC )
{
    Nodo *pNodo;
    ElementoCola elemento;
    pNodo = pC->cabeza;
    elemento = pNodo->elemento;
    pC->cabeza = pNodo->sig;
    if ( pNodo->sig == NULL )
        pC->final = NULL;
    free(pNodo);
    pC->longitud--;
    return elemento;
}

int main()
{
    Cola Q;
    int longQ;
    ElementoCola e;
    construirCola( &Q );
    mostrar(Q);
    longQ = obtenerLongitud(Q);
    printf("La cola tiene %d nodos\n", longQ);
    encolar( &Q, 56);
    mostrar(Q);
    longQ = obtenerLongitud(Q);
    printf("La cola tiene %d nodos\n", longQ);
    encolar( &Q, 25);
    mostrar(Q);
    longQ = obtenerLongitud(Q);
    printf("La cola tiene %d nodos\n", longQ);
    encolar( &Q, 80);
    mostrar(Q);
    longQ = obtenerLongitud(Q);
    printf("La cola tiene %d nodos\n", longQ);
    while( !esColaVacia(Q) )
    {
        e = desencolar( &Q );
        printf("Elemento desencolado: %d\n",e);
        mostrar( Q );
    }
    return 0;
}
