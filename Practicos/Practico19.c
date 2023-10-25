#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxF 12
#define MaxC 31

typedef struct {
  int lluv[MaxF][MaxC];
  int cantF;
  int cantC;
} TData;
TData lluvias;
time_t t;

void CargaRandom(TData *k);
void CargarLluvias(TData *k);
void MaximaPrecipitacion(TData k);
void Mostrar(TData k);

int main() {
  CargaRandom(&lluvias);
  Mostrar(lluvias);
  MaximaPrecipitacion(lluvias);
  return 0;
}

void CargaRandom(TData *k) {
  srand((unsigned) time(&t));
  k->cantF = MaxF;
  k->cantC = MaxC;
  for(int i = 0; i < k->cantF; i++) {
    for(int j = 0; j < k->cantC; j++) {
      k->lluv[i][j] = rand()%1000;
    }
  }
}

void CargarLluvias(TData *k) {
  k->cantF = MaxF;
  k->cantC = MaxC;
  for(int i = 0; i < k->cantF; i++) {
    for(int j = 0; j < k->cantC; j++) {
      scanf("%d", &(k->lluv[i][j]));
    }
  }
}

void Mostrar(TData k) {
  for(int i = 0; i < k.cantF; i++) {
    for(int j = 0; j < k.cantC; j++) {
      printf("%d ", k.lluv[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void MaximaPrecipitacion(TData k) {
  if(k.cantF != 0 && k.cantC != 0) {
    int max = k.lluv[0][0];
    int mes = 1;
    int dia = 1;
    
    for(int i = 0; i < k.cantF; i++) {
      for(int j = 0; j < k.cantC; j++) {
        if(k.lluv[i][j] > max) {
          max = k.lluv[i][j];
          mes = i +1;
          dia = j +1;
        }
      }
    }
    
    printf("Maxima precipitacion: %d, Dia: %d, Mes: %d\n", max, dia, mes);
  }
}
