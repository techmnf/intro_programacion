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
  /*char palabra[Max];
  int i;
  
  scanf("%s", &palabra);
  frase->cant = strlen(palabra);
  for(i = 0; i < frase->cant; i++) {
    frase->a[i] = palabra[i];
  }*/
  
  scanf("%i", &(frase->cant));
  for(int i = 0; i < frase->cant; i++) {
    scanf("%c", &(frase->a[i]));
  }
}

int esCapicua(TData frase) {
  int i = 0;
  while((i < frase.cant) && (frase.a[i] == frase.a[frase.cant-i-1])) {
    i++;
  }
  
  if(i > frase.cant/2) {
    return 1;
  }
  else {
    return 0;
  }
}
    
