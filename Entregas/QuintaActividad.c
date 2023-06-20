/*
////////////////////////////////////////////////////////////////
//////////////////  Ejercicio 11, Guia 6  //////////////////////
////////////////  Fernandez Matias Nicolas  ////////////////////
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
//////¿Por qué el último prinf muestra ese valor de a?//////////
////////////////////////////////////////////////////////////////
    Por que cuando se llama a la acción "Swap", se pasa
    el mismo puntero en ambos parametros, por lo que estas
    variables cuando modifican en realidad estan actuando
    sobre la misma posicion de memoria.
    
    Por lo que cuando se suman "a" y "b" para luego almacenar 
    en "a", en realidad se esta sumando la misma posicion
    de memoria y almacenandose sobre la misma, al restar, se resta
    de igual modo, esto es como hacer "a=a-a", por esta razon
    da 0

    En la línea Swap(&a, &a);, se pasa la dirección de memoria
    de a dos veces como argumentos. Dentro de la función Swap,
    los punteros x y y apuntan a la misma dirección de memoria.
    Como resultado, las operaciones aritméticas que se realizan
    para intercambiar los valores no funcionan correctamente.

    La línea *x = (*x) + (*y); suma el valor en la dirección de
    memoria apuntada por x (es decir, a) con el valor en la dirección
    de memoria apuntada por y (también a). Entonces, *x ahora contiene
    el doble del valor original de a.

    Luego, la línea *y = (*x) - (*y); resta el valor en la dirección de
    memoria apuntada por x (que ahora es el doble del valor original de a)
    del valor en la dirección de memoria apuntada por y (también el doble
    del valor original de a). La resta de dos veces el valor original de a
    da como resultado 0, y ese valor se guarda en la dirección de memoria
    apuntada por y (es decir, a).

    En resumen: dentro de la función Swap, se realizan operaciones aritméticas
    para intercambiar los valores en las direcciones de memoria apuntadas por
    x y y. Sin embargo, dado que x y y apuntan a la misma dirección de memoria
    (la dirección de a), todas las operaciones aritméticas se realizan en la
    misma ubicación de memoria. Como resultado, el valor de a se modifica y se
    guarda en sí mismo.
    
*/

#include <stdio.h>
int a, b;

void Swap(int *x, int *y) {
    *x = (*x) + (*y);
    *y = (*x) - (*y);
    *x = (*x) - (*y);
}

int main() {
    printf("introduce el valor de la variable a ");
    scanf("%i", &a);
    printf("introduce el valor de la variable b ");
    scanf("%i", &b);
    Swap(&a, &b);
    printf("el valor de a es %d ", a);
    printf("el valor de b es %d ", b);
    printf("\n introduce el valor de la variable a ");
    scanf("%i", &a);
    printf("introduce el valor de la variable b ");
    scanf("%i", &b);
    Swap(&a, &a);
    printf("el valor de a es %d ", a);
    return 0;
}