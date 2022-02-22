-- WE WILL BE USING THIS USERNAME AND PASSWORD FOR CONNECTING TO THE DATABASE WITH ALL PRIVILEGES.
-- This will create user with name="admin" and password="admin"
create user 'amar'@'localhost' identified by 'amar';

-- This provides all the privileges to the admin. With grant option provides user with all the administritive privileges.
grant all privileges on *.* to 'amar'@'localhost' with grant option;

-- This will show you all the grants that are given to the admin, like create, update, insert etc.
show grants for 'admin'@'localhost';