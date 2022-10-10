/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 30 de agosto de 2022, 23:47
 */

#include <stdio.h>
#include <stdlib.h>
#include "lce.h"

int main(int argc, char** argv) {
    Lista listaC;
    construir_lista(&listaC);
    
    insertarAlFinal(&listaC, 20);
    insertarAlFinal(&listaC, 30);
    insertarAlFinal(&listaC, 40);
    imprime(listaC);
    
/*
    Nodo*buscar;
    buscar = obtenerNodo(listaC, 10);
    printf("%d\n", buscar->sig->elemento);
*/
    Nodo*ant;
    ant = obtener_nodo_anterior(listaC, 30);
    printf("%d\n", ant->elemento);
    
    eliminarNodo(&listaC, 40);
    imprime(listaC);
    return (EXIT_SUCCESS);
}

