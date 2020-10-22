use assignment;
drop table sailors;
drop table boats;
drop table reserves;
drop table sailing;

create table sailors
(
    sailID int,
    sailName varchar(20),
    rating int,
    age real
);

create table boats
(
    boatID int,
    boatName varchar(20),
    color varchar(20)
);

create table reserves
(
    sailID int,
    boatID int,
    day date
);

create table sailing
(
	sid int,
	sname varchar(20),
	Rating int,
	Age real
);

insert into sailors
values
    (101,'s1',3,18),
    (102,'s2',9,20),
    (103,'BUZZB',5,19),
    (104,'s4',10,16),
    (105,'David',6,19),
    (106,'s6',4,17),
    (107,'s7',8,25),
    (108,'s8',8,30),
    (109,'Lubber',7,35),
    (110,'s10',10,27);

insert into boats
values
    (201,'b1','yellow'),
    (202,'b2','orange'),
    (203,'b3','green'),
    (204,'b4','blue'),
    (205,'b5','red'),
    (206,'b6','brown'),
    (207,'b7','black'),
    (208,'b8','blue'),
    (209,'b9','red'),
    (210,'b10','green');
insert into reserves
values
    (101,202,'2019-04-01'),
    (102,208,'2019-03-21'),
    (103,210,'2019-03-17'),
    (104,209,'2019-02-25'),
    (105,203,'2019-03-10'),
    (106,201,'2019-04-19'),
    (107,207,'2019-04-30'),
    (108,204,'2019-02-23'),
    (109,206,'2019-03-02'),
    (105,205,'2019-03-10');


insert into sailing
values
	(18,'Jones',3,30.0),
	(41,'Jonah',6,56.0),
	(22,'Priscilla',7,44.0),
	(63,'Preetham',NULL,15.0);


/*select * from sailors;
select * from boats;
select * from reserves;
select * from sailing;*/
/*  1  */ 
select sailName,age from sailors where rating>7;
/*  2   */
select * from sailors where rating>7;
/*  3   */
select avg(age) from sailors;
/*  4   */
select color from boats inner join reserves on boats.boatID=reserves.boatID inner join sailors on reserves.sailID=sailors.sailID where sailName='Lubber';
/*  5   */
select sailors.sailName,reserves.boatID,reserves.day from sailors inner join reserves on sailors.sailID=reserves.sailID;
/*  6   */
select sailName from sailors inner join reserves on reserves.sailID=sailors.sailID inner join boats on boats.boatID=reserves.boatID where color='red';
/*  7   */
select age from sailors where sailName like "B%_%B";
/*  8   */
select sailName from sailors inner join reserves on reserves.sailID=sailors.sailID inner join boats on boats.boatID=reserves.boatID where color='red' or color='green';
/*  9   */
select reserves.sailID from reserves inner join boats on boats.boatID=reserves.boatID inner join sailors on reserves.sailID=sailors.sailID where (age>20 and not color='red');
/*  10 */
select s.sailName from sailors s,boats b1,reserves r1,boats b2,reserves r2 where s.sailID=r1.sailID and r1.boatID=b1.boatID and s.sailID=r2.sailID and r2.boatID=b2.boatID and (b1.color='red' and b2.color='green');
/*  11  */
select sailors.sailID from sailors inner join reserves on reserves.sailID=sailors.sailID inner join boats on reserves.boatID=boats.boatID where color='red' and not color= 'green' ;
/*  12  */
select sailName from sailors where rating in (select max(rating) from sailors);
/*  13  */
select count(color) from boats inner join reserves on reserves.boatID=boats.boatID where color='red';
/*  14  */
select avg(age) from sailors group by rating having count(*)>=2;
/*  15  */
select avg(age) from sailors where age>=18 group by rating having count(*)>=2;
/*  16  */
select avg(age) from sailors where age>=18 group by rating having count(*)>=2 ;
/*  17a  */
select * from sailing s1 left outer join sailing s2 on s1.sid=s2.sid;
/*  17b */ 
select * from sailing s1 right outer join sailing s2 on s1.sid=s2.sid;
/*  17c  */
select * from sailing s1 left outer join sailing s2 on s1.sid=s2.sid union select * from sailing s1 right outer join sailing s2 on s1.sid=s2.sid;
/*  18  */
select min(age) from sailors where age>=18 group by rating having count(*)>=2;
/*  19  */
select sailName from sailors where rating>(select rating from sailors where sailName='David');
/*  20  */
select distinct(s.rating+1) from sailors s,boats b1,reserves r1,boats b2,reserves r2 where s.sailID=r1.sailID and r1.boatID=b1.boatID and s.sailID=r2.sailID and r2.boatID=b2.boatID and b1.boatID!=b2.boatID ; 
/*  21  */

/*  22  */
select sailName from sailors where rating>(select max(rating) from sailors where sailName='David');




/*to select similar atleat 2 object*/
/*select rating from sailors group by rating having count(*)>=2;*/

