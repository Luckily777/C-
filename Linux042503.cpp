…Ë÷√∂œµ„ …æ≥˝∂œµ„ 

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
	(gdb)list
	10	        printf("void fun2(void)\n");
11	}
12
13	void fun3(void) {
	14	        printf("void fun3(void)\n");
	15
}
16
17	int main(int argc, char* argv[]) {
	18		typedef void FUN(void);
	19		FUN * arr[3] = { fun1 ,fun2 ,fun3 };
	(gdb)list 1
		1	#include <stdio.h>
		2	#include <stdlib.h>
		3
		4
		5	void fun1(void) {
		6		printf("void fun1(void)\n");
		7
	}
	8
		9	void fun2(void) {
		10	        printf("void fun2(void)\n");
		(gdb)list
			11
	}
	12
		13	void fun3(void) {
		14	        printf("void fun3(void)\n");
		15
	}
	16
		17	int main(int argc, char* argv[]) {
		18		typedef void FUN(void);
		19		FUN * arr[3] = { fun1 ,fun2 ,fun3 };
		20
			(gdb)list
			21		printf("in main...\n");
		22		int i;
		23		for (i = 0; i < 100; i++) {
			24			arr[i % 3]();
			25			sleep(1);
			26
		}
		27		for (i = 0; i < argc; i++) {
			28			printf("argv[%d]=%s\n", i, argv[i]);
			29
		}
		30		printf("exiting...\n");
		(gdb)list
			31		return 0;
		32
	}
	33
		(gdb) break 20
		Breakpoint 1 at 0x400614: file 042501.c, line 20.
		(gdb)info breakpoints
		Num     Type           Disp Enb Address            What
		1       breakpoint     keep y   0x0000000000400614 in main at 042501.c : 20
		(gdb) break fun3
		Breakpoint 2 at 0x4005e1 : file 042501.c, line 14.
		(gdb)info breakpoints
		Num     Type           Disp Enb Address            What
		1       breakpoint     keep y   0x0000000000400614 in main at 042501.c : 20
		2       breakpoint     keep y   0x00000000004005e1 in fun3 at 042501.c : 14
		(gdb)run
		Starting program : / root / study / day01 / a.out

		Breakpoint 1, main(argc = 1, argv = 0x7fffffffe0b8) at 042501.c : 21
		21		printf("in main...\n");
	Missing separate debuginfos, use: debuginfo - install glibc - 2.17 - 292.el7.x86_64
	(gdb) next
		in main...
		23		for (i = 0; i < 100; i++) {
		(gdb)n
			24			arr[i % 3]();
		(gdb)n
			void fun1(void)
			25			sleep(1);
		(gdb)n
			n
			n
			23		for (i = 0; i < 100; i++) {
			(gdb)n
				24			arr[i % 3]();
			(gdb)n
				void fun2(void)
				25			sleep(1);
			(gdb)n
				23		for (i = 0; i < 100; i++) {
				(gdb)n
					24			arr[i % 3]();
				(gdb)n

					Breakpoint 2, fun3() at 042501.c:14
					14	        printf("void fun3(void)\n");
				(gdb)until 28
					void fun3(void)
					main(argc = 1, argv = 0x7fffffffe0b8) at 042501.c:25
					25			sleep(1);
				(gdb)info b
					Num     Type           Disp Enb Address            What
					1       breakpoint     keep y   0x0000000000400614 in main at 042501.c:20
					breakpoint already hit 1 time
					2       breakpoint     keep y   0x00000000004005e1 in fun3 at 042501.c : 14
					breakpoint already hit 1 time
					(gdb) delete 2
					(gdb)next
					23		for (i = 0; i < 100; i++) {
					(gdb)n
						24			arr[i % 3]();
					(gdb)n
						void fun1(void)
						25			sleep(1);
					(gdb)n
						n
						23		for (i = 0; i < 100; i++) {
						(gdb)n
							24			arr[i % 3]();
						(gdb)wntil 28
							Undefined command : "wntil".Try "help".
							(gdb)until 28
							void fun2(void)
							void fun3(void)
							void fun1(void)
							void fun2(void)
							void fun3(void)
							void fun1(void)
							void fun2(void)
							void fun3(void)
							void fun1(void)
							void fun2(void)
							void fun3(void)
							void fun1(void)
							void fun2(void)
							^ C
							Program received signal SIGINT, Interrupt.
							0x00007ffff7ad27f0 in __nanosleep_nocancel() from / lib64 / libc.so.6
							(gdb)quit
							A debugging session is active.

							Inferior 1[process 3907] will be killed.

							Quit anyway ? (y or n) y
