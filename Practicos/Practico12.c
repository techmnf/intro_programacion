#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  char nom[100];
  char ape[100];
  int dni;
  int edad;
} TPers;

typedef struct Nodo {
  TPers info;
  struct Nodo *next;
} TElem;

TElem elem;
int estado;
int opcionSeleccionada;

void Crear(TElem *list);
void InsertarCab(TElem *list, TPers reg);
void SuprimirCab(TElem *list);
int Vacia(TElem *list);
void Listar(TElem *list);

void LeerReg(TPers *reg);
void MostrarMenu();
void OpcionMenuSeleccionada(int opcionSeleccionada, int *cont, TElem *q);

void ImprimirEnPantalla(char *msg);

int main() {
  estado = 1;

  Crear(&elem);
  MostrarMenu();
  
  while(estado == 1) {
    scanf("%i", &opcionSeleccionada);
    OpcionMenuSeleccionada(opcionSeleccionada, &estado, &elem);
  }
  
  return 0;
}

void Crear(TElem *list) {
  list = NULL;
}

void InsertarCab(TElem *list, TPers reg) {
  TElem *aux;
  
  aux = (TElem *) malloc(sizeof(TElem));
  aux->info = reg;
  aux->next = list;
  list = aux;
}

void SuprimirCab(TElem *list) {
  TElem *aux;
  
  if(Vacia(list) == 0) {
    aux = list;
    
    list = list->next;
    free(aux);
  }
}

int Vacia(TElem *list) {
  return list == NULL;
  /*if(list == NULL) {
    return 1;
  }
  else {
    return 0;
  }*/
}

void Listar(TElem *list) {
  TElem *aux;
  aux = list;
  
  while(aux != NULL) {
    printf("%s", aux->info.nom);
    printf("%s", aux->info.ape);
    printf("%d", aux->info.edad);
    printf("%d", aux->info.dni);

    aux = aux->next;
  }
}

void LeerReg(TPers *reg) {
  printf("\t Nombre: ");
  scanf("%s", reg->nom);
  
  printf("\t Apellido: ");
  scanf("%s", reg->ape);
  
  printf("\t Edad: ");
  scanf("%d", &reg->edad);
    
  printf("\t DNI: ");
  scanf("%d", &reg->dni);
}

void MostrarMenu() {
  ImprimirEnPantalla("Insertar: (0)");
  ImprimirEnPantalla("Listar: (1)");
  ImprimirEnPantalla("Eliminar: (2)");
  ImprimirEnPantalla("Salir: (3)");
}

void OpcionMenuSeleccionada(int opcionSeleccionada, int *cont, TElem *q) {
  int i, j;
  char msg[100];  
  TPers nuevo;
  
  switch(opcionSeleccionada) {
    case 0:
      strcpy(msg, "Cuantas Personas desea insertar: ");
      printf("%s", msg);
      scanf("%i", &i);
      printf("\n");
      
      j = 0;
      while(j < i) {
        strcpy(msg, "Registro: #");
        printf("%s", msg);
        printf("%i", j+1);
        printf("\n");
        
        LeerReg(&nuevo);
        InsertarCab(q, nuevo);
        
        j++;
      }
      break;
      
    case 1:
      if(Vacia(q) == 1) {
        ImprimirEnPantalla("Lista vacia");
      }
      else {
        ImprimirEnPantalla("Lista contiene: ");
        Listar(q);
      }
      break;
      
    case 2:
      if(Vacia(q) == 1) {
        ImprimirEnPantalla("La lista esta vacia");
      }
      else {
        SuprimirCab(q);
        ImprimirEnPantalla("Suprimido con exito!!!");
      }
      break;
      
    case 3:
      *cont = 0;
      ImprimirEnPantalla("Saliendo...");
      break;
      
    default: 
      break;
  }
}

void ImprimirEnPantalla(char *msg) {
  printf("%s", msg);
  printf("\n");
}
