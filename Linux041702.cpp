文件权限修改

[root@localhost ~]# ls - l a.out
ls : 无法访问a.out : 没有那个文件或目录
[root@localhost ~]# touch a.out
[root@localhost ~]# ls - l a.out
- rw - r--r--. 1 root root 0 4月  17 14:47 a.out
[root@localhost ~]# chmod u - w a.out
chmod : 无法访问"w" : 没有那个文件或目录
[root@localhost ~]# chmod u - w a.out
[root@localhost ~]# ls - l a.out
- r--r--r--. 1 root root 0 4月  17 14:47 a.out
[root@localhost ~]# chmod a = rwx a.out
[root@localhost ~]# ls - l a.out
- rwxrwxrwx. 1 root root 0 4月  17 14:47 a.out
[root@localhost ~]# chmod g - r a.out
[root@localhost ~]# chmod o - r a.out
[root@localhost ~]# chmod u - r a.out
[root@localhost ~]# ls - l a.out
--wx - wx - wx. 1 root root 0 4月  17 14:47 a.out
[root@localhost ~]#  chmod u + r a.out
[root@localhost ~]# ls - l a.out
- rwx - wx - wx. 1 root root 0 4月  17 14:47 a.out
[root@localhost ~]# chmod 0740 a.out
[root@localhost ~]# ls - l a.out
- rwxr---- - . 1 root root 0 4月  17 14:47 a.out
