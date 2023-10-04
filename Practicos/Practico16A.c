#include<stdio.h>

int num;
int SumatoriaAumento(int n);

int main() {
  printf("Ingrese un valor para ver la sumatoria desde 1 al numero dado, el numero debe ser natural: ");
  scanf("%i", &num);
  
  printf("Sumatoria con aumento: %i\n", SumatoriaAumento(num));
  
  return 0;
}

int SumatoriaAumento(int n) {
  if(n == 1) {
    return 1;
  }
  else {
    return n + SumatoriaAumento(n-1);
  }
}
