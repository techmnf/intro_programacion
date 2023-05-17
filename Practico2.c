#include <math.h>
#include <stdio.h>
#include <string.h>

int num;
int cont = 0;
int i = 2;
char msg[20];

int main() {
  printf("\n Ingrese un numero: ");
  scanf("%i", &num);
  
  if(num <= 1) {
    cont += 1;
  }
  else {
    while(i <= sqrt(num)) {
      if((num % i) == 0) {
        cont++;
      }
      
      i++;
    }
  }
  
  if(cont == 0) {
    strcpy(msg, "Es primo\n");
  }
  else {
    strcpy(msg, "No es primo\n");
  }
  
  printf("%s", msg);
  
  return 0;
}
