#include <math.h>
#include <stdio.h>
#include <string.h>
int n;  // dato
int esPrimo; //variable intermedia
int sqrtN; //variable intermedia
int i; //contador
char primo[11];  // resultado
int main()
{
    printf("\n Ingrese un numero: ");
    scanf("%i", &n);
    esPrimo = 1;
    if(n%2 == 0 && n != 2) {
        esPrimo = 0;
    }
    
    sqrtN = (int)sqrt(n);
    i = 1;
    while(esPrimo == 1 && i <= sqrtN) {
        i += 2;
        if(n%i == 0) {
            esPrimo = 0;
        }
    }
    
    if(esPrimo == 1) {
        strcpy(primo, "Es primo");
    }
    else {
        strcpy(primo, "No es primo");
    }
    
    printf("%s", primo);
    
    return 0;
}
