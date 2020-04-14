[root@localhost 桌面]# ls
hello.c
[root@localhost 桌面]# cd
[root@localhost ~]# ls
anaconda - ks.cfg       install.log.syslog                   模板  下载
anaconda - screenshots  VMwareTools - 10.3.10 - 13959562.tar.gz  视频  音乐
b                     vmware - tools - distrib                 图片  桌面
install.log           公共的                               文档
[root@localhost ~]# cd houzi
bash : cd: houzi: 没有那个文件或目录
[root@localhost ~]# cd / home /
[root@localhost home]# ls
houzi
[root@localhost home]# ls - s
bash : ls - : command not found
[root@localhost home]# ls - l
总用量 4
drwx------. 4 500 500 4096 4月  14 21:12 houzi
[root@localhost home]# cd houzi
[root@localhost houzi]# cd
[root@localhost ~]# cd / home /
[root@localhost home]# useradd w
[root@localhost home]# usermod - d / home / w1 w
[root@localhost home]# pwd
/ home
[root@localhost home]# ls
houzi  w
[root@localhost home]# ls - l
总用量 8
drwx------. 4 w w 4096 4月  14 21:12 houzi
drwx------. 4 w w 4096 4月  14 21 : 31 w
[root@localhost home]# mkdir w1
[root@localhost home]# ls - l
总用量 12
drwx------. 4 w    w    4096 4月  14 21:12 houzi
drwx------. 4 w    w    4096 4月  14 21 : 31 w
drwxr - xr - x. 2 root root 4096 4月  14 21 : 33 w1
[root@localhost home]# usermod - d / home / w1 w
usermod：无改变
[root@localhost home]# mkdir w2
[root@localhost home]# ls
houzi  w  w1  w2
[root@localhost home]# usermod - d / home / w2 w
[root@localhost home]# ls
houzi  w  w1  w2
[root@localhost home]# ls - l
bash : ls - l : command not found
[root@localhost home]# cd w2
[root@localhost w2]# ls
[root@localhost w2]# pwd
/ home / w2
[root@localhost w2]# cd / etc / shadow
bash : cd: / etc / shadow : 不是目录
[root@localhost w2]# vim / etc / shadow
[root@localhost w2]# vim / etc / passwd
[root@localhost w2]#  id w
uid = 500(w)gid = 500(w)组 = 500(w)
[root@localhost w2]# groupadd group1
[root@localhost w2]# vim / etc / group
[root@localhost w2]# usermod - g group1 w
[root@localhost w2]# id w
uid = 500(w)gid = 501(group1)组 = 501(group1)
[root@localhost w2]# useradd - g group1 ww
[root@localhost w2]# ls
[root@localhost w2]# id ww
uid = 501(ww)gid = 501(group1)组 = 501(group1)
[root@localhost w2]# passwd w
更改用户 w 的密码 。
新的 密码：
无效的密码： 过于简单化 / 系统化
无效的密码： 过于简单
重新输入新的 密码：
passwd： 所有的身份验证令牌已经成功更新。
[root@localhost w2]# passwd ww
更改用户 ww 的密码 。
新的 密码：
无效的密码： 过于简单化 / 系统化
无效的密码： 过于简单
重新输入新的 密码：
passwd： 所有的身份验证令牌已经成功更新。
[root@localhost w2]# id
uid = 0(root)gid = 0(root)组 = 0(root)环境 = unconfined_u:unconfined_r:unconfined_t:s0 - s0 : c0.c1023
[root@localhost w2]# cd
[root@localhost ~]# su - w
su：无效选项 -- w
请尝试执行"su --help"来获取更多信息。
[root@localhost ~]# su - w
- bash - 4.1$ exit
logout
[root@localhost ~]# su - w
- bash - 4.1$ pwd
/ home / w2
- bash - 4.1$ exit
logout
[root@localhost ~]# su - ww
su：无效选项 -- w
请尝试执行"su --help"来获取更多信息。
[root@localhost ~]# su - ww
[ww@localhost ~]$ pwd
/ home / ww
[ww@localhost ~]$ id
uid = 501(ww)gid = 501(group1)组 = 501(group1)环境 = unconfined_u:unconfined_r:unconfined_t:s0 - s0 : c0.c1023
[ww@localhost ~]$ su - w
密码：
- bash - 4.1$ exit
logout
[ww@localhost ~]$ exit
logout
[root@localhost ~]# vim / etc / sudoers
[root@localhost ~]# vim / etc / sudoers
[root@localhost ~]# su - w
- bash - 4.1$ exit
logout
[root@localhost ~]# su - ww
su：无效选项 -- w
请尝试执行"su --help"来获取更多信息。
[root@localhost ~]# su - ww
[ww@localhost ~]$ sudo shutdown - c

We trust you have received the usual lecture from the local System
Administrator.It usually boils down to these three things :

#1) Respect the privacy of others.
#2) Think before you type.
#3) With great power comes great responsibility.

[sudo] password for ww:
ww 不在 sudoers 文件中。此事将被报告。
[ww@localhost ~]$ exit
logout
[root@localhost ~]# su - w
- bash - 4.1$ sudu shutdown - c
- bash: sudu: command not found
- bash - 4.1$ sudo shutown - c

We trust you have received the usual lecture from the local System
Administrator.It usually boils down to these three things :

#1) Respect the privacy of others.
#2) Think before you type.
#3) With great power comes great responsibility.

[sudo] password for w:
sudo：shutown：找不到命令
- bash - 4.1$ exit
logout
You have new mail in / var / spool / mail / root
[root@localhost ~]# id ww
uid = 501(ww)gid = 501(group1)组 = 501(group1)
[root@localhost ~]# id w
uid = 500(w)gid = 501(group1)组 = 501(group1)
[root@localhost ~]# vim / etc / passwd
[root@localhost ~]# 
