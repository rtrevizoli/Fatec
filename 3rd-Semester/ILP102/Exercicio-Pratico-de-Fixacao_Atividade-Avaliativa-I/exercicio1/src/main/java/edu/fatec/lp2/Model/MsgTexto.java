package edu.fatec.lp2.Model;

public class MsgTexto extends Mensagem {
    private int numChar;

    public MsgTexto(Contatinho contatinho, String conteudo)
    {
        super(contatinho, conteudo);
    }

    public Mensagem sendMessage(String conteudo)
    {
        return this;
    }
    
}