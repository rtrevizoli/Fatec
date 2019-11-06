#include <stdio.h>
#include <stdlib.h>

int main() {

    typedef struct horario {
        int hora, minuto, segundo;
    } HORARIO;

    typedef struct data {
        int dia, mes, ano;
    } DATA;

    struct compromisso {
        DATA datacompromisso;
        HORARIO horariocompromisso;
        char str[50];
    } COMPROMISSO;

    system("PAUSE");
    return 0;
}