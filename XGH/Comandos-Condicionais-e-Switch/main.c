#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void menu() {
    printf("--Options Menu--\n"
           "A) Valida maior, inteiro;\n");
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

int main() {

    char x;
    menu();
    x = toupper(getchar());

    switch(x) {
    case 'A':
        ex01();
        break;
    default:
        printf("Invalid Option!!");
    }

    getchar();
	return 0;
}
