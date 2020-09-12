[root@Seven7 ~]# vim / etc / my.cnf
[root@Seven7 ~]# service mariadb restart
Redirecting to / bin / systemctl restart mariadb.service
[root@Seven7 ~]# mysql
Welcome to the MariaDB monitor.Commands end with; or \g.
Your MariaDB connection id is 2
Server version : 5.5.65 - MariaDB MariaDB Server

Copyright(c) 2000, 2018, Oracle, MariaDB Corporation Aband others.

Type 'help;' or '\h' for help.Type '\c' to clear the current input statement.

MariaDB[(none)] > use tset1
ERROR 1049 (42000) : Unknown database 'tset1'
MariaDB[(none)] > use tset1;
ERROR 1049 (42000) : Unknown database 'tset1'
MariaDB[(none)] > ls
->ls;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'ls
ls' at line 1
MariaDB[(none)] > use test1;
Reading table information for completion of tableand column names
You can turn off this feature to get a quicker startup with - A

Database changed
MariaDB[test1] > ls
->ls;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'ls
ls' at line 1
MariaDB[test1] > ls;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'ls' at line 1
MariaDB[test1] > select * from;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB[test1] > select * from test1;
ERROR 1146 (42S02) : Table 'test1.test1' doesn't exist
MariaDB[test1] > creat table t1(id int, name char(20));
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'creat table t1(id int,name char(20))' at line 1
MariaDB[test1] > creat table t1(id int, name char(20))
->Ctrl - C -- exit!
Aborted
[root@Seven7 ~]# mysql
Welcome to the MariaDB monitor.Commands end with; or \g.
Your MariaDB connection id is 3
Server version : 5.5.65 - MariaDB MariaDB Server

Copyright(c) 2000, 2018, Oracle, MariaDB Corporation Aband others.

Type 'help;' or '\h' for help.Type '\c' to clear the current input statement.

MariaDB[(none)] > selece * from test1;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'selece * from test1' at line 1
MariaDB[(none)] > show create databases
->show create databases;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'databases
show create databases' at line 1
MariaDB[(none)] > show create databases show create databaes;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'databases show create databaes' at line 1
MariaDB[(none)] > show create databaes;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'databaes' at line 1
MariaDB[(none)] > show databases;
+-------------------- +
| Database |
+-------------------- +
| information_schema |
| mysql              |
| performance_schema |
| test               |
| test1 |
+-------------------- +
5 rows in set(0.00 sec)

MariaDB[(none)] > use test;
Database changed
MariaDB[test] > show tables;
Empty set(0.00 sec)

MariaDB[test] > use;
ERROR: USE must be followed by a database name
MariaDB[test] > drop database test;
Query OK, 0 rows affected(0.00 sec)

MariaDB[(none)] > show databases;
+-------------------- +
| Database |
+-------------------- +
| information_schema |
| mysql              |
| performance_schema |
| test1 |
+-------------------- +
4 rows in set(0.00 sec)

MariaDB[(none)] > use test1;
Reading table information for completion of tableand column names
You can turn off this feature to get a quicker startup with - A

Database changed
MariaDB[test1] > show tables;
+---------------- - +
| Tables_in_test1 |
+---------------- - +
| t1              |
| t2 |
+---------------- - +
2 rows in set(0.00 sec)

MariaDB[test1] > select * from t1;
+------ +
| name |
+------ +
| a    |
| A    |
| b    |
| B |
+------ +
4 rows in set(0.00 sec)

MariaDB[test1] > create table t3(id int, name char(20));
Query OK, 0 rows affected(0.01 sec)

MariaDB[test1] > desc t3;
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| Field | Type | Null | Key | Default | Extra |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| id | int(11) | YES  |     | NULL    |       |
| name | char(20) | YES  |     | NULL    |       |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
2 rows in set(0.00 sec)

MariaDB[test1] > alter table t3 add sex char(20) after name;
Query OK, 0 rows affected(0.00 sec)
Records: 0  Duplicates : 0  Warnings : 0

MariaDB[test1] > desc t3;
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| Field | Type | Null | Key | Default | Extra |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| id | int(11) | YES  |     | NULL    |       |
| name | char(20) | YES  |     | NULL    |       |
| sex | char(20) | YES  |     | NULL    |       |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
3 rows in set(0.01 sec)

MariaDB[test1] > alter table t3 drop sex;
Query OK, 0 rows affected(0.01 sec)
Records: 0  Duplicates : 0  Warnings : 0

MariaDB[test1] > desc t3;
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| Field | Type | Null | Key | Default | Extra |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| id | int(11) | YES  |     | NULL    |       |
| name | char(20) | YES  |     | NULL    |       |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
2 rows in set(0.00 sec)

MariaDB[test1] > alter table t3 modify sex char(20);
ERROR 1054 (42S22) : Unknown column 'sex' in 't3'
MariaDB[test1] > alter table name t3 modify sex char(20);
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'modify sex char(20)' at line 1
MariaDB[test1] > alter table t3 modify name char(20);
Query OK, 0 rows affected(0.00 sec)
Records: 0  Duplicates : 0  Warnings : 0

MariaDB[test1] > desc t3;
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| Field | Type | Null | Key | Default | Extra |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| id | int(11) | YES  |     | NULL    |       |
| name | char(20) | YES  |     | NULL    |       |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
2 rows in set(0.00 sec)

MariaDB[test1] > alter table t3 sex char(20) after name;
ERROR 1064 (42000) : You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'char(20) after name' at line 1
MariaDB[test1] > alter table t3 add sex char(20) after name;
Query OK, 0 rows affected(0.00 sec)
Records: 0  Duplicates : 0  Warnings : 0

MariaDB[test1] > alter table t3 rename to t4;
Query OK, 0 rows affected(0.00 sec)

MariaDB[test1] > desc t4;
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| Field | Type | Null | Key | Default | Extra |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
| id | int(11) | YES  |     | NULL    |       |
| name | char(20) | YES  |     | NULL    |       |
| sex | char(20) | YES  |     | NULL    |       |
+------ - +---------- + ------ + ---- - +-------- - +------ - +
3 rows in set(0.00 sec)

MariaDB[test1] > alter table t4 rename to t3;
Query OK, 0 rows affected(0.00 sec)

MariaDB[test1] >
