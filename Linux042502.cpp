gdb 调试

[root@luckily ~]# cd study /
[root@luckily study]# ls
day01
[root@luckily study]# cd day01 /
[root@luckily day01]# ls
042401.c  a.out
[root@luckily day01]# vim 042501.c
[root@luckily day01]# ls
042401.c  042501.c  a.out
[root@luckily day01]# gdb
[root@luckily day01]# gcc - g 042501.c
042401.c  042501.c  a.out
[root@luckily day01]# gdb


(gdb)file a.out
Reading symbols from / root / study / day01 / a.out...done.
(gdb)set args abc def hehe haha
(gdb) run ^ CQuit
(gdb) run
Starting program : / root / study / day01 / a.out abc def hehe haha
(gdb) quit
A debugging session is active.

Inferior 1[process 3536] will be killed.

Quit anyway ? (y or n) y


(gdb) file a.out
Reading symbols from / root / study / day01 / a.out...done.
(gdb)set args aaa bbb ccc
(gdb) start
Temporary breakpoint 1 at 0x4005fc: file 042501.c, line 19.
Starting program : / root / study / day01 / a.out aaa bbb ccc

Temporary breakpoint 1, main(argc = 4, argv = 0x7fffffffe098) at 042501.c : 19
19		FUN * arr[3] = { fun1 ,fun2 ,fun3 };
Missing separate debuginfos, use: debuginfo - install glibc - 2.17 - 292.el7.x86_64
(gdb) quit
A debugging session is active.

Inferior 1[process 3798] will be killed.

Quit anyway ? (y or n) y




双端控制黑客第一步 调试

（1）
[root@luckily day01]# . / a.out




（2）
luckily study]# cd day01
[root@luckily day01]# ps
PID TTY          TIME CMD
3582 pts / 1    00:00 : 00 bash
3645 pts / 1    00 : 00 : 00 ps
[root@luckily day01]# ps - ef | grep a.out
root       3631   3120  0 09:49 pts / 0    00 : 00 : 00 . / a.out
root       3661   3582  0 09 : 49 pts / 1    00 : 00 : 00 grep --color = auto a.out
[root@luckily day01]# gdb
GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
Copyright(C) 2013 Free Software Foundation, Inc.
License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
    This is free software : you are free to changeand redistribute it.
    There is NO WARRANTY, to the extent permitted by law.Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-redhat-linux-gnu".
    For bug reporting instructions, please see :
< http ://www.gnu.org/software/gdb/bugs/>.
    (gdb)attach 3631
    Attaching to process 3631
    warning : unable to open / proc file '/proc/3631/status'
    warning : unable to open / proc file '/proc/3631/status'
    ptrace : 没有那个进程.
    (gdb)attach 3631
    Attaching to process 3631
    warning : unable to open / proc file '/proc/3631/status'
    warning : unable to open / proc file '/proc/3631/status'
    ptrace : 没有那个进程.
    (gdb)quit
    [root@luckily day01]#  ps - ef | grep a.out
    root       3699   3120  0 09:51 pts / 0    00 : 00 : 00 . / a.out
    root       3707   3582  0 09 : 52 pts / 1    00 : 00 : 00 grep --color = auto a.out
    [root@luckily day01]# gdb
    GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
    Copyright(C) 2013 Free Software Foundation, Inc.
    License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
    This is free software : you are free to changeand redistribute it.
    There is NO WARRANTY, to the extent permitted by law.Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-redhat-linux-gnu".
    For bug reporting instructions, please see :
< http ://www.gnu.org/software/gdb/bugs/>.
    (gdb)attach 3699
    Attaching to process 3699
    Reading symbols from / root / study / day01 / a.out...done.
    Reading symbols from / lib64 / libc.so.6...(no debugging symbols found)...done.
    Loaded symbols for / lib64 / libc.so.6
    Reading symbols from / lib64 / ld - linux - x86 - 64.so.2...(no debugging symbols found)...done.
    Loaded symbols for / lib64 / ld - linux - x86 - 64.so.2
    0x00007f2d216697f0 in __nanosleep_nocancel() from / lib64 / libc.so.6
    Missing separate debuginfos, use: debuginfo - install glibc - 2.17 - 292.el7.x86_64
    (gdb) continue
    Continuing.
    ^ C
    Program received signal SIGINT, Interrupt.
    0x00007f2d216697f0 in __nanosleep_nocancel() from / lib64 / libc.so.6
    (gdb) ^ CQuit
    (gdb) quit
    A debugging session is active.

    Inferior 1[process 3699] will be detached.

    Quit anyway ? (y or n) y
    Detaching from program : / root / study / day01 / a.out, process 3699
    [root@luckily day01]#  ^ C
    [root@luckily day01]# 
