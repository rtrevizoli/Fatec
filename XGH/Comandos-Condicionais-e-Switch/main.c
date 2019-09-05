#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void menu() {
    printf("--Options Menu--\n"
           "A) Valida maior, inteiro;\n"
           "B) Menor que 0 ou Raiz do Maior;\n"
           "C) Raiz do positivo ou quadrado do negativo;\n"
           "D) Quadrado e raiz do numero positivo;\n"
           "E) Par o impar;\n");
}

void ex01() {
    int n1, n2;
    printf("Informe dois numeros: ");
    scanf("%d %d", &n1, &n2);

    if(n1 > n2) {
        printf("O maior numero e o: %d", n1);
    } else {
        printf("O maior numero e o: %d", n2);
    }
}

void ex02() {
    int n;
    printf("Informe um numero: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("Invalid Number!");
    } else {
        printf("O quadrado e: %d", n*n);
    }
}

void ex03() {
    float n;
    printf("Informe um numero: ");
    scanf("%f", &n);

    if(n < 0) {
        printf("O quadrado do negativo e: %.2f", n*n);
    } else {
        printf("A raiz do positivo e: %.2f", sqrt(n));
    }
}

void ex04() {
    float e;
    printf("Informe um numero: ");
    scanf("%f", &e);

    if(e < 0) {
        printf("Numero negativo!");
    } else {
        printf("Quadrado do numero: %.2f", e*e);
        printf("\nRaiz do numero: %.2f", sqrt(e));
    }
}

void ex05() {
    int n;
    printf("Informe um numero: ");
    scanf("%d", &n);

    if(n%2 == 0) {
        printf("O numero %d e Par.", n);
    } else {
        printf("O numero %d e Impar.", n);
    }
}
int main() {
    char x;
    menu();
    x = toupper(getchar());

    switch(x) {
    case 'A':
        ex01();
        break;
    case 'B':
        ex02();
        break;
    case 'C':
        ex03();
        break;
    case 'D':
        ex04();
        break;
    case 'E':
        ex05();
        break;
    default:
        printf("Invalid Option!!");
    }

    getchar();
	return 0;
}
