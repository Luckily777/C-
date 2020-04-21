mysql数据库的安装


[root@luckily ~]# yum list | grep mysql
akonadi - mysql.x86_64                        1.9.2 - 4.el7                base
apr - util - mysql.x86_64                       1.5.2 - 6.el7                base
dovecot - mysql.x86_64                        1:2.2.36 - 3.el7_7.1         updates
freeradius - mysql.x86_64                     3.0.13 - 10.el7_6            base
libdbi - dbd - mysql.x86_64                     0.8.3 - 16.el7               base
mysql - connector - java.noarch                 1 : 5.1.25 - 3.el7             base
mysql - connector - odbc.x86_64                 5.2.5 - 8.el7                base
pcp - pmda - mysql.x86_64                       4.3.2 - 5.el7_7              updates
php - mysql.x86_64                            5.4.16 - 46.1.el7_7          updates
php - mysqlnd.x86_64                          5.4.16 - 46.1.el7_7          updates
qt - mysql.i686                               1 : 4.8.7 - 3.el7_6            base
qt - mysql.x86_64                             1 : 4.8.7 - 3.el7_6            base
qt5 - qtbase - mysql.i686                       5.9.7 - 2.el7                base
qt5 - qtbase - mysql.x86_64                     5.9.7 - 2.el7                base
redland - mysql.x86_64                        1.0.16 - 6.el7               base
rsyslog - mysql.x86_64                        8.24.0 - 41.el7_7.4          updates
[root@luckily ~]# wget http ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
--2020 - 04 - 20 23 : 10 : 48--http ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
    正在解析主机 dev.mysql.com(dev.mysql.com)... 137.254.60.11
    正在连接 dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 80...已连接。
    已发出 HTTP 请求，正在等待回应... 301 Moved Permanently
    位置：https ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm [跟随至新的 URL]
--2020 - 04 - 20 23 : 10 : 49--https ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
    正在连接 dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 443...已连接。
    无法建立 SSL 连接。
    [root@luckily ~]# wget http ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
--2020 - 04 - 20 23 : 15 : 42--http ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
    正在解析主机 dev.mysql.com(dev.mysql.com)... 137.254.60.11
    正在连接 dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 80...已连接。
    已发出 HTTP 请求，正在等待回应... 读取文件头错误(Connection reset by peer)。
    重试中。

    --2020 - 04 - 20 23 : 17 : 20--(尝试次数： 2)  http ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
    正在连接 dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 80...已连接。
    已发出 HTTP 请求，正在等待回应... 301 Moved Permanently
    位置：https ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm [跟随至新的 URL]
--2020 - 04 - 20 23 : 17 : 30--https ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
    正在连接 dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 443...已连接。
    已发出 HTTP 请求，正在等待回应... 302 Found
    位置：https ://repo.mysql.com//mysql57-community-release-el7-8.noarch.rpm [跟随至新的 URL]
--2020 - 04 - 20 23 : 17 : 37--https ://repo.mysql.com//mysql57-community-release-el7-8.noarch.rpm
    正在解析主机 repo.mysql.com(repo.mysql.com)... 23.215.59.160
    正在连接 repo.mysql.com(repo.mysql.com) | 23.215.59.160 | : 443...已连接。
    已发出 HTTP 请求，正在等待回应... 200 OK
    长度：9116(8.9K)[application / x - redhat - package - manager]
    正在保存至 : “mysql57 - community - release - el7 - 8.noarch.rpm”

    100 % [============================================ = > ] 9, 116       19.7KB / s 用时 0.5s

    2020 - 04 - 20 23 : 17 : 40 (19.7 KB / s) - 已保存 “mysql57 - community - release - el7 - 8.noarch.rpm”[9116 / 9116])

    [root@luckily ~]# yum localinstall mysql57 - community - release - el7 - 8.noarch.rpm
    已加载插件：fastestmirror, langpacks
    正在检查 mysql57 - community - release - el7 - 8.noarch.rpm: mysql57 - community - release - el7 - 8.noarch
    mysql57 - community - release - el7 - 8.noarch.rpm 将被安装
    正在解决依赖关系
    -- > 正在检查事务
    --->软件包 mysql57 - community - release.noarch.0.el7 - 8 将被 安装
    -- > 解决依赖关系完成

    依赖关系解决

    ====================================================================================== =
    Package                   架构   版本   源                                       大小
    ====================================================================================== =
    正在安装:
mysql57 - community - release noarch el7 - 8 / mysql57 - community - release - el7 - 8.noarch 8.2 k

事务概要
====================================================================================== =
安装  1 软件包

总计：8.2 k
安装大小：8.2 k
Is this ok[y / d / N]: y
Downloading packages :
Running transaction check
Running transaction test
Transaction test succeeded
Running transaction
正在安装 : mysql57 - community - release - el7 - 8.noarch                             1 / 1
验证中 : mysql57 - community - release - el7 - 8.noarch                             1 / 1

已安装 :
    mysql57 - community - release.noarch 0 : el7 - 8

    完毕！
    [root@luckily ~]# yum - y install mysql - community - server
    已安装 :
mysql - community - libs.x86_64 0 : 5.7.29 - 1.el7                 mysql - community - libs - compat.x86_64 0 : 5.7.29 - 1.el7                 mysql - community - server.x86_64 0 : 5.7.29 - 1.el7

作为依赖被安装 :
mysql - community - client.x86_64 0 : 5.7.29 - 1.el7                                                  mysql - community - common.x86_64 0 : 5.7.29 - 1.el7

替代 :
mariadb - libs.x86_64 1 : 5.5.64 - 1.el7

完毕！
