[root@localhost ~]# ls
anaconda - ks.cfg                      ģ��
anaconda - screenshots                 ��Ƶ
install.log                          ͼƬ
install.log.syslog                   �ĵ�
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib                 ����
������                               ����
[root@localhost ~]# mkdir a
[root@localhost ~]# ls
a                                    ģ��
anaconda - ks.cfg                      ��Ƶ
anaconda - screenshots                 ͼƬ
install.log                          �ĵ�
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib                 ����
������
[root@localhost ~]# mkdir b
[root@localhost ~]# mkdir c
[root@localhost ~]# ls
a                                    ������
anaconda - ks.cfg                      ģ��
anaconda - screenshots                 ��Ƶ
b                                    ͼƬ
c                                    �ĵ�
install.log                          ����
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
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
mkdir : �޷�����Ŀ¼"a" : �ļ��Ѵ���
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
������
ģ��
��Ƶ
ͼƬ
�ĵ�
����
����
����
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
������
ģ��
��Ƶ
ͼƬ
�ĵ�
����
����
����
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
bash : cd: / a : û���Ǹ��ļ���Ŀ¼
[root@localhost a]# cd
[root@localhost ~]# cd / a
bash : cd: / a : û���Ǹ��ļ���Ŀ¼
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
������
ģ��
��Ƶ
ͼƬ
�ĵ�
����
����
����
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
bash : cd: / a : û���Ǹ��ļ���Ŀ¼
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
������
ģ��
��Ƶ
ͼƬ
�ĵ�
����
����
����
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
rmdir : ɾ�� "b" ʧ�� : Ŀ¼�ǿ�
[root@localhost ~]# rmdir c
[root@localhost ~]# rmdir e
[root@localhost ~]# rmdir f
[root@localhost ~]# rmdir d
[root@localhost ~]# cd a
[root@localhost a]# rmdir a
[root@localhost a]# rmdir b
rmdir : ɾ�� "b" ʧ�� : Ŀ¼�ǿ�
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
a                                    ������
anaconda - ks.cfg                      ģ��
anaconda - screenshots                 ��Ƶ
b                                    ͼƬ
install.log                          �ĵ�
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib                 ����
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
bash : cd: / c : û���Ǹ��ļ���Ŀ¼
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
bash : cd: / b : û���Ǹ��ļ���Ŀ¼
[root@localhost ~]# rm a
rm : �޷�ɾ��"a" : ��һ��Ŀ¼
[root@localhost ~]# rm - r a
rm���Ƿ����Ŀ¼"a" ? y
rm���Ƿ����Ŀ¼"a/b" ? n
[root@localhost ~]# ls
a                                    ������
anaconda - ks.cfg                      ģ��
anaconda - screenshots                 ��Ƶ
b                                    ͼƬ
install.log                          �ĵ�
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib                 ����
[root@localhost ~]# rm - rf a
[root@localhost ~]# ls
anaconda - ks.cfg                      ģ��
anaconda - screenshots                 ��Ƶ
b                                    ͼƬ
install.log                          �ĵ�
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib                 ����
������
[root@localhost ~]# rm - rf / a
[root@localhost ~]# ls
anaconda - ks.cfg                      ģ��
anaconda - screenshots                 ��Ƶ
b                                    ͼƬ
install.log                          �ĵ�
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib                 ����
������
[root@localhost ~]# touch filea fileb
[root@localhost ~]# ls
anaconda - ks.cfg                      ������
anaconda - screenshots                 ģ��
b                                    ��Ƶ
filea                                ͼƬ
fileb                                �ĵ�
install.log                          ����
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib
[root@localhost ~]# mv filea . / b
[root@localhost ~]# ls
anaconda - ks.cfg                      ������
anaconda - screenshots                 ģ��
b                                    ��Ƶ
fileb                                ͼƬ
install.log                          �ĵ�
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib                 ����
[root@localhost ~]# cd b
[root@localhost b]# ls
c  filea
[root@localhost b]# cd ..
[root@localhost ~]# pwd
/ root
[root@localhost ~]# ls
anaconda - ks.cfg                      ������
anaconda - screenshots                 ģ��
b                                    ��Ƶ
fileb                                ͼƬ
install.log                          �ĵ�
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib                 ����
[root@localhost ~]# mv fileb fileabc
[root@localhost ~]# ls
anaconda - ks.cfg                      ������
anaconda - screenshots                 ģ��
b                                    ��Ƶ
fileabc                              ͼƬ
install.log                          �ĵ�
install.log.syslog                   ����
VMwareTools - 10.3.10 - 13959562.tar.gz  ����
vmware - tools - distrib                 ����
[root@localhost ~]# mv fileabc . / b / fileb
[root@localhost ~]# cd b
[root@localhost b]# ls
c  filea  fileb
[root@localhost b]# cp fileb filec
[root@localhost b]# ls
c  filea  fileb  filec
[root@localhost b]# ls - l
������ 4
drwxr - xr - x. 3 root root 4096 4��  10 00:18 c
- rw - r--r--. 1 root root    0 4��  10 01 : 21 filea
- rw - r--r--. 1 root root    0 4��  10 01 : 21 fileb
- rw - r--r--. 1 root root    0 4��  10 01 : 24 filec
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
-rw - r--r--. 1 root root 0 4��  10 01 : 21 filea
- rw - r--r--. 1 root root 0 4��  10 01 : 21 fileb
- rw - r--r--. 1 root root 0 4��  10 01 : 24 filec
[root@localhost b]# 
