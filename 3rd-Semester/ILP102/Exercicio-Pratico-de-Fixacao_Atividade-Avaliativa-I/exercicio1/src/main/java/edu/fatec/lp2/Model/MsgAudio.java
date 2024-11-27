package edu.fatec.lp2.Model;

public class MsgAudio extends Mensagem {
    private int duracao;

    public MsgAudio(Contatinho contatinho, String conteudo)
    {
        super(contatinho, conteudo);
    }
    
    public Mensagem sendMessage(String conteudo)
    {
        return this;
    }
}
