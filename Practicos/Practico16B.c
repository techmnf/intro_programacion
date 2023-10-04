#include<stdio.h>

int num;
int ProductoriaAumento(int n);

int main() {
  printf("Ingrese un valor para ver la productoria desde 1 al numero dado, el numero debe ser natural: ");
  scanf("%i", &num);
  
  printf("Productoria con aumento: %i\n", ProductoriaAumento(num));
  
  return 0;
}

int ProductoriaAumento(int n) {
  if(n == 1) {
    return 1;
  }
  else {
    return n + ProductoriaAumento(n-1);
  }
}
