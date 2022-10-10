/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 30 de agosto de 2022, 22:32
 */

#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

int main(int argc, char** argv) {
    Lista listaD;
    construir_lista(&listaD);
    
    insertarAlInicio(&listaD, 10);
    insertarAlInicio(&listaD, 12);
    insertarAlInicio(&listaD, 14);
    insertarAlInicio(&listaD, 16);
    
    insertarAlFinal(&listaD, 20);
    
    
    imprime(listaD);
    
    eliminarNodo(&listaD, 14);
    imprime(listaD);
    
    eliminarNodo(&listaD, 20);
    imprime(listaD);
    
    destruir_lista(&listaD);
    imprime(listaD);
    return (EXIT_SUCCESS);
}

