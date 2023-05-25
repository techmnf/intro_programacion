#include<stdio.h>
#include<math.h>

float a,b,c,d,e,f;
float mayorNum;
float Mayor(float x, float y);

int main() {
  printf("Introduzca 6 numeros para calcular cual es el mayor de todos\n");
  
  printf("Introduzca el primer numero: ");
  scanf("%f", &a);
  printf("Introduzca el segundo numero: ");
  scanf("%f", &b);
  printf("Introduzca el tercer numero: ");
  scanf("%f", &c);
  printf("Introduzca el cuarto numero: ");
  scanf("%f", &d);
  printf("Introduzca el quinto numero: ");
  scanf("%f", &e);
  printf("Introduzca el sexto numero: ");
  scanf("%f", &f);
  
  mayorNum = Mayor(
    Mayor(
      Mayor(a,b),
      Mayor(c,d)
    ),
    Mayor(e,f)
  );
  printf("El numero mayor es: ");
  printf("%f", mayorNum);
  printf("\n");
  
  return 0;
}

float Mayor(float x, float y) {
  return((x+y)+fabs(x-y))/2;
}
