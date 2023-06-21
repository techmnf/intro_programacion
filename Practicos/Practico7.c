#include<stdio.h>
#include<string.h>
#define Max 81

typedef struct {
  char a[Max];
  int cant;
} TData;

char msg[128];
TData pal;

void cargarPalabra(TData *frase);

int esCapicua(TData frase);

int main() {
  cargarPalabra(&pal);
  
  if(esCapicua(pal) == 1) {
    strcpy(msg, "Esta palabra es palindroma\n");
  }
  else {
    strcpy(msg, "Esta palabra no es palindroma\n");
  }
  
  printf("%s", msg);
}

void cargarPalabra(TData *frase) {
  char palabra[Max];
  
  printf("Ingrese la palabra (o frase sin espacios en blanco y en minuscula): ");
  scanf("%s", palabra);
  printf("\n");
  
  frase->cant = strlen(palabra);
  for(int i = 0; i <= frase->cant; i++) {
    frase->a[i] = palabra[i];
  }
}

int esCapicua(TData frase) {
  int i = 0;
  while((i <= frase.cant) && (frase.a[i] == frase.a[frase.cant-i]) == 0) {
    i++;
  }
  
  if(i > frase.cant/2) {
    return 1;
  }
  else {
    return 0;
  }
}
