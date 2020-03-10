#include <iostream>
#include <vector>
using namespace std;

int num_moedas(vector<int>& moedas, int troco) {
    int qte_moedas = 0;
    int tam_moedas = moedas.size();

    /*
    troco = 26
    M = {1, 2, 5, 10, 20}

    aux_moedas = 26 / 20 = 1
    troco = 26 - 1 * 20 = 6
    qte_moedas = 1

    aux_moedas = 6 / 10 = 0
    troco = troco - 0
    qte_moedas = 1

    aux_moedas = 6 / 5 = 1
    troco = 6 - 1 * 5 = 1
    qte_moedas = 2

    aux_moedas = 1 / 2 = 0
    troco = 1
    qte_moedas = 2

    aux_moedas = 1 / 1 = 1
    troco = 1 - 1 * 1 = 0
    qte_troco = 3

    */

    for(int i = tam_moedas - 1; i >= 0; i--) {
        int aux_moedas = troco / moedas[i];
        troco -= aux_moedas * moedas[i];
        qte_moedas += aux_moedas;
    }

    return qte_moedas;
}

int main(int argc, char*  argv[]) {
    vector<int> moedas;

    int troco;

    troco = 26;
    moedas.push_back(1);
    moedas.push_back(2);
    moedas.push_back(5);
    moedas.push_back(10);
    moedas.push_back(20);

    cout << "Número de moedas: " << num_moedas(moedas, troco);

    return 0;
}
