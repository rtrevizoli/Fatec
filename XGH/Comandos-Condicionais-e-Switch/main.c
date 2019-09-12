#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void menu() {
    printf("--Options Menu--\n"
           "1) Valida maior, inteiro;\n"
           "2) Menor que 0 ou Raiz do Maior;\n"
           "3) Raiz do positivo ou quadrado do negativo;\n"
           "4) Quadrado e raiz do numero positivo;\n"
           "5) Par o impar;\n"
           "6) Maior e diferença;\n"
           "7) Maior e igual;\n"
           "8) Valida notas\n"
           "9) Consulta emprestimo;\n"
           "10) Peso ideal;\n"
           "11) Soma dos algarismos;\n"
           "12) Invalido negativo ou log do positivo;\n"
           "13) Media ponderada de 3 notas;\n"
           "14) Media ponderada, [R, REC, A];\n"
           "15) Informe weekday w switch;\n"
           "16) Informe month w switch;\n"
           "17) Area do trapezio;\n"
           "18) Operacoes matematicas;\n"
           "19) Divisao por 3 e 5;\n"
           "20) De 3 lados, defina o triangulo;\n"
           "21) Menu operacoes aritimeticas;\n"
           "22) Posso aposentar ?;\n"
           "23) Ano bissexto;\n"
           "24) Taxa por estado;\n"
           "25) Raizes da funcao de segundo grau;\n"
           "26) Consumo da gasolina;\n");
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

void ex21() {
    int x=0;
    float n1=0, n2=0;
    printf("Informe dois numeros: ");
    scanf("%f %f", &n1, &n2);

    printf("--Selecione uma operacao--\n"
           "1) Soma de 2 numeros;\n"
           "2) Diferenca entre 2 numeros (maior pelo menor);\n"
           "3) Produto entre dois numeros;\n"
           "4) Divisao entre dois numeros (o denominador nao pode ser zero).\n");
    scanf("%d", &x);

    float maior=n1, menor=n2;

    if(n1 < n2) {
        maior = n2;
        menor = n1;
    }

    switch(x) {
    case 1:
        printf("%.f + %.f = %.f", n1, n2, n1+n2);
        break;
    case 2:
        printf("%.f - %.f = %.f", maior, menor, maior-menor);
        break;
    case 3:
        printf("%.f * %.f = %.f", n1, n2, n1*n2);
        break;
    case 4:
        while(n2 == 0){
            printf("Por favor, informe um numero diferente de zero para o denominador: ");
            scanf("%f", &n2);
        }

        printf("%.f / %.f = %.2f", n1, n2, n1/n2);
        break;
    default:
        printf("Invalid Option");
    }
}

void ex22() {
    int i=0, ts=0;

    printf("Informe sua idade e seu tempo de servico respectivamente e em anos: ");
    scanf("%d %d", &i, &ts);

    if(i >= 65 || ts >= 30 || (i >= 60 && ts >= 25)){
        printf("Parabens, voce pode se aposentar!");
    } else {
        printf("Infelizmente informo que voce ainda nao pode se aposentar. :c");
    }
}

void ex23() {
    int y=0;

    printf("Informe um ano: ");
    scanf("%d", &y);

    if(y%400 == 0 || (y%4 == 0 && y%100 != 0)) {
        printf("O ano %d e bissexto.", y);
    } else {
        printf("O ano %d nao e bissexto.", y);
    }
}

void ex24() {
    int x=0;
    float vp=0;

    printf("Informe o valor do produto: R$");
    scanf("%f", &vp);

    printf("--Escolha um estado abaixo--\n"
          "1) MG;\n"
          "2) MS;\n"
          "3) RJ;\n"
          "4) SP.\n");
    scanf("%d", &x);

    switch(x) {
    case 1:
        printf("O preco do produto e R$%.2f", vp*1.07);
        break;
    case 2:
        printf("O preco do produto e R$%.2f", vp*1.08);
        break;
    case 3:
        printf("O preco do produto e R$%.2f", vp*1.15);
        break;
    case 4:
        printf("O preco do produto e R$%.2f", vp*1.12);
        break;
    default:
        printf("Invalid Option");
    }
}

void ex25() {
    float a=0, b=0, c=0, D=0;

     while(a == 0) {
        printf("Informe o a, diferente de zero: ");
        scanf("%f", &a);
     }

     printf("Informe b: ");
     scanf("%f", &b);

     printf("Informe c: ");
     scanf("%f", &c);

     D = b*b-(4*a*c);

     if(D < 0) {
        printf("Nao existe raizes para a equacao.");
     } else if(D == 0) {
         printf("x: %.2f", (-b/(2*a)));
     } else {
        printf("xi: %.2f\n"
               "xii: %.2f", (-b+sqrt(D))/(2*a), (-b-sqrt(D))/(2*a));
     }
}

void ex26() {
    float km=0, l=0, kmpl=0;

    printf("Informe a Quilometragem percorrida pelo carro: ");
    scanf("%f", &km);

    printf("Informe a quantidade de litros utilizada pelo carro: ");
    scanf("%f", &l);

    kmpl = km/l;

    if(kmpl < 8) {
        printf("Venda o carro!");
    } else if(kmpl >= 8 && kmpl <= 14) {
        printf("Economico.");
    } else {
        printf("Super Economico!");
    }

}

int main() {
    int x;
    menu();
    scanf("%d", &x);

    switch(x) {
    case 1:
        ex01();
        break;
    case 2:
        ex02();
        break;
    case 3:
        ex03();
        break;
    case 4:
        ex04();
        break;
    case 5:
        ex05();
        break;
    case 6:
        ex06();
        break;
    case 7:
        ex07();
        break;
    case 8:
        ex08();
        break;
    case 9:
        ex09();
        break;
    case 10:
        ex10();
        break;
    case 11:
        ex11();
        break;
    case 12:
        ex12();
        break;
    case 13:
        ex13();
        break;
    case 14:
        ex14();
        break;
    case 15:
        ex15();
        break;
    case 16:
        ex16();
        break;
    case 17:
        ex17();
        break;
    case 18:
        ex18();
        break;
    case 19:
        ex19();
        break;
    case 20:
        ex20();
        break;
    case 21:
        ex21();
        break;
    case 22:
        ex22();
        break;
    case 23:
        ex23();
        break;
    case 24:
        ex24();
        break;
    case 25:
        ex25();
        break;
    case 26:
        ex26();
        break;
    default:
        printf("Invalid Option!!");
    }

    getchar();
	return 0;
}
