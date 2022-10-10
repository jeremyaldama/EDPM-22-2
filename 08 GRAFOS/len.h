#ifndef LEN_H
#define LEN_H

typedef int ElementoListaEntero;

typedef struct nodoListaEntero {
    ElementoListaEntero elemento;    
    struct nodoListaEntero *sig;
} NodoListaEntero;

typedef struct {
    int longitud;
    NodoListaEntero *cabeza;
} ListaEntero;

void construir_lista_entero(ListaEntero *);
int es_lista_de_enteros_vacia(ListaEntero);
NodoListaEntero *crear_nuevo_nodo_entero(ElementoListaEntero, NodoListaEntero *);
NodoListaEntero *obtener_ultimo_nodo_entero(ListaEntero);
void insertar_entero_al_inicio(ListaEntero *, ElementoListaEntero);
void insertar_entero_al_final(ListaEntero *, ElementoListaEntero);
int longitud_lista_enteros(ListaEntero);
void imprime_lista_enteros(ListaEntero);
int se_encuentra_entero(ListaEntero, ElementoListaEntero);
ElementoListaEntero retorna_cabeza_entero(ListaEntero);
void elimina_cabeza_entero(ListaEntero *);
void elimina_nodo_entero(ListaEntero *, ElementoListaEntero);
void destruir_lista_entero(ListaEntero *);

#endif