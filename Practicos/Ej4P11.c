/**************************************************
Nombre y Apellido: Lautaro Dovis
DNI: 44295171
Implementacion del ejercicio 4 de la practica 11.
**************************************************/

#include <stdio.h>


char c, x;
int iguales, distintos;
FILE* f;

void cargarArchivo (char nomExt[]);

int main( ) {
 cargarArchivo("secu.txt");
 iguales = 0;
 distintos = -1;
 getchar();
 printf("Ingrese el caracter del cual quiere ver cuantos caracteres distintos e iguales tiene: ");
 scanf("%c", &c);
 f= fopen("secu.txt", "r");
 while (!(feof(f))){
    x=fgetc(f);
    if(c==x){
      iguales++;
    }
    else{
      distintos++;
    }
 }
 fclose(f);
 printf("La cantidad de caracteres iguales a '%c' es: %d", c, iguales);
 printf("\nLa cantidad de caracteres distintos a '%c' es: %d\n", c, distintos);
 return 0;
 }

void cargarArchivo (char nomExt[]){
  char c;
  FILE* f;
  printf("\nIngrese un caracter o un * en caso de querer terminar: ");
  scanf("%c", &x);
  f= fopen("secu.txt", "w");
  while ( x != '*') {
    getchar();
    fputc(x,f);
    printf("Ingrese un caracter o un * en caso de querer terminar: ");
    scanf("%c", &x);
  }
  fclose(f);
}
  /*Los getchar() se pueden reemplazar de la siguiente forma:
    printf("mensaje: ");
    scanf("%c", &x); while(getchar()!='\n');
    scanf("%d", &y); while (getchar(!='\n');
  
  */

