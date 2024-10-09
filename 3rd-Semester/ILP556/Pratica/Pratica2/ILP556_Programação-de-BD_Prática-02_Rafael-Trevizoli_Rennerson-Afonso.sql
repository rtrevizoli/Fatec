use venda;

-- Pratica 2 - Juncoes
-- ILP556 - Programação de Banco de Dados
-- Professora Juliana Forin Pasquini Martinez
-- Rafael Trevizoli - 1460282423016
-- Rennerson Vasconcelos Afonso - 1460282323017

-- 1. Listar todos os clientes, ordenados por nome do cliente.
select * from cliente c order by cli_nome asc;

-- 2. Listar os clientes que os nomes comecem com as letras ‘F’ ou ‘B’ e são do estado de São
-- Paulo (SP). Dica: Usar o comando like.
select *
from cliente c
where cli_estado = 'SP' 
	and cli_nome like 'F%' or cli_nome like 'B%';

-- 3. Listar o nome do cliente do pedido de número 1.
select c.cli_nome
from cliente c
	inner join pedido p on p.cli_codigo = c.cli_codigo
where p.ped_numero = 1;

-- 4. Listar o nome do cliente, o nome do vendedor do pedido de código 2.
select c.cli_nome
from cliente c 
	inner join pedido p on p.cli_codigo = c.cli_codigo
	inner join vendedor v on p.ven_codigo = v.ven_codigo
where p.ped_numero = 2;

-- 5.  Listar a quantidade de pedido.
select count(*) from pedido p;

-- 6. Listar a quantidade de pedido que cada vendedor realizou (Dica: Utilizar group by)
select v.ven_nome, count(p.ped_numero)
from pedido p
	inner join vendedor v on p.ven_codigo = v.ven_codigo
group by v.ven_codigo;

-- 7. Listar todos os itens do pedido de código 1.
select p2.prod_descricao
from pedido p
	inner join item_pedido ip on p.ped_numero = ip.ped_numero
	inner join produto p2 on ip.pro_codigo = p2.pro_codigo
where p.ped_numero = 1;

-- 8. Listar a soma total do pedido de código 1.
-- 8.1 Jeito facil
select p.ped_valor_total from pedido p where p.ped_numero = 9;

-- 8.2 Jeito dificil 
select sum(ip.item_quantidade * p2.pro_valor_unidade)
from pedido p 
	inner join item_pedido ip on p.ped_numero = ip.ped_numero
	inner join produto p2 on ip.pro_codigo = p2.pro_codigo
where p.ped_numero = 1;

-- 9. Listar os clientes e os seus telefones (Listar apenas os clientes que possuam telefone).
-- Dica: Junção: Inner join /where
select c.cli_nome, t.tel_numero from cliente c 
	inner join telefone t on c.cli_codigo = t.cli_codigo;

-- 10. Listar os clientes e os seus telefones (Listar também os clientes que não tenham
-- telefone)
-- Dica: left outer join /right outer join
select c.cli_nome, t.tel_numero from cliente c 
	left join telefone t on c.cli_codigo = t.cli_codigo;

-- 11. Listar quantidade de produtos por unidade(descrição).
select p.prod_descricao, p.pro_quantidade from produto p 

-- 12. Listar todos os pedidos realizados na data 01/10/2010.
select * from pedido p where p.ped_data = '2010-10-01';

-- 13. Listar todos os pedidos realizados na data 01/10/2010 e que possuem prazo de entrega
-- maior que 3
select * from pedido p where p.ped_data = '2010-10-01' and p.ped_prazo_entrega > 3;

-- 14. Listar todas as vendas(pedidos) do produto Caneta.
select p.ped_numero from pedido p 
	right join item_pedido ip on p.ped_numero = ip.ped_numero 
	right join produto p2 on ip.pro_codigo = p2.pro_codigo
where p2.prod_descricao = 'CANETA'

-- 15. Listar todos os pedidos que o cliente de código 1 realizou (Listar o número do pedido,
-- data do pedido e o nome do cliente).
select p.ped_numero, p.ped_data, c.cli_nome from cliente c 
	left join pedido p on c.cli_codigo = p.cli_codigo
where p.cli_codigo = 1;

-- 16. Listar a quantidade de pedido que o cliente do código 2 realizou.
select count(*) from pedido p 
	right join cliente c on p.cli_codigo = c.cli_codigo
where c.cli_codigo = 2;

-- 17. Listar o nome do produto de maior valor.
select max(p.pro_valor_unidade) from produto p;

-- 18. Quais os pedidos que têm quantidade de itens maior que 5?
select a.ped_numero from (
	select p.ped_numero, count(p.ped_numero) qtd_items from pedido p 
		inner join item_pedido ip on p.ped_numero = ip.ped_numero
	group by ip.ped_numero
) a
where a.qtd_items > 1;

-- 19. Quais clientes têm pedidos com prazo de entrega maior que 15 dias e que são do estado de
-- São Paulo ou Rio de Janeiro?
select * from cliente c 
	inner join pedido p on c.cli_codigo = p.cli_codigo 
where p.ped_prazo_entrega > 15
	and c.cli_estado in ('RJ', 'SP');

-- 20. Criar mais 7 consultas (Perguntas e Respostas), seguindo as sintaxes apresentadas na
-- imagem a seguir. OBS: Usar Union para representar o FULL OUTER JOIN.
select * from cliente c 
	left join pedido p on c.cli_codigo = p.cli_codigo;

select * from cliente c 
	inner join pedido p on c.cli_codigo = p.cli_codigo;

select * from cliente c 
	right join pedido p on c.cli_codigo = p.cli_codigo;

select * from cliente c 
	left join pedido p on c.cli_codigo = p.cli_codigo
where p.cli_codigo is null;

select * from cliente c 
	right join pedido p on c.cli_codigo = p.cli_codigo
where c.cli_codigo is null;

select cli_codigo from cliente c 
union
select cli_codigo from pedido p;

select cli_codigo from cliente c
where cli_codigo is null
union
select cli_codigo from pedido p
where cli_codigo is null ;


