package edu.fatec.lp2.Model;

public class Contatinho {
    private String nome;
    private String celular;

    public Contatinho(String nome, String celular)
    {
        this.nome = nome;
        this.celular = celular;
    }

    public String getNome()
    {
        return this.nome;
    }
}