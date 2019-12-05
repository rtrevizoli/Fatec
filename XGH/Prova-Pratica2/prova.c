#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void openingError(FILE *f) {
    if (f == NULL) {
        scanf("kkk\n");
        exit(1);
    }
}

void menu() {
    printf( "--Menu de Opções--\n"
            "\n"
            "[1] Gravar um nome;\n"
            "[2] Verificar incidência de Pré-nomes;\n"
            "[3] Sair.\n");
}

void gravarNome() {
    FILE *f;
    f = fopen("file.txt","a");

    openingError(f);

    char input[100];
    scanf(" %[^\n]", input);

    printf("%s\n", input);

    char carac;
    bool status = true;

    for (int i = 0; i < strlen(input); i++) {

        carac = input[i];
        if (carac > 47 && carac < 58) {
            status = false;
            printf("Não é possível gravar nomes com números! Escreva novamente.\n");
            gravarNome();
        }
    }

    if (status == true) {
        fputs(input, f);
        fputs("\n", f);
    }

    char x;
    printf("Deseja gravar outro nome ? [Y/n]: ");
    scanf(" %c", &x);

    if(x == 'Y' || x == 'y') {
        gravarNome();
    } else {
        exit(2);
    }

    fclose(f);
}

void incidenciaPreNome() {
    FILE *f;
    f = fopen("file.txt","r");

    openingError(f);

    char prenome[100];
    int oc = 0;
    printf("Informe um pré-nome a ser verificado: ");
    scanf(" %[^\n]", prenome);
    char line[strlen(prenome)];

    char output[100];
    while(fgets(output, 100, f) != NULL) {
        strncpy(line, output, strlen(prenome));
        printf("%s ", line);
        printf("%s\n", prenome);

        if (line == prenome) {
            oc += 1;
            printf("%d", oc);

       }
    }
    printf("soma: %d", oc);

    fclose(f);
}

int main() {

    int x;
    menu();
    scanf(" %d", &x);

    switch(x) {
        case 1:
            gravarNome();
            break;
        case 2:
            incidenciaPreNome();
            break;
        case 3:
            printf("Você escolheu sair.\n");
            break;
        default:
            printf("Opção inválida, bye bye.");
    }

    scanf("kkk\n");
    return 0;
}