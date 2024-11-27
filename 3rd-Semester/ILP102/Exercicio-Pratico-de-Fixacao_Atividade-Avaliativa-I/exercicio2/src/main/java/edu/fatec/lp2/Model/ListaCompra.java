package edu.fatec.lp2.Model;

import java.util.ArrayList;
import java.util.List;

import edu.fatec.lp2.Service.Calculavel;

public class ListaCompra implements Calculavel
{
    private List<ItemCompra> itensCompra = new ArrayList<>();
    private int qtdeMax;

    public ListaCompra(int qtdeMax)
    {
        this.qtdeMax = qtdeMax;
    }

    public void incluir(ItemCompra produto)
    {
        if (itensCompra.size() < qtdeMax)
            this.itensCompra.add(produto);
    }

    public double calcularPreco()
    {
        double total = 0.0;
        for (ItemCompra itemCompra : itensCompra)
        {
            total += itemCompra.calcularPreco();
        }

        return total;
    }
}
