#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct {
  char apellido[MAX];
  char nombre[MAX];
  int sueldo;
} TEmpleado;
typedef struct {
  TEmpleado emp[MAX];
  int cant;
} TData;

TData empleado;

void CargarListaEmpleado(TData *e);
void Insercion(TData *e);
void MostrarLista(TData e);

int main() {
  CargarListaEmpleado(&empleado);
  Insercion(&empleado);
  MostrarLista(empleado);
  return 0;
}

void CargarListaEmpleado(TData *e) {
  int c, z;
  printf("Ingrese cantidad de nombres a cargar: ");
  scanf("%i", &c);
  printf("\n");
  if(c > 0) {
    for(int i = 0; i < c; i++) {
      printf("Ingrese el nombre: ");
      scanf("%s", (e->emp[i].nombre));
      
      printf("Ingrese el apellido: ");
      scanf("%s", (e->emp[i].apellido));
      
      printf("Ingrese el sueldo: ");
      scanf("%i", &(e->emp[i].sueldo));
      
      printf("\n");
    }
    
    e->cant = c;
  }
  else {
    printf("No se han cargado datos");
  }
}

void Insercion(TData *e) {
  int i = 0;
  TEmpleado aux;
  while(i < e->cant) {
    aux = e->emp[i];
    int j = i -1;
    
    while((j >= 0) && (e->emp[j].sueldo < aux.sueldo)) {
      e->emp[j+1] = e->emp[j];
      j--;
    }
    e->emp[j +1] = aux;
    
    i++;
  }
}

void MostrarLista(TData e) {
  int i = 0;
  while(i < e.cant) {
    printf(
      "Empleado %i: %s, %s: %i\n",
      i +1,
      e.emp[i].apellido,
      e.emp[i].nombre,
      e.emp[i].sueldo
    );
    i++;
  }
}
