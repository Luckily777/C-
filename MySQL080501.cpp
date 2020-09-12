//查看mariadb
[root@luckily ~]# rpm - qa | grep mariadb

[root@luckily ~]# yum install - y mariadb - server
[root@luckily ~]# yum install - y mariadb - devel


//转换yum源

[root@luckily ~]# cd / etc / yum.repos.d /
[root@luckily yum.repos.d]# mv / etc / yum.repos.d / CentOS - Base.repo / etc / yum.repos.d / CentOS - Base.repo_bak
mv：是否覆盖"/etc/yum.repos.d/CentOS-Base.repo_bak"？ y
[root@luckily yum.repos.d]# wget - O / etc / yum.repos.d / CentOS - Base.repo http ://mirrors.aliyun.com/repo/Centos-7.repo
--2020 - 08 - 05 17:02 : 07--http ://mirrors.aliyun.com/repo/Centos-7.repo
    正在解析主机 mirrors.aliyun.com(mirrors.aliyun.com)... 111.32.158.127, 111.32.130.240, 111.32.158.129, ...
    正在连接 mirrors.aliyun.com(mirrors.aliyun.com) | 111.32.158.127 | : 80...已连接。
    已发出 HTTP 请求，正在等待回应... 200 OK
    长度：2523(2.5K)[application / octet - stream]
    正在保存至 : “ / etc / yum.repos.d / CentOS - Base.repo”

    100 % [============================================ = > ] 2, 523       --. - K / s 用时 0s

    2020 - 08 - 05 17:02 : 07 (152 MB / s) - 已保存 “ / etc / yum.repos.d / CentOS - Base.repo”[2523 / 2523])

    [root@luckily yum.repos.d]# yum makecache
    已加载插件：fastestmirror, langpacks
    Loading mirror speeds from cached hostfile
    * base: mirrors.aliyun.com
    * extras : mirrors.aliyun.com
    * updates : mirrors.aliyun.com
    base | 3.6 kB  00 : 00 : 00
    extras | 2.9 kB  00 : 00 : 00
    mysql - connectors - community | 2.5 kB  00 : 00 : 00
    mysql - tools - community | 2.5 kB  00 : 00 : 00
    mysql57 - community | 2.5 kB  00 : 00 : 00
    updates | 2.9 kB  00 : 00 : 00
    元数据缓存已建立


//查看
[root@luckily ~]# ps aux | grep mysqld
//修改登录
[root@luckily ~]# vim / etc / my.cnf

//查看状态

[root@luckily ~]# service mysqld status
Redirecting to / bin / systemctl status mysqld.service
● mysqld.service - MySQL Server
Loaded : loaded(/ usr / lib / systemd / system / mysqld.service; enabled; vendor preset : disabled)
Active : active(running) since 三 2020 - 08 - 05 16:59 : 53 CST; 27min ago

