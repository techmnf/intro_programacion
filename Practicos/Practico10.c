include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define max 20

typedef struct {
  char ape[100];
  int dni;
} TPersona;

typedef struct {
  TPersona pers[max];
  int cant;
} TData;

TData data;
int documento;

void NombreDoc(TData com, int doc);
void Cargar(TData *com);

int main() {
  Cargar(&data);
  printf("Ingrese dni a buscar: ");

  int documento;
  scanf("%d", &documento);
  NombreDoc(data, documento);
  
  printf("\n");
  
  return 0;
}

void NombreDoc(TData com, int doc) {
  int i = 0;
  char msg[100];
  bool dniEncontrado = false;
  
  do {
    if(com.pers[i].dni == doc) {
      strcpy(msg, com.pers[i].ape);
      dniEncontrado = true;
    }
    i++;
  } while(i < com.cant && !dniEncontrado);
  
  if(!dniEncontrado) {
    strcpy(msg, "No se encontro ninguna persona con ese DNI");
  }
  
  printf("%s", msg);
}

void Cargar(TData *com) {
  printf("Ingrese cantidad de registros a cargar: ");
  scanf("%d", &com->cant);

  printf("\n Ingrese los datos de cada persona\n");
  for(int i = 0; i < com->cant; i++) {
    printf("Personal %d \n", i+1);
    
    printf("\t Apellido: ");
    scanf("%s", com->pers[i].ape);
    
    printf("\t DNI: ");
    scanf("%d", &com->pers[i].dni);
  }
}
