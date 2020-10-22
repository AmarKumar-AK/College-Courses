
drop database lab7;
create database lab7;
use lab7;
create table salesman(sid int, sname varchar(20), city varchar(20), commission float);
create table customer(cid int, cname varchar(20), city varchar(20), grade int, sid int);
create table ordr(order_no int, amount float, order_date date, cid int,sid int);

insert into salesman values
	(5001,'james hoog','new york',0.15),
	(5002,'nail knite','paris',0.13),
	(5005,'pit alex','london',0.11),
	(5006,'mc lyon','paris',0.14),
	(5003,'lauson hen','california',0.12),
	(5007,'paul adam','rome',0.13);
insert into customer values
	(3002,'nick romando','new york',100,5001),
	(3005,'graham zusi','california',200,5002),
	(3001,'brad guzan','london',300,5005),
	(3004,'fabian johns','paris',300,5006),
	(3007,'brad davis','new york',200,5001),
	(3009,'geoff camero','berlin',100,5003),
	(3008,'julian green','london',300,5002),
	(3003,'jozy altidor','moscow',200,5007);
insert into ordr values
	(70001,	150.5,	'2012-10-05'	,3005,	5002),
	(70009,	270.65,	'2012-09-10'	,3001,	5005),
	(70002,	65.26,	'2012-10-05'	,3002,	5001),
	(70004,	110.5,	'2012-08-17'	,3009,	5003),
	(70007, 948.5, 	'2012-09-10'	,3005, 	5002),
	(70005, 2400.6, '2012-07-27'	,3007, 	5001),
	(70008, 5760, 	'2012-09-10'	,3002, 	5001),
	(70010, 1983.43,'2012-10-10'	,3004, 	5006),
	(70003, 2480.4, '2012-10-10'	,3009, 	5003),
	(70012, 250.45, '2012-06-27'	,3008, 	5002),
	(70011, 75.29, 	'2012-08-17'	,3003, 	5007),
	(70013, 3045.6,	'2012-04-25' 	,3002,	5001);
/*select * from salesman;
select * from customer;
select * from ordr;*/
-- create view v1 as
-- (select s.sname,count(o.sid) 'number_of_order',avg(o.amount) 
-- 'avg_purchase amount' from salesman as s,ordr as o
-- where s.sid=o.sid group by s.sname);
-- select * from v1;

-- create view v2 as
-- (select s.sname from salesman as s 
-- where s.commission>0.13 and city='new york');
-- select * from v2;

-- create view v3 as
-- (select o.order_date,count(o.order_date) '#c_ordr',
-- count(distinct(o.sid)) '#sman_attchd',
-- avg(o.amount),sum(o.amount)
-- from ordr as o group by order_date);
-- select * from v3;

-- create view v4 as
-- (select o.order_no,s.sname,c.cname from salesman as s,
-- ordr as o,customer as c where s.sid=o.sid and c.cid=o.cid);
-- select * from v4;

-- create view temp1 as
-- (select distinct(o.order_date) "ordrdate",max(o.amount) "amount"  
-- from ordr as o group by o.order_date);
-- create view v5 as
-- (select t.ordrdate,o.sid,s.sname from temp1 as t,ordr as o,
-- salesman as s where t.amount=o.amount and o.sid=s.sid);
-- select * from v5;

-- create view temp3 as
-- select o.order_date,o.sid from ordr as o group by o.order_date,o.sid;
-- select s.sname from salesman as s inner join temp3
-- create view temp4 as
-- (select o.sid,o.amount from ordr as o  order by o.sid,o.amount);
-- create view temp5 as 
-- (select sid,sum(amount) "amt" from temp4 group by sid 
-- having count(sid)>=3);
-- select a.sid from temp5 as a where amt=(select max(b.amt) from temp5 as b);

-- create view v7 as
-- (select * from customer where grade=(select max(grade) 
-- from customer));
-- select * from v7;

-- create view v8 as
-- (select count(s.sid)"#salesman",s.city from salesman as s 
-- group by s.city);
-- select * from v8;

-- create view temp2 as
-- (select s.sid,s.sname,c.cid,c.cname from salesman as s,customer as c
-- where c.city=s.city);
-- create view v9 as
-- (select t.sname,t.cname from temp2 as t,ordr as o 
-- where t.sid=o.sid and t.cid=o.cid); 
-- select * from v9;

-- create view v10 as
-- (select * from salesman as s where s.sid in
-- (select o.sid from ordr as o where o.order_date='2012-10-10'));
-- select * from v10;

-- create view v11 as
-- (select * from salesman as s where s.sid in
-- (select o.sid from ordr as o where o.order_date='2012-08-17' union
-- (select p.sid from ordr as p where p.order_date='2012-10-10')));
-- select * from v11;