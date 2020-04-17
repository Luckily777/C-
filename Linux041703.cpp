目录权限修改 和两个位
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
[root@localhost ~]# useradd Luckily
[root@localhost ~]# passwd Luckily
更改用户 Luckily 的密码 。
新的 密码：
无效的密码： 过于简单化 / 系统化
无效的密码： 过于简单
重新输入新的 密码：
passwd： 所有的身份验证令牌已经成功更新。
[root@localhost ~]# su Luckily
[Luckily@localhost root]$ c
bash : c: command not found
[Luckily@localhost root]$ cd
[Luckily@localhost ~]$ su root
密码：
[root@localhost Luckily]# cd
[root@localhost ~]# ls - ld /
ls: 无法访问 - : 没有那个文件或目录
ls : 无法访问ld: 没有那个文件或目录
/ :
	bin   dev  home  lib64       media  mnt  opt   root  selinux  sys  usr
	boot  etc  lib   lost + found  misc   net  proc  sbin  srv      tmp  var
	[root@localhost ~]# mkdir / test
	[root@localhost ~]# ls - ld / tet = st
	ls : 无法访问 / tet = st : 没有那个文件或目录
	[root@localhost ~]# ls - ld / test
	drwxr - xr - x. 2 root root 4096 4月  17 14:59 / test
	[root@localhost ~]# chmod 0000 / test
	[root@localhost ~]# ls - ld / test
	d-------- - . 2 root root 4096 4月  17 14:59 / test
	[root@localhost ~]# su Luckily
	[Luckily@localhost root]$ cd / test
	bash : cd: / test : 权限不够
	[Luckily@localhost root]$ ls / test
	ls : 无法打开目录 / test : 权限不够
	[Luckily@localhost root]$ touch / test / hehe.c
	touch : 无法创建"/test/hehe.c" : 权限不够
	[Luckily@localhost root]$ su root
	密码：
	[root@localhost ~]# chmod 0004 / test
	[root@localhost ~]# ls - ld / test
	d------r--. 2 root root 4096 4月  17 14:59 / test
	[root@localhost ~]#  ^ C
	[root@localhost ~]# su Luckily
	[Luckily@localhost root]$ cd / test
	bash : cd: / test : 权限不够
	[Luckily@localhost root]$ ls / test
	[Luckily@localhost root]$ touch / test / hehe.c
	touch : 无法创建"/test/hehe.c" : 权限不够
	[Luckily@localhost root]$ su root
	密码：
	[root@localhost ~]# chmod o + w / test
	[root@localhost ~]# ls - ld / test
	d------rw - . 2 root root 4096 4月  17 14:59 / test
	[root@localhost ~]# su Luckily
	[Luckily@localhost root]$ ls / test
	[Luckily@localhost root]$ cd / test
	bash : cd: / test : 权限不够
	[Luckily@localhost root]$ touch / test / hehe.c
	touch : 无法创建"/test/hehe.c" : 权限不够
	[Luckily@localhost root]$ chmod o + x / test
	chmod : 更改"/test" 的权限 : 不允许的操作
	[Luckily@localhost root]$ su root
	密码：
	[root@localhost ~]# chmod o + x / test
	[root@localhost ~]# chmod o - r / test
	[root@localhost ~]# ls - ld / test
	d------ - wx. 2 root root 4096 4月  17 14:59 / test
	[root@localhost ~]# su Luckily
	[Luckily@localhost root]$ ls / test
	ls : 无法打开目录 / test : 权限不够
	[Luckily@localhost root]$ cd / test
	[Luckily@localhost test]$ pwd
	/ test
	[Luckily@localhost test]$ cd -
	bash : cd : / root : 权限不够
	[Luckily@localhost test]$ cd
	[Luckily@localhost ~]$  cd / test
	[Luckily@localhost test]$ ls / test
	ls : 无法打开目录 / test : 权限不够
	[Luckily@localhost test]$ touch abc.txt
	[Luckily@localhost test]$  cd / root
	bash : cd: / root : 权限不够
	[Luckily@localhost test]$ ls - ld / home / Luckily
	drwx------. 4 Luckily Luckily 4096 4月  17 15 : 06 / home / Luckily
	[Luckily@localhost test]$ su root
	密码：
	[root@localhost test]# tail / etc / passwd
	haldaemon : x:68 : 68 : HAL daemon : / : / sbin / nologin
	ntp : x:38 : 38:: / etc / ntp : / sbin / nologin
	apache : x:48 : 48 : Apache : / var / www : / sbin / nologin
	saslauth : x:498 : 76 : Saslauthd user : / var / empty / saslauth : / sbin / nologin
	postfix : x:89 : 89:: / var / spool / postfix : / sbin / nologin
	gdm : x:42 : 42:: / var / lib / gdm : / sbin / nologin
	pulse : x:497 : 496 : PulseAudio System Daemon : / var / run / pulse : / sbin / nologin
	sshd : x:74 : 74 : Privilege - separated SSH : / var / empty / sshd : / sbin / nologin
	tcpdump : x:72 : 72:: / : / sbin / nologin
	Luckily : x:500 : 502:: / home / Luckily : / bin / bash
	[root@localhost test]# ls - l / etc / shadow
	----------. 1 root root 1034 4月  17 14:57 / etc / shadow
	[root@localhost test]# whoami
	root
	[root@localhost test]# which passwd
	/ usr / bin / passwd
	[root@localhost test]# ls - l 'which passwd'
	ls: 无法访问which passwd : 没有那个文件或目录
	[root@localhost test]# ls - l `which passwd`
	- rwsr - xr - x. 1 root root 30768 11月 24 2015 / usr / bin / passwd
	[root@localhost test]# ls - l `which passwd`
	- rwsr - xr - x. 1 root root 30768 11月 24 2015 / usr / bin / passwd
	[root@localhost test]# chmod u - s / usr / bin / passwd
	[root@localhost test]# ls - l `which passwd`
	- rwxr - xr - x. 1 root root 30768 11月 24 2015 / usr / bin / passwd
	[root@localhost test]# cd
	[root@localhost ~]# ls
	87v                   my.p                                 图片
	anaconda - ks.cfg       test.c                               文档
	anaconda - screenshots  VMwareTools - 10.3.10 - 13959562.tar.gz  下载
	a.out                 vmware - tools - distrib                 音乐
	b                     公共的                               桌面
	install.log           模板
	install.log.syslog    视频
	[root@localhost ~]# ls - ld 87v
	- rw - r--r--. 1 root root 0 4月  17 14:29 87v
	[root@localhost ~]# chmod u - x 87v
	[root@localhost ~]# ls - ls 87v
	0 - rw - r--r--. 1 root root 0 4月  17 14:29 87v
	[root@localhost ~]# ls - ld 87v
	- rw - r--r--. 1 root root 0 4月  17 14:29 87v
	[root@localhost ~]# chmod u + x 87v
	[root@localhost ~]# ls - ld 87v
	- rwxr--r--. 1 root root 0 4月  17 14:29 87v
	[root@localhost ~]# chmod u - x 87v
	[root@localhost ~]# ls - ld 87v
	- rw - r--r--. 1 root root 0 4月  17 14:29 87v

	有效用户和实际用户位
	[root@localhost ~]# chmod u + s 87v
	[root@localhost ~]# ls - ld 87v
	- rwSr--r--. 1 root root 0 4月  17 14:29 87v
	[root@localhost ~]# ls - ld /
	dr - xr - xr - x. 26 root root 4096 4月  17 14:59 /
	[root@localhost ~]# chmod 0777 /
	[root@localhost ~]# ls - ld /
	drwxrwxrwx. 26 root root 4096 4月  17 14:59 /
	[root@localhost ~]# su Luckily
	[Luckily@localhost root]$ touch / mmc.txt
	[Luckily@localhost root]$ ls /
	bin   etc   lib64       misc     net   root     srv   tmp
	boot  home  lost + found  mmc.txt  opt   sbin     sys   usr
	dev   lib   media       mnt      proc  selinux  test  var
	[Luckily@localhost root]$ ls - l / mmc.txt
	- rw - rw - r--. 1 Luckily Luckily 0 4月  17 15:51 / mmc.txt


		粘贴位
		[root@localhost ~]# chmod o + t /
		[root@localhost ~]# ls - ld /
		drwxrwxrwt. 26 root root 4096 4月  17 15:51 /
		[root@localhost ~]# su Luckily
		[Luckily@localhost root]$ echo "baigujing" > / mmc.txt
		[Luckily@localhost root]$ cat / mmc.txt
		baigujing
		[Luckily@localhost root]$ rm / mmc.txt
		[Luckily@localhost root]$ ls /
		bin   dev  home  lib64       media  mnt  opt   root  selinux  sys   tmp  var
		boot  etc  lib   lost + found  misc   net  proc  sbin  srv      test  usr
		[Luckily@localhost root]$ chmod o - t /
		chmod: 更改"/" 的权限 : 不允许的操作
		[Luckily@localhost root]$ exit
		exit
		[root@localhost ~]# chmod o - t /
		[root@localhost ~]# ls - ld /
		drwxrwxrwx. 26 root root 4096 4月  17 15:56 /