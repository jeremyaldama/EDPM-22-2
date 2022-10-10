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

typedef ArbolBinario ArbolBinarioBusqueda;

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

void insertar( ArbolBinarioBusqueda *pABB, ElementoArbol elemento)
{
    Nodo *p, *padre;
    if ( esArbolVacio(*pABB) )
        plantar( pABB, NULL, elemento, NULL);
    else
    {
        padre = NULL;
        p = *pABB;
        while( p!= NULL )
        {
            padre = p;
            if( elemento < p->elemento )
                p = p->hizq;
            else
                p = p->hder;
        }
        if ( elemento < padre->elemento )
            plantar(&padre->hizq, NULL, elemento, NULL);
        else
            plantar(&padre->hder, NULL, elemento, NULL);
    }
}

int buscar( ArbolBinarioBusqueda ABB, ElementoArbol valor )
{
    if ( esArbolVacio(ABB) )
        return 0;
    else
        if ( ABB->elemento == valor )
            return 1;
        else
            if ( valor < ABB->elemento )
                return buscar(ABB->hizq,valor);
            else
                return buscar(ABB->hder,valor);
}

ElementoArbol menor( ArbolBinarioBusqueda ABB )  
{
	Nodo *p;
	p = ABB;
	while ( p->hizq != NULL )
		p = p->hizq;
	return p->elemento;
}

void eliminar( ArbolBinarioBusqueda *pABB, ElementoArbol elemento )
{
    Nodo *p;
    ElementoArbol menorDerecha;
	if ( !esArbolVacio(*pABB) )
    {
        if ( (*pABB)->elemento == elemento )
        {
            if ( (*pABB)->hder == NULL )
            {
            	p = *pABB;
            	*pABB = (*pABB)->hizq;
            	free(p);
			}
			else
				if( (*pABB)->hizq == NULL )
            	{
            		p = *pABB;
            		*pABB = (*pABB)->hder;
            		free(p);
				}
				else
				{
					menorDerecha = menor((*pABB)->hder);
					(*pABB)->elemento = menorDerecha;
					eliminar( &((*pABB)->hder), menorDerecha);
				}
        }
        else
            if ( elemento < (*pABB)->elemento )
                eliminar( &((*pABB)->hizq), elemento);
            else
                eliminar( &((*pABB)->hder), elemento);
    }
}

void destruir( ArbolBinarioBusqueda *pABB )
{
	if ( !esArbolVacio(*pABB) )
	{
		destruir( &( (*pABB)->hizq ) );
		destruir( &( (*pABB)->hder ) );
		free(*pABB);
		*pABB = NULL;
	}
}

int main() 
{
    ArbolBinarioBusqueda A;
    int b;
    construirArbol( &A);
    insertar(&A,100);
    insertar(&A,50);
    insertar(&A,150);
    insertar(&A,20);
    insertar(&A,80);
    insertar(&A,60);
    insertar(&A,90);
    insertar(&A,130);
    insertar(&A,170);
    insertar(&A,110);
    insertar(&A,140);
    recorrerEnOrden(A);
    b = buscar(A,90);
    printf("\nBusqueda de 90: %d\n",b);
    b = buscar(A,44);
    printf("Busqueda de 44: %d\n",b);
    
    eliminar(&A,90);
    recorrerEnOrden(A);
    printf("\n");
    eliminar(&A,80);
    recorrerEnOrden(A);
    
    printf("\n");
    eliminar(&A,100);
    recorrerEnOrden(A);
    
    destruir(&A);
    printf("\nArbol esta vacio: %d\n", esArbolVacio(A));
    
    return 0;
}
