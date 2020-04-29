 大小端的存储问题

     [root@luckily day02]# vim 042802.c
     [root@luckily day02]# gcc - g 042802.c
     [root@luckily day02]# gdb a.out
     GNU gdb(GDB) Red Hat Enterprise Linux 7.6.1 - 115.el7
     Copyright(C) 2013 Free Software Foundation, Inc.
     License GPLv3 + : GNU GPL version 3 or later < http ://gnu.org/licenses/gpl.html>
     This is free software : you are free to changeand redistribute it.
     There is NO WARRANTY, to the extent permitted by law.Type "show copying"
     and "show warranty" for details.
     This GDB was configured as "x86_64-redhat-linux-gnu".
     For bug reporting instructions, please see :
 < http ://www.gnu.org/software/gdb/bugs/>...
     Reading symbols from / root / study / day02 / a.out...done.
     (gdb)l
     1	#include <stdio.h>
     2
     3	int main(void) {
     4		int a = 1;
     5		printf("a=%d\n", a);
     6		return 0;
     7
 }
 (gdb)b 6
     Breakpoint 1 at 0x400550: file 042802.c, line 6.
     (gdb)info
     "info" must be followed by the name of an info command.
     List of info subcommands :

 info address -- Describe where symbol SYM is stored
     info all - registers -- List of all registers and their contents
     info args -- Argument variables of current stack frame
     info auto - load -- Print current status of auto - loaded files
     info auto - load - scripts -- Print the list of automatically loaded Python scripts
     info auxv -- Display the inferior's auxiliary vector
     info bookmarks -- Status of user - settable bookmarks
     info breakpoints -- Status of specified breakpoints(all user - settable breakpoints if no argument)
     info checkpoints -- IDs of currently known checkpoints
     info classes -- All Objective - C classes
     info common -- Print out the values contained in a Fortran COMMON block
     info copying -- Conditions for redistributing copies of GDB
     info dcache -- Print information on the dcache performance
     info display -- Expressions to display when program stops
     info extensions -- All filename extensions associated with a source language
     info files -- Names of targetsand files being debugged
     info float --Print the status of the floating point unit
     info frame -- All about selected stack frame
     info frame - filter -- List all registered Python frame - filters
     info functions -- All function names
     info handle -- What debugger does when program gets various signals
     info inferiors -- IDs of specified inferiors(all inferiors if no argument)
     -- - Type <return> to continue, or q <return> to quit-- - quit
     Quit
     (gdb) info b
     Num     Type           Disp Enb Address            What
     1       breakpoint     keep y   0x0000000000400550 in main at 042802.c:6
     (gdb)b 5
     Breakpoint 2 at 0x40053c : file 042802.c, line 5.
     (gdb)r
     Starting program : / root / study / day02 / a.out

     Breakpoint 2, main() at 042802.c : 5
     5		printf("a=%d\n", a);
 Missing separate debuginfos, use: debuginfo - install glibc - 2.17 - 292.el7.x86_64
 (gdb) print a
     $1 = 1
     (gdb)print & a
     $2 = (int*)0x7fffffffdfcc
     (gdb)x / 4bx 0x7fffffffdfcc
     0x7fffffffdfcc:	0x01	0x00	0x00	0x00
     (gdb)x / 1bx 0x7fffffffdfcc
     0x7fffffffdfcc : 0x01
     (gdb)quit
     A debugging session is active.

     Inferior 1[process 3608] will be killed.

     Quit anyway ? (y or n) y
     [root@luckily day02]# readelf - h a.out
     ELF 头：
     Magic：  7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
     类别:                              ELF64
     数据 : 2 补码，小端序(little endian)
     版本 : 1 (current)
     OS / ABI : UNIX - System V
     ABI 版本 : 0
     类型 : EXEC(可执行文件)
     系统架构 : Advanced Micro Devices X86 - 64
     版本 : 0x1
     入口点地址：              0x400440
     程序头起点：              64 (bytes into file)
     Start of section headers : 7152 (bytes into file)
     标志：             0x0
     本头的大小：       64 (字节)
     程序头大小：       56 (字节)
     Number of program headers : 9
     节头大小：         64 (字节)
     节头数量：         35
     字符串表索引节头： 34
