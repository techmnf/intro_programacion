#include<stdio.h>
#define Max 150

typedef struct {
  int d[Max];
  int cant;
} TData;
TData datos;
int i;

int main() {
  i = 0;
  
  printf("Ingrese cantidad de elementos: ");
  scanf("%d", &datos.cant);
  
  while(i < datos.cant) {
    printf("Ingrese el elemento de la posicion %d: ", i+1);
    scanf("%d", &datos.d[i]);
    i = i+1;
  }
  
  i = (datos.cant - 1);
  while(i >= 0) {
    printf("El elemento de la posicion %d tiene el valor: %d\n", i+1, datos.d[i]);
    i = i-1;
  }
  
  return 0;
}
