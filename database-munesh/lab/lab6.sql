/*Flights ​ ( f ​ lno: integer ​ , from: string, to: string, distance: integer, Departs:time, arrives:time,
price:integer)
Aircraft ​ ( a ​ id: integer ​ , aname: string, cruisingrange: integer)
Certified ( ​ ​ eid: integer, aid: integer ​ )
Employees ​ ( ​ eid: integer ​ , ename: string, salary: integer)*/
drop database lab6;
create database lab6;
use lab6;

create table Flights(flno int,source varchar(20),destination varchar(20),distance int,departs time, arrives time,price int);
create table Aircraft(aid int,aname varchar(20),cruisingrange int);
create table Certified(eid int,aid int);
create table Employees(eid int,ename varchar(20),salary int);

insert into Flights values
(1,'Los Angles','Chicago',1800,'06:00:00','09:00:00',5000),
(2,'Delhi','Madras',3900,'07:00:00','8:30:00',4500),
(3,'Honolulu','Chicago',350,'14:00:00','14:30:00',3000),
(4,'Los Angeles','Honolulu',1200,'12:00:00','14:00:00',35000),
(5,'Kolkata','Madras',1900,'17:00:00','20:30:00',5500),
(6,'Madison','New York',500,'15:00:00','18:00:00',4000),
(7,'Kolkata','Delhi',5000,'13:00:00','15:00:00',3500);
insert into Aircraft values
(11,'a',3200),
(12,'b',500),
(13,'Boeing',3800),
(14,'d',1100),
(15,'e',4000),
(11,'f',3500),
(11,'g',300),
(12,'i',1500),
(12,'j',2500),
(11,'h',1400);
insert into Certified values
(101,11),
(102,11),
(102,12),
(103,13),
(105,13),
(105,15);
insert into Employees values
(101,'ak',78000),
(102,'bk',20000),
(103,'ck',82000),
(104,'dk',70000),
(105,'ek',185000),
(106,'fk',95000);
/*select * from Aircraft; select * from Employees; select * from Certified; select * from Flights;*/

/*  1   */
/*select A.aname from Aircraft as A 
inner join Certified as C 
on A.aid=C.aid
inner join Employees as E
on E.eid=C.eid
where salary>80000;*/

/*  1   */
select A.aname from Aircraft as A 
where A.aid in (select C.aid from Certified as C 
where C.eid in (select E.eid from Employees as E 
where salary>80000));

/*  2   */
create view new as (select C.eid,A.cruisingrange from 
Certified as C,Aircraft as A where C.aid 
in (select A.aid from Aircraft));

select eid,max(cruisingrange) 
from new group by eid having count(eid)>3;

/*  3   */
select E.ename from Employees as E where 
salary<(select min(F.price) from Flights as F 
where source='Los Angeles' and destination='Honolulu');

/*  4   */
select A.aname,avg(E.salary) from Aircraft as A 
inner join Certified as C on C.aid=A.aid
inner join Employees as E on C.eid=E.eid
where cruisingrange>1000 group by A.aname ; 

/*  5   */
select E.ename from Employees as E 
inner join Certified as C on C.eid=E.eid
inner join Aircraft as A on A.aid=C.aid
where A.aname='Boeing';

/*  6   */
/*  7   */
/*  8   */
create view em as (select C.eid from Certified as C
where C.aid in (select distinct(A.aid) from Aircraft as A 
where A.aname='Boeing')); 

select E.ename from Employees as E 
where E.eid in (select distinct(C.eid) from Certified as C 
where C.eid not in (select eid from em));

/*  9   */
/*  10  */
create view avg1 as 
(select avg(salary) "salary" from Employees as E);

create view avg2 as 
(select avg(salary) "salary" from Employees as E 
where E.eid in (select distinct(C.eid) from Certified as C));

select abs(avg1.salary-avg2.salary) "salary difference" from avg1,avg2; 

/*  11  */
select  E.ename,E.salary from Employees as E
where E.eid not in (select distinct(C.eid) from Certified as C)
and E.salary>(select avg(salary) "salary" from Employees as E 
where E.eid in (select distinct(C.eid) from Certified as C));

/*  12  */
create view mile as (select distinct(A.aid) from Aircraft as A 
where A.aid in (select C.aid from Certified as C) 
and A.cruisingrange>1000);
select E.ename from Employees as E where E.eid in
(select distinct(C.eid) from Certified as C 
where C.aid in (select mile.aid from mile));

/*  13  */
create view v1 as (select A.aid from Aircraft as A 
where A.aid in (select C.aid from Certified as C)
and A.cruisingrange>1000);
select E.ename from Employees as E 
where E.eid in (select C.eid from Certified as C 
where C.aid in (select v1.aid from v1 
group by v1.aid having count(v1.aid)>=2)); 

/*  14  */
select E.ename from Employees as E 
where E.eid in (select C.eid from Certified as C 
where C.aid in (select A.aid from Aircraft as A 
where A.aid in (select C.aid from Certified)
and A.cruisingrange>1000 and A.aname='Boeing'));

/*  15  */
select C.eid from Certified as C 
where C.aid in(select A.aid from Aircraft as A 
where A.aname='Boeing');

/*  16  */
select E.ename from Employees as E 
where E.eid in(select C.eid from Certified as C 
where C.aid in(select A.aid from Aircraft as A 
where A.aname='Boeing'));

/*  17  */
select A.aid from Aircraft as A 
where A.cruisingrange>
(select F.distance from Flights as F 
where source='Kolkata' and destination='Madras' );

/*  18  */
create view dist as
(select A.cruisingrange from Aircraft as A
where A.aid in (select C.aid from Certified as C
where C.eid in (select E.eid from Employees as E
where salary>100000)));
select * from Flights where distance < 
(select min(cruisingrange) from dist);

/*  19  */
create view temp as(
select C.eid from Certified as C where C.aid in(select distinct(A.aid) from Aircraft as A where A.cruisingrange>3000));
select E.ename from Employees as E where E.eid in(
select T.eid from temp as T where T.eid not in(select C.eid from Certified as C where C.aid in (select distinct(B.aid) from Aircraft as B where B.aname='Boeing')));
/*	20	*/

create view temp1 as(
select max(F.salary) "eid of Employees with max salary" from Employees as F where F.eid in(
select E.eid from Employees as E where E.eid not in(select C.eid from Certified as C)));
create view temp2 as(select max(F.salary) "eid of Employees with max salary" from Employees as F where F.eid in(
select E.eid from Employees as E where E.eid in(select C.eid from Certified as C)));
select * from temp1 union (select * from temp2);
/*	21	*/

create view emp as (
select * from Employees as F where F.eid in(
select E.eid from Employees as E where E.eid not in(select C.eid from Certified as C)));
create view pil as (
select * from Employees as F where F.eid in(
select E.eid from Employees as E where E.eid in(select C.eid from Certified as C)));

(select eid from emp order by salary desc limit 1,1) union
(select eid from pil order by salary desc limit 1,1);
/*	22	*/
create view lnum1 as(
select A.aid,count(A.aid) "cou" from Aircraft as A group by A.aid); 
select L.aid from lnum1 as L where L.cou=(select max(M.cou) from lnum1 as M);
/*	23	*/

create view lnum as(
select A.aid,count(A.aid) "cou" from Aircraft as A group by A.aid); 
select L.aid from lnum as L where L.cou=3;
/*	24	*/

select sum(E.salary) "sal" from Employees as E where E.eid in(select C.eid from Certified as C) union
(select sum(E.salary) "sal" from Employees as E where E.eid not in(select C.eid from Certified as C));











/*
with recursive 
reachable_from(source,destination,depth) as 
(select root.source,root.destination,0 as depth
from Flights as root where root.source='Los Angeles'
union all 
select in1.source,out1.destination,in1.depth+1 from
reachable_from in1,Flights out1 where
in1.destination=out1.source and in1.depth<=10);
select * from reachable_from;*/

/*select A.aid from Aircraft as A
group by A.aid having count(A.aid)>3;*/
/*select max(cruisingrange),aid from Aircraft 
group by aid having count(aid)>3;*/
/*select A.aname,E.salary from Aircraft as A,Employees as E 
where A.aid in (select C.aid from Certified as C);*/
