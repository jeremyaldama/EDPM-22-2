#include <stdio.h>
#include <stdlib.h>

typedef int ElementoLista;

typedef struct nodo
{
    ElementoLista elemento;
    struct nodo *sig;
} Nodo;

typedef struct lista
{
    Nodo *cabeza;
    
} Lista;

void construirLista( Lista *pL )
{
    pL->cabeza = NULL;
}

int esListaVacia( Lista L )
{
    return L.cabeza == NULL;
}

Nodo* crearNuevoNodo( ElementoLista elemento, Nodo *sig )
{
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}

void insertarComienzo( Lista *pL, ElementoLista elemento )
{
    Nodo *pNuevoNodo;
    pNuevoNodo = crearNuevoNodo( elemento, pL->cabeza);
    pL->cabeza = pNuevoNodo;
}

void mostrar( Lista L )
{
    Nodo *pNodo;
    if ( esListaVacia( L) )
        printf("La lista esta vacia\n");
    else
    {
        pNodo = L.cabeza;
        while ( pNodo != NULL )
        {
            printf("%d ", pNodo->elemento);
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}

Nodo* obtenerUltimoNodo( Lista L )
{
    Nodo *pNodo, *pUltimo;
    pUltimo = NULL;
    pNodo = L.cabeza;
    while( pNodo != NULL )
    {
        pUltimo = pNodo;
        pNodo = pNodo->sig;
    }
    return pUltimo;
}

void insertarFinal(Lista *pL, ElementoLista elemento )
{
    Nodo *pNuevoNodo, *pUltimo;
    pNuevoNodo = crearNuevoNodo( elemento, NULL);
    pUltimo = obtenerUltimoNodo(*pL);
    if ( pUltimo == NULL )
        pL->cabeza = pNuevoNodo;
    else
        pUltimo->sig = pNuevoNodo;
}

int buscar( Lista L, ElementoLista valor )
{
    Nodo *pNodo;
    pNodo = L.cabeza;
    while ( pNodo != NULL )
    {
        if (valor==pNodo->elemento)
            return 1;
        pNodo = pNodo->sig;    
    }
    return 0;
}

Nodo* obtenerNodo(Lista L, ElementoLista valor)
{
    Nodo *pNodo;
    pNodo = L.cabeza;
    while ( pNodo != NULL )
    {
        if (valor == pNodo->elemento)
            break;
        pNodo = pNodo->sig;
    }
    return pNodo;
}

Nodo* obtenerNodoAnterior( Lista L, ElementoLista valor)
{
    Nodo *pNodo, *pAnterior;
    pAnterior = NULL;
    pNodo = L.cabeza;
    while ( pNodo != NULL )
    {
        if ( pNodo->elemento == valor )
            break;
        pAnterior = pNodo;
        pNodo = pNodo->sig;
    }
    return pAnterior;
}

void eliminarNodo( Lista *pL, ElementoLista valor )
{
    Nodo *pNodoEliminar, *pAnterior;
    pNodoEliminar = obtenerNodo( *pL, valor);
    if ( pNodoEliminar == NULL )
        printf("%d no esta en la lista\n",valor);
    else
    {
        pAnterior = obtenerNodoAnterior(*pL, valor);
        if ( pAnterior == NULL )
            pL->cabeza = pNodoEliminar->sig;
        else
            pAnterior->sig =pNodoEliminar->sig;
        free(pNodoEliminar);
        printf("El nodo fue eliminado\n");
    }
}

void destruirLista( Lista *pL )
{
    Nodo *pNodo, *pAux;
    pNodo = pL->cabeza;
    while ( pNodo != NULL )
    {
        pAux = pNodo->sig;
        free(pNodo);
        pNodo = pAux;
    }
    pL->cabeza = NULL;
    printf("Todos los nodos han sido eliminados\n");
}

int obtenerLongitud( Lista L )
{
    Nodo *pNodo;
    int nodos = 0;
    pNodo = L.cabeza;
    while ( pNodo != NULL )
    {
        nodos++;
        pNodo = pNodo->sig;
    }
    return nodos;
}

int main() 
{
    Lista LA;
    int b,lonLA;
    construirLista(&LA);
    mostrar(LA);
    insertarComienzo( &LA, 45);
    mostrar(LA);
    insertarComienzo( &LA, 29);
    mostrar(LA);
    insertarFinal( &LA, 87);
    mostrar(LA);
    insertarFinal( &LA, 100);
    mostrar(LA);
    b = buscar( LA, 87);
    printf("%d\n",b);
    b = buscar( LA, 91);
    printf("%d\n",b);
    eliminarNodo( &LA, 87);
    mostrar(LA);
    eliminarNodo( &LA, 29);
    mostrar(LA);
    eliminarNodo( &LA, 30);
    mostrar(LA);
    lonLA = obtenerLongitud(LA);
    printf("La lista tiene %d nodos\n", lonLA);
    destruirLista( &LA );
    mostrar(LA);
    lonLA = obtenerLongitud(LA);
    printf("La lista tiene %d nodos\n", lonLA);
    return 0;
}
