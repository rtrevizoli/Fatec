package edu.fatec.lp2.Model;

import edu.fatec.lp2.Service.Calculavel;

public class ItemCompra implements Calculavel
{
    private int quantidade;
    private Produto produto;
    private double desconto;

    public ItemCompra(Produto produdo, double desconto)
    {
        this.produto = produdo;
        this.desconto = desconto;
    }

    public double calcularPreco()
    {
        return this.quantidade * this.produto.getPreco() * desconto;
    }
}
