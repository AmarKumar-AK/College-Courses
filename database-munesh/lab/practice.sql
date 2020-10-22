use practice;
drop table instructor;
create table instructor(name varchar(20),deptname varchar(20),salary int);
insert into instructor values
('a','a1',1000),
('b','b1',1500),
('c','b1',1200),
('d','a1',1900),
('e','c1',1500),
('f','d1',1300),
('g','b1',1700),
('h','b1',1800),
('i','c1',1100),
('j','a1',1600),
('k','b1',1400);

/*select name from instructor where salary < all(select salary from instructor where deptname='b1'); */
/*select name,deptname from instructor where salary > some(select salary from instructor where deptname='b1');*/
/*select distinct * from instructor as T,instructor as S where T.salary>S.salary and S.deptname='b1';*/
/*update instructor set salary=salary*1.5;*/
/*create view faculty as select name,deptname from instructor;*/
/*create view departmenttotalsalary(deptname,totalsalary) as select deptname,sum(salary) from instructor group by deptname;*/
/*update instructor set salary=case when salary<=1500 then salary*1.5 else salary*2 end;*/








/*...................not working............................*/

/*select A.deptname from instructor as A where 
unique
(select B.deptname from instructor as B where A.deptname=B.deptname);*/
/*select deptname,avgs from 
(select deptname,avg(salary) as avgs from instructor group by deptname where avgs>1300);*/
/*select deptname,avgs from 
(select deptname,avg(salary) as from instructor group by deptname) 
as deptavg(dname,avgs) where avgs>1300;*/