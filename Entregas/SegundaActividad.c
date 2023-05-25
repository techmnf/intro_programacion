#include <stdio.h>
float horasSemanales;  // dato
float salario;  // resultado
int main()
{
    printf("\n Ingrese las horas semanales del trabajador: ");
    scanf("%f", &horasSemanales);
    
    if(horasSemanales > 40) {
        salario = (10*40) + (horasSemanales-40)*10*1.5;
    }
    else {
        salario = horasSemanales*10;
    }

    printf("El salario del trabajador es: %.2f \n", salario);
    //%.2f escribe el nÃºmero con solo dos decimales
    return 0;
}