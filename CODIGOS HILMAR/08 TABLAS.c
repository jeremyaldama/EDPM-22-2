//typedef int ElementoArbol;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem 
{
    char *llave;
    char *dato;
} ElementoArbol;

typedef struct nodo
{
    struct nodo *hizq;
    ElementoArbol elemento;
    struct nodo *hder;
} Nodo;

typedef Nodo* ArbolBinario;

typedef ArbolBinario ArbolBinarioBusqueda;

typedef ArbolBinarioBusqueda Tabla;

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
        printf("%s ", AB->elemento.llave ); 
        recorrerEnOrden ( ABD );
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
            if( strcmp(elemento.llave, (p->elemento).llave ) == -1 )
                p = p->hizq;
            else
                p = p->hder;
        }
        if ( strcmp(elemento.llave, (padre->elemento).llave ) == -1 )
            plantar(&padre->hizq, NULL, elemento, NULL);
        else
            plantar(&padre->hder, NULL, elemento, NULL);
    }
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
        if ( strcmp((*pABB)->elemento.llave, elemento.llave ) == 0 )
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
            if ( strcmp(elemento.llave , (*pABB)->elemento.llave ) == -1 )
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

//****************************************tablas*************************

void construirTabla(Tabla *pT)
{
	construirArbol(pT);
}

void destruirTabla(Tabla *pT)
{
	destruir(pT);
}

Nodo* buscar(ArbolBinarioBusqueda ABB, char *llave)
{
	if (esArbolVacio(ABB))
		return NULL;
	else
	{
		if (strcmp(ABB->elemento.llave, llave)==0)
			return ABB;
		else if (strcmp(ABB->elemento.llave, llave) == 1 )
			return buscar(ABB->hizq, llave);
		else
			return buscar(ABB->hder, llave);	
	}
}

void registrarEntrada(Tabla *pT, char *llave, char *dato)
{
	ElementoArbol entrada;
	Nodo *pNodoEntrada;
	
	entrada.llave=strdup(llave);
	if (dato != NULL)
		entrada.dato = strdup(dato);
	else
		entrada.dato = NULL;
	
	pNodoEntrada = buscar(*pT, llave);
	if ( pNodoEntrada == NULL )
		insertar(pT, entrada);
	else
	{
		if ( pNodoEntrada->elemento.llave != NULL )
			free( pNodoEntrada->elemento.llave );
		if ( pNodoEntrada->elemento.dato != NULL )
			free( pNodoEntrada->elemento.dato );
		pNodoEntrada->elemento = entrada;
	}
}

int llaveTieneDato(Tabla T, char *llave)
{
	Nodo *pNodoEntrada;
	pNodoEntrada = buscar(T, llave);
	if ( pNodoEntrada == NULL )
		return 0;
	else
		return pNodoEntrada->elemento.dato != NULL;
}

char *datoLlave(Tabla T, char *llave)
{
	Nodo *pNodoEntrada;
	pNodoEntrada = buscar(T, llave);
	if ( pNodoEntrada == NULL )
		return NULL;
	else
		return pNodoEntrada->elemento.dato;
}

void eliminarEntrada(Tabla *T, char *llave)
{
	ElementoArbol entrada;
	entrada.llave=llave;
	entrada.dato=NULL;
	eliminar(T, entrada);
}

int esTablaVacia(Tabla T)
{
	return esArbolVacio(T);
}

int main() 
{
    Tabla tabla;
    int x;
    char *v;
    
    construirTabla(&tabla);

    registrarEntrada(&tabla, "Peru", "Lima");
    registrarEntrada(&tabla, "Brasil", NULL);
    registrarEntrada(&tabla, "Uruguay", "Montevideo");
    registrarEntrada(&tabla, "Argentina", "Buenos Aires");
    registrarEntrada(&tabla, "Venezuela", "Caracas");
    registrarEntrada(&tabla, "Colombia", "Bogota");
    registrarEntrada(&tabla, "Ecuador", "Quito");
    registrarEntrada(&tabla, "Paraguay", "Asuncion");
    registrarEntrada(&tabla, "Chile", "Santiago");
    registrarEntrada(&tabla, "Bolivia", "La Paz");
    registrarEntrada(&tabla, "Peru", "Callao");
    recorrerEnOrden(tabla); putchar('\n');
    
    x = llaveTieneDato(tabla, "Uruguay");
	printf("Uruguay tiene dato: %d\n",x);

	x = llaveTieneDato(tabla, "Brasil");
	printf("Brasil tiene dato: %d\n",x);
	
	v = datoLlave( tabla, "Peru");
	printf("la capital de Peru es %s\n",v);
	
    eliminarEntrada(&tabla, "Peru");
	recorrerEnOrden(tabla); putchar('\n');

    destruirTabla(&tabla);
    x = esTablaVacia(tabla);
    printf("Es tabla vacia: %d\n",x);
    
    return 0;
}

