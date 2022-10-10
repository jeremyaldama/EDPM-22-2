#include <stdio.h>
#include <stdlib.h>

typedef int Vertice;

typedef struct nodoA
{
    Vertice vertice;
    struct nodoA *sig;
} NodoA;

typedef struct listaA
{
    NodoA *cabeza;
} ListaAristas;

typedef struct nodoV
{
    Vertice vertice;
    ListaAristas LA;
	struct nodoV *sig;
} NodoV;

typedef struct listaV
{
    NodoV *cabeza;
    
} ListaVertices;


typedef ListaVertices Grafo;


//// Funciones para lista de vertices ////////////////////////

void construirListaVertices( ListaVertices *pLV )
{ 
    pLV->cabeza = NULL;
}

int esListaVerticesVacia( ListaVertices LV )
{
    return LV.cabeza == NULL;
}

NodoV* crearNuevoNodoVertice( Vertice vertice, NodoV *sig )
{
    NodoV *pNuevoNodo;
    pNuevoNodo = (NodoV*)malloc(sizeof(NodoV));
    pNuevoNodo->vertice = vertice;
    pNuevoNodo->LA.cabeza = NULL;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}

void insertarComienzoListaVertices( ListaVertices *pLV, Vertice vertice )
{
    NodoV *pNuevoNodo;
    pNuevoNodo = crearNuevoNodoVertice( vertice, pLV->cabeza);
    pLV->cabeza = pNuevoNodo;
}

void mostrarListaVertices( ListaVertices LV )
{
    NodoV *pNodo;
    if ( esListaVerticesVacia( LV ) )
        printf("La lista de vertices esta vacia\n");
    else
    {
        pNodo = LV.cabeza;
        while ( pNodo != NULL )
        {
            printf("%d ", pNodo->vertice);
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}

NodoV* obtenerUltimoNodoListaVertices( ListaVertices LV )
{
    NodoV *pNodo, *pUltimo;
    pUltimo = NULL;
    pNodo = LV.cabeza;
    while( pNodo != NULL )
    {
        pUltimo = pNodo;
        pNodo = pNodo->sig;
    }
    return pUltimo;
}

void insertarFinalListaVertices(ListaVertices *pLV, Vertice vertice )
{
    NodoV *pNuevoNodo, *pUltimo;
    pNuevoNodo = crearNuevoNodoVertice( vertice, NULL);
    pUltimo = obtenerUltimoNodoListaVertices(*pLV);
    if ( pUltimo == NULL )
        pLV->cabeza = pNuevoNodo;
    else
        pUltimo->sig = pNuevoNodo;
}

int buscarEnListaVertices( ListaVertices LV, Vertice vertice )
{
    NodoV *pNodo;
    pNodo = LV.cabeza;
    while ( pNodo != NULL )
    {
        if ( vertice == pNodo->vertice )
            return 1;
        pNodo = pNodo->sig;    
    }
    return 0;
}

NodoV* obtenerNodoListaVertices( ListaVertices LV, Vertice vertice )
{
    NodoV *pNodo;
    pNodo = LV.cabeza;
    while ( pNodo != NULL )
    {
        if ( vertice == pNodo->vertice)
            break;
        pNodo = pNodo->sig;
    }
    return pNodo;
}

NodoV* obtenerNodoAnteriorListaVertices( ListaVertices LV, Vertice vertice )
{
    NodoV *pNodo, *pAnterior;
    pAnterior = NULL;
    pNodo = LV.cabeza;
    while ( pNodo != NULL )
    {
        if ( pNodo->vertice == vertice )
            break;
        pAnterior = pNodo;
        pNodo = pNodo->sig;
    }
    return pAnterior;
}

void eliminarNodoListaVertices( ListaVertices *pLV, Vertice vertice )
{
    NodoV *pNodoEliminar, *pAnterior;
    pNodoEliminar = obtenerNodoListaVertices( *pLV, vertice);
    if ( pNodoEliminar == NULL )
        printf("%d no esta en la lista\n", vertice);
    else
    {
        pAnterior = obtenerNodoAnteriorListaVertices(*pLV, vertice);
        if ( pAnterior == NULL )
            pLV->cabeza = pNodoEliminar->sig;
        else
            pAnterior->sig = pNodoEliminar->sig;
        free(pNodoEliminar);
        //printf("El vertice fue eliminado\n");
    }
}

void destruirListaVertices( ListaVertices *pLV )
{
    NodoV *pNodo, *pAux;
    pNodo = pLV->cabeza;
    while ( pNodo != NULL )
    {
        pAux = pNodo->sig;
        free(pNodo);
        pNodo = pAux;
    }
    pLV->cabeza = NULL;
    printf("Todos los vertices han sido eliminados\n");
}

int obtenerLongitudListaVertices( ListaVertices LV )
{
    NodoV *pNodo;
    int nodos = 0;
    pNodo = LV.cabeza;
    while ( pNodo != NULL )
    {
        nodos++;
        pNodo = pNodo->sig;
    }
    return nodos;
}

//// Funciones para lista de aristas ////////////////////////////////////////

void construirListaAristas( ListaAristas *pLA )
{ 
    pLA->cabeza = NULL;
}

int esListaAristasVacia( ListaAristas LA )
{
    return LA.cabeza == NULL;
}

NodoA* crearNuevoNodoArista( Vertice vertice, NodoA *sig )
{
    NodoA *pNuevoNodo;
    pNuevoNodo = (NodoA*)malloc(sizeof(NodoA));
    pNuevoNodo->vertice = vertice;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}

void insertarComienzoListaAristas( ListaAristas *pLA, Vertice vertice )
{
    NodoA *pNuevoNodo;
    pNuevoNodo = crearNuevoNodoArista( vertice, pLA->cabeza);
    pLA->cabeza = pNuevoNodo;
}

void mostrarVerticesAristas( ListaAristas LA )
{
    NodoA *pNodo;
    if ( esListaAristasVacia( LA ) )
        printf("La lista de aristas esta vacia\n");
    else
    {
        pNodo = LA.cabeza;
        while ( pNodo != NULL )
        {
            printf("%d ", pNodo->vertice);
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}

NodoA* obtenerUltimoNodoListaAristas( ListaAristas LA )
{
    NodoA *pNodo, *pUltimo;
    pUltimo = NULL;
    pNodo = LA.cabeza;
    while( pNodo != NULL )
    {
        pUltimo = pNodo;
        pNodo = pNodo->sig;
    }
    return pUltimo;
}

void insertarFinalListaAristas(ListaAristas *pLA, Vertice vertice )
{
    NodoA *pNuevoNodo, *pUltimo;
    pNuevoNodo = crearNuevoNodoArista( vertice, NULL);
    pUltimo = obtenerUltimoNodoListaAristas(*pLA);
    if ( pUltimo == NULL )
        pLA->cabeza = pNuevoNodo;
    else
        pUltimo->sig = pNuevoNodo;
}

int buscarEnListaAristas( ListaAristas LA, Vertice vertice )
{
    NodoA *pNodo;
    pNodo = LA.cabeza;
    while ( pNodo != NULL )
    {
        if ( vertice == pNodo->vertice )
            return 1;
        pNodo = pNodo->sig;    
    }
    return 0;
}

NodoA* obtenerNodoListaAristas( ListaAristas LA, Vertice vertice )
{
    NodoA *pNodo;
    pNodo = LA.cabeza;
    while ( pNodo != NULL )
    {
        if ( vertice == pNodo->vertice)
            break;
        pNodo = pNodo->sig;
    }
    return pNodo;
}

NodoA* obtenerNodoAnteriorListaAristas( ListaAristas LA, Vertice vertice )
{
    NodoA *pNodo, *pAnterior;
    pAnterior = NULL;
    pNodo = LA.cabeza;
    while ( pNodo != NULL )
    {
        if ( pNodo->vertice == vertice )
            break;
        pAnterior = pNodo;
        pNodo = pNodo->sig;
    }
    return pAnterior;
}

void eliminarNodoListaAristas( ListaAristas *pLA, Vertice vertice )
{
    NodoA *pNodoEliminar, *pAnterior;
    pNodoEliminar = obtenerNodoListaAristas( *pLA, vertice);
    if ( pNodoEliminar == NULL )
        printf("%d no esta en la lista\n", vertice);
    else
    {
        pAnterior = obtenerNodoAnteriorListaAristas(*pLA, vertice);
        if ( pAnterior == NULL )
            pLA->cabeza = pNodoEliminar->sig;
        else
            pAnterior->sig = pNodoEliminar->sig;
        free(pNodoEliminar);
        //printf("El vertice fue eliminado\n");
    }
}

void destruirListaAristas( ListaAristas *pLA )
{
    NodoA *pNodo, *pAux;
    pNodo = pLA->cabeza;
    while ( pNodo != NULL )
    {
        pAux = pNodo->sig;
        free(pNodo);
        pNodo = pAux;
    }
    pLA->cabeza = NULL;
    //printf("Todos los vertices han sido eliminados\n");
}

int obtenerLongitudListaAristas( ListaAristas LA )
{
    NodoA *pNodo;
    int nodos = 0;
    pNodo = LA.cabeza;
    while ( pNodo != NULL )
    {
        nodos++;
        pNodo = pNodo->sig;
    }
    return nodos;
}

////////// Funciones para grafos //////////////////////////////

void construirGrafo( Grafo *pG )
{
	construirListaVertices( pG );
}

int esGrafoVacio( Grafo G )
{
	return esListaVerticesVacia( G );
}

int existeVertice( Grafo G, Vertice vertice )
{
	return buscarEnListaVertices( G, vertice );
}

void agregarVertice( Grafo *pG, Vertice vertice )
{
	if ( !existeVertice( *pG, vertice) )
	{
		insertarFinalListaVertices(pG, vertice );
		printf("Se agrego el vertice %d al grafo\n", vertice);
	}
	else
		printf("El vertice %d ya esta registrado\n", vertice);
}

void agregarArista( Grafo *pG, Vertice verticeOrigen, Vertice verticeDestino )
{
	NodoV *p;
	if ( existeVertice( *pG, verticeOrigen) && existeVertice( *pG, verticeDestino ) )
	{
		p = obtenerNodoListaVertices( *pG, verticeOrigen );
		if ( buscarEnListaAristas( p->LA, verticeDestino ) == 0 )
		{
			insertarFinalListaAristas( &(p->LA), verticeDestino );
			printf("La arista %d - %d ha sido creada\n", verticeOrigen, verticeDestino );
		}	
		else
			printf("No es posible volver a registrar una misma arista\n");
	}
	else
		printf("No es posible construir la arista porque alguno de los vertices no existe\n");
}

void mostrarAdyacentes( Grafo G, Vertice vertice )
{
	NodoV *p;
	if ( !existeVertice( G, vertice) )
		printf("No se pueden mostrar adyacentes de un vertice que no existe\n");
	else
	{
		p = obtenerNodoListaVertices( G, vertice );	
		mostrarVerticesAristas( p->LA );
	}	
}

void eliminarArista( Grafo *pG, Vertice verticeOrigen, Vertice verticeDestino )
{
	NodoV *p;
	if ( existeVertice( *pG, verticeOrigen) && existeVertice( *pG, verticeDestino ) )
	{
		p = obtenerNodoListaVertices( *pG, verticeOrigen );
		if ( buscarEnListaAristas( p->LA, verticeDestino ) == 1 )
		{
			eliminarNodoListaAristas( &(p->LA), verticeDestino );
			printf("La arista %d - %d ha sido eliminada\n", verticeOrigen, verticeDestino );
		}	
		else
			printf("No es posible eliminar la arista %d - %d porque no existe\n",verticeOrigen,verticeDestino);
	}
	else
		printf("No es posible eliminar la arista porque alguno de los vertices no existe\n");
}


void eliminarVertice( Grafo *pG, Vertice vertice )
{
	NodoV *p;
	if ( existeVertice( *pG, vertice) )
	{
		p = obtenerNodoListaVertices( *pG, vertice );
		destruirListaAristas( &(p->LA) );
		eliminarNodoListaVertices( pG, vertice );
		printf("El vertice %d ha sido eliminado\n",vertice);
	}
	else
		printf("No se puede eliminar un vertice que no existe\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////

int main() 
{
    Grafo G1;
    construirGrafo(&G1);
    printf("Es grafo vacio: %d\n", esGrafoVacio(G1));
    
    agregarVertice( &G1, 1);
    mostrarListaVertices( G1);
    agregarVertice( &G1, 2);
    mostrarListaVertices( G1);
    agregarVertice( &G1, 3);
    mostrarListaVertices( G1);
    agregarVertice( &G1, 4);
    mostrarListaVertices( G1);
    
	agregarArista( &G1, 1, 2); 
    agregarArista( &G1, 1, 3); 
    agregarArista( &G1, 2, 1);
    agregarArista( &G1, 2, 3);
    agregarArista( &G1, 2, 4);
    agregarArista( &G1, 3, 4);
    agregarArista( &G1, 2, 1);
    
    printf("Adyacentes al vertice 1: ");
    mostrarAdyacentes(G1,1);
	
	printf("Adyacentes al vertice 2: ");
    mostrarAdyacentes(G1,2);
	
	printf("Adyacentes al vertice 3: ");
    mostrarAdyacentes(G1,3);
    
    printf("Adyacentes al vertice 4: ");
    mostrarAdyacentes(G1,4);
	
	printf("Adyacentes al vertice 5: ");
    mostrarAdyacentes(G1,5);
    
    eliminarArista( &G1, 2,5);
    eliminarArista( &G1, 2,2);
    eliminarArista( &G1, 2,3);
    printf("Adyacentes al vertice 2: ");
    mostrarAdyacentes(G1,2);
    
    eliminarArista( &G1, 1, 3); 
    eliminarArista( &G1, 2, 3);
	eliminarVertice( &G1,3 );
    mostrarListaVertices(G1);
    
    return 0;
}
