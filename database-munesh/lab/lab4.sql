use lab4;
create table library
(
    ref_no int not null primary key,
    book_name varchar(50),
    author varchar(20),
    price int
);
insert into library
VALUES
    (1,'Math','Amar',305),
    (2,'Physics','Firoz',610),
    (3,'Chemistry','Saumya',470),
    (4,'Biology','Praveen',203),
    (5,'Sociology','Krishna',101),
    (6,'Design','Bazif',740),
    (7,'Computer','Shiv',530);
/*starting table*/
    select * from library;
/*adding column website and email*/
    alter table library add (website varchar(30),contact int);
/*show new table*/
    select * from library;
/*describe the new table*/
    desc library;
/*changing contact with int to varchar*/
    alter table library modify contact varchar(30);
/*describing new table*/
    desc library;
/*changing column contact with email*/
    alter table library change contact email varchar(30);
/*show new table*/
    SELECT * FROM library;
/*deleting a column*/
    alter table library drop website;
/*show new table*/
    SELECT * FROM library;
/*calculating average of price*/
    select avg(price) from library;
/*5% GST on price*/
    select avg(price*0.05) from library;
/*counting no. of rows*/
    select count(author) from library;
/*updating table*/
    update library set author='Amar' where ref_no=5;
/*show new table*/
    select * from library;
/*counting distinct author name*/
    select count(distinct author) from library;
/*show maximum price of book*/
    select max(price) from library;
/*show minimum price of book*/
    select min(price) from library;
/*summing all the price*/
    select sum(price) from library;
/*rounding average price*/
    select avg(ref_no),round(avg(price),2) rounded_score from library;
/*adding constraint*/
    alter table library add constraint constraint_1 unique(book_name);
    alter table library add constraint constraint_2 unique(price);
/*describe table*/ 
    desc library;
    alter table library drop index constraint_1;
    desc library;