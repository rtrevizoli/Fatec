create schema prova_1_2;
use prova_1_2;

-- Prova 1, parte 2 - 1ª. Prova de Programação de Dados - 2º Semestre de 2024 - Parte 2 - Peso 5
-- ILP556 - Programação de Banco de Dados
-- Professora Juliana Forin Pasquini Martinez
-- Rafael Trevizoli - 1460282423016

-- 1. (1,0) Liste os CDs que possuem a data de lançamento maior que 01/06/2014 e o preço de venda maior
-- que 30.50 ordenados pelo nome. Exiba: (cd_nome,cd_preco_venda,cd_data_lançamento).
select
	c.cd_nome,
	c.cd_preco_venda,
	c.cd_data_lancamento
from
	prova_1_2.cd c
where
	c.cd_data_lancamento > 01 / 06 / 2024
	and c.cd_preco_venda > 30.5

-- 2. (2,0) Liste apenas as gravadoras que não possuem CDs relacionados. Exiba: (grav_nome).
select
	g.grav_nome
from
	prova_1_2.gravadora g
left join prova_1_2.cd c on
	g.grav_codigo = c.grav_codigo
where
	c.cd_codigo is null

-- 3. (2,0) Exibir a quantidade de músicas que cada autor possui, lista também os autores que não possuem
-- músicas. Exiba:(Aut_Nome,Quantidade)
select
	a.aut_codigo 'Aut_Nome',
	count(am.mus_codigo) 'Quantidade'
from
	prova_1_2.autor a
left join prova_1_2.autor_musica am on
	a.aut_codigo = am.aut_codigo
group by
	1

-- 4. (1,0) Exiba o nome do CD mais caro.
select
	c1.cd_nome
from
	prova_1_2.cd c1
where
	c1.cd_preco_venda = (
	select
		max(c.cd_preco_venda)
	from
		prova_1_2.cd c)

-- 5.(2,0) Crie uma view para listar o nome do autor responsável pela música Pais e Filhos.
create or replace
view autor_da_musica_Pais_e_Filhos
as
select
	a.aut_nome
from
	prova_1_2.musica m
inner join prova_1_2.autor_musica am on
	m.mus_codigo = am.mus_codigo
inner join prova_1_2.autor a on
	am.aut_codigo = a.aut_codigo
where
	m.mus_nome = "Pais e Filhos"

-- 6. (2,0) Exiba a duração correspondente ao CD de nome “ CD1”.
select
	sum(m.mus_duracao)
from
	prova_1_2.cd c
left join prova_1_2.faixa f on
	c.cd_codigo = f.cd_codigo
left join prova_1_2.musica m on
	f.mus_codigo = m.mus_codigo
where
	c.cd_nome = "CD1"