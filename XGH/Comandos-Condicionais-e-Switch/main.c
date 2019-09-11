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
           "M) Media ponderada de 3 notas;\n"
           "N) Media ponderada, [R, REC, A];\n"
           "O) Informe weekday w switch;\n"
           "P) Informe month w switch;\n"
           "Q) Area do trapezio;\n"
           "R) Operacoes matematicas;\n"
           "S) Divisao por 3 e 5;\n"
           "T) De 3 lados, defina o triangulo;\n");
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

void ex14(){
    float n1=0, n2=0, n3=0, m=0;
    printf("Numa escala de 0 a 10, informe 3 notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    m = (n1*2 + n2*3 + n3*5)/10;

    if(m < 3) {
        printf("Aluno reprovado.");
    } else if(m >= 3 && m < 5) {
        printf("Aluno em recuperacao.");
    } else {
        printf("Aluno aprovado.");
    }
}

void ex15(){
    int n=0;
    printf("Informe um numero entre 1 e 7: ");
    scanf("%d", &n);

    switch(n) {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Thuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
    default:
        printf("Invalid option");
    }
}

void ex16() {
    int n=0;
    printf("Informe um numero entre 1 e 12: ");
    scanf("%d", &n);

    switch(n) {
    case 1:
        printf("January");
        break;
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("Dezember");
        break;
    default:
        printf("Invalid Oprtion");
    }
}

void ex17(){
    float bM=0, bm=0, A=0, h=0;

    while(bm <= 0){
        printf("Informe a base menor: ");
        scanf("%f", &bm);
    }

    while(bM <= 0){
        printf("Informe a base maior: ");
        scanf("%f", &bM);
    }

    while(h <= 0){
        printf("Informe a altura: ");
        scanf("%f", &h);
    }

    printf("A area do trapezio e: %.2f", ((bm+bM)*h)/2);
}

void ex18() {
    int x=0;
    float n1=0, n2=0;

    printf("Informe dois numeros: ");
    scanf("%f %f", &n1, &n2);

    printf("--Escolha uma Operacao--\n"
           "1) Adicao +;\n"
           "2) Subtracao -;\n"
           "3) Multiplicacao *;\n"
           "4) Divisao /;\n");

    scanf("%d", &x);

    switch(x) {
    case 1:
        printf("%.f + %.f = %.f", n1, n2, n1+n2);
        break;
    case 2:
        printf("%.f - %.f = %.f", n1, n2, n1-n2);
        break;
    case 3:
        printf("%.2f * %.2f = %.2f", n1, n2, n1*n2);
        break;
    case 4:
        printf("%.2f / %.2f = %.2f", n1, n2, n1/n2);
        break;
    default:
        printf("Invalid Option");
    }
}

void ex19() {
    float n=0;

    printf("Informe um numero: ");
    scanf("%f", &n);

    if(fmod(n, 3) == 0 && fmod(n, 5) == 0){
        printf("Este numero e divisivel por 3 e por 5.");
    } else if(fmod(n, 3) == 0){
        printf("Este numero e divisivel por 3.");
    } else if(fmod(n, 5) == 0){
        printf("Este numero e divisivel por 5.");
    } else {
        printf("Este numero nao e divisivel por 3, nem por 5.");
    }
}

void ex20() {
    float l1=0, l2=0, l3=0;

    printf("Informe 3 medidas: ");
    scanf("%f %f %f", &l1, &l2, &l3);

    if(l1 > l2+l3 || l2 > l1+l3 || l3 > l1+l2) {
        printf("As medidas informadas nao formam um triangulo.");
    } else if(l1 == l2 && l2 == l3) {
        printf("Triangulo Equilatero.");
    } else if(l1 != l2 && l2 != l3) {
        printf("Triangulo Escaleno.");
    } else {
        printf("Triangulo Isosceles.");
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
    case 'N':
        ex14();
        break;
    case 'O':
        ex15();
        break;
    case 'P':
        ex16();
        break;
    case 'Q':
        ex17();
        break;
    case 'R':
        ex18();
        break;
    case 'S':
        ex19();
        break;
    case 'T':
        ex20();
        break;
    default:
        printf("Invalid Option!!");
    }

    getchar();
	return 0;
}
