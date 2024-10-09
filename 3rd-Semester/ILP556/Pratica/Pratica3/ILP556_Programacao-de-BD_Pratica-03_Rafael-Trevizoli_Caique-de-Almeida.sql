create schema pratica03;
use pratica03;

-- Pratica 3 - Views
-- ILP556 - Programação de Banco de Dados
-- Professora Juliana Forin Pasquini Martinez
-- Rafael Trevizoli - 1460282423016
-- Caique Ramon Carvalho de Almeida - 1460282323041

-- 1. Crie as tabelas conforme modelo lógico acima e insira pelo menos 5 linhas. Entregar script.
drop table if exists Funcionario;
drop table if exists Departamento;
drop table if exists Cidade;
drop table if exists Estado;
drop table if exists Cargo;

create table if not exists Cargo (
	car_cod int auto_increment
	, car_descricao varchar(20) not null
	, constraint PK_CARGO_CAR_COD primary key(car_cod)
);

insert into cargo (car_descricao)
values
	("Aprendiz")
	, ("Estagiário")
	, ("Analista")
	, ("Engenheiro")
	, ("Especialista");


create table if not exists Estado (
	est_cod int auto_increment
	, est_nome varchar(30) not null
	, constraint PK_ESTADO_EST_COD primary key(est_cod)
);

insert into Estado (est_nome)
values
	("São Paulo")
	, ("Rio de Janeiro")
	, ("Paraná")
	, ("Santa Catarina")
	, ("Espírito Santo");

create table if not exists Cidade (
	cid_cod int auto_increment
	, est_cod int
	, cid_nome varchar(30)
	, constraint PK_CIDADE_CID_COD_E_EST_COD primary key (cid_cod, est_cod)
	, constraint FK_CIDADE_EST_COD foreign key(est_cod) references Estado(est_cod)
);

insert into Cidade (est_cod, cid_nome)
values
	(1, "São Paulo")
	, (2, "Rio de Janeiro")
	, (3, "Curitiba")
	, (4, "Florianópolis")
	, (5, "Vitória");

create table if not exists Departamento (
	dep_cod int auto_increment
	, dep_descricao varchar(20) not null
	, constraint PK_DEPARTAMENTO_DEP_COD primary key (dep_cod)
);

insert into Departamento (dep_descricao)
values
	("Recursos Humanos")
	, ("Financeiro")
	, ("Jurídico")
	, ("Engenharia")
	, ("Operações");

create table if not exists Funcionario (
	fun_cod int auto_increment
	, fun_logradouro varchar(30) not null
	, fun_nome varchar(30) not null
	, fun_salario decimal(8,2) not null
	, car_cod int
	, fun_cep varchar(8) not null
	, fun_nro int not null
	, cid_cod int
	, est_cod int
	, dep_cod int
	, constraint PK_FUNCIONARIO_FUN_COD primary key (fun_cod)
	, constraint FK_FUNCIONARIO_CAR_COD foreign key (car_cod) references Cargo(car_cod)
	, constraint FK_FUNCIONARIO_CID_COD foreign key (cid_cod) references Cidade(cid_cod)
	, constraint FK_FUNCIONARIO_EST_COD foreign key (est_cod) references Estado(est_cod)
	, constraint FK_FUNCIONARIO_DEP_COD foreign key (dep_cod) references Departamento(dep_cod)
);

insert into Funcionario (fun_logradouro, fun_nome, fun_salario, car_cod, fun_cep, fun_nro, cid_cod, est_cod, dep_cod)
values
	("Avenida Nove de Julho", "Juan", 8000.00, 5, "01000", 1, 1, 1, 1)
	, ("Avenida Nelson D'avila", "Caique", 7000.00, 4, "02000", 2, 2, 2, 2)
	, ("Avenida Euclides Miragaia", "Aline", 6000.00, 3, "03000", 3, 3, 3, 3)
	, ("Avenida Dr. João Guilhermino", "Rennerson", 5000.00, 2, "04000", 4, 4, 4, 4)
	, ("Avenida Barão do Rio Branco", "Alexandre", 4000.00, 1, "05000", 5, 5, 5, 5);

-- 2. Crie a View Funcionário_View com os campos :fun_cod, fun_nome ,fun_logradoro, cid_nome,
-- est_estado, carg_descricao, dep_descricao. Apenas será possível a leitura dos dados cadastrais
-- pela view Funcionario_View.

create or replace view Funcionario_View
as
select
	f.fun_cod,
	f.fun_nome,
	f.fun_logradouro,
	c.cid_nome,
	e.est_nome,
	c2.car_descricao,
	d.dep_descricao
from
	funcionario f
inner join cidade c on
	f.cid_cod = c.cid_cod
inner join estado e on
	f.est_cod = e.est_cod
inner join cargo c2 on
	f.car_cod = c2.car_cod
inner join departamento d on
	f.dep_cod = d.dep_cod;

-- 3. Consulte os dados cadastrais pela View (Funcionario_View).
select * from funcionario_view;

-- 4. Consulte os dados dos funcionários pela tabela Funcionário.
select * from funcionario f;

-- 5. Insira um funcionário na tabela Funcionário e consulte pela View (Funcionario_View).
insert into Funcionario (fun_logradouro, fun_nome, fun_salario, car_cod, fun_cep, fun_nro, cid_cod, est_cod, dep_cod)
values
	("Rua Sete de Setembro", "Jean", 3000.00, 1, "05000", 5, 5, 5, 5);

select * from funcionario_view;

-- 6. Insira o campo fun_obs na View (Funcionario_View). OBS: Ele deve existir primeiro na
-- tabela de origem
alter table Funcionario 
add column fun_obs varchar(30);

create or replace view Funcionario_View
as
select
	f.fun_cod,
	f.fun_nome,
	f.fun_logradouro,
	c.cid_nome,
	e.est_nome,
	c2.car_descricao,
	d.dep_descricao,
	f.fun_obs
from
	funcionario f
inner join cidade c on
	f.cid_cod = c.cid_cod
inner join estado e on
	f.est_cod = e.est_cod
inner join cargo c2 on
	f.car_cod = c2.car_cod
inner join departamento d on
	f.dep_cod = d.dep_cod;

-- 7. Consulte a definição da View (Funcionario_View) no dicionário de dados.
select *
from information_schema.views
where
	table_schema = "pratica03"
	and table_name = "funcionario_view";

-- 8. A respeito de uma view criada no MySQL, marque com X a (s) resposta(s) correta(s):
-- (X) A. Por meio de uma view os dados apenas podem ser vistos.
-- ( ) B.Tabela virtual na qual os dados estão fisicamente armazenados.
-- (X) C.Utilizada para evitar que usuários não autorizados tenham acesso a todos os dados de
-- uma tabela.
-- ( ) D. Para remover uma view utilizamos o seguinte comando delete view <nome da view>.