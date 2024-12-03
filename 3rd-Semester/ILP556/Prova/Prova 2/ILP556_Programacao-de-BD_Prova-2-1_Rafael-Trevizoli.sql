-- 2a Avaliação de Programação de BD
-- ILP556 - Programação de Banco de Dados
-- Professora Juliana Forin Pasquini Martinez
-- Rafael Trevizoli - 1460282423016

-- Obs.: Assume-se que os scripts DDL/ DML (Biblioteca.sql/ Biblioteca_insert.sql) foram executados.

-- Com base no modelo lógico relacional do estudo de caso Biblioteca 
-- resolva as questões a seguir utilizando SQL.

-- 1. (2,0) Listar todas os títulos dos livros que não foram devolvidos.
select
	distinct l.liv_titulo
from
	livro l
inner join exemplar e on
	l.liv_cod = e.liv_cod
inner join item_emprestimo ie on
	e.exe_cod = ie.exe_cod
left join devolucao d on
	ie.emp_cod = d.emp_cod
	and ie.exe_cod = d.exe_cod
where
	d.dev_cod is null

-- 2. (2,0) Exibir quantidade de exemplares por livros, exiba também os livros que não possuam exemplares.
select
	l.liv_titulo,
	count(l.liv_titulo)
from
	livro l
right join exemplar e on
	l.liv_cod = e.liv_cod
group by
	l.liv_titulo

-- 3. (2,0) Listar o aluno com maior número de exemplares emprestados.
select
	p.pes_nome,
	count(e.emp_cod) emprestimos
from
	emprestimo e
right join pessoa p on
	e.pes_cod = p.pes_cod
inner join aluno a on p.pes_cod = a.pes_cod 
group by
	1
order by
	emprestimos desc
limit 1

-- 4. (2,0) Liste os três alunos com o maior número de exemplares emprestados, e em seguida os três 
-- professores com o maior número de exemplares emprestados.
(
select
	p.pes_nome,
	count(e.emp_cod) emprestimos
from
	emprestimo e
right join pessoa p on
	e.pes_cod = p.pes_cod
inner join aluno a on
	p.pes_cod = a.pes_cod
group by
	p.pes_nome
)
union
(
select
        p.pes_nome,
        count(e.emp_cod) emprestimos
from
        emprestimo e
right join pessoa p on
        e.pes_cod = p.pes_cod
inner join professor p2 on
p.pes_cod = p2.pes_cod
group by
        p.pes_nome
)
order by
    emprestimos desc
limit 6;

-- 5. (2,0) Crie um gatilho (trigger), chamado tr_atualiza_status, que seja acionado após a inserção 
-- de uma nova linha na tabela item_empréstimo. Esse gatilho deve atualizar a coluna ex_status do 
-- exemplar correspondente na tablea exemplar para o valor 1.
create trigger tr_atualiza_status
after
insert
	on
	item_emprestimo
for each row
begin
    update
		exemplar e
	set
		e.ex_status = 1
	where
		e.exe_cod = NEW.exe_cod;		
end
