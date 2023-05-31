#include<stdio.h>
#include<string.h>

typedef struct {
  float x;
  float y;
} tpunto;

typedef struct {
  float a;
  float b;
} trecta;

tpunto p1;
trecta rec;
char msg[64];

void cargarPunto(tpunto *p) {
  printf("Ingrese coord. x del punto: ");
  //scanf("%f", &(*p.x));
  scanf("%f", &p->x);
  
  printf("Ingrese coord. y del punto: ");
  //scanf("%f", &(*p.y));
  scanf("%f", &p->y);
}

void cargarRecta(trecta *coef) {
  printf("Ingrese coef. a de la recta: ");
  //scanf("%f", &(*coef.a));
  scanf("%f", &coef->a);
  
  printf("Ingrese coef. b de la recta: ");
  //scanf("%f", &(*coef.b));
  scanf("%f", &coef->b);
}

int pertenece(tpunto p, trecta coef) {
  return p.y == p.x*coef.a + coef.b;
}

int main() {
  cargarPunto(&p1);
  cargarRecta(&rec);
  
  if(pertenece(p1, rec) == 1) {
    strcpy(msg, "El punto pertenece a la recta\n");
  }
  else {
    strcpy(msg, "El punto NO pertenece a la recta\n");
  }
  printf("%s", msg);
  
  return 0;
}
