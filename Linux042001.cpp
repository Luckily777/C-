[root@localhost ����]# cd
[root@localhost ~]# vim / etc / yum.repos.d / CentOS - Base.repo
87v                                    install.log
.abrt / install.log.syslog
anaconda - ks.cfg.lesshst
anaconda - screenshots / .local /
a.out                                  my.p
b / .nautilus /
.bash_history.pulse /
.bash_logout.pulse - cookie
.bash_profile.ssh /
.bashrc.tcshrc
.cache / test.c
.config / .thumbnails /
.cshrc                                 vim - common - 7.4.629 - 5.el6.x86_64.rpm
.dbus / vim - enhanced - 7.4.629 - 5.el6.x86_64.rpm
.esd_auth.viminfo
.gconf / VMwareTools - 10.3.10 - 13959562.tar.gz
.gconfd / vmware - tools - distrib /
.gnome2 / ������ /
.gnote / ģ�� /
.gnupg / ��Ƶ /
.gstreamer - 0.10 / ͼƬ /
.gtk - bookmarks                         �ĵ� /
.gvfs / ���� /
.ICEauthority                          ���� /
.imsettings.log                        ���� /
[root@localhost ~]# vim / etc / yum.repos.d / CentOS - Base.repo
87v                                    install.log
.abrt / install.log.syslog
anaconda - ks.cfg.lesshst
anaconda - screenshots / .local /
a.out                                  my.p
b / .nautilus /
.bash_history.pulse /
.bash_logout.pulse - cookie
.bash_profile.ssh /
.bashrc.tcshrc
.cache / test.c
.config / .thumbnails /
.cshrc                                 vim - common - 7.4.629 - 5.el6.x86_64.rpm
.dbus / vim - enhanced - 7.4.629 - 5.el6.x86_64.rpm
.esd_auth.viminfo
.gconf / VMwareTools - 10.3.10 - 13959562.tar.gz
.gconfd / vmware - tools - distrib /
.gnome2 / ������ /
.gnote / ģ�� /
.gnupg / ��Ƶ /
.gstreamer - 0.10 / ͼƬ /
.gtk - bookmarks                         �ĵ� /
.gvfs / ���� /
.ICEauthority                          ���� /
.imsettings.log                        ���� /
[root@localhost ~]# vim / etc / yum.repos.d / CentOS - Base.repo.backup
[root@localhost ~]# mv / etc / yum.repos.d / CentOS - Base.repo / etc / yum.repos.d / CentOS - Base.repo.backup[root@localhost ~]# wget - O / etc / yum.repos.d / CentOS - Base.repo http ://mirrors.aliyun.com/repo/Centos-7.repo
--2020 - 04 - 20 16 : 18 : 42--http ://mirrors.aliyun.com/repo/Centos-7.repo
    ���ڽ������� mirrors.aliyun.com... 111.19.177.241, 111.19.233.241, 111.19.210.114, ...
    �������� mirrors.aliyun.com | 111.19.177.241 | : 80...�����ӡ�
    �ѷ��� HTTP �������ڵȴ���Ӧ... 200 OK
    ���ȣ�2523(2.5K)[application / octet - stream]
    ���ڱ����� : �� / etc / yum.repos.d / CentOS - Base.repo��

    100 % [====================================================>] 2, 523       --. - K / s   in 0s

    2020 - 04 - 20 16 : 18 : 42 (832 MB / s) - �ѱ��� �� / etc / yum.repos.d / CentOS - Base.repo��[2523 / 2523])

    [root@localhost ~]# yum makecache
    �Ѽ��ز����fastestmirror, refresh - packagekit, security
    Loading mirror speeds from cached hostfile
    * base: mirrors.aliyun.com
    * extras : mirrors.aliyun.com
    * updates : mirrors.aliyun.com
    base | 3.7 kB     00 : 00
    extras | 3.4 kB     00 : 00
    extras / prestodelta | 2.2 kB     00 : 00
    extras / other_db | 14 kB     00 : 00
    updates | 3.4 kB     00 : 00
    updates / prestodelta | 298 kB     00 : 00
    Ԫ���ݻ����ѽ���
    [root@localhost ~]# ls
    87v                   install.log.syslog                     vmware - tools - distrib  ����
    anaconda - ks.cfg       my.p                                   ������                ����
    anaconda - screenshots  test.c                                 ģ��                  ����
    a.out                 vim - common - 7.4.629 - 5.el6.x86_64.rpm    ��Ƶ
    b                     vim - enhanced - 7.4.629 - 5.el6.x86_64.rpm  ͼƬ
    install.log           VMwareTools - 10.3.10 - 13959562.tar.gz    �ĵ�
    [root@localhost ~]# cp / etc / passwd ~
    [root@localhost ~]# ls
    87v                   install.log         vim - common - 7.4.629 - 5.el6.x86_64.rpm    ģ��  ����
    anaconda - ks.cfg       install.log.syslog  vim - enhanced - 7.4.629 - 5.el6.x86_64.rpm  ��Ƶ  ����
    anaconda - screenshots  my.p                VMwareTools - 10.3.10 - 13959562.tar.gz    ͼƬ
    a.out                 passwd              vmware - tools - distrib                   �ĵ�
    b                     test.c              ������                                 ����
    [root@localhost ~]# grep root passwd
    root : x:0 : 0 : root : / root : / bin / bash
    operator : x : 11 : 0 : operator : / root : / sbin / nologin
    [root@localhost ~]# grep - n "root" passwd
    1:root:x:0 : 0 : root : / root : / bin / bash
    11 : operator : x : 11 : 0 : operator : / root : / sbin / nologin
    [root@localhost ~]# 
