�����װ����

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
�Ѽ��ز����fastestmirror, langpacks
Loading mirror speeds from cached hostfile
* base: mirrors.aliyun.com
* extras : mirrors.aliyun.com
* updates : mirrors.aliyun.com
���ڽ��������ϵ
-- > ���ڼ������
--->����� gcc.x86_64.0.4.8.5 - 39.el7 ���� ��װ
-- > ���ڴ���������ϵ cpp = 4.8.5 - 39.el7����������� gcc - 4.8.5 - 39.el7.x86_64 ��Ҫ
-- > ���ڴ���������ϵ glibc - devel >= 2.2.90 - 12����������� gcc - 4.8.5 - 39.el7.x86_64 ��Ҫ
-- > ���ڼ������
--->����� cpp.x86_64.0.4.8.5 - 39.el7 ���� ��װ
--->����� glibc - devel.x86_64.0.2.17 - 292.el7 ���� ��װ
-- > ���ڴ���������ϵ glibc - headers = 2.17 - 292.el7����������� glibc - devel - 2.17 - 292.el7.x86_64 ��Ҫ
-- > ���ڴ���������ϵ glibc - headers����������� glibc - devel - 2.17 - 292.el7.x86_64 ��Ҫ
-- > ���ڼ������
--->����� glibc - headers.x86_64.0.2.17 - 292.el7 ���� ��װ
-- > ���ڴ���������ϵ kernel - headers >= 2.2.1����������� glibc - headers - 2.17 - 292.el7.x86_64 ��Ҫ
-- > ���ڴ���������ϵ kernel - headers����������� glibc - headers - 2.17 - 292.el7.x86_64 ��Ҫ
-- > ���ڼ������
--->����� kernel - headers.x86_64.0.3.10.0 - 1062.18.1.el7 ���� ��װ
-- > ���������ϵ���

������ϵ���

================================================================================
Package             �ܹ�        �汾                        Դ            ��С
================================================================================
���ڰ�װ:
gcc                 x86_64      4.8.5 - 39.el7                base          16 M
Ϊ��������װ :
cpp                 x86_64      4.8.5 - 39.el7                base         5.9 M
glibc - devel         x86_64      2.17 - 292.el7                base         1.1 M
glibc - headers       x86_64      2.17 - 292.el7                base         687 k
kernel - headers      x86_64      3.10.0 - 1062.18.1.el7        updates      8.8 M

�����Ҫ
================================================================================
��װ  1 �����(+4 ���������)

�ܼƣ�33 M
����������1.1 M
��װ��С��59 M
Downloading packages :
No Presto metadata available for base
���棺 / var / cache / yum / x86_64 / 7 / base / packages / glibc - devel - 2.17 - 292.el7.x86_64.rpm : ͷV3 RSA / SHA256 Signature, ��Կ ID f4a80eb5 : NOKEY
glibc - devel - 2.17 - 292.el7.x86_64.rpm �Ĺ�Կ��δ��װ
glibc - devel - 2.17 - 292.el7.x86_64.rpm | 1.1 MB   00 : 00
�� http ://mirrors.aliyun.com/centos/RPM-GPG-KEY-CentOS-7 ������Կ
���� GPG key 0xF4A80EB5 :
    �û�ID : "CentOS-7 Key (CentOS 7 Official Signing Key) <security@centos.org>"
    ָ�� : 6341 ab27 53d7 8a78 a7c2 7bb1 24c6 a8a7 f4a8 0eb5
    ���� : http://mirrors.aliyun.com/centos/RPM-GPG-KEY-CentOS-7
Running transaction check
Running transaction test
Transaction test succeeded
Running transaction
���ڰ�װ : cpp - 4.8.5 - 39.el7.x86_64                                     1 / 5
���ڰ�װ : kernel - headers - 3.10.0 - 1062.18.1.el7.x86_64                  2 / 5
���ڰ�װ : glibc - headers - 2.17 - 292.el7.x86_64                           3 / 5
���ڰ�װ : glibc - devel - 2.17 - 292.el7.x86_64                             4 / 5
���ڰ�װ : gcc - 4.8.5 - 39.el7.x86_64                                     5 / 5
��֤�� : glibc - devel - 2.17 - 292.el7.x86_64                             1 / 5
��֤�� : gcc - 4.8.5 - 39.el7.x86_64                                     2 / 5
��֤�� : kernel - headers - 3.10.0 - 1062.18.1.el7.x86_64                  3 / 5
��֤�� : glibc - headers - 2.17 - 292.el7.x86_64                           4 / 5
��֤�� : cpp - 4.8.5 - 39.el7.x86_64                                     5 / 5

�Ѱ�װ :
    gcc.x86_64 0 : 4.8.5 - 39.el7

    ��Ϊ��������װ :
cpp.x86_64 0 : 4.8.5 - 39.el7
glibc - devel.x86_64 0 : 2.17 - 292.el7
glibc - headers.x86_64 0 : 2.17 - 292.el7
kernel - headers.x86_64 0 : 3.10.0 - 1062.18.1.el7

��ϣ�
[root@luckily ~]# yum - y install  gcc - c++
�Ѽ��ز����fastestmirror, langpacks
Loading mirror speeds from cached hostfile
* base: mirrors.aliyun.com
* extras : mirrors.aliyun.com
* updates : mirrors.aliyun.com
���ڽ��������ϵ
-- > ���ڼ������
--->����� gcc - c++.x86_64.0.4.8.5 - 39.el7 ���� ��װ
-- > ���ڴ���������ϵ libstdc++ - devel = 4.8.5 - 39.el7����������� gcc - c++ - 4.8.5 - 39.el7.x86_64 ��Ҫ
-- > ���ڼ������
--->����� libstdc++ - devel.x86_64.0.4.8.5 - 39.el7 ���� ��װ
-- > ���������ϵ���

������ϵ���

================================================================================
Package                 �ܹ�           �汾                 Դ            ��С
================================================================================
���ڰ�װ:
gcc - c++                 x86_64         4.8.5 - 39.el7         base         7.2 M
Ϊ��������װ :
libstdc++ - devel         x86_64         4.8.5 - 39.el7         base         1.5 M

�����Ҫ
================================================================================
��װ  1 �����(+1 ���������)

����������8.7 M
��װ��С��25 M
Downloading packages :
(1 / 2) : libstdc++ - devel - 4.8.5 - 39.el7.x86_64.rpm | 1.5 MB   00 : 01
(2 / 2) : gcc - c++ - 4.8.5 - 39.el7.x86_64.rpm | 7.2 MB   00 : 02
--------------------------------------------------------------------------------
�ܼ�                                               3.1 MB / s | 8.7 MB  00 : 02
Running transaction check
Running transaction test
Transaction test succeeded
Running transaction
���ڰ�װ : libstdc++ - devel - 4.8.5 - 39.el7.x86_64                         1 / 2
���ڰ�װ : gcc - c++ - 4.8.5 - 39.el7.x86_64                                 2 / 2
��֤�� : gcc - c++ - 4.8.5 - 39.el7.x86_64                                 1 / 2
��֤�� : libstdc++ - devel - 4.8.5 - 39.el7.x86_64                         2 / 2

�Ѱ�װ :
    gcc - c++.x86_64 0 : 4.8.5 - 39.el7

    ��Ϊ��������װ :
libstdc++ - devel.x86_64 0 : 4.8.5 - 39.el7

��ϣ�
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
�Ѽ��ز����fastestmirror, langpacks
Loading mirror speeds from cached hostfile
* base: mirrors.aliyun.com
* extras : mirrors.aliyun.com
* updates : mirrors.aliyun.com
����� gdb - 7.6.1 - 115.el7.x86_64 �Ѱ�װ���������°汾
�����κδ���
[root@luckily ~]# gcc
gcc : ��������û�������ļ�
�����жϡ�
[root@luckily ~]# g++
g++: ��������û�������ļ�
�����жϡ�
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
