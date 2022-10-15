/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 6 de septiembre de 2022, 18:52
 */

#include <stdio.h>
#include <stdlib.h>

#include "ab.h"

int main(int argc, char** argv) {
    ArbolBinario arbol, arbolIzq, arbolDer, arbolIzq2, arbolDer2, arbolIzq3, arbolDer3;
    construirArbolBinario(&arbol);
    construirArbolBinario(&arbolDer);
    construirArbolBinario(&arbolIzq);
    construirArbolBinario(&arbolIzq2);
    construirArbolBinario(&arbolIzq3);
    construirArbolBinario(&arbolDer2);
    construirArbolBinario(&arbolDer3);
    
    plantarArbolBinario(&arbol, arbolIzq, 20, arbolDer);
    plantarArbolBinario(&arbolIzq2, NULL, 50, NULL);
    plantarArbolBinario(&arbolDer2, NULL, 100, NULL);
    plantarArbolBinario(&arbol->hijoIzq, arbolIzq2, 10, arbolDer2);
    plantarArbolBinario(&arbol->hijoDer, arbolIzq3, 30, arbolDer3);
    
    recorridoPorNivel(arbol);
    printf("\n");
    //enOrden(arbol);
    printf("\n");
    //postOrden(arbol);
    printf("\n");
    preOrden(arbol);
    int alt;
    alt = altura(arbol);
    printf("\n%d\n", alt);
    preOrdenIterativo(arbol);
    return (EXIT_SUCCESS);
}

