出现与安装包不符的问题解决


rm - f / var / lib / rpm / __ *
rpm --rebuilddb - v - v





[root@luckily ~]# yum clean dbcache
已加载插件：fastestmirror, langpacks
正在清理软件源： base extras updates
6 sqlite 文件已移除
[root@luckily ~]# yum clean metadata
已加载插件：fastestmirror, langpacks
正在清理软件源： base extras updates
8 metadata 文件已移除
0 sqlite 文件已移除
0 metadata 文件已移除
[root@luckily ~]# yum clean rpmdb
已加载插件：fastestmirror, langpacks
正在清理软件源： base extras updates
4 rpmdb 文件已移除
[root@luckily ~]# yum clean headers
已加载插件：fastestmirror, langpacks
正在清理软件源： base extras updates
0 header 文件已移除
[root@luckily ~]# yum clean all
已加载插件：fastestmirror, langpacks
正在清理软件源： base extras updates
Cleaning up list of fastest mirrors
[root@luckily ~]# rm - rf / var / cache / yum / timedhosts.txt
[root@luckily ~]# rm - rf / var / cache / yum/*
[root@luckily ~]# yum makecache
