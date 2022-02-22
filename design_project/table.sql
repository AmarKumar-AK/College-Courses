use elec;

drop table employee;
create table employee(eid int primary key,ename varchar(50),doj date,dob date,dept varchar(50),age int,boardname varchar(50),designation varchar(50),phone bigint,password varchar(50));
drop table consumer;
create table consumer(cid int,cname varchar(50),phone bigint,boardname varchar(50),state varchar(50),subdiv varchar(50),divis varchar(50),city varchar(50),meterno int primary key,password varchar(50),email varchar(50),address varchar(50));
drop table distributioncompany;
create table distributioncompany(did int primary key,dname varchar(50),tenure int,state varchar(50),tid int);
	drop table powercompany;
create table powercompany(pid int primary key,pname varchar(50),type varchar(50),totalpower int,state varchar(50));
	drop table transmissioncompany;
create table transmissioncompany(tid int primary key,tname varchar(50),did int,tcapacity int,state varchar(50),tenure int);
	drop table circles;
create table circles(cname varchar(50),state varchar(50),managerid int,did int);
	drop table division;
create table division(divid int primary key,divname varchar(50),headname varchar(50),state varchar(50), did int);
	drop table subdivision;
create table subdivision(sdivid int primary key,divid int,headname varchar(50),state varchar(50),sdivname varchar(50));
	drop table electricityboard;
create table electricityboard(boardname varchar(50) primary key,noofconsumer int,state varchar(50),chairmanid int,powerconsumed int);
	drop table billinginfo;
create table billinginfo(billid int primary key,cid int,issuedate date,prevreading int,meterno int,curreading int,rate int,type varchar(50),unit int);
	drop table newconnection;
create table newconnection(cname varchar(50),phone bigint,boardname varchar(50),state varchar(50),subdiv varchar(50),divis varchar(50),city varchar(50),email varchar(50),address varchar(50),refid varchar(50), cid int);
	drop table ncstatus;
create table ncstatus(cid int,refid varchar(50),status varchar(50));

insert into employee values
	(7001,	'Amar kumar',		'2012-08-11',	'2000-11-06',	'dept1',	18,	'Andhra pradesh power generation corporation',	'designation1',		844667,	'password'),
	(7002,	'firoz mohammad',	'2010-10-08',	'1999-12-06',	'dept2',	19,	'assam state electricity board',				'designation2',		129748,	'password'),
	(7003,	'saumya prakash',	'2013-12-03',	'1998-06-10',	'dept3',	21,	'delhi vidyut board',							'designation3',		729733,	'password'),
	(7004,	'vaibhav singhal',	'2015-09-07',	'1999-03-23',	'dept4',	20,	'gujarat urja vikas nigam',						'designation4',		264856,	'password'),
	(7005,	'Praveen Rana',		'2012-03-05',	'1998-12-12',	'dept5',	20,	'Haryana power generation corporation',			'designation5',		197835,	'password'),
	(7006,	'Shiv Shankar',		'2014-04-05',	'1999-08-11',	'dept6',	19,	'uttar pradesh rajya vidyut utpadan nigam',		'designation6',		131635,	'password'),
	(7007,	'Aviral Rai',		'2017-03-07',	'1997-11-10',	'dept7',	21,	'jharkhand state electricity board',			'designation7',		213163,	'password'),
	(7008,	'Samarth vats',		'2012-06-25',	'2000-04-29',	'dept8',	19,	'tamil nadu electricity board',					'designation8',		646461,	'password'),
	(7009,	'Bazif Rasool',		'2018-09-19',	'1996-09-16',	'dept9',	22,	'Bihar state power holding company limited',	'designation9',		146116,	'password'),
	(7010,	'Anurag Anand',		'2013-03-13',	'1999-10-25',	'dept10',	18,	'maharastra state electricity board',			'designation10',	197413,	'password');

insert into consumer values
	(8001,	'John',		254789,	'Andhra pradesh power generation corporation',	'Andhra pradesh',	'subdiv1',	'divis1',	'hyderabad',	101,	'password',	'john@gmail.com',		'GT road'		),
	(8002,	'Andrew',	961315,	'assam state electricity board',				'Assam',			'subdiv2',	'divis2',	'dispur',		102,	'password',	'Andrew@gmail.com',		'Ak sahaylane'	),
	(8003,	'Peterson',	487964,	'delhi vidyut board',							'Delhi',			'subdiv3',	'divis3',	'delhi NCR',	103,	'password',	'Peterson@gmail.com',	'ps road'		),
	(8004,	'David',	479368,	'gujarat urja vikas nigam',						'Gujarat',			'subdiv4',	'divis4',	'surat',		104,	'password',	'David@gmail.com',		'dholakpur'		),
	(8005,	'Michael',	169893,	'Haryana power generation corporation',			'Haryana',			'subdiv5',	'divis5',	'chandpur',		105,	'password',	'Michael@gmail.com',	'pk colony'		),
	(8006,	'Angelina',	494631,	'Uttar Pradesh rajya vidyut utpadan nigam',		'uttar pradesh',	'subdiv6',	'divis6',	'kanpur',		106,	'password',	'Angelina@gmail.com',	'GT road'		),
	(8007,	'selena',	494646,	'jharkhand state electricity board',			'jharkhand',		'subdiv7',	'divis7',	'ranchi',		107,	'password',	'selena@gmail.com',		'pnc colony'	),
	(8006,	'Angelina',	494631,	'Uttar Pradesh rajya vidyut utpadan nigam',		'uttar pradesh',	'subdiv6',	'divis6',	'kanpur',		111,	'password',	'Angelina@gmail.com',	'GT road'		),

	(8008,	'ellie',	216987,	'tamil nadu electricity board',					'tamil nadu',		'subdiv8',	'divis8',	'kandigai',		108,	'password',	'ellie@gmail.com',		'ghoda ghat'	),
	(8009,	'justin',	997463,	'Bihar state power holding company limited',	'Bihar',			'subdiv9',	'divis9',	'gaya',			109,	'password',	'justin@gmail.com',		'manpur'		),
	(8010,	'parker',	967435,	'maharastra state electricity board',			'maharastra',		'subdiv10',	'divis10',	'andheri',		110,	'password',	'parker@gmail.com',		'raj ghat'		);

insert into distributioncompany values
	(2001,	'Andhra pradesh distribution company',	5,	'Andhra Pradesh',	4001),
	(2002,	'Assam distribution company',			8,	'Assam',			4002),
	(2003,	'Delhi distribution company',			3,	'Delhi',			4003),
	(2004,	'gujarat distribution company',			6,	'Gujarat',			4004),
	(2005,	'Haryana distribution company',			9,	'Haryana',			4005),
	(2006,	'tamil nadu distribution company',		5,	'tamil nadu',		4006),
	(2007,	'uttar pradesh distribution company',	6,	'uttar pradesh',	4007),
	(2008,	'Bihar state distribution company',		9,	'Bihar',			4008),
	(2009,	'maharastra distribution company',		7,	'maharastra',		4009),
	(2010,	'jharkhand distribution company',		2,	'jharkhand',		4010);

insert into powercompany values
	(3001,	'APGenco',	'type1',	15789,	'Andhra Pradesh'),
	(3002,	'APGCL',	'type2',	45632,	'Assam'),
	(3003,	'IPGCL',	'type3',	89542,	'Delhi'),
	(3004,	'GSECL',	'type4',	26654,	'Gujarat'),
	(3005,	'GPGCL',	'type5',	47943,	'Haryana'),
	(3006,	'GJFUF',	'type6',	79641,	'tamil nadu'),
	(3007,	'JHFJG',	'type7',	44313,	'uttar pradesh'),
	(3008,	'GDJYJ',	'type8',	19613,	'Bihar'),
	(3009,	'SIEKS',	'type9',	24854,	'maharastra'),
	(3010,	'KHESG',	'type10',	46463,	'jharkhand');
insert into transmissioncompany values
	(4001,	'APTransco',	2001,	500,	'Andhra Pradesh',	5),
	(4002,	'AEGCL SLDC',	2002,	700,	'Assam',			8),
	(4003,	'SLDC Delhi',	2003,	300,	'Delhi',			3),
	(4004,	'GETCO',		2004,	800,	'Gujarat',			6),
	(4005,	'HVPNL',		2005,	700,	'Haryana',			9),
	(4006,	'GUAA',			2006,	200,	'tamil nadu',		5),
	(4007,	'DASJH',		2007,	500,	'uttar pradesh',	6),
	(4008,	'AHAKL',		2008,	300,	'Bihar',			9),
	(4009,	'IUYQW',		2009,	600,	'maharastra',		7),
	(4010,	'AKHSDA',		2010,	400,	'jharkhand',		2);

insert into circles values
	('cname1',	'Delhi',			201,	2001),
	('cname2',	'Gujarat',			202,	2002),
	('cname3',	'Assam',			203,	2003),
	('cname4',	'Andhra Pradesh',	204,	2004),
	('cname5',	'Haryana',			205,	2005),
	('cname6',	'tamil nadu',		206,	2006),
	('cname7',	'uttar pradesh',	207,	2007),
	('cname8',	'Bihar',			208,	2008),
	('cname9',	'maharastra',		209,	2009),
	('cname10',	'jharkhand',		210,	2010);
insert into division values
	(5001,	'divname1',	7001,	'Delhi',			2001),
	(5002,	'divname2',	7002, 	'Assam',			2002),
	(5003,	'divname3',	7003,	'Haryana',			2003),
	(5004,	'divname4',	7004,	'Andhra Pradesh',	2004),
	(5005,	'divname5',	7005,	'Gujarat',			2005),
	(5006,	'divname6',	7006,	'tamil nadu',		2006),
	(5007,	'divname7',	7007,	'uttar pradesh',	2007),
	(5008,	'divname8',	7008,	'Bihar',			2008),
	(5009,	'divname9',	7009,	'maharastra',		2009),
	(5010,	'divname10',7010,	'jharkhand',		2010);
insert into subdivision values
	(6001,	5001,	'Akshay',	'Haryana',			'sdivname1'),
	(6002,	5003,	'Ranjan',	'Delhi',			'sdivname2'),
	(6003,	5003,	'Manish',	'Delhi',			'sdivname3'),
	(6004,	5003,	'Prateek',	'Delhi',			'sdivname4'),
	(6005,	5005,	'Anurag',	'Gujarat',			'sdivname5'),
	(6007,	5007,	'Manish',	'uttar pradesh',	'sdivname5');
insert into electricityboard values
	('ASEC',	250000,	'Assam',		301,	2500),
	('DVB',		400000,	'Delhi',		302,	3200),
	('GUVN',	610000,	'Gujarat',		303,	4000),
	('HPGC',	120000,	'Haryana',		304,	1600),
	('JSEB',	320000,	'Jharkhand',	305,	5600);
insert into billinginfo values
	(10001,	8001,	'2017-12-20',	165,	101,	180,	12,	'type',	2),
	(10002,	8002,	'2018-06-15',	200,	102,	250,	16,	'type',	6),
	(10003,	8003,	'2018-10-30',	240,	103,	260,	18,	'type',	5),
	(10004,	8004,	'2017-11-01',	350,	104,	370,	26,	'type',	9),
	(10006,	8006,	'2017-11-01',	350,	106,	370,	26,	'type',	9),
  	(10005, 8005, 	'2019-01-06', 	120, 	105, 	200, 	15, 'type', 4);
