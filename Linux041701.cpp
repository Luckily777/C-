 文件权限解读
     [root@localhost 桌面]# userdel - r ww
     [root@localhost 桌面]# ls
     hello.c
     [root@localhost 桌面]# cd
     [root@localhost ~]# userdel - r w
     userdel：组“w”没有移除，因为它不是用户 w 的主组
     userdel： / home / w2 并不属于 w，所以不会删除
     [root@localhost ~]# ls - l
     总用量 55224
     - rw------ - . 1 root root     1614 4月   7 03:48 anaconda - ks.cfg
     drwxr - x-- - . 2 root root     4096 4月   7 04 : 27 anaconda - screenshots
     drwxr - xr - x. 3 root root     4096 4月  10 01 : 24 b
     - rw - r--r--. 1 root root    46478 4月   7 03 : 48 install.log
     - rw - r--r--. 1 root root    10033 4月   7 03 : 46 install.log.syslog
     - r--r--r--. 1 root root 56431201 4月   7 05 : 00 VMwareTools - 10.3.10 - 13959562.tar.gz
     drwxr - xr - x. 9 root root     4096 6月  13 2019 vmware - tools - distrib
     drwxr - xr - x. 2 root root     4096 4月  10 00 : 13 公共的
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 模板
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 视频
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 图片
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 文档
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 下载
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 音乐
     drwxr - xr - x. 2 root root     4096 4月  14 21 : 12 桌面
     [root@localhost ~]# id w
     id : w：无此用户
     [root@localhost ~]# id ww
     id : ww：无此用户
     [root@localhost ~]# ls
     anaconda - ks.cfg       install.log.syslog                   模板  下载
     anaconda - screenshots  VMwareTools - 10.3.10 - 13959562.tar.gz  视频  音乐
     b                     vmware - tools - distrib                 图片  桌面
     install.log           公共的                               文档
     [root@localhost ~]# cat b
     cat : b: 是一个目录
     [root@localhost ~]# ls - l / dev / tty
     crw - rw - rw - . 1 root tty 5, 0 4月  17 12:58 / dev / tty
     [root@localhost ~]# ls - l / dev / sda
     brw - rw----. 1 root disk 8, 0 4月  17 12:58 / dev / sda
     [root@localhost ~]# mkfifo my.p
     You have new mail in / var / spool / mail / root
     [root@localhost ~]# ls
     anaconda - ks.cfg       install.log.syslog                   公共的  文档
     anaconda - screenshots  my.p                                 模板    下载
     b                     VMwareTools - 10.3.10 - 13959562.tar.gz  视频    音乐
     install.log           vmware - tools - distrib                 图片    桌面
     [root@localhost ~]# ls - l my.p
     prw - r--r--. 1 root root 0 4月  17 13:33 my.p
     [root@localhost ~]# echo abc
     abc
     [root@localhost ~]# echo abc > test.c
     [root@localhost ~]# ls
     anaconda - ks.cfg       my.p                                 模板  音乐
     anaconda - screenshots  test.c                               视频  桌面
     b                     VMwareTools - 10.3.10 - 13959562.tar.gz  图片
     install.log           vmware - tools - distrib                 文档
     install.log.syslog    公共的                               下载
     [root@localhost ~]# cat test.c
     abc
     [root@localhost ~]# echo def > test.c
     [root@localhost ~]# cat test.c
     def
     [root@localhost ~]# touch 87v
     [root@localhost ~]# ls
     87v                   install.log.syslog                   公共的  下载
     anaconda - ks.cfg       my.p                                 模板    音乐
     anaconda - screenshots  test.c                               视频    桌面
     b                     VMwareTools - 10.3.10 - 13959562.tar.gz  图片
     install.log           vmware - tools - distrib                 文档
     [root@localhost ~]# ls - l
     总用量 55228
     - rw - r--r--. 1 root root        0 4月  17 14:29 87v
     - rw------ - . 1 root root     1614 4月   7 03 : 48 anaconda - ks.cfg
     drwxr - x-- - . 2 root root     4096 4月   7 04 : 27 anaconda - screenshots
     drwxr - xr - x. 3 root root     4096 4月  10 01 : 24 b
     - rw - r--r--. 1 root root    46478 4月   7 03 : 48 install.log
     - rw - r--r--. 1 root root    10033 4月   7 03 : 46 install.log.syslog
     prw - r--r--. 1 root root        0 4月  17 13 : 33 my.p
     - rw - r--r--. 1 root root        4 4月  17 14 : 29 test.c
     - r--r--r--. 1 root root 56431201 4月   7 05 : 00 VMwareTools - 10.3.10 - 13959562.tar.gz
     drwxr - xr - x. 9 root root     4096 6月  13 2019 vmware - tools - distrib
     drwxr - xr - x. 2 root root     4096 4月  10 00 : 13 公共的
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 模板
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 视频
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 图片
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 文档
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 下载
     drwxr - xr - x. 2 root root     4096 4月   7 04 : 33 音乐
     drwxr - xr - x. 2 root root     4096 4月  14 21 : 12 桌面
     [root@localhost ~]# ls - l - h 87v
     - rw - r--r--. 1 root root 0 4月  17 14:29 87v
     [root@localhost ~]# ls - l - h test.c
     - rw - r--r--. 1 root root 4 4月  17 14:29 test.c
     [root@localhost ~]# ls - l - h b
     总用量 4.0K
     drwxr - xr - x. 3 root root 4.0K 4月  10 00:18 c
     - rw - r--r--. 1 root root    0 4月  10 01 : 21 filea
     - rw - r--r--. 1 root root    0 4月  10 01 : 21 fileb
     - rw - r--r--. 1 root root    0 4月  10 01 : 24 filec
     [root@localhost ~]# 