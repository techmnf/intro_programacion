#include<stdio.h>

#define MaxF 20
#define MaxC 20

typedef struct {
  int mat[MaxF][MaxC];
  int cantC;
  int cantF;
} TData;

TData data;

void Cargar(TData *k);
void Mostrar();
int Bordes(TData k);

int main() {
  return 0;
}

void Cargar(TData *k) {
  int i;
  int j;
  
  scanf("%i", &(k->cantC));
  scanf("%i", &(k->cantF));
  
  for(i = 0; i < k->cantF; i++) {
    for(j = 0; j < k->cantC; j++) {
      scanf("%i", &(k->mat[i][j]));
    }
  }
}

void Mostrar() {
  int i;
  int j;
  
  for(i = 0; i < k->cantF; i++) {
    for(j = 0; j < k->cantC; j++) {
      printf("%i", k->mat[i][j]);
    }
  }
}

int Bordes(TData k) {
  int i;
  int j;
  int sumBar = 0;
  int sumInt = 0;
  
  for(i = 0; i < k->cantF; i++) {
    for(j = 0; j < k->cantC; j++) {
      if(i == 0 || i == k.cantF || j == 0 || j == k.cantC) {
        sumBar += k.mat[i][j];
      }
      else {
        sumInt += k.mat[i][j];
      }
    }
  }
  
  return sumBar == sumInt;
}
