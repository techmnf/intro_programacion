#include <stdio.h>

char letra; //Variable para leer la entrada del usuario (dato)
int esLetraConsonante; //Variable para la salida (resultado)

int esMayuscula(char c);
char aMinuscula(char c);
int esVocal(char c);
int esConsonante(char c);

int main() {
    printf("Introduce una letra: ");
    scanf("%c", &letra);

    esLetraConsonante = esConsonante(letra);

    if(esLetraConsonante == 0) {
        printf("La letra introducida no es consonante");
    }
    else {
        printf("La letra introducida es consonante");
    }
    printf("\n");

    return 0;
}

int esMayuscula(char c) {
    return ((c >= 'A') && (c <= 'Z'));
}

char aMinuscula(char c) {
    /* si un caracter esta comprendido entre A y Z,
    se le suma la diferencia entre los ASCII de las
    minusculas y las mayusculas ( 97 - 65 = 32 )
    para a minuscula */
    return (c + ('a' - 'A'));
}

int esVocal(char c) {
    char minus; // Léxico local
    if (esMayuscula(c)){
        minus = aMinuscula(c);
    }
    else {
        minus = c;
    }
    return (
        (minus == 'a') || 
        (minus == 'e') || 
        (minus == 'i') || 
        (minus == 'o') || 
        (minus == 'u')
    );
}

int esConsonante(char c) {
    char minus; // Léxico local
    
    if(esMayuscula(c)) {
        minus = aMinuscula(c);
    }
    else {
        minus = c;
    }

    if((minus >= 'a') && (minus <= 'z')) {
        return 1-esVocal(c);
    }
    else {
        return 0;
    }
}