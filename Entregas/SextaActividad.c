/*
////////////////////////////////////////////////////////////////
//////////////////  Ejercicio 13, Guia 7  //////////////////////
////////////////  Fernandez Matias Nicolas  ////////////////////
////////////////////////////////////////////////////////////////
*/

#include <stdio.h>

int numero = 5;
int cant = 10;
int arregloEntero[] = {0,1,2,3,4,5,6,7,8,9};

void guardarNumero(int nuevoNumero, int (*arregloEntero)[], int *cant) {
    int a = 0;
    int yaIncluido = 0;

    for (int i = 0; i < *cant; i++) {
        if(yaIncluido == 0 && nuevoNumero <= (*arregloEntero)[i]) {
            yaIncluido = 1;
            a = (*arregloEntero)[i];
            (*arregloEntero)[i] = nuevoNumero;
            (*cant)++;
        }
        else if(yaIncluido == 1) {
            a = a + (*arregloEntero)[i];
           (*arregloEntero)[i] = a - (*arregloEntero)[i];
            a = a - (*arregloEntero)[i];
        }
    }
    
}

//Ejemplo de uso
int main() {
    for (int i = 0; i < cant; i++)
    {
        printf("%i", arregloEntero[i]);
    }

    printf("\n");
    guardarNumero(numero, &arregloEntero, &cant);

    for (int i = 0; i < cant; i++)
    {
        printf("%i", arregloEntero[i]);
    }
    return 0;
    
}