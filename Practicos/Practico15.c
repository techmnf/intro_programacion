#include<stdio.h>
#include<string.h>

void Cargar();
void Compara();

int main() {
  Cargar();
  Compara();
  return 0;
}

void Cargar() {
  FILE* f = fopen("secu.txt", "w");
  char car;
  if(f != NULL) {
    printf("Ingrese un caracter o *: ");
    scanf("%c", &car);
    while(car!='*') {
      fputc(car, f);
      printf("Ingrese un caracter o *: ");
      scanf("%c", &car);
    }
    
    fclose(f);
  }
}

void Compara() {
  FILE* f = fopen("secu.txt", "r");
  char c;
  char c2;
  int iguales = 0;
  int distintos = 0;
  
  if(f != NULL) {
    printf("Escriba una letra para comparar: ");
    scanf("%c", &c);
    while(!feof(f)) {
      c2 = fgetc(f);
      //printf("%c \n", c2);
      if(c == c2) {
        iguales++;
      }
      else {
        distintos++;
      }
     }
    
    printf(
      "El caracter escrito es: %c, los caracteres iguales son: %d, y distintos son: %d \n",
      c,
      iguales, 
      distintos
    );
    
    fclose(f);
  }
}
