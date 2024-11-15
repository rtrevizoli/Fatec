create database if not exists pratica06;
use pratica06;

-- Pratica 6
-- ILP556 - Programação de Banco de Dados
-- Professora Juliana Forin Pasquini Martinez
-- Rafael Trevizoli - 1460282423016
-- Caique Ramon Carvalho de Almeida - 1460282323041

-- Triggers
-- show triggers

-- Obs.: Assume-se que o script DDL/ DML (funcionario.sql) foi executado.
alter table func_log modify column msg text

-- Criar triggers que altere o atributo derivado(dep_total_sal) quando ocorrer:
--  1. Inserção de um novo empregado:
-- Criação do trigger.
drop trigger if exists incrementa_folha_departamento_apos_novo_funcionario

create trigger incrementa_folha_departamento_apos_novo_funcionario
after
insert
	on
	funcionario
for each row
begin
	if new.fun_sal > 0 then
	    update
			departamento d
		set
			d.dep_total_sal = d.dep_total_sal + NEW.fun_sal
		where
			d.dep_id = NEW.dep_id;
		
		insert into func_log (fun_id, fun_data, novo_sal, msg)
		values (new.fun_cod, now(), new.fun_sal, concat("Funcionário adicionado, salario: ", "R$", " ", new.fun_sal));
	end if;
end

-- Valor total de salário do departamento antes da inserção de um novo funcionário.
select d.dep_total_sal from departamento d where d.dep_id = 3
select * from func_log fl 

-- Inserção de um novo funcionário.
insert into funcionario values (7, "Dirceu", 7000, 3)

-- Valor total de salário do departamento após inserção de um novo funcionário.
select d.dep_total_sal from departamento d where d.dep_id = 3
select * from func_log fl 

--  2. Alteração salarial de um empregado:
-- Criação do trigger.
drop trigger if exists ajusta_folha_departamento_apos_alteracao_salarial_de_funcionario

create trigger ajusta_folha_departamento_apos_alteracao_salarial_de_funcionario
after
update
	on
	funcionario
for each row
begin
	if new.fun_sal <> old.fun_sal then
	    update
			departamento d
		set
			d.dep_total_sal = d.dep_total_sal + (NEW.fun_sal - OLD.fun_sal)
		where
			d.dep_id = NEW.dep_id;
		
		insert into func_log (fun_id, fun_data, novo_sal, msg)
		values (
			new.fun_cod
			, now()
			, new.fun_sal
			, concat("Reajuste salarial (", "R$", " ", old.fun_sal, " => ", "R$", " ", new.fun_sal, ")")
		);
	end if;
end

-- Valor total de salário do departamento antes da alteração salarial de um empregado.
select d.dep_total_sal from departamento d where d.dep_id = 1
select * from func_log fl where fun_id = 3

-- Alteração salarial de um empregado.
update funcionario f set f.fun_sal = 3000 where f.fun_cod = 3

-- Valor total de salário do departamento após a alteração salarial de um empregado.
select d.dep_total_sal from departamento d where d.dep_id = 1
select * from func_log fl where fun_id = 3

--  3. Mudança de departamento
-- Criação do trigger
drop trigger if exists ajusta_folha_departamentos_apos_transferencia_de_funcionario

create trigger ajusta_folha_departamentos_apos_transferencia_de_funcionario
after
update
	on
	funcionario
for each row
begin
	if new.dep_id <> old.dep_id then
		update
			departamento d
		set
			d.dep_total_sal = d.dep_total_sal - old.fun_sal
		where
			d.dep_id = old.dep_id;

		update
			departamento d
		set
			d.dep_total_sal = case
				when 
					(select 1 from INFORMATION_SCHEMA.TRIGGERS where TRIGGER_NAME = "ajusta_folha_departamento_apos_alteracao_salarial_de_funcionario")
				then
					d.dep_total_sal + old.fun_sal
				else 
					d.dep_total_sal + new.fun_sal
				end
		where
			d.dep_id = new.dep_id;
		
		insert into func_log (fun_id, fun_data, novo_sal, msg)
		values (
			new.fun_cod
			, now()
			, case
				when 
					(select 1 from INFORMATION_SCHEMA.TRIGGERS where TRIGGER_NAME = "ajusta_folha_departamento_apos_alteracao_salarial_de_funcionario")
				then
					old.fun_sal
				else 
					 new.fun_sal
				end
			, concat("Mudança de departamento (", (select d.dep_descricao from departamento d where d.dep_id = old.dep_id), " => ", (select d.dep_descricao from departamento d where d.dep_id = new.dep_id), ")")
		);
	end if;
end

-- Valor total da folha salarial do departamento a e b antes da transferência de funcionário.
select d.dep_descricao, d.dep_total_sal from departamento d where dep_id in (2, 4)
select * from func_log fl where fun_id in (2 ,4)

-- Transferência de funcionáro do setor a para o setor b com aumento salarial
update funcionario f set f.dep_id = 4, f.fun_sal = (f.fun_sal + 500) where f.fun_cod = 2
select * from func_log fl where fun_id = 2

-- Transferência de funcionáro do setor a para o setor b sem aumento salarial
update funcionario f set f.dep_id = 4 where f.fun_cod = 4
select * from func_log fl where fun_id = 4

-- Valor total da folha salarial do departamento a e b após a transferência de funcionário.
select d.dep_descricao, d.dep_total_sal from departamento d where dep_id in (2, 4)
select * from func_log fl where fun_id in (2 ,4)

--  4. Remoção de um empregado
drop trigger if exists funcionario_desligado

create trigger funcionario_desligado
after
delete
	on
	funcionario
for each row
begin
	update departamento d
	set
		d.dep_total_sal = d.dep_total_sal - old.fun_sal
	where
		d.dep_id = old.dep_id;
	
	insert into func_log (fun_id, fun_data, novo_sal, msg)
	values (
		old.fun_cod
		, now()
		, old.fun_sal
		, concat("Funcionário desligado, salario: ", "R$", " ", case when old.fun_sal is null then 0 else old.fun_sal end)
	);
end

-- Funcionário e log funcionário antes do desligamento.
select f.fun_cod, f.fun_nome, f.fun_sal, d.dep_descricao, d.dep_total_sal from funcionario f left join departamento d on f.dep_id = d.dep_id where f.fun_cod in (5, 6)
select * from func_log where fun_id in (5, 6)

-- Desligamento de funcionário que não recebe salário e não está vinculado a nenhum setor.
delete from funcionario where fun_cod = 6

-- Desligamento de funcionario que recebe salário e está vinculado a algum setor.
delete from funcionario where fun_cod = 5

-- Funcionário e log funcionário após o desligamento
select f.fun_cod, f.fun_nome, f.fun_sal, d.dep_descricao, d.dep_total_sal from funcionario f left join departamento d on f.dep_id = d.dep_id where f.fun_cod in (5, 6)
select * from func_log where fun_id in (5, 6)


