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

    scanf("kkk\n");

    return 0;
}