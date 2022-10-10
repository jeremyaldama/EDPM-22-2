#include <stdlib.h>
#include <stdio.h>

typedef int ElementoArbol;

typedef struct nodo
{
    struct nodo *hizq;
    ElementoArbol elemento;
    struct nodo *hder;
} Nodo;

typedef Nodo* ArbolBinario;

void construirArbol( ArbolBinario *pAB )
{
    *pAB = NULL;
}

Nodo* crearNuevoNodo(ArbolBinario arbolIzq, ElementoArbol elemento, ArbolBinario arbolDer)
{
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo) );
    pNuevoNodo->hizq = arbolIzq;
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->hder = arbolDer;
    return pNuevoNodo;
}

void plantar( ArbolBinario *pAB, ArbolBinario arbolIzq, ElementoArbol elemento, ArbolBinario arbolDer )
{
    Nodo *pNuevoNodo;
    pNuevoNodo = crearNuevoNodo( arbolIzq, elemento, arbolDer );
    *pAB = pNuevoNodo;
}

int esArbolVacio( ArbolBinario AB )
{
    return AB == NULL;
}

void recorrerEnOrden( ArbolBinario AB )
{
    ArbolBinario ABI, ABD;
    if ( !esArbolVacio(AB) )
    {
        ABI = AB->hizq;
        ABD = AB->hder;
        recorrerEnOrden( ABI );
        printf("%d ", AB->elemento );  // raiz
        recorrerEnOrden ( ABD );
    }
}

void recorrerEnPreOrden( ArbolBinario AB )
{
    ArbolBinario ABI, ABD;
    if ( !esArbolVacio(AB) )
    {
        ABI = AB->hizq;
        ABD = AB->hder;
        printf("%d ", AB->elemento );  // raiz
        recorrerEnPreOrden( ABI );
        recorrerEnPreOrden( ABD );
    }
}

void recorrerEnPostOrden( ArbolBinario AB )
{
    ArbolBinario ABI, ABD;
    if ( !esArbolVacio(AB) )
    {
        ABI = AB->hizq;
        ABD = AB->hder;
        recorrerEnPostOrden( ABI );
        recorrerEnPostOrden( ABD );
        printf("%d ", AB->elemento );  // raiz
    }
}

int contarNodos( ArbolBinario AB )
{
    ArbolBinario ABI, ABD;
    int nodosABI, nodosABD;
    if ( esArbolVacio(AB) )
        return 0;
    else
    {
        ABI = AB->hizq;
        ABD = AB->hder;
        nodosABI = contarNodos( ABI );
        nodosABD = contarNodos( ABD );
        return nodosABI + nodosABD + 1;
    }
}

int esHoja( ArbolBinario AB )
{
    if ( esArbolVacio(AB) )
        return 0;
    else
        return AB->hizq == NULL && AB->hder == NULL;
        // return esArbolVacio( AB->hizq ) && esArbolVacio( AB->hder);
}

int maximo( int x, int y )
{
    return ( x>=y) ? x : y;
}

int altura( ArbolBinario AB )
{
    int alturaABI, alturaABD;
    if ( esArbolVacio(AB) )
        return -1;
    else
    {
        alturaABI = altura( AB->hizq );
        alturaABD = altura( AB->hder );
        return maximo( alturaABI, alturaABD) + 1;
    }
}

int esEquilibrado( ArbolBinario AB )
{
    int alturaABI, alturaABD, difAltura;
    if ( esArbolVacio(AB) )
        return 1;
    else
    {
        alturaABI = altura( AB->hizq);
        alturaABD = altura( AB->hder);
        difAltura = abs( alturaABI - alturaABD );
        return difAltura <=1 && esEquilibrado(AB->hizq) && esEquilibrado(AB->hder);
    }
}

int main() 
{
    ArbolBinario A1,A2,A3,A4,A;  
    int nodosA, esHojaA1, esHojaA3;
    int altA1, altA3, altA, equiA;
    construirArbol(&A1);
    construirArbol(&A2);
    construirArbol(&A3);
    construirArbol(&A4);
    construirArbol(&A);
    plantar(&A1,NULL,10,NULL);
    plantar(&A2,NULL,40,NULL);
    plantar(&A3,A1,25,A2);
    plantar(&A4,NULL,100,NULL);
    plantar(&A,A3,70,A4);
    /*printf("Recorrido en orden de A1: ");
    recorrerEnOrden(A1);
    printf("\nRecorrido en orden de A2: ");
    recorrerEnOrden(A2);
    printf("\nRecorrido en orden de A3: ");
    recorrerEnOrden(A3);
    printf("\nRecorrido en orden de A4: ");
    recorrerEnOrden(A4);*/
    printf("\nRecorrido en orden de A: ");
    recorrerEnOrden(A);
    printf("\nRecorrido en preorden de A: ");
    recorrerEnPreOrden(A);
    printf("\nRecorrido en postorden de A: ");
    recorrerEnPostOrden(A);
    nodosA = contarNodos(A);
    printf("\nEl arbol tiene %d nodos\n", nodosA);
    esHojaA1 = esHoja(A1);
    printf("A1 es hoja: %d\n",esHojaA1);
    esHojaA3 = esHoja(A3);
    printf("A3 es hoja: %d\n",esHojaA3);
    altA1 = altura(A1);
    printf("\nLa altura de A1 es %d\n",altA1);
    altA3 = altura(A3);
    printf("\nLa altura de A3 es %d\n",altA3);
    altA = altura(A);
    printf("\nLa altura de A es %d\n",altA);
    equiA = esEquilibrado(A);
    printf("\nA es equilibrado: %d\n",equiA);
    return 0;
}
