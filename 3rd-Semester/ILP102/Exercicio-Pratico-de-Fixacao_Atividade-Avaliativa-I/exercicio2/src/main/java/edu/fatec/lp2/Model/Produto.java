package edu.fatec.lp2.Model;

import lombok.Getter;

public class Produto
{
    private String nome;
    private String unidade;
    private String descricao;
    @Getter
    private double preco;
    private double descontoMaximo;
    private Supermercado supermercado;

    public Produto(Supermercado supermercado)
    {
        this.supermercado = supermercado;
    }
    
    public String toString()
    {
        return this.nome;
    }
}
