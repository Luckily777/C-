[root@localhost ����]# ls
hello.c
[root@localhost ����]# cd
[root@localhost ~]# ls
anaconda - ks.cfg       install.log.syslog                   ģ��  ����
anaconda - screenshots  VMwareTools - 10.3.10 - 13959562.tar.gz  ��Ƶ  ����
b                     vmware - tools - distrib                 ͼƬ  ����
install.log           ������                               �ĵ�
[root@localhost ~]# cd houzi
bash : cd: houzi: û���Ǹ��ļ���Ŀ¼
[root@localhost ~]# cd / home /
[root@localhost home]# ls
houzi
[root@localhost home]# ls - s
bash : ls - : command not found
[root@localhost home]# ls - l
������ 4
drwx------. 4 500 500 4096 4��  14 21:12 houzi
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
������ 8
drwx------. 4 w w 4096 4��  14 21:12 houzi
drwx------. 4 w w 4096 4��  14 21 : 31 w
[root@localhost home]# mkdir w1
[root@localhost home]# ls - l
������ 12
drwx------. 4 w    w    4096 4��  14 21:12 houzi
drwx------. 4 w    w    4096 4��  14 21 : 31 w
drwxr - xr - x. 2 root root 4096 4��  14 21 : 33 w1
[root@localhost home]# usermod - d / home / w1 w
usermod���޸ı�
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
bash : cd: / etc / shadow : ����Ŀ¼
[root@localhost w2]# vim / etc / shadow
[root@localhost w2]# vim / etc / passwd
[root@localhost w2]#  id w
uid = 500(w)gid = 500(w)�� = 500(w)
[root@localhost w2]# groupadd group1
[root@localhost w2]# vim / etc / group
[root@localhost w2]# usermod - g group1 w
[root@localhost w2]# id w
uid = 500(w)gid = 501(group1)�� = 501(group1)
[root@localhost w2]# useradd - g group1 ww
[root@localhost w2]# ls
[root@localhost w2]# id ww
uid = 501(ww)gid = 501(group1)�� = 501(group1)
[root@localhost w2]# passwd w
�����û� w ������ ��
�µ� ���룺
��Ч�����룺 ���ڼ򵥻� / ϵͳ��
��Ч�����룺 ���ڼ�
���������µ� ���룺
passwd�� ���е������֤�����Ѿ��ɹ����¡�
[root@localhost w2]# passwd ww
�����û� ww ������ ��
�µ� ���룺
��Ч�����룺 ���ڼ򵥻� / ϵͳ��
��Ч�����룺 ���ڼ�
���������µ� ���룺
passwd�� ���е������֤�����Ѿ��ɹ����¡�
[root@localhost w2]# id
uid = 0(root)gid = 0(root)�� = 0(root)���� = unconfined_u:unconfined_r:unconfined_t:s0 - s0 : c0.c1023
[root@localhost w2]# cd
[root@localhost ~]# su - w
su����Чѡ�� -- w
�볢��ִ��"su --help"����ȡ������Ϣ��
[root@localhost ~]# su - w
- bash - 4.1$ exit
logout
[root@localhost ~]# su - w
- bash - 4.1$ pwd
/ home / w2
- bash - 4.1$ exit
logout
[root@localhost ~]# su - ww
su����Чѡ�� -- w
�볢��ִ��"su --help"����ȡ������Ϣ��
[root@localhost ~]# su - ww
[ww@localhost ~]$ pwd
/ home / ww
[ww@localhost ~]$ id
uid = 501(ww)gid = 501(group1)�� = 501(group1)���� = unconfined_u:unconfined_r:unconfined_t:s0 - s0 : c0.c1023
[ww@localhost ~]$ su - w
���룺
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
su����Чѡ�� -- w
�볢��ִ��"su --help"����ȡ������Ϣ��
[root@localhost ~]# su - ww
[ww@localhost ~]$ sudo shutdown - c

We trust you have received the usual lecture from the local System
Administrator.It usually boils down to these three things :

#1) Respect the privacy of others.
#2) Think before you type.
#3) With great power comes great responsibility.

[sudo] password for ww:
ww ���� sudoers �ļ��С����½������档
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
sudo��shutown���Ҳ�������
- bash - 4.1$ exit
logout
You have new mail in / var / spool / mail / root
[root@localhost ~]# id ww
uid = 501(ww)gid = 501(group1)�� = 501(group1)
[root@localhost ~]# id w
uid = 500(w)gid = 501(group1)�� = 501(group1)
[root@localhost ~]# vim / etc / passwd
[root@localhost ~]# 
