#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include "pilas.h"
#include "colas.h"

void construir_grafo(Grafo *tad){
	construir_lista_vertice(&tad->lista_vertice);
	tad->longitud=0;
}

void destruir_grafo(Grafo *tad){
	destruir_lista_vertice(&tad->lista_vertice);
	tad->longitud=0;
}

int es_grafo_vacio(Grafo tad){
	return es_lista_vertice_vacia(tad.lista_vertice);
}

int longitud_grafo(Grafo tad){
	return tad.longitud;
}

int se_encuentra_vertice(Grafo tad, Vertice vertice){
	return se_encuentra_vertice_en_lista(tad.lista_vertice, vertice);
}

void anhadir_vertice(Grafo *tad, Vertice vertice){	
	if (!se_encuentra_vertice(*tad, vertice)){		
		insertar_vertice_al_final(&tad->lista_vertice, vertice);
		tad->longitud++;
	}
}

void eliminar_vertice(Grafo *tad, Vertice vertice){
	if (se_encuentra_vertice(*tad, vertice)){	
		eliminar_vertice_en_lista(&tad->lista_vertice, vertice);
		tad->longitud--;	
	}
}

int se_encuentra_arista(Grafo tad, Vertice vertice_origen, Vertice vertice_destino){
	return se_encuentra_arista_en_lista_vertices(tad.lista_vertice, vertice_origen, vertice_destino);
}

void anhadir_arista(Grafo tad, Vertice vertice_origen, Vertice vertice_destino){
	int se_encuentra_vertice_origen=se_encuentra_vertice(tad, vertice_origen);
	int se_encuentra_vertice_destino=se_encuentra_vertice(tad, vertice_destino);
	if (!se_encuentra_vertice_origen || !se_encuentra_vertice_destino){		
        printf("Error al añadir la arista. No se ha encontrado algunas de los siguientes vértices: [%d, %d].\n", vertice_origen, vertice_destino);
        exit(61);
	}
	if (!se_encuentra_arista(tad, vertice_origen, vertice_destino))
		insertar_en_lista_de_aristas(tad.lista_vertice, vertice_origen, vertice_destino);
}

void eliminar_arista(Grafo tad, Vertice vertice_origen, Vertice vertice_destino){
	int se_encuentra_vertice_origen=se_encuentra_vertice(tad, vertice_origen);
	if (se_encuentra_vertice_origen)
		eliminar_de_lista_de_aristas(tad.lista_vertice, vertice_origen, vertice_destino);		
}

ListaEntero adyacentes(Grafo tad, Vertice vertice){
	ListaEntero lista_adyacentes;
	construir_lista_entero(&lista_adyacentes);
	int se_encuentra_vertice_origen=se_encuentra_vertice(tad, vertice);
	if (se_encuentra_vertice_origen)
		obtener_vertices_adyacentes(&lista_adyacentes, tad.lista_vertice, vertice);
	return lista_adyacentes;
}

void profundidad_recursivo(Grafo tad, Vertice vertice_origen, int recorrido[], int *orden_recorrido){
    (*orden_recorrido)++;
    recorrido[vertice_origen-1] = *orden_recorrido;
    printf("%d ", vertice_origen);
    
    ListaEntero lista_adyacentes = adyacentes(tad, vertice_origen);
    while (!es_lista_de_enteros_vacia(lista_adyacentes)){
        Vertice vertice = retorna_cabeza_entero(lista_adyacentes);
        elimina_cabeza_entero(&lista_adyacentes);
        if (recorrido[vertice-1]==0)
            profundidad_recursivo(tad, vertice, recorrido, orden_recorrido);
    }
}

void profundidad_iterativo(Grafo tad, Vertice vertice_origen, int recorrido[]){
    int orden_recorrido = 1, i;
    for (i=0; i<tad.longitud; i++) recorrido[i] = 0;
    Pila pila;
    construir_pila(&pila);
    recorrido[vertice_origen-1] = orden_recorrido;
    printf("%d ", vertice_origen);
    
    ElementoPila elementoPila;
    elementoPila.vertice = vertice_origen;
    elementoPila.lista_adyacentes = adyacentes(tad, vertice_origen);
    apilar(&pila, elementoPila);
    
    while (!es_pila_vacia(pila)){
        elementoPila = desapilar(&pila);
        if (!es_lista_de_enteros_vacia(elementoPila.lista_adyacentes)){
            Vertice vertice = retorna_cabeza_entero(elementoPila.lista_adyacentes);
            elimina_cabeza_entero(&elementoPila.lista_adyacentes);
            apilar(&pila, elementoPila);
            if (recorrido[vertice-1]==0){
                orden_recorrido++;
                recorrido[vertice-1]=orden_recorrido;
                printf("%d ", vertice);
                
                elementoPila.vertice = vertice;
                elementoPila.lista_adyacentes = adyacentes(tad, vertice);
                apilar(&pila, elementoPila);
            }
        }
    }
    destruir_pila(&pila);
}

void amplitud_iterativo(Grafo tad, Vertice vertice_origen, int recorrido[]){
    int orden_recorrido = 1, i;
    for (i=0; i<tad.longitud; i++) recorrido[i] = 0;
    Cola cola;
    construir_cola(&cola);
    recorrido[vertice_origen-1] = orden_recorrido;
    printf("%d ", vertice_origen);
    
    pide_vez(&cola, vertice_origen);
    
    while (!es_cola_vacia(cola)){
        Vertice vertice = avanzar(&cola);
        ListaEntero lista_adyacentes = adyacentes(tad, vertice);
        while (!es_lista_de_enteros_vacia(lista_adyacentes)){
            vertice = retorna_cabeza_entero(lista_adyacentes);
            elimina_cabeza_entero(&lista_adyacentes);
            if (recorrido[vertice-1]==0){
                orden_recorrido++;
                recorrido[vertice-1] = orden_recorrido;
                printf("%d ", vertice);
                pide_vez(&cola, vertice);
            }
        }
    }
    destruir_cola(&cola);
}