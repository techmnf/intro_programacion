#include<stdio.h>

char elementoActual, elementoDato;
FILE* f;
int i, iguales, distintos;

void CargarArchivo(FILE *g);

int main() {
  CargarArchivo(f);
  f = fopen("test.txt", "r");
  
  iguales = 0;
  distintos = 0;
  
  printf("Ingrese el Caracter a buscar cuantos iguales y distintos hay: ");
  scanf("%c", &elementoDato);
  getchar();
  printf("%c", elementoDato);
  if (f != NULL) {
    while((elementoActual = fgetc(f)) != EOF) {
    //while(!feof(f)) {
      //elementoActual = fgetc(f);
      if(elementoActual == elementoDato) {
        iguales++;
      }
      else {
        distintos++;
      }
    }
  }
  
  fclose(f);
  printf("Cantidad de elementos iguales: %i.\nCantidad de elementos distintos: %i.\n", iguales, distintos);
  
  return 0;
}

void CargarArchivo(FILE *g) {
    int cantidadElementos;
    char elem;

    g = fopen("test.txt", "w");
    printf("Ingrese cuantos elementos desea cargar en el archivo: ");
    scanf("%d", &cantidadElementos);
    getchar();
    if (g != NULL) {
        for (int i = 0; i < cantidadElementos; i++) {
            printf("Ingrese un caracter: ");
            scanf("%c", &elem);
            getchar();
            fprintf(g, "%c", elem);
            //fputc(elem, g);
        }
        fclose(g);
        printf("\n");
    }
}
