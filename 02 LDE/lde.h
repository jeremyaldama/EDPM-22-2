#ifndef LDE_H
#define LDE_H

typedef int ElementoLista;

typedef struct nodo {
    ElementoLista elemento;    
    struct nodo *sig, *ant;
} Nodo;

typedef struct {
    int longitud;
    Nodo *cabeza;
} Lista;

void construir_lista(Lista *tad);
int es_lista_vacia(Lista tad);
Nodo *crearNuevoNodo(ElementoLista elemento, Nodo* sig, Nodo* ant);
Nodo *obtener_ultimo_nodo(Lista tad);
void insertarAlInicio(Lista *tad, ElementoLista elemento);

int longitud(Lista tad);
void imprime(Lista tad);
void imprime_desde_el_final(Lista tad);
Nodo* se_encuentra(Lista tad, ElementoLista llave);
void elimina_cabeza(Lista *tad);
void destruir_lista(Lista *tad);
void insertarAlFinal(Lista*tad, ElementoLista elemento);
Nodo *obtenerNodo(Lista tad, ElementoLista elemento);
void eliminarNodo(Lista*tad, ElementoLista elemento);

//tarea
//void insertar_al_final(Lista *tad, ElementoLista elemento);
//void insertar_en_orden(Lista *tad, ElementoLista elemento);
//void elimina_cola(Lista *tad);
//void elimina_nodo(Lista *tad, ElementoLista elemento);

#endif