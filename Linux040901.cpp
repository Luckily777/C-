[root@localhost ~]# ls
anaconda - ks.cfg                      模板
anaconda - screenshots                 视频
install.log                          图片
install.log.syslog                   文档
VMwareTools - 10.3.10 - 13959562.tar.gz  下载
vmware - tools - distrib                 音乐
公共的                               桌面
[root@localhost ~]# mkdir a
[root@localhost ~]# ls
a                                    模板
anaconda - ks.cfg                      视频
anaconda - screenshots                 图片
install.log                          文档
install.log.syslog                   下载
VMwareTools - 10.3.10 - 13959562.tar.gz  音乐
vmware - tools - distrib                 桌面
公共的
[root@localhost ~]# mkdir b
[root@localhost ~]# mkdir c
[root@localhost ~]# ls
a                                    公共的
anaconda - ks.cfg                      模板
anaconda - screenshots                 视频
b                                    图片
c                                    文档
install.log                          下载
install.log.syslog                   音乐
VMwareTools - 10.3.10 - 13959562.tar.gz  桌面
vmware - tools - distrib
[root@localhost ~]# cd a
[root@localhost a]# ls
[root@localhost a]# ls - a
.  ..
[root@localhost a]# mkdir a
[root@localhost a]# ls
a
[root@localhost a]# cd ..
[root@localhost ~]# mkdir a
mkdir : 无法创建目录"a" : 文件已存在
[root@localhost ~]# mkdir d f e
[root@localhost ~]# ls
a
anaconda - ks.cfg
anaconda - screenshots
b
c
d
e
f
install.log
install.log.syslog
VMwareTools - 10.3.10 - 13959562.tar.gz
vmware - tools - distrib
公共的
模板
视频
图片
文档
下载
音乐
桌面
[root@localhost ~]# cd a
[root@localhost a]# mkdir b
[root@localhost a]# cd b
[root@localhost b]# mkdir c
[root@localhost b]# cd ..
[root@localhost a]# cd
[root@localhost ~]# mkdir - p b / c / d
[root@localhost ~]# pwd
/ root
[root@localhost ~]# ls
a
anaconda - ks.cfg
anaconda - screenshots
b
c
d
e
f
install.log
install.log.syslog
VMwareTools - 10.3.10 - 13959562.tar.gz
vmware - tools - distrib
公共的
模板
视频
图片
文档
下载
音乐
桌面
[root@localhost ~]# cd b
[root@localhost b]# ls
c
[root@localhost b]# cd c
[root@localhost c]# ls
d
[root@localhost c]# pwd
/ root / b / c
[root@localhost c]# cd
[root@localhost ~]# cd a
[root@localhost a]# cd / a
bash : cd: / a : 没有那个文件或目录
[root@localhost a]# cd
[root@localhost ~]# cd / a
bash : cd: / a : 没有那个文件或目录
[root@localhost ~]# ls
a
anaconda - ks.cfg
anaconda - screenshots
b
c
d
e
f
install.log
install.log.syslog
VMwareTools - 10.3.10 - 13959562.tar.gz
vmware - tools - distrib
公共的
模板
视频
图片
文档
下载
音乐
桌面
[root@localhost ~]# ls /
bin   home        media  opt   selinux  usr
boot  lib         misc   proc  srv      var
dev   lib64       mnt    root  sys
etc   lost + found  net    sbin  tmp
[root@localhost ~]# pwd
/ root
[root@localhost ~]# cd
[root@localhost ~]# cd /
[root@localhost / ]# ls
bin   home        media  opt   selinux  usr
boot  lib         misc   proc  srv      var
dev   lib64       mnt    root  sys
etc   lost + found  net    sbin  tmp
[root@localhost / ]# cd
[root@localhost ~]# cd / a
bash : cd: / a : 没有那个文件或目录
[root@localhost ~]# mkdir / a
[root@localhost ~]# ls
a
anaconda - ks.cfg
anaconda - screenshots
b
c
d
e
f
install.log
install.log.syslog
VMwareTools - 10.3.10 - 13959562.tar.gz
vmware - tools - distrib
公共的
模板
视频
图片
文档
下载
音乐
桌面
[root@localhost ~]# cd /
[root@localhost / ]# ls
a     etc    lost + found  net   sbin     tmp
bin   home   media       opt   selinux  usr
boot  lib    misc        proc  srv      var
dev   lib64  mnt         root  sys
[root@localhost / ]# cd
[root@localhost ~]# pwd
/ root
[root@localhost ~]# cd / a
[root@localhost a]# pwd
/ a
[root@localhost a]# cd
[root@localhost ~]# cd a
[root@localhost a]# cd / a
[root@localhost a]# cd
[root@localhost ~]# rmdir b
rmdir : 删除 "b" 失败 : 目录非空
[root@localhost ~]# rmdir c
[root@localhost ~]# rmdir e
[root@localhost ~]# rmdir f
[root@localhost ~]# rmdir d
[root@localhost ~]# cd a
[root@localhost a]# rmdir a
[root@localhost a]# rmdir b
rmdir : 删除 "b" 失败 : 目录非空
[root@localhost a]# cd
[root@localhost ~]# cd / a
[root@localhost a]# pwd
/ a
[root@localhost a]# cd
[root@localhost ~]# cd a
[root@localhost a]# pwd
/ root / a
[root@localhost a]# ls
b
[root@localhost a]# cd
[root@localhost ~]# ls
a                                    公共的
anaconda - ks.cfg                      模板
anaconda - screenshots                 视频
b                                    图片
install.log                          文档
install.log.syslog                   下载
VMwareTools - 10.3.10 - 13959562.tar.gz  音乐
vmware - tools - distrib                 桌面
[root@localhost ~]# cd b
[root@localhost b]# ls
c
[root@localhost b]# pwd
/ root / b
[root@localhost b]# cd c
[root@localhost c]# ls
d
[root@localhost c]# pwd
/ root / b / c
[root@localhost c]# cd ..
[root@localhost b]#  cd / c
bash : cd: / c : 没有那个文件或目录
[root@localhost b]# cd c
[root@localhost c]# pwd
/ root / b / c
[root@localhost c]# cd
[root@localhost ~]# cd a
[root@localhost a]# cd
[root@localhost ~]# cd / a
[root@localhost a]# cd
[root@localhost ~]# cd b
[root@localhost b]# pwd
/ root / b
[root@localhost b]# cd
[root@localhost ~]# cd / b
bash : cd: / b : 没有那个文件或目录
[root@localhost ~]# rm a
rm : 无法删除"a" : 是一个目录
[root@localhost ~]# rm - r a
rm：是否进入目录"a" ? y
rm：是否进入目录"a/b" ? n
[root@localhost ~]# ls
a                                    公共的
anaconda - ks.cfg                      模板
anaconda - screenshots                 视频
b                                    图片
install.log                          文档
install.log.syslog                   下载
VMwareTools - 10.3.10 - 13959562.tar.gz  音乐
vmware - tools - distrib                 桌面
[root@localhost ~]# rm - rf a
[root@localhost ~]# ls
anaconda - ks.cfg                      模板
anaconda - screenshots                 视频
b                                    图片
install.log                          文档
install.log.syslog                   下载
VMwareTools - 10.3.10 - 13959562.tar.gz  音乐
vmware - tools - distrib                 桌面
公共的
[root@localhost ~]# rm - rf / a
[root@localhost ~]# ls
anaconda - ks.cfg                      模板
anaconda - screenshots                 视频
b                                    图片
install.log                          文档
install.log.syslog                   下载
VMwareTools - 10.3.10 - 13959562.tar.gz  音乐
vmware - tools - distrib                 桌面
公共的
[root@localhost ~]# touch filea fileb
[root@localhost ~]# ls
anaconda - ks.cfg                      公共的
anaconda - screenshots                 模板
b                                    视频
filea                                图片
fileb                                文档
install.log                          下载
install.log.syslog                   音乐
VMwareTools - 10.3.10 - 13959562.tar.gz  桌面
vmware - tools - distrib
[root@localhost ~]# mv filea . / b
[root@localhost ~]# ls
anaconda - ks.cfg                      公共的
anaconda - screenshots                 模板
b                                    视频
fileb                                图片
install.log                          文档
install.log.syslog                   下载
VMwareTools - 10.3.10 - 13959562.tar.gz  音乐
vmware - tools - distrib                 桌面
[root@localhost ~]# cd b
[root@localhost b]# ls
c  filea
[root@localhost b]# cd ..
[root@localhost ~]# pwd
/ root
[root@localhost ~]# ls
anaconda - ks.cfg                      公共的
anaconda - screenshots                 模板
b                                    视频
fileb                                图片
install.log                          文档
install.log.syslog                   下载
VMwareTools - 10.3.10 - 13959562.tar.gz  音乐
vmware - tools - distrib                 桌面
[root@localhost ~]# mv fileb fileabc
[root@localhost ~]# ls
anaconda - ks.cfg                      公共的
anaconda - screenshots                 模板
b                                    视频
fileabc                              图片
install.log                          文档
install.log.syslog                   下载
VMwareTools - 10.3.10 - 13959562.tar.gz  音乐
vmware - tools - distrib                 桌面
[root@localhost ~]# mv fileabc . / b / fileb
[root@localhost ~]# cd b
[root@localhost b]# ls
c  filea  fileb
[root@localhost b]# cp fileb filec
[root@localhost b]# ls
c  filea  fileb  filec
[root@localhost b]# ls - l
总用量 4
drwxr - xr - x. 3 root root 4096 4月  10 00:18 c
- rw - r--r--. 1 root root    0 4月  10 01 : 21 filea
- rw - r--r--. 1 root root    0 4月  10 01 : 21 fileb
- rw - r--r--. 1 root root    0 4月  10 01 : 24 filec
[root@localhost b]# ls
c  filea  fileb  filec
[root@localhost b]# ls - 1
c
filea
fileb
filec
[root@localhost b]# ls file * -1
filea
fileb
filec
[root@localhost b]# ls - l file ?
-rw - r--r--. 1 root root 0 4月  10 01 : 21 filea
- rw - r--r--. 1 root root 0 4月  10 01 : 21 fileb
- rw - r--r--. 1 root root 0 4月  10 01 : 24 filec
[root@localhost b]# 
