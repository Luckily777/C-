�����밲װ��������������


rm - f / var / lib / rpm / __ *
rpm --rebuilddb - v - v





[root@luckily ~]# yum clean dbcache
�Ѽ��ز����fastestmirror, langpacks
�����������Դ�� base extras updates
6 sqlite �ļ����Ƴ�
[root@luckily ~]# yum clean metadata
�Ѽ��ز����fastestmirror, langpacks
�����������Դ�� base extras updates
8 metadata �ļ����Ƴ�
0 sqlite �ļ����Ƴ�
0 metadata �ļ����Ƴ�
[root@luckily ~]# yum clean rpmdb
�Ѽ��ز����fastestmirror, langpacks
�����������Դ�� base extras updates
4 rpmdb �ļ����Ƴ�
[root@luckily ~]# yum clean headers
�Ѽ��ز����fastestmirror, langpacks
�����������Դ�� base extras updates
0 header �ļ����Ƴ�
[root@luckily ~]# yum clean all
�Ѽ��ز����fastestmirror, langpacks
�����������Դ�� base extras updates
Cleaning up list of fastest mirrors
[root@luckily ~]# rm - rf / var / cache / yum / timedhosts.txt
[root@luckily ~]# rm - rf / var / cache / yum/*
[root@luckily ~]# yum makecache
