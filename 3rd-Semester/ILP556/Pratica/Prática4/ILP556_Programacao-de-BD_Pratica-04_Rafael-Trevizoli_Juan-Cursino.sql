create schema pratica04;
use pratica04;

-- Pratica 4 - DDL_Alter-table
-- ILP556 - Programação de Banco de Dados
-- Professora Juliana Forin Pasquini Martinez
-- Rafael Trevizoli - 1460282423016
-- Juan Henrique Evaristo Cursino - 

-- 1. Transformar o Modelo Lógico (Notação Chen) para Physical data model (notação Jasmim Martin
-- na Ferramenta Vertabelo.
select "https://drive.google.com/file/d/1zagyc_M1_n9bU-YP5MDMKgYh7VpCasuM/view?usp=sharing"

-- 2. Gerar o script DDL.
-- Criar as tabelas com o script criado, para resolução dos exercícios 3 a 6.
select "https://drive.google.com/file/d/1mL0MuO_vFlu8zZI8xYl8_7Wmg8WFTGJR/view?usp=sharing"

-- 3. Altere a tabela PROJETO, fazendo as seguintes mudanças: 
-- a. Adicionar uma coluna de nome STATUS, de preenchimento obrigatório, com dados de tipo 
-- numérico, aceitando apenas os valores 0 (flag que indica projeto inativo) e 1 (flag que 
-- indica projeto em andamento).
alter table PROJETO
add column STATUS boolean;

-- b.  Alterar a coluna TITULO, aumentando seu tamanho para 155 caracteres.
alter table PROJETO
modify column TITULO varchar(155);

-- c. Renomear a coluna DATA_CAD para DATA_CADASTRO.
alter table PROJETO
rename column DATA_CAD to DATA_CADASTRO;

-- 4. Altere a tabela FUNCIONARIO, fazendo as seguintes mudanças:
-- a. Transformar a coluna ENDERECO numa tabela separada, sendo que cada endereço poderá estar
-- vinculado a mais de um funcionário (Ex: marido, esposa e filho trabalhando na mesma empresa)
-- e cada funcionário poderá informar mais de um endereço. DICA: Dessa forma, teremos um relacionamento
-- N x M entre funcionário e a nova entidade ENDERECO.
create table if not exists ENDERECO
(
	cod_endereco int auto_increment
	, endereco varchar(252) not null
	, Constraint PK_ENDERECO_COD_ENDERECO primary key (cod_endereco)
);

alter table funcionario 
modify column ENDERECO int;

alter table funcionario
rename column ENDERECO to COD_ENDERECO;

alter table funcionario 
add constraint FK_FUNCIONATIO_COD_ENDERECO foreign key(COD_ENDERECO) references ENDERECO(COD_ENDERECO);

-- b. Excluir a restrição associada à coluna SALARIO.
alter table funcionario 
drop constraint CK_FUNCIONARIO_SALARIO;

-- 5. Altere a tabela DEPENDENTE, fazendo as seguintes mudanças:
-- a. A coluna PARENTESCO deixa de ser texto e passa a ser controlada através de outra tabela, onde
-- são armazenados o CODIGO e DESCRICAO do tipo de parentescos aceitos pela empresa. Dessa forma, uma
-- chave estrangeira na tabela DEPENDENTE deverá referenciar a chave primária dessa nova tabela, num
-- relacionamento 1 x N (Parentesco 🡪 Dependente).
create table if not exists PARENTESCO
(
	COD_PARENTESCO int auto_increment
	, DESCRICAO varchar(30)
	, constraint PK_PARENTESCO_COD_PARENTESCO primary key (COD_PARENTESCO)
	, constraint CK_PARENTESCO_DESCRICAO Check(DESCRICAO in ("PAI", "MÃE", "IRMAOS", "FILHO"))
);

alter table dependente 
drop constraint CK_DEPENDENTE_PARENTESCO;

alter table dependente
modify column PARENTESCO int;

alter table dependente
rename column PARENTESCO to COD_PARENTESCO;

alter table dependente 
add constraint FK_DEPENDENTE_COD_PARENTESCO foreign key(COD_PARENTESCO) references PARENTESCO(COD_PARENTESCO);

-- b. Criar uma chave alternativa na tabela DEPENDENTE, onde será armazenado o CPF dos dependentes.
alter table dependente 
add column CPF varchar(11);

-- c. Automatizar o processo de exclusão de registros da tabela DEPENDENTE ao excluir um registro da
-- tabela FUNCIONARIO. Para isso, utilizar o comando DELETE CASCADE na chave estrangeira da coluna
-- DEPENDENTE.COD_FUNCvide aula DDL – PARTE 2.

-- 6. Altere a tabela PARTICIPA, fazendo as seguintes mudanças:
-- Renomear a tabela PARTICIPA para FUNC_PROJETO
rename table PARTICIPA TO FUNC_PROJETO;