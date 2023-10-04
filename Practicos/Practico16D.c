#include<stdio.h>

int num;
int Fibonacci(int n);

int main() {
  do {
    printf("Ingrese que número de la serie fibonacci quiere saber: ");
    scanf("%i", &num);
  } while(num <= 0);
  
  printf("%i\n", Fibonacci(num));
  return 0;
}

int Fibonacci(int n) {
  if(n == 1 || n == 2) {
    return 1;
  }
  else {
    return Fibonacci(n -1) + Fibonacci(n -2);
  }
}
