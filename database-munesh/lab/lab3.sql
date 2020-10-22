use lab3;
create table employee_table(
	id smallint auto_increment not null primary key ,
	name varchar(20),
	salary int,
	age int,
	joiningDate date,
	contact int,
	Designation varchar(20)
	);
insert into employee_table
	values
	(1,'Amar kumar',20000,18,'2019-01-01',5496434,'faculty'),
	(2,'Saumya prakash',40000,19,'2018-02-02',1346463,'faculty'),
	(3,'Firoz kumar',35000,19,'2018-03-03',4964616,'faculty'),
	(4,'Praveen prakash',57000,18,'2017-05-05',2974631,'student'),
	(5,'Krishna kumar',32000,20,'2017-04-04',4943146,'faculty'),
	(6,'Aviral prakash',46000,22,'2018-09-08',4964313,'faculty'),
	(7,'Bazif kumar',19000,19,'2018-07-06',413649,'faculty'),
	(8,'shiv prakash',68000,18,'2017-05-04',216946,'faculty'),
	(9,'samarth kumar',52000,20,'2017-02-03',136846,'faculty');
select * from employee_table;

select name from employee_table;

select * from employee_table where name like "%kumar%";

select * from employee_table where name like "A_a%";

select * from employee_table where name like "%prakash";

select name,age,
		case when age >=20 then 'experienced' else 'non experienced' end as 'Experience' from employee_table;

select em.name,em.age,
		if(em.age>=20,'experienced','non experienced') as 'Experience'
from employee_table as em;

select name as username from employee_table;

select * from employee_table order by age;

select * from employee_table order by contact limit 2,3;

select * from employee_table where id between 4 and 6;

select * from employee_table where id not between 2 and 5;

select * from employee_table where age=18 and Designation='faculty';
update employee_table set name='Amar kumar2' where name='Amar kumar';