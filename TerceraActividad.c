#include <math.h>
#include <stdio.h>
#include <string.h>
int n;  // dato
bool esPrimo; //variable intermedia
int sqrtN; //variable intermedia
int i; //contador
char primo;  // resultado
int main()
{
    printf("\n Ingrese un numero: ");
    scanf("%i", &n);
    esPrimo = true;
    if(n%2 == 0) {
        esPrimo = false;
    }
    
    sqrtN = (int)sqrt(n);
    i = 1;
    while(esPrimo && i <= sqrtN) {
        i += 2;
        if(n%i == 0) {
            esPrimo = false;
        }
    }
    
    return 0;
}
