#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  char nombre[100];
  char apellido [100];
  char telefono[12];
  char calleDomicilio[100];
  int edad;
  int sexo; //0: female, 1: male
} TSocio;

typedef struct Nodo {
  TSocio info;
  struct Nodo *next;
} TElem;

TElem *q;
TSocio socio;
char nombre[100];
int posicion;
int opcion;

void Inicializar(TElem **list);
void InsertarC(TElem *list, TSocio reg);
int Buscar(TElem *list, char nombreBuscado[100]);
void Mostrar(TElem *list);
void MuestraRegistro(TElem *list, int pos);
void CargarSocio(TSocio *reg);
void LiberarMemoria(TElem **list);

int main() {
  Inicializar(&q);
  do {
    printf("Ingrese una opción: ");
    printf("\t 1.Insertar a la cabeza");
    printf("\t 2.Buscar un elemento");
    printf("\t 3.Mostrar un registro");
    printf("\t 4.Mostrar todos los registros");
    printf("\t 5.Vaciar la lista");
    printf("\t 6.Salir");
    
    scanf("%i", &opcion);
    switch(opcion) {
      case 1:
        CargarSocio(&socio);
        InsertarC(q, socio);
        break;
      
      case 2:
        printf("\t Ingrese el nombre del socio a buscar");
        scanf("%s", nombre);
        posicion = Buscar(q, nombre);
        
        printf("La posicion es: %d", posicion);
        break;
      
      case 3:
        printf("\t Ingrese el nombre del socio a buscar");
        scanf("%s", nombre);
        posicion = Buscar(q, nombre);
        
        if(posicion == -1) {
          printf("\n No se encuentra el nombre de ese socio");
        }
        else {
          MuestraRegistro(q, posicion);
        }
        break;
      
      case 4:
        Mostrar(q);
        break;
      
      case 5:
        LiberarMemoria(&q);
        break;
    }
    
  } while(opcion == 6);
  return 0;
}

void Inicializar(TElem **list) {
  TElem *aux = (TElem *) malloc(sizeof(TElem));
  aux->next = NULL;
  *list = aux;
}

void InsertarC(TElem *list, TSocio reg) {
  TElem *aux = (TElem *) malloc(sizeof(TElem));
  aux->info = reg;
  aux->next = list->next;
  list->next = aux;
}

int Buscar(TElem *list, char nombreBuscado[100]) {
  int pos = 0;
  TElem *aux = list->next;
  while(aux != NULL) {
    pos++;
    if(strcmp((aux->info).nombre, nombreBuscado) == 0) {
      return pos;
    }
    
    aux = aux->next;
  }
  return -1;
}

void Mostrar(TElem *list) {
  TElem *aux = list->next;
  while(aux != NULL) {
    printf("\t Nombre: ");
    printf("%s", aux->info.nombre);
    
    printf("\t Apellido: ");
    printf("%s", aux->info.apellido);
    
    printf("\t Telefono: ");
    printf("%s", aux->info.telefono);
    
    printf("\t Calle Domicilio: ");
    printf("%s", aux->info.calleDomicilio);
    
    printf("\t Edad: ");
    printf("%d", aux->info.edad);
    
    printf("\t Sexo: ");
    if(aux->info.sexo == 0) {
      printf("F");
    }
    else {
      printf("M");
    }
    
    aux = aux->next;
  }
}

void MuestraRegistro(TElem *list, int pos) {
  if(pos == -1) {
    printf("Posición incorrecta");
  }
  else {
    if(list->next == NULL) {
      printf("Lista vacia");
    }
    else {
      int cont = 0;
      TElem *aux = list->next;
      while((aux != NULL) && (pos != cont)) {
        aux = aux->next;
        cont++;
      }
      
      if(aux != NULL) {
        printf("\t Nombre: ");
        printf("%s", aux->info.nombre);
        
        printf("\t Apellido: ");
        printf("%s", aux->info.apellido);
        
        printf("\t Telefono: ");
        printf("%s", aux->info.telefono);
        
        printf("\t Calle Domicilio: ");
        printf("%s", aux->info.calleDomicilio);
        
        printf("\t Edad: ");
        printf("%d", aux->info.edad);
        
        printf("\t Sexo: ");
        if(aux->info.sexo == 0) {
          printf("F");
        }
        else {
          printf("M");
        }
      }
    }
  }
}

void CargarSocio(TSocio *reg) {
  printf("Ingrese los datos de un Socio");
  
  printf("Ingrese el nombre del socio");
  scanf("%s", reg->nombre);
  
  printf("Ingrese el apellido del socio");
  scanf("%s", reg->apellido);
  
  printf("Ingrese el número de telefono del socio");
  scanf("%s", reg->telefono);
  
  printf("Ingrese la calle del Domicilio del socio");
  scanf("%s", reg->calleDomicilio);
  
  printf("Ingrese la edad del socio");
  scanf("%i", &reg->edad);
  
  printf("Ingrese el sexo (F o M) del socio");
  scanf("%i", &reg->sexo);
  
  
  
  printf("\t Nombre: ");
  printf("%s", reg->nombre);
        
  printf("\t Apellido: ");
  printf("%s", reg->apellido);
        
  printf("\t Telefono: ");
  printf("%s", reg->telefono);
        
  printf("\t Calle Domicilio: ");
  printf("%s", reg->calleDomicilio);
        
  printf("\t Edad: ");
  printf("%d", reg->edad);
        
  printf("\t Sexo: ");
  if(reg->sexo == 0) {
    printf("F");
  }
  else {
    printf("M");
  }
}

void LiberarMemoria(TElem **list) {
  TElem *aux;
  while((*list)->next != NULL) {
    aux = (*list)->next;
    (*list)->next = aux->next;
    free(aux);
  }
}
