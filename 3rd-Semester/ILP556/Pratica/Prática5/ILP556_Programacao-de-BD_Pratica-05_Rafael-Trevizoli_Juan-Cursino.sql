create schema pratica05;
use pratica05;

-- Pratica 5
-- ILP556 - Programação de Banco de Dados
-- Professora Juliana Forin Pasquini Martinez
-- Rafael Trevizoli - 1460282423016
-- Juan Henrique Evaristo Cursino - 1460282323011

-- Estudo de Caso: Catálogo de CDs

-- Uma loja, localizada em São José dos Campos, que vende CDs de músicas adquiriu um sistema de
-- software: Catálogo de CDs. Essa aquisição ocorreu devido às perguntas constantes dos clientes a
-- respeito de informações do CD como nome e a agravadora do CD e também da necessidade da empresa
-- conhecer melhor o seu produto (CD). Seguem explicações do CD:

-- a) Contém diversas faixas em que ficam gravadas as músicas. Cada música tem seu tempo de
-- duração e os seus autores.

-- b) Possui informações da gravadora, visto que o departamento de compras da loja, na falta de um
-- CD, pode localizar mais facilmente onde efetuar a compra;

-- c) Possui uma indicação para outro CD.

-- d) Os CDs são classificados com base na faixa de preços (categoria) que ele pertence.

-- Parte 1 – Preparação do Ambiente
-- Executar o script catalogo-MYSQL.

-- Parte 2
-- Com base no modelo Entidade – Relacionamento do Catálogo de CDs realize as questões 1 a 16,
-- utilizando a SQL.

-- 1. Quais as gravadoras que não possuem CDs cadastrados com preço inferior a 80,00?
select
	g.grav_nome
from
	pratica05.gravadora g
left join pratica05.cd c on
	g.grav_codigo = c.grav_codigo
where
	c.cd_preco_venda > 80;

-- 2. Quais os CDs que têm o preço igual ao maior preço de cada gravadora?
select
	c.cd_nome,
	max(c.cd_preco_venda)
from
	pratica05.cd c
group by
	c.cd_nome
having
	max(c.cd_preco_venda) = 
(
	select
		max(cd_preco_venda)
	from
		pratica05.cd
);	
	
-- 3. Quais os CDs que têm preço inferior a qualquer outro CD da gravadora com código 10?
select
	c.cd_nome
from
	pratica05.cd c
where
	c.cd_preco_venda <
(
	select
		c.cd_preco_venda
	from
		pratica05.cd c
	where
		c.cd_codigo = 10
);

-- 4. Quais CDs têm o preço de venda menor que a média de preço de venda de todas as gravadoras?
select
	c.cd_nome,
	c.cd_preco_venda
from
	cd c
where
	c.cd_preco_venda <
(
	select
		avg(c.cd_preco_venda)
	from
		gravadora g
	left join cd c on
		g.grav_codigo = c.grav_codigo
);


-- 5. Liste os nomes dos CDs que tenham preço de venda maior que 10,00 reais ou a gravadora seja a de
-- código 3, ordenados por ordem alfabética decrescente dos nomes dos CDs. Exibir os nomes dos CDs em
-- iniciando com a letra maiúscula.
select
	-- c.cd_nome,
	concat(lower(left(c.cd_nome, 1)), substring(c.cd_nome, 2)) as cd_nome
	-- , c.cd_preco_venda
from
	cd c
inner join gravadora g on
	c.grav_codigo = g.grav_codigo
where
	c.cd_preco_venda > 10
	or g.grav_codigo = 3
order by
	c.cd_nome desc;

-- 6. Exibir o nome, a data de lançamento e nome da gravadora dos CDs que possuem data de lançamento
-- em um intervalo de datas.
select
	c.cd_nome,
	c.cd_data_lancamento,
	g.grav_nome 
from
	cd c
right join gravadora g on
	c.grav_codigo = g.grav_codigo
where
	c.cd_data_lancamento between '2024-11-02' and '2024-11-04';

-- 7. Exibir o nome do Cd e de suas gravadoras, exiba também os CD´S que não possuam gravadoras.
select
	c.cd_nome,
	g.grav_nome
from
	cd c
left outer join gravadora g on
	c.grav_codigo = g.grav_codigo

-- 8. Listar quantas músicas que há em cada CD. (Exibir código do CD e a quantidade de música).

-- 9. Definir a qual categoria (cat_codigo) cada Cd pertence.

-- 10. Listar o nome do CD indicado para cada CD gravado.