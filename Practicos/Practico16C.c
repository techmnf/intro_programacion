#include<stdio.h>

int num, resultado;
int FactorialAumento(int n);
void FactorialCola(int n, int *res);
void Menu();

int main() {
  Menu();
  return 0;
}

int FactorialAumento(int n) {
  if(n == 0) {
    return 1;
  }
  else {
    return n * FactorialAumento(n-1);
  }
}

void FactorialCola(int n, int *res) {
  if(n == 0) {
    *res = 1;
  }
  else if(n == 1) {
    *res = (*res) * 1;
  }
  else {
    *res = (*res) * (n);
    FactorialCola(n -1, res);
  }
}

void Menu() {
  printf("Ingrese un valor para ver su factorial en ambas versiones, en caso de ingresar negativo se finaliza el programa: ");
  scanf("%i", &num);
  
  while (num >= 0) {
    resultado = 1;
    
    printf("Factorial con aumento: %d\n", FactorialAumento(num));
    
    FactorialCola(num, &resultado);
    printf("Factorial con cola: %d\n", resultado);
    
    printf("Otro factorial: ");
    scanf("%i", &num);
  }
}
