#include<stdio.h>
#include<string.h>

#define MAX 50
#define MaxCaracteres 100

typedef struct{
  char b[MAX][MaxCaracteres];
  int cant;
} TData;

TData cad;
int op;

void CargarArreglo(TData *c);
void MostrarArreglo(TData c);

void Burbuja(TData *c);
void Seleccion(TData *c);
void Insercion(TData *c);
void QuickSort(TData *c, int izq, int der);

int main() {
  CargarArreglo(&cad);
  MostrarArreglo(cad);
  
  printf("~ Ingrese el tipo de ordenamiento que quiera usar ~ ");
  
  scanf("%i", &op);
  if(op == 1) {
    Burbuja(&cad);
    printf("~ ~ ~ Datos ordenados por el metodo Burbuja~ ~ ~\n");
    MostrarArreglo(cad);
  } 
  
  else if(op == 2) {
    Seleccion(&cad);
    printf("~ ~ ~ Datos ordenados por el metodo Seleccion ~ ~ ~\n");
    MostrarArreglo(cad);
  } 
  
  else if(op == 3) {
    Insercion(&cad);
    printf("~ ~ ~ Datos ordenados por el metodo Insercion ~ ~ ~\n");
    MostrarArreglo(cad);
  } 
  
  else if(op == 4) {
    QuickSort(&cad, 0, cad.cant-1);
    printf("~ ~ ~ Datos ordenados por el metodo Quicksort ~ ~ ~\n");
    MostrarArreglo(cad);
  } 
  
  else {
    printf("Ingrese una opcion valida entre 1 y 4\n");
  }
  
  return 0;
}

void CargarArreglo(TData *c) {
  int i = 0;
  int cant = 0;
  
  printf("Ingrese la cantidad de elementos que desea cargar: ");
  
  scanf("%i", &cant);
  while(i < cant) {
    printf("Nombre: ");
    scanf("%s", c->b[i]);
    i++;
  }
  
  c->cant = cant;
}

void MostrarArreglo(TData c) {
  int i = 0;
  while(i < c.cant) {
    printf("%s\n", c.b[i]);
    i++;
  }
}

void Burbuja(TData *c) {
  char temp[MaxCaracteres];
  for(int i = c->cant-1 ; i > 0 ; i--){
    for(int j = 0 ; j < i ; j++){
      if(strcmp(c->b[j],c->b[j+1]) > 0 ){
        strcpy(temp, c->b[j]);
        strcpy(c->b[j], c->b[j+1]);
        strcpy(c->b[j+1], temp);
      }
    }
  }
}

void Seleccion(TData *c) {
  int i = 0;
  int min;
  char temp[MaxCaracteres];
  
  while(i < c->cant) {
    int j = i;
    min = i;
    
    while(j < c->cant) {
      if(strcmp(c->b[j], c->b[min]) > 0){
        min = j;
      }
      j++;
    }
    
    strcpy(temp, c->b[i]);
    strcpy(c->b[i], c->b[min]);
    strcpy(c->b[min], temp);
    
    i++;
  }
}

void Insercion(TData *c) { 
  int i = 1;
  char aux[MaxCaracteres];
  
  while(i < c->cant) {
    strcpy(aux, c->b[i]);
    int j = i -1;
    
    while((j >= 0) && (strcmp(c->b[j], aux) > 0)) {
      strcpy(c->b[j+1], c->b[j]);
      j--;
    }
    strcpy(c->b[j+1], aux);
    i++;
  }
}

void QuickSort(TData *c, int izq, int der) {
  int i = izq;
  int j = der;
  char p[MaxCaracteres];
  char y[MaxCaracteres];
  
  strcpy(p, c->b[(izq + der)/2]);
  
  do {
    while((strcmp(c->b[i], p) < 0) && (j <= der)) {
      i++;
    }
    
    while((strcmp(c->b[j], p) > 0) && (j > izq)) {
      j--;
    }
    
    if(i <= j) {
      strcpy(y, c->b[i]);
      strcpy(c->b[i], c->b[j]);
      strcpy(c->b[j], y);
      
      i++;
      j--;
    }
  } while(i <= j);
  
  if(izq < j) {
    QuickSort(c, izq, j);
  }
  
  if(i < der) {
    QuickSort(c, i, der);
  }
}
