-- 16-8-2024 - Instalação MYSQL (https://drive.google.com/drive/folders/1uK5tIiGBp4qL0AKxYVxN9N0w67neLMtB?usp=drive_link)
-- 16-8-2024 - DDL (https://drive.google.com/drive/folders/1602oURZa8XernVEJPP0XeLYHqjbac5ak?usp=drive_link)
-- https://dontpad.com/pbdddl

create database IF NOT EXISTS venda;
use venda;

create table IF NOT EXISTS cliente (
	cli_id int,
    cli_nome varchar(30),
    cli_ativo int default(1),
    cli_data_nasc date,
    primary key(cli_id)
    );

ALTER TABLE cliente
modify column cli_id int not null AUTO_INCREMENT;

insert into cliente (cli_nome, cli_data_nasc) values ("Rafael", "1997-03-26");
insert into cliente (cli_nome, cli_data_nasc) values ("*Ana", "1996-02-09");
insert into cliente (cli_nome, cli_data_nasc) values ("Fernando", "2018-12-27");

update cliente
set cli_nome = "Ana"
where cli_id = 3;

create table IF NOT EXISTS pedido (
	ped_id int,
    ped_valor decimal,
    ped_data date,
    ped_valor_total decimal(9, 2),
    primary key(ped_id)
);

insert IGNORE into pedido values (1,10,'2024-3-12',10);
insert IGNORE into pedido values (2,20,'2024-3-13',20);
insert IGNORE into pedido values (3,30,'2024-3-14',30);

create table IF NOT EXISTS produto (
	prod_id int,
    pro_nome varchar(30) not null,
    pro_quantidade int,
    pro_valor decimal(9, 2),
    primary key(prod_id)
);

create table IF NOT EXISTS itempedido (
	ped_id int,
    prod_id int,
    ite_quantidade int,
    ite_valor decimal(7, 2),
    foreign key(ped_id) references pedido(ped_id),
    foreign key(prod_id) references produto(prod_id),
    primary key(ped_id, prod_id)
);