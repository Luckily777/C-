¶Ïµãµ÷ÊÔ 



[root@luckily day01]# vim 042502.c
[root@luckily day01]# gcc 042502.c - g
[root@luckily day01]# . / a.out
¶Î´íÎó(ÍÂºË)
[root@luckily day01]# gdb a.out
GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
Copyright(C) 2013 Free Software Foundation, Inc.
License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
    This is free software : you are free to changeand redistribute it.
    There is NO WARRANTY, to the extent permitted by law.Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-redhat-linux-gnu".
    For bug reporting instructions, please see :
< http ://www.gnu.org/software/gdb/bugs/>...
    Reading symbols from / root / study / day01 / a.out...done.
    (gdb)list 1
    1	#include <stdio.h>
    2	#include <stdlib.h>
    3
    4	int* p = NULL;
5	int fun(int n) {
    6		p = (int*)"abc";
    7		return n + 1;
    8
}
9
10	int main(int argc, int* argv[]) {
    (gdb)
        11		int r = fun(3);
    12 * p = 10;
    13		printf("*p=%d\n", *p);
    14		int i;
    15		for (i = 0; i < argc; i++) {
        16			printf("argv[%d]=%s\n", i, argv[i]);
        17
    }
    18
}
19
(gdb)
Line number 20 out of range; 042502.c has 19 lines.
(gdb) break fun
Breakpoint 1 at 0x400534: file 042502.c, line 6.
(gdb)run
Starting program : / root / study / day01 / a.out

Breakpoint 1, fun(n = 3) at 042502.c : 6
6		p = (int*)"abc";
Missing separate debuginfos, use: debuginfo - install glibc - 2.17 - 292.el7.x86_64
(gdb) return
Make fun return now ? (y or n) y
#0  0x0000000000400560 in main(argc = 1,
    argv = 0x7fffffffe0b8) at 042502.c:11
    11		int r = fun(3);
(gdb)n
12 * p = 10;
(gdb)

Program received signal SIGSEGV, Segmentation fault.
0x000000000040056a in main(argc = 1, argv = 0x7fffffffe0b8) at 042502.c:12
12 * p = 10;
(gdb)n

Program terminated with signal SIGSEGV, Segmentation fault.
The program no longer exists.
(gdb)q
[root@luckily day01]# gdb a.out
GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
Copyright(C) 2013 Free Software Foundation, Inc.
License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
    This is free software : you are free to changeand redistribute it.
    There is NO WARRANTY, to the extent permitted by law.Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-redhat-linux-gnu".
    For bug reporting instructions, please see :
< http ://www.gnu.org/software/gdb/bugs/>...
    Reading symbols from / root / study / day01 / a.out...done.
    (gdb)l
    2	#include <stdlib.h>
    3
    4	int* p = NULL;
5	int fun(int n) {
    6		p = (int*)"abc";
    7		return n + 1;
    8
}
9
10	int main(int argc, int* argv[]) {
    11		int r = fun(3);
    (gdb) break 12
        Breakpoint 1 at 0x400563: file 042502.c, line 12.
        (gdb)r
        Starting program : / root / study / day01 / a.out

        Breakpoint 1, main(argc = 1, argv = 0x7fffffffe0b8) at 042502.c : 12
        12 * p = 10;
    Missing separate debuginfos, use: debuginfo - install glibc - 2.17 - 292.el7.x86_64
    (gdb) print p
        $1 = (int*)0x400660
        (gdb)print * p
        $2 = 6513249
        (gdb)set var p = (int*)malloc(sizeof(int))
        (gdb)print p
        $3 = (int*)0x602010
        (gdb)print * p
        $4 = 0
        (gdb)s
        13		printf("*p=%d\n", *p);
    (gdb)print p
        $5 = (int*)0x602010
        (gdb)print * p
        $6 = 10
        (gdb)n
        * p = 10
        15		for (i = 0; i < argc; i++) {
        (gdb)l 18
            13		printf("*p=%d\n", *p);
        14		int i;
        15		for (i = 0; i < argc; i++) {
            16			printf("argv[%d]=%s\n", i, argv[i]);
            17
        }
        18
    }
    19
        (gdb)n
        16			printf("argv[%d]=%s\n", i, argv[i]);
    (gdb)n
        argv[0] = / root / study / day01 / a.out
        15		for (i = 0; i < argc; i++) {
        (gdb)n
            18
    }
    (gdb)n
        0x00007ffff7a2f505 in __libc_start_main() from / lib64 / libc.so.6
        (gdb)n
        Single stepping until exit from function __libc_start_main,
        which has no line number information.
        [Inferior 1 (process 4241) exited with code 01]
    (gdb) n
        The program is not being run.
        (gdb)
