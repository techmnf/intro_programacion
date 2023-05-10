#include <stdio.h>
#include <string.h>
int n;  // dato
bool esPrimo; //variable intermedia
char primo;  // resultado
int main()
{
    printf("\n Ingrese un numero: ");
    scanf("%i", &n);
    esPrimo = true;
    if(n%2 == 0 && n != 2) {
        esPrimo = false;
    }
    
    while(esPrimo) {
      
    }
    
    return 0;
}
