/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 3 de septiembre de 2022, 19:48
 */

#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

int main(int argc, char** argv) {
    Cola cola;
    construirCola(&cola);
    
    encolar(&cola, 3);
    encolar(&cola, 5);
    encolar(&cola, 7);
    encolar(&cola, 9);
    encolar(&cola, 1);
    imprimir(cola);
    
    desencolar(&cola);
    imprimir(cola);
    return (EXIT_SUCCESS);
}

