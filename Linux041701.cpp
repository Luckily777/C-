 �ļ�Ȩ�޽��
     [root@localhost ����]# userdel - r ww
     [root@localhost ����]# ls
     hello.c
     [root@localhost ����]# cd
     [root@localhost ~]# userdel - r w
     userdel���顰w��û���Ƴ�����Ϊ�������û� w ������
     userdel�� / home / w2 �������� w�����Բ���ɾ��
     [root@localhost ~]# ls - l
     ������ 55224
     - rw------ - . 1 root root     1614 4��   7 03:48 anaconda - ks.cfg
     drwxr - x-- - . 2 root root     4096 4��   7 04 : 27 anaconda - screenshots
     drwxr - xr - x. 3 root root     4096 4��  10 01 : 24 b
     - rw - r--r--. 1 root root    46478 4��   7 03 : 48 install.log
     - rw - r--r--. 1 root root    10033 4��   7 03 : 46 install.log.syslog
     - r--r--r--. 1 root root 56431201 4��   7 05 : 00 VMwareTools - 10.3.10 - 13959562.tar.gz
     drwxr - xr - x. 9 root root     4096 6��  13 2019 vmware - tools - distrib
     drwxr - xr - x. 2 root root     4096 4��  10 00 : 13 ������
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ģ��
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ��Ƶ
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ͼƬ
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 �ĵ�
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ����
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ����
     drwxr - xr - x. 2 root root     4096 4��  14 21 : 12 ����
     [root@localhost ~]# id w
     id : w���޴��û�
     [root@localhost ~]# id ww
     id : ww���޴��û�
     [root@localhost ~]# ls
     anaconda - ks.cfg       install.log.syslog                   ģ��  ����
     anaconda - screenshots  VMwareTools - 10.3.10 - 13959562.tar.gz  ��Ƶ  ����
     b                     vmware - tools - distrib                 ͼƬ  ����
     install.log           ������                               �ĵ�
     [root@localhost ~]# cat b
     cat : b: ��һ��Ŀ¼
     [root@localhost ~]# ls - l / dev / tty
     crw - rw - rw - . 1 root tty 5, 0 4��  17 12:58 / dev / tty
     [root@localhost ~]# ls - l / dev / sda
     brw - rw----. 1 root disk 8, 0 4��  17 12:58 / dev / sda
     [root@localhost ~]# mkfifo my.p
     You have new mail in / var / spool / mail / root
     [root@localhost ~]# ls
     anaconda - ks.cfg       install.log.syslog                   ������  �ĵ�
     anaconda - screenshots  my.p                                 ģ��    ����
     b                     VMwareTools - 10.3.10 - 13959562.tar.gz  ��Ƶ    ����
     install.log           vmware - tools - distrib                 ͼƬ    ����
     [root@localhost ~]# ls - l my.p
     prw - r--r--. 1 root root 0 4��  17 13:33 my.p
     [root@localhost ~]# echo abc
     abc
     [root@localhost ~]# echo abc > test.c
     [root@localhost ~]# ls
     anaconda - ks.cfg       my.p                                 ģ��  ����
     anaconda - screenshots  test.c                               ��Ƶ  ����
     b                     VMwareTools - 10.3.10 - 13959562.tar.gz  ͼƬ
     install.log           vmware - tools - distrib                 �ĵ�
     install.log.syslog    ������                               ����
     [root@localhost ~]# cat test.c
     abc
     [root@localhost ~]# echo def > test.c
     [root@localhost ~]# cat test.c
     def
     [root@localhost ~]# touch 87v
     [root@localhost ~]# ls
     87v                   install.log.syslog                   ������  ����
     anaconda - ks.cfg       my.p                                 ģ��    ����
     anaconda - screenshots  test.c                               ��Ƶ    ����
     b                     VMwareTools - 10.3.10 - 13959562.tar.gz  ͼƬ
     install.log           vmware - tools - distrib                 �ĵ�
     [root@localhost ~]# ls - l
     ������ 55228
     - rw - r--r--. 1 root root        0 4��  17 14:29 87v
     - rw------ - . 1 root root     1614 4��   7 03 : 48 anaconda - ks.cfg
     drwxr - x-- - . 2 root root     4096 4��   7 04 : 27 anaconda - screenshots
     drwxr - xr - x. 3 root root     4096 4��  10 01 : 24 b
     - rw - r--r--. 1 root root    46478 4��   7 03 : 48 install.log
     - rw - r--r--. 1 root root    10033 4��   7 03 : 46 install.log.syslog
     prw - r--r--. 1 root root        0 4��  17 13 : 33 my.p
     - rw - r--r--. 1 root root        4 4��  17 14 : 29 test.c
     - r--r--r--. 1 root root 56431201 4��   7 05 : 00 VMwareTools - 10.3.10 - 13959562.tar.gz
     drwxr - xr - x. 9 root root     4096 6��  13 2019 vmware - tools - distrib
     drwxr - xr - x. 2 root root     4096 4��  10 00 : 13 ������
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ģ��
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ��Ƶ
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ͼƬ
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 �ĵ�
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ����
     drwxr - xr - x. 2 root root     4096 4��   7 04 : 33 ����
     drwxr - xr - x. 2 root root     4096 4��  14 21 : 12 ����
     [root@localhost ~]# ls - l - h 87v
     - rw - r--r--. 1 root root 0 4��  17 14:29 87v
     [root@localhost ~]# ls - l - h test.c
     - rw - r--r--. 1 root root 4 4��  17 14:29 test.c
     [root@localhost ~]# ls - l - h b
     ������ 4.0K
     drwxr - xr - x. 3 root root 4.0K 4��  10 00:18 c
     - rw - r--r--. 1 root root    0 4��  10 01 : 21 filea
     - rw - r--r--. 1 root root    0 4��  10 01 : 21 fileb
     - rw - r--r--. 1 root root    0 4��  10 01 : 24 filec
     [root@localhost ~]# 