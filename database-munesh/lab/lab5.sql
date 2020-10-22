use lab5;
drop table borrower;
drop table depositor;
create table borrower
(
    branch_id int not null primary key,
    borrower_name varchar(20),
    bank_name varchar(20),
    loan_number int

);

create table depositor
(
    branch_id int not null primary key,
    depositor_name varchar(20),
    amount int,
    account_number int
);

insert into borrower
values
    (1,'amar','SBI',12536),
    (2,'shiv','PNB',79641),
    (3,'firoz','ICICI',69794),
    (4,'SP','BOB',49461),
    (5,'krishna','CBI',16496);

insert into depositor
values
    (1,'amar',1000,16412536),
    /*(2,'shiv',2500,79279641),*/
    /*(3,'firoz',6000,16569794),*/
    /*(4,'SP',4500,19481149),
    (5,'krishna',7000,54946316),*/
    (6,'praveen',8000,21548565);

/*select*//*working*/
select * from borrower where branch_id<=4 and loan_number<69999;
/*project*//*working*/
select depositor_name,amount from depositor where amount>=4500;
/*union*//*working*/
select borrower_name from borrower union select depositor_name from depositor;
/*intersection*/
select branch_id,borrower_name from borrower inner join depositor using(branch_id);
/*difference*/
select * from borrower where borrower_name not in (select depositor_name from depositor);  
/*cartesian product*//*working*/
select borrower.borrower_name,borrower.bank_name,borrower.loan_number,depositor.amount from borrower cross join depositor;
/*rename*/
rename table borrower to borr;
show tables;
/*max*/
select * from depositor order by amount desc limit 1;


