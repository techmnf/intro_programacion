#import<stdio.h>
#import<string.h>

//Lexico
int edad; //var para amacenar la edad a almacenar
char madurez[30]; //variable para informar el resultado

int main() {
  printf("Ingrese la edad: ");
  scanf("%i", &edad);
  
  if(0 <= edad && edad <= 11) {
    strcpy(madurez, "el ciudadano es niña/o\n");
  } else if(12 <= edad && edad <= 17) {
    strcpy(madurez, "el ciudadano es adolescente\n");
  } else if(18 <= edad && edad <= 49) {
    strcpy(madurez, "el ciudadano es adulto\n");
  } else if(edad >= 50) {
    strcpy(madurez, "el ciudadano es adulto mayor\n");
  }
  
  printf("%s", madurez);

  return 0;
}
