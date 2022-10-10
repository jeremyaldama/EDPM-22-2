#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "grafos.h"

int main(){
    Grafo tad;
    construir_grafo(&tad);
    assert(es_grafo_vacio(tad));

    anhadir_vertice(&tad, 1);    
    assert(se_encuentra_vertice(tad, 1));
    assert(longitud_grafo(tad)==1);
    anhadir_vertice(&tad, 2);
    assert(se_encuentra_vertice(tad, 2));
    assert(longitud_grafo(tad)==2);
    anhadir_vertice(&tad, 3);
    assert(se_encuentra_vertice(tad, 3));
    assert(longitud_grafo(tad)==3);
    anhadir_vertice(&tad, 4);
    assert(se_encuentra_vertice(tad, 4));
    assert(longitud_grafo(tad)==4);
    anhadir_vertice(&tad, 5);
    assert(se_encuentra_vertice(tad, 5));
    assert(longitud_grafo(tad)==5);

    eliminar_vertice(&tad, 2); 
    assert(longitud_grafo(tad)==4);
    assert(!se_encuentra_vertice(tad, 2));
    assert(longitud_grafo(tad)==4);

    eliminar_vertice(&tad, 5);
    assert(!se_encuentra_vertice(tad, 5));
    assert(longitud_grafo(tad)==3);

    eliminar_vertice(&tad, 4);
    assert(!se_encuentra_vertice(tad, 4));
    assert(longitud_grafo(tad)==2);

    eliminar_vertice(&tad, 1);
    assert(!se_encuentra_vertice(tad, 1));
    assert(longitud_grafo(tad)==1);

    eliminar_vertice(&tad, 3);
    assert(!se_encuentra_vertice(tad, 3));
    assert(longitud_grafo(tad)==0);
    assert(es_grafo_vacio(tad));

    anhadir_vertice(&tad, 1);    
    assert(se_encuentra_vertice(tad, 1));
    assert(longitud_grafo(tad)==1);
    anhadir_vertice(&tad, 2);
    assert(se_encuentra_vertice(tad, 2));
    assert(longitud_grafo(tad)==2);
    anhadir_vertice(&tad, 3);
    assert(se_encuentra_vertice(tad, 3));
    assert(longitud_grafo(tad)==3);
    anhadir_vertice(&tad, 4);
    assert(se_encuentra_vertice(tad, 4));
    assert(longitud_grafo(tad)==4);
    anhadir_vertice(&tad, 5);
    assert(se_encuentra_vertice(tad, 5));
    assert(longitud_grafo(tad)==5);

    anhadir_arista(tad, 1, 2);
    assert(se_encuentra_arista(tad, 1, 2));
    anhadir_arista(tad, 1, 4);
    assert(se_encuentra_arista(tad, 1, 4));
    anhadir_arista(tad, 1, 5);
    assert(se_encuentra_arista(tad, 1, 5));
    anhadir_arista(tad, 2, 3);
    assert(se_encuentra_arista(tad, 2, 3));
    anhadir_arista(tad, 3, 5);
    assert(se_encuentra_arista(tad, 3, 5));
    anhadir_arista(tad, 4, 3);
    assert(se_encuentra_arista(tad, 4, 3));
    anhadir_arista(tad, 4, 5);
    assert(se_encuentra_arista(tad, 4, 5));

    eliminar_arista(tad, 1, 2);
    assert(!se_encuentra_arista(tad, 1, 2));
    eliminar_arista(tad, 1, 4);
    assert(!se_encuentra_arista(tad, 1, 4));
    eliminar_arista(tad, 1, 5);
    assert(!se_encuentra_arista(tad, 1, 5));
    eliminar_arista(tad, 2, 3);
    assert(!se_encuentra_arista(tad, 2, 3));
    eliminar_arista(tad, 3, 5);
    assert(!se_encuentra_arista(tad, 3, 5));
    eliminar_arista(tad, 4, 3);
    assert(!se_encuentra_arista(tad, 4, 3));
    eliminar_arista(tad, 4, 5);
    assert(!se_encuentra_arista(tad, 4, 5));

    anhadir_arista(tad, 1, 2);
    assert(se_encuentra_arista(tad, 1, 2));
    anhadir_arista(tad, 1, 4);
    assert(se_encuentra_arista(tad, 1, 4));
    anhadir_arista(tad, 1, 5);
    assert(se_encuentra_arista(tad, 1, 5));
    anhadir_arista(tad, 2, 3);
    assert(se_encuentra_arista(tad, 2, 3));
    anhadir_arista(tad, 3, 5);
    assert(se_encuentra_arista(tad, 3, 5));
    anhadir_arista(tad, 4, 3);
    assert(se_encuentra_arista(tad, 4, 3));
    anhadir_arista(tad, 4, 5);
    assert(se_encuentra_arista(tad, 4, 5));

    ListaEntero lista_adyacentes=adyacentes(tad, 1);
    assert(!se_encuentra_entero(lista_adyacentes, 1));
    assert(se_encuentra_entero(lista_adyacentes, 2));
    assert(!se_encuentra_entero(lista_adyacentes, 3));
    assert(se_encuentra_entero(lista_adyacentes, 4));
    assert(se_encuentra_entero(lista_adyacentes, 5));
    imprime_lista_enteros(lista_adyacentes);
    destruir_lista_entero(&lista_adyacentes);

    lista_adyacentes=adyacentes(tad, 2);
    assert(!se_encuentra_entero(lista_adyacentes, 1));
    assert(!se_encuentra_entero(lista_adyacentes, 2));
    assert(se_encuentra_entero(lista_adyacentes, 3));
    assert(!se_encuentra_entero(lista_adyacentes, 4));
    assert(!se_encuentra_entero(lista_adyacentes, 5));
    imprime_lista_enteros(lista_adyacentes);
    destruir_lista_entero(&lista_adyacentes);

    lista_adyacentes=adyacentes(tad, 3);
    assert(!se_encuentra_entero(lista_adyacentes, 1));
    assert(!se_encuentra_entero(lista_adyacentes, 2));
    assert(!se_encuentra_entero(lista_adyacentes, 3));
    assert(!se_encuentra_entero(lista_adyacentes, 4));
    assert(se_encuentra_entero(lista_adyacentes, 5));
    imprime_lista_enteros(lista_adyacentes);
    destruir_lista_entero(&lista_adyacentes);

    lista_adyacentes=adyacentes(tad, 4);
    assert(!se_encuentra_entero(lista_adyacentes, 1));
    assert(!se_encuentra_entero(lista_adyacentes, 2));
    assert(se_encuentra_entero(lista_adyacentes, 3));
    assert(!se_encuentra_entero(lista_adyacentes, 4));
    assert(se_encuentra_entero(lista_adyacentes, 5));
    imprime_lista_enteros(lista_adyacentes);
    destruir_lista_entero(&lista_adyacentes);

    lista_adyacentes=adyacentes(tad, 5);
    assert(!se_encuentra_entero(lista_adyacentes, 1));
    assert(!se_encuentra_entero(lista_adyacentes, 2));
    assert(!se_encuentra_entero(lista_adyacentes, 3));
    assert(!se_encuentra_entero(lista_adyacentes, 4));
    assert(!se_encuentra_entero(lista_adyacentes, 5));
    imprime_lista_enteros(lista_adyacentes);
    destruir_lista_entero(&lista_adyacentes);

    destruir_grafo(&tad);

    //grafo para probar el recorrido en profundidad, ejercicio 9.8 del libro EDMAD
    construir_grafo(&tad);
    anhadir_vertice(&tad, 1);    
    anhadir_vertice(&tad, 2);    
    anhadir_vertice(&tad, 3);    
    anhadir_vertice(&tad, 4);    
    anhadir_vertice(&tad, 5);    
    anhadir_vertice(&tad, 6);    
    anhadir_vertice(&tad, 7);    
    anhadir_vertice(&tad, 8);    
    anhadir_vertice(&tad, 9);    
    anhadir_vertice(&tad, 10);    
    anhadir_vertice(&tad, 11);    
    anhadir_vertice(&tad, 12);    

    anhadir_arista(tad, 1, 2);
    anhadir_arista(tad, 1, 3);
    anhadir_arista(tad, 1, 4);
    anhadir_arista(tad, 1, 5);
    anhadir_arista(tad, 1, 6);

    anhadir_arista(tad, 3, 5);

    anhadir_arista(tad, 5, 6);
    anhadir_arista(tad, 5, 7);

    anhadir_arista(tad, 6, 8);

    anhadir_arista(tad, 9, 3);
    anhadir_arista(tad, 9, 10);
    anhadir_arista(tad, 9, 11);

    anhadir_arista(tad, 10, 11);
    anhadir_arista(tad, 10, 12);

    anhadir_arista(tad, 11, 12);

    printf("Recorrido en profundidad recursivo\n");
    printf("Se debe recorrer los vértices:\n\t[1,2,3,5,6,8,7,4]\n");
    printf("Se ha recorrido:\n\t");

    int cantidad_vertices=longitud_grafo(tad);
    int *recorrido=(int*)malloc(cantidad_vertices*sizeof(int));
    int i;
    for(i=0; i<cantidad_vertices; i++)
        recorrido[i]=0;
    int orden_recorrido=0;
    profundidad_recursivo(tad, 1, recorrido, &orden_recorrido);
    
    printf("\n");
    printf("El arreglo recorrido es:\n\t");
    for(i=0; i<cantidad_vertices; i++)
        printf("%d ", recorrido[i]);
    printf("\n");

    printf("\nRecorrido en profundidad iterativo\n");
    printf("Se debe recorrer los vértices:\n\t[1,2,3,5,6,8,7,4]\n");
    printf("Se ha recorrido:\n\t");
        
    profundidad_iterativo(tad, 1, recorrido);
    
    printf("\n");
    printf("El arreglo recorrido es:\n\t");
    for(i=0; i<cantidad_vertices; i++)
        printf("%d ", recorrido[i]);
    printf("\n");

    printf("Recorrido en amplitud iterativa\n");
    printf("Se debe recorrer los vértices:\n\t[1,2,3,4,5,6,7,8]\n");
    printf("Se ha recorrido:\n\t");

    for(i=0; i<cantidad_vertices; i++)
        recorrido[i]=0;
    amplitud_iterativo(tad, 1, recorrido);

    printf("\n");
    printf("El arreglo recorrido es:\n\t");
    for(i=0; i<cantidad_vertices; i++)
        printf("%d ", recorrido[i]);
    printf("\n");

    free(recorrido);
    destruir_grafo(&tad);

    printf("Todas las pruebas se han ejecutado con éxito\n");
    return 0;
}