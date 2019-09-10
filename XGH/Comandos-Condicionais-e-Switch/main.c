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
           "E) Par o impar;\n"
           "F) Maior e diferença;\n"
           "G) Maior e igual;\n"
           "H) Valida notas\n"
           "I) Consulta emprestimo;\n"
           "J) Peso ideal;\n"
           "K) Soma dos algarismos;\n"
           "L) Invalido negativo ou log do positivo;\n"
           "M) Media ponderada de 3 notas;\n");
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

void ex06() {
    int n1, n2;
    printf("Informe dois numeros: ");
    scanf("%d %d", &n1, &n2);

    if(n1 > n2) {
        printf("O maior numero e: %d e a diferença de ambos e: %d", n1, n1-n2);
    } else {
        printf("O maior numero e: %d e a diferença de ambos e: %d", n2, n2-n1);
    }
}

void ex07() {
    int n1, n2;
    printf("Informe dois numeros: ");
    scanf("%d %d", &n1, &n2);

    if(n1 == n2) {
        printf("Numeros iguais.");
    } else if(n1 > n2) {
        printf("O maior numero e: %d", n1);
    } else {
        printf("O maior numero e: %d", n2);
    }
}

void ex08() {
    float n1, n2;
    printf("Informe duas notas: ");
    scanf("%f %f", &n1, &n2);

    if((n1 >= 0 && n1 <= 10) && (n2 >= 0 && n2 <= 10)) {
        printf("A media e: %.2f", (n1+n2)/2);
    } else if((n1 < 0 || n1 > 10) && (n2 < 0 || n2 > 10)) {
        printf("Nota 1 e nota 2 invalida.");
    } else {
        printf("Nota 1 ou nota 2 invalidas.");
    }
}

void ex09() {
    float s, e;
    printf("Informe o salario: R$");
    scanf("%f", &s);
    printf("Informe o valor do emprestimo: R$");
    scanf("%f", &e);

    if(e > s*.2) {
        printf("Emprestimo nao concedido.");
    } else {
        printf("Emprestimo concedido");
    }
}

void ex10() {
    float h;
    char s;
    printf("Informe seu sexo: [M/F] ");
    getchar();
    s = toupper(getchar());
    printf("Informe sua altura: ");
    scanf("%f", &h);

    if(s == 'M') {
        printf("Sua altura ideal e: %.2f", (72.7*h)-58);
    } else {
        printf("Sua altura ideal e: %.2f", (62.1*h)-(44.7));
    }
}

void ex11() {
    int n, sum = 0;
    printf("Informe um numero: ");
    scanf("%d", &n);

    if(n > 0) {
        while(n > 0) {
            sum = sum + n%10;
            n = n/10;
        }

        printf("A soma dos algarismos e: %d", sum);
    } else {
        printf("Numero invalido");
    }
}

void ex12(){
    float n=0;
    printf("Informe um numero inteiro: ");
    scanf("%f", &n);

    if(n < 0) {
        printf("Invalid number");
    } else {
        printf("Log de %.f e: %f", n, log(n));
    }
}

void ex13(){
    float n1=0, n2=0, n3=0, m=0;
    printf("Numa escala de 0 a 100, informe as 3 notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    m = (n1*1 + n2*1 + n3*2)/4;

    if(m <= 60) {
        printf("Aluno reprovado");
    } else {
        printf("Aluno aprovado");
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
    case 'F':
        ex06();
        break;
    case 'G':
        ex07();
        break;
    case 'H':
        ex08();
        break;
    case 'I':
        ex09();
        break;
    case 'J':
        ex10();
        break;
    case 'K':
        ex11();
        break;
    case 'L':
        ex12();
        break;
    case 'M':
        ex13();
        break;
    default:
        printf("Invalid Option!!");
    }

    getchar();
	return 0;
}
