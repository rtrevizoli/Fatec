-- ILP556 - Programação de Banco de Dados
-- Professora: Juliana Forin Pasquini Martinez
-- 3o Semestre de Banco de Dados, Noturno
-- 1460282423016 - Rafael Trevizoli

create database IF NOT EXISTS prática01;
use prática01;

create table IF NOT EXISTS cinema (
	cin_cod int
	, cin_nomefantasia varchar(18) not null
    , cin_rua varchar(20)
    , cin_avenida varchar(20)
    , cin_bairro varchar(10)
    , cin_municipio varchar(20)
    , cin_estado varchar(18)
    , cin_capacidade_lotacao int not null
    , primary key(cin_cod)
    , Constraint CK_CIN_ESTADO Check(cin_estado in ("São Paulo", "Rio de Janeiro", "Minas Gerais"))
    , Constraint CK_CIN_CAPACIDADE_LOTACAO Check(cin_capacidade_lotacao > 0)
);

create table if not exists Genero (
	gen_codigo int
    , gen_descricao varchar(18)
    , primary key(gen_codigo)
);

create table if not exists Tipo (
	tip_codigo int
    , tip_descricao varchar(18)
    , primary key(tip_codigo)
);

create table if not exists Ator (
	ato_codigo int
    , ato_nome varchar(20)
    , ato_nacionalidade varchar(20)
    , ato_idade int
    , primary key(ato_codigo)
);

create table if not exists Filme (
	fil_codigo int
    , gen_codigo int
    , tip_codigo int
    , ato_codigo int
    , fil_titulo_original varchar(18) not null
    , fil_titulo_portugues varchar(18)
    , fil_duracao int not null
    , fil_pais_origem varchar(15)
    , primary key(fil_codigo)
    , foreign key(gen_codigo) references Genero(gen_codigo)
    , foreign key(tip_codigo) references Tipo(tip_codigo)
    , foreign key(ato_codigo) references Ator(ato_codigo)
    , Constraint UK_FIL_TITULO_ORIGINAL Unique(fil_titulo_original)
    , Constraint CK_FIL_DURACAO Check(fil_duracao > 0)
);

create table if not exists Filme_cinema (
	fil_codigo int
    , cin_cod int
    , primary key(fil_codigo, cin_cod)
);

create table if not exists Sessao (
	ses_codigo int
    , fil_codigo int
    , cin_cod int
    , ses_hora_inicial datetime not null
    , ses_hora_final datetime not null
    , ses_total_pessoas datetime default(0)
    , primary key(ses_codigo)
    , foreign key(fil_codigo, cin_cod) references Filme_cinema(fil_codigo, cin_cod)
    , Constraint CK_SES_HORA_FINAL Check(ses_hora_final > ses_hora_inicial)
);

create table if not exists Ator_Filme (
	ato_codigo int
    , fil_codigo int
    , primary key(ato_codigo, fil_codigo)
);