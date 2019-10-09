#include <stdio.h>
#include <stdlib.h>

int main() {

    int rg[] = {};
    int len[] = {};
    int i = 0, maxi = 0;

    for (;;) {

        printf("Informe um numero de RG: ");
        scanf("%d", &rg[i]);

        int  cd = 0, valor = rg[i];
        do {
            cd += 1;
            valor /= 10;
        } while (valor != 0);
        len[i] = cd;

        i += 1;
        maxi += 1;

        char c = 'w';

        printf("Deseja inserir mais um rg ?[s/ n] ");
        getchar();
        scanf("%c", &c);

        if (c == 'n') {
            break;
        }
    }

    for (int i = 0; i < maxi; i++) {
        if (len[i] == 9) {
            if (rg[i]/100000000 == 1) {
                printf("\n---->%i\n", rg[i]);
            }
        }
    }

    //427483268
    getchar();
    return 0;
}
