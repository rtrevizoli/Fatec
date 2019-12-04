#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f;
    f = fopen("arq.txt", "w");

    if (f == NULL) {
        printf("Erro na abertura!\n");
        scanf("kkk\n");
        exit(1);    
    }

    char input = 'a';
    scanf(" %c", &input);

    while(input != '0') {
        fputc(input, f);

        scanf(" %c", &input);        
    }

    fclose(f);

    f = fopen("arq.txt", "r");

    if (f == NULL) {
        printf("Erro na abertura!\n");
        scanf("kkk\n");
        exit(1);    
    }

    char c = fgetc(f);

    printf("\nFile Start\n");

    while(c != EOF) {
        printf("%c\n", c);
        c = fgetc(f);
    }

    printf("Game Over\n");


    scanf("kkk\n");

    return 0;
}