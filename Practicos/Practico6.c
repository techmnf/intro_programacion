#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 30

typedef struct {
  int a[Max];
  int cant;
} TData;
TData numeros;

time_t t;

void sortear(TData *nums);
void informar(TData nums);

int main() {
  sortear(&numeros);
  informar(numeros);
  return 0;
}

void sortear(TData *nums) {
  int i;
  srand((unsigned) time(&t));
  
  do {
    printf("Ingrese la cantidad de numeros para sortear (no puede ser mayor a %i):", Max);
    scanf("%i", &nums->cant);
    printf("\n");
  } while(nums->cant > Max);
  
  for(i = 0; i <= nums->cant; i++) {
    nums->a[i] = rand()%1000;
  }
}

void informar(TData nums) {
  int i;
  for(i = 0; i < nums.cant; i++) {
    printf("El numero %i, es: %i\n", (i+1), nums.a[i]);
  }
}
