[root@localhost 桌面]# cd
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
.gnome2 / 公共的 /
.gnote / 模板 /
.gnupg / 视频 /
.gstreamer - 0.10 / 图片 /
.gtk - bookmarks                         文档 /
.gvfs / 下载 /
.ICEauthority                          音乐 /
.imsettings.log                        桌面 /
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
.gnome2 / 公共的 /
.gnote / 模板 /
.gnupg / 视频 /
.gstreamer - 0.10 / 图片 /
.gtk - bookmarks                         文档 /
.gvfs / 下载 /
.ICEauthority                          音乐 /
.imsettings.log                        桌面 /
[root@localhost ~]# vim / etc / yum.repos.d / CentOS - Base.repo.backup
[root@localhost ~]# mv / etc / yum.repos.d / CentOS - Base.repo / etc / yum.repos.d / CentOS - Base.repo.backup[root@localhost ~]# wget - O / etc / yum.repos.d / CentOS - Base.repo http ://mirrors.aliyun.com/repo/Centos-7.repo
--2020 - 04 - 20 16 : 18 : 42--http ://mirrors.aliyun.com/repo/Centos-7.repo
    正在解析主机 mirrors.aliyun.com... 111.19.177.241, 111.19.233.241, 111.19.210.114, ...
    正在连接 mirrors.aliyun.com | 111.19.177.241 | : 80...已连接。
    已发出 HTTP 请求，正在等待回应... 200 OK
    长度：2523(2.5K)[application / octet - stream]
    正在保存至 : “ / etc / yum.repos.d / CentOS - Base.repo”

    100 % [====================================================>] 2, 523       --. - K / s   in 0s

    2020 - 04 - 20 16 : 18 : 42 (832 MB / s) - 已保存 “ / etc / yum.repos.d / CentOS - Base.repo”[2523 / 2523])

    [root@localhost ~]# yum makecache
    已加载插件：fastestmirror, refresh - packagekit, security
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
    元数据缓存已建立
    [root@localhost ~]# ls
    87v                   install.log.syslog                     vmware - tools - distrib  下载
    anaconda - ks.cfg       my.p                                   公共的                音乐
    anaconda - screenshots  test.c                                 模板                  桌面
    a.out                 vim - common - 7.4.629 - 5.el6.x86_64.rpm    视频
    b                     vim - enhanced - 7.4.629 - 5.el6.x86_64.rpm  图片
    install.log           VMwareTools - 10.3.10 - 13959562.tar.gz    文档
    [root@localhost ~]# cp / etc / passwd ~
    [root@localhost ~]# ls
    87v                   install.log         vim - common - 7.4.629 - 5.el6.x86_64.rpm    模板  音乐
    anaconda - ks.cfg       install.log.syslog  vim - enhanced - 7.4.629 - 5.el6.x86_64.rpm  视频  桌面
    anaconda - screenshots  my.p                VMwareTools - 10.3.10 - 13959562.tar.gz    图片
    a.out                 passwd              vmware - tools - distrib                   文档
    b                     test.c              公共的                                 下载
    [root@localhost ~]# grep root passwd
    root : x:0 : 0 : root : / root : / bin / bash
    operator : x : 11 : 0 : operator : / root : / sbin / nologin
    [root@localhost ~]# grep - n "root" passwd
    1:root:x:0 : 0 : root : / root : / bin / bash
    11 : operator : x : 11 : 0 : operator : / root : / sbin / nologin
    [root@localhost ~]# 
