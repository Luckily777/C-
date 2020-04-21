软件安装步骤

[root@luckily ~]# yum list | grep gcc
libgcc.x86_64                               4.8.5 - 39.el7               @anaconda
compat - gcc - 44.x86_64                        4.4.7 - 8.el7                base
compat - gcc - 44 - c++.x86_64                    4.4.7 - 8.el7                base
compat - gcc - 44 - gfortran.x86_64               4.4.7 - 8.el7                base
gcc.x86_64                                  4.8.5 - 39.el7               base
gcc - c++.x86_64                              4.8.5 - 39.el7               base
gcc - gfortran.x86_64                         4.8.5 - 39.el7               base
gcc - gnat.x86_64                             4.8.5 - 39.el7               base
gcc - go.x86_64                               4.8.5 - 39.el7               base
gcc - objc.x86_64                             4.8.5 - 39.el7               base
gcc - objc++.x86_64                           4.8.5 - 39.el7               base
gcc - plugin - devel.x86_64                     4.8.5 - 39.el7               base
libgcc.i686                                 4.8.5 - 39.el7               base
relaxngcc.noarch                            1.12 - 6.el7                 base
relaxngcc - javadoc.noarch                    1.12 - 6.el7                 base
[root@luckily ~]# yum - y install  gcc
已加载插件：fastestmirror, langpacks
Loading mirror speeds from cached hostfile
* base: mirrors.aliyun.com
* extras : mirrors.aliyun.com
* updates : mirrors.aliyun.com
正在解决依赖关系
-- > 正在检查事务
--->软件包 gcc.x86_64.0.4.8.5 - 39.el7 将被 安装
-- > 正在处理依赖关系 cpp = 4.8.5 - 39.el7，它被软件包 gcc - 4.8.5 - 39.el7.x86_64 需要
-- > 正在处理依赖关系 glibc - devel >= 2.2.90 - 12，它被软件包 gcc - 4.8.5 - 39.el7.x86_64 需要
-- > 正在检查事务
--->软件包 cpp.x86_64.0.4.8.5 - 39.el7 将被 安装
--->软件包 glibc - devel.x86_64.0.2.17 - 292.el7 将被 安装
-- > 正在处理依赖关系 glibc - headers = 2.17 - 292.el7，它被软件包 glibc - devel - 2.17 - 292.el7.x86_64 需要
-- > 正在处理依赖关系 glibc - headers，它被软件包 glibc - devel - 2.17 - 292.el7.x86_64 需要
-- > 正在检查事务
--->软件包 glibc - headers.x86_64.0.2.17 - 292.el7 将被 安装
-- > 正在处理依赖关系 kernel - headers >= 2.2.1，它被软件包 glibc - headers - 2.17 - 292.el7.x86_64 需要
-- > 正在处理依赖关系 kernel - headers，它被软件包 glibc - headers - 2.17 - 292.el7.x86_64 需要
-- > 正在检查事务
--->软件包 kernel - headers.x86_64.0.3.10.0 - 1062.18.1.el7 将被 安装
-- > 解决依赖关系完成

依赖关系解决

================================================================================
Package             架构        版本                        源            大小
================================================================================
正在安装:
gcc                 x86_64      4.8.5 - 39.el7                base          16 M
为依赖而安装 :
cpp                 x86_64      4.8.5 - 39.el7                base         5.9 M
glibc - devel         x86_64      2.17 - 292.el7                base         1.1 M
glibc - headers       x86_64      2.17 - 292.el7                base         687 k
kernel - headers      x86_64      3.10.0 - 1062.18.1.el7        updates      8.8 M

事务概要
================================================================================
安装  1 软件包(+4 依赖软件包)

总计：33 M
总下载量：1.1 M
安装大小：59 M
Downloading packages :
No Presto metadata available for base
警告： / var / cache / yum / x86_64 / 7 / base / packages / glibc - devel - 2.17 - 292.el7.x86_64.rpm : 头V3 RSA / SHA256 Signature, 密钥 ID f4a80eb5 : NOKEY
glibc - devel - 2.17 - 292.el7.x86_64.rpm 的公钥尚未安装
glibc - devel - 2.17 - 292.el7.x86_64.rpm | 1.1 MB   00 : 00
从 http ://mirrors.aliyun.com/centos/RPM-GPG-KEY-CentOS-7 检索密钥
导入 GPG key 0xF4A80EB5 :
    用户ID : "CentOS-7 Key (CentOS 7 Official Signing Key) <security@centos.org>"
    指纹 : 6341 ab27 53d7 8a78 a7c2 7bb1 24c6 a8a7 f4a8 0eb5
    来自 : http://mirrors.aliyun.com/centos/RPM-GPG-KEY-CentOS-7
Running transaction check
Running transaction test
Transaction test succeeded
Running transaction
正在安装 : cpp - 4.8.5 - 39.el7.x86_64                                     1 / 5
正在安装 : kernel - headers - 3.10.0 - 1062.18.1.el7.x86_64                  2 / 5
正在安装 : glibc - headers - 2.17 - 292.el7.x86_64                           3 / 5
正在安装 : glibc - devel - 2.17 - 292.el7.x86_64                             4 / 5
正在安装 : gcc - 4.8.5 - 39.el7.x86_64                                     5 / 5
验证中 : glibc - devel - 2.17 - 292.el7.x86_64                             1 / 5
验证中 : gcc - 4.8.5 - 39.el7.x86_64                                     2 / 5
验证中 : kernel - headers - 3.10.0 - 1062.18.1.el7.x86_64                  3 / 5
验证中 : glibc - headers - 2.17 - 292.el7.x86_64                           4 / 5
验证中 : cpp - 4.8.5 - 39.el7.x86_64                                     5 / 5

已安装 :
    gcc.x86_64 0 : 4.8.5 - 39.el7

    作为依赖被安装 :
cpp.x86_64 0 : 4.8.5 - 39.el7
glibc - devel.x86_64 0 : 2.17 - 292.el7
glibc - headers.x86_64 0 : 2.17 - 292.el7
kernel - headers.x86_64 0 : 3.10.0 - 1062.18.1.el7

完毕！
[root@luckily ~]# yum - y install  gcc - c++
已加载插件：fastestmirror, langpacks
Loading mirror speeds from cached hostfile
* base: mirrors.aliyun.com
* extras : mirrors.aliyun.com
* updates : mirrors.aliyun.com
正在解决依赖关系
-- > 正在检查事务
--->软件包 gcc - c++.x86_64.0.4.8.5 - 39.el7 将被 安装
-- > 正在处理依赖关系 libstdc++ - devel = 4.8.5 - 39.el7，它被软件包 gcc - c++ - 4.8.5 - 39.el7.x86_64 需要
-- > 正在检查事务
--->软件包 libstdc++ - devel.x86_64.0.4.8.5 - 39.el7 将被 安装
-- > 解决依赖关系完成

依赖关系解决

================================================================================
Package                 架构           版本                 源            大小
================================================================================
正在安装:
gcc - c++                 x86_64         4.8.5 - 39.el7         base         7.2 M
为依赖而安装 :
libstdc++ - devel         x86_64         4.8.5 - 39.el7         base         1.5 M

事务概要
================================================================================
安装  1 软件包(+1 依赖软件包)

总下载量：8.7 M
安装大小：25 M
Downloading packages :
(1 / 2) : libstdc++ - devel - 4.8.5 - 39.el7.x86_64.rpm | 1.5 MB   00 : 01
(2 / 2) : gcc - c++ - 4.8.5 - 39.el7.x86_64.rpm | 7.2 MB   00 : 02
--------------------------------------------------------------------------------
总计                                               3.1 MB / s | 8.7 MB  00 : 02
Running transaction check
Running transaction test
Transaction test succeeded
Running transaction
正在安装 : libstdc++ - devel - 4.8.5 - 39.el7.x86_64                         1 / 2
正在安装 : gcc - c++ - 4.8.5 - 39.el7.x86_64                                 2 / 2
验证中 : gcc - c++ - 4.8.5 - 39.el7.x86_64                                 1 / 2
验证中 : libstdc++ - devel - 4.8.5 - 39.el7.x86_64                         2 / 2

已安装 :
    gcc - c++.x86_64 0 : 4.8.5 - 39.el7

    作为依赖被安装 :
libstdc++ - devel.x86_64 0 : 4.8.5 - 39.el7

完毕！
[root@luckily ~]# yum list | grep gdb
gdb.x86_64                                  7.6.1 - 115.el7              @anaconda
gdbm.x86_64                                 1.10 - 8.el7                 @anaconda
gdb - doc.noarch                              7.6.1 - 115.el7              base
gdb - gdbserver.x86_64                        7.6.1 - 115.el7              base
gdbm.i686                                   1.10 - 8.el7                 base
gdbm - devel.i686                             1.10 - 8.el7                 base
gdbm - devel.x86_64                           1.10 - 8.el7                 base
libreoffice - gdb - debug - support.x86_64        1:5.3.6.1 - 21.el7           base
swig3 - gdb.x86_64                            3.0.12 - 17.el7              extras
[root@luckily ~]# yum - y install gdb
已加载插件：fastestmirror, langpacks
Loading mirror speeds from cached hostfile
* base: mirrors.aliyun.com
* extras : mirrors.aliyun.com
* updates : mirrors.aliyun.com
软件包 gdb - 7.6.1 - 115.el7.x86_64 已安装并且是最新版本
无须任何处理
[root@luckily ~]# gcc
gcc : 致命错误：没有输入文件
编译中断。
[root@luckily ~]# g++
g++: 致命错误：没有输入文件
编译中断。
[root@luckily ~]# gdb
GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
Copyright(C) 2013 Free Software Foundation, Inc.
License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
    This is free software : you are free to changeand redistribute it.
    There is NO WARRANTY, to the extent permitted by law.Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-redhat-linux-gnu".
    For bug reporting instructions, please see :
< http ://www.gnu.org/software/gdb/bugs/>.
    (gdb)q
    [root@luckily ~]# gdb --version
    GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
    Copyright(C) 2013 Free Software Foundation, Inc.
    License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
    This is free software : you are free to changeand redistribute it.
    There is NO WARRANTY, to the extent permitted by law.Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-redhat-linux-gnu".
    For bug reporting instructions, please see :
< http ://www.gnu.org/software/gdb/bugs/>.
    [root@luckily ~] # 
