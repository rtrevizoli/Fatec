package edu.fatec.lp2.Service;

import edu.fatec.lp2.Model.Contatinho;
import edu.fatec.lp2.Model.Mensagem;

public class Whatsapp {
    private Contatinho[] contatos;
    private Mensagem[] mensagens;

    public Whatsapp(Contatinho[] contatos, Mensagem[] mensagens)
    {
        this.contatos = contatos;
        this.mensagens = mensagens;
    }

    public void listarContatos()
    {
        for (Contatinho contato : contatos)
            System.out.println(contato.getNome());
    }

    public void listarMensagens()
    {
        for (Mensagem mensagem : mensagens)
            System.out.println(mensagem.getConteudo());
    }
    
}