package edu.fatec.lp2.Model;

public class MsgFoto extends Mensagem {
    private int tamanho;

    public MsgFoto(Contatinho contatinho, String conteudo)
    {
        super(contatinho, conteudo);
    }
    
    public Mensagem sendMessage(String conteudo)
    {
        return this;
    }
}
