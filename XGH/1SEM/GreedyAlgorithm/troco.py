'''
Algoritmos Gulosos
- Sempre escolhe a alternativa que parece mais promissora naquele instante
- NUNCA reconsidera essa decisão
- Uma escolha que foi feita nunca é revista
- Não há backtrancking
- A escolha é feita de acordo com um critério guloso - decisão localmente ótima
- Nem sempre dão soluções ótimas

Problema do Troco (Troco Mínimo)
Moedas = {100, 50, 25, 5, 1}
Troco = 75
Quantidade mínima de moedas = 2 (1 de 50 + 1 de 25)

100 -> 75 < 100 
50 -> 75 > 50 -> 1 de 50
75 - 50 = 25
50 -> 25 < 50
25 -> 25 = 25 -> 1 de 25
25 - 25 = 0
'''

def troco_min(troco):
    moedas = [100, 50, 25, 5, 1]
    troco = 130
    total = 0
    moedas_utilizadas = {} # Dicionario (moeda: quantidade)

    for i in range(len(moedas)):
        num_moedas = troco // moedas[i]
        troco -= num_moedas * moedas[i]
        total += num_moedas
        if num_moedas > 0:
            moedas_utilizadas[moedas[i]] = num_moedas

    print("Total de moedas: ", total)
    print("Moedas utilizadas:")
    for moeda, quantidade in moedas_utilizadas.items():
        print("Moeda de", moeda, "->", quantidade)

troco_min(130)



