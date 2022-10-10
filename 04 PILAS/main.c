/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 3 de septiembre de 2022, 19:33
 */

#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
#include "pilas.h"

int main(int argc, char** argv) {
    Pila pila;
    construirPila(&pila);
    
    apilar(&pila, 2);
    mostrar(pila);
    apilar(&pila, 10);
    mostrar(pila);
    
    ElementoPila el;
    el = desapilar(&pila);
    printf("%d\n", el);
    mostrar(pila);
    return (EXIT_SUCCESS);
}

