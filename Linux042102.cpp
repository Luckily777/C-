mysql���ݿ�İ�װ


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
    ���ڽ������� dev.mysql.com(dev.mysql.com)... 137.254.60.11
    �������� dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 80...�����ӡ�
    �ѷ��� HTTP �������ڵȴ���Ӧ... 301 Moved Permanently
    λ�ã�https ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm [�������µ� URL]
--2020 - 04 - 20 23 : 10 : 49--https ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
    �������� dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 443...�����ӡ�
    �޷����� SSL ���ӡ�
    [root@luckily ~]# wget http ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
--2020 - 04 - 20 23 : 15 : 42--http ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
    ���ڽ������� dev.mysql.com(dev.mysql.com)... 137.254.60.11
    �������� dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 80...�����ӡ�
    �ѷ��� HTTP �������ڵȴ���Ӧ... ��ȡ�ļ�ͷ����(Connection reset by peer)��
    �����С�

    --2020 - 04 - 20 23 : 17 : 20--(���Դ����� 2)  http ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
    �������� dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 80...�����ӡ�
    �ѷ��� HTTP �������ڵȴ���Ӧ... 301 Moved Permanently
    λ�ã�https ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm [�������µ� URL]
--2020 - 04 - 20 23 : 17 : 30--https ://dev.mysql.com/get/mysql57-community-release-el7-8.noarch.rpm
    �������� dev.mysql.com(dev.mysql.com) | 137.254.60.11 | : 443...�����ӡ�
    �ѷ��� HTTP �������ڵȴ���Ӧ... 302 Found
    λ�ã�https ://repo.mysql.com//mysql57-community-release-el7-8.noarch.rpm [�������µ� URL]
--2020 - 04 - 20 23 : 17 : 37--https ://repo.mysql.com//mysql57-community-release-el7-8.noarch.rpm
    ���ڽ������� repo.mysql.com(repo.mysql.com)... 23.215.59.160
    �������� repo.mysql.com(repo.mysql.com) | 23.215.59.160 | : 443...�����ӡ�
    �ѷ��� HTTP �������ڵȴ���Ӧ... 200 OK
    ���ȣ�9116(8.9K)[application / x - redhat - package - manager]
    ���ڱ����� : ��mysql57 - community - release - el7 - 8.noarch.rpm��

    100 % [============================================ = > ] 9, 116       19.7KB / s ��ʱ 0.5s

    2020 - 04 - 20 23 : 17 : 40 (19.7 KB / s) - �ѱ��� ��mysql57 - community - release - el7 - 8.noarch.rpm��[9116 / 9116])

    [root@luckily ~]# yum localinstall mysql57 - community - release - el7 - 8.noarch.rpm
    �Ѽ��ز����fastestmirror, langpacks
    ���ڼ�� mysql57 - community - release - el7 - 8.noarch.rpm: mysql57 - community - release - el7 - 8.noarch
    mysql57 - community - release - el7 - 8.noarch.rpm ������װ
    ���ڽ��������ϵ
    -- > ���ڼ������
    --->����� mysql57 - community - release.noarch.0.el7 - 8 ���� ��װ
    -- > ���������ϵ���

    ������ϵ���

    ====================================================================================== =
    Package                   �ܹ�   �汾   Դ                                       ��С
    ====================================================================================== =
    ���ڰ�װ:
mysql57 - community - release noarch el7 - 8 / mysql57 - community - release - el7 - 8.noarch 8.2 k

�����Ҫ
====================================================================================== =
��װ  1 �����

�ܼƣ�8.2 k
��װ��С��8.2 k
Is this ok[y / d / N]: y
Downloading packages :
Running transaction check
Running transaction test
Transaction test succeeded
Running transaction
���ڰ�װ : mysql57 - community - release - el7 - 8.noarch                             1 / 1
��֤�� : mysql57 - community - release - el7 - 8.noarch                             1 / 1

�Ѱ�װ :
    mysql57 - community - release.noarch 0 : el7 - 8

    ��ϣ�
    [root@luckily ~]# yum - y install mysql - community - server
    �Ѱ�װ :
mysql - community - libs.x86_64 0 : 5.7.29 - 1.el7                 mysql - community - libs - compat.x86_64 0 : 5.7.29 - 1.el7                 mysql - community - server.x86_64 0 : 5.7.29 - 1.el7

��Ϊ��������װ :
mysql - community - client.x86_64 0 : 5.7.29 - 1.el7                                                  mysql - community - common.x86_64 0 : 5.7.29 - 1.el7

��� :
mariadb - libs.x86_64 1 : 5.5.64 - 1.el7

��ϣ�
