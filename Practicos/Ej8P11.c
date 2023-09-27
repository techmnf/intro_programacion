/**************************************************
Nombre y Apellido: Lautaro Dovis
DNI: 44295171
Implementacion del ejercicio 8 de la practica 11.
**************************************************/

#include <stdio.h>

#define NMax 120

typedef struct{
  char nombre[30];
  int edad;
}TAlumno;

typedef struct{
  TAlumno a[NMax];
  int cant;
}TData;

int i;
FILE* f;
TAlumno alumno;
TData curso;

int main(){
  f=fopen("alumnos.dat", "r");
  curso.cant=0;
  while (curso.cant<NMax && !(feof(f))){
    fread(&alumno, sizeof(alumno),1,f);
    curso.a[curso.cant] = alumno;
    curso.cant++;
  }
  fclose(f);
  for(i=0; i<curso.cant-1; i++){
    printf("\nNombre del alumno %d: %s. Su edad: %d.", i+1, curso.a[i].nombre, curso.a[i].edad);
  }
return 0;
}
