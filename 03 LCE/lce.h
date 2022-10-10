#ifndef LCE_H
#define LCE_H

typedef int ElementoLista;

typedef struct nodo {
    ElementoLista elemento;    
    struct nodo *sig;
} Nodo;

typedef struct {
    int longitud;
    Nodo *cabeza;
} Lista;

void construir_lista(Lista *tad);
int es_lista_vacia(Lista tad);
Nodo *crear_nuevo_nodo(ElementoLista elemento, Nodo* sig);
Nodo *obtener_ultimo_nodo(Lista tad);
Nodo *obtener_nodo_anterior(Lista, ElementoLista);
void insertar_al_inicio(Lista *tad, ElementoLista elemento);
void insertar_en_orden(Lista *tad, ElementoLista elemento);
int longitud(Lista tad);
void imprime(Lista tad);
Nodo* se_encuentra(Lista tad, ElementoLista llave);
void destruir_lista(Lista *tad);
void insertarAlFinal(Lista *pL, ElementoLista elemento);
Nodo* obtenerNodo(Lista l, ElementoLista valor);
void eliminarNodo(Lista*pL, ElementoLista valor);
//tarea

//void elimina_nodo(Lista *tad, ElementoLista elemento);
#endif