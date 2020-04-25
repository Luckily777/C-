gcc 编译过程


[root@luckily ~]# mkdir study
[root@luckily ~]# cd study /
[root@luckily study]# ls
[root@luckily study]# mkdir day01
[root@luckily study]# cd day01 /
[root@luckily day01]# ls
[root@luckily day01]# pwd
/ root / study / day01
[root@luckily day01]# vim 042401.c
[root@luckily day01]# gcc - E 042401.c
[root@luckily day01]# vim 042401.c
[root@luckily day01]# gcc - E 042401.C - o 042401.i
gcc : 错误：042401.C：没有那个文件或目录
gcc : 致命错误：没有输入文件
编译中断。
[root@luckily day01]# gcc - E 042401.c - o 042401.i
[root@luckily day01]# vim 042401.i
[root@luckily day01]# vim 042401.c
[root@luckily day01]# gcc - E 042401.c - o 042401.i
[root@luckily day01]# vim 042401.i
[root@luckily day01]# gcc - S 042401.i
[root@luckily day01]# ls
042401.c  042401.i  042401.s
[root@luckily day01]# file 042401.s
042401.s: ASCII text
[root@luckily day01]# vim 042401.s
[root@luckily day01]# gcc - c 042401.s
[root@luckily day01]# ls
042401.c  042401.i  042401.o  042401.s
[root@luckily day01]# file 042401.o
042401.o: ELF 64 - bit LSB relocatable, x86 - 64, version 1 (SYSV), not stripped
[root@luckily day01]# file 042401.c
042401.c: C source, ASCII text
[root@luckily day01]# file 042401.i
042401.i: C source, UTF - 8 Unicode text
[root@luckily day01]# file 042401.s
042401.s: ASCII text
[root@luckily day01]#  vim 042401.o
[root@luckily day01]# readelf - a 042401.o
root@luckily day01]# ls
042401.c  042401.i  042401.o  042401.s
[root@luckily day01]# objdump - dS 042401.o

042401.o：     文件格式 elf64 - x86 - 64


Disassembly of section.text:

0000000000000000 < main > :
    0 : 55                   	push % rbp
    1 : 48 89 e5             	mov % rsp, % rbp
    4 : bf 00 00 00 00       	mov    $0x0, % edi
    9 : e8 00 00 00 00       	callq  e <main + 0xe>
    e : 5d                   	pop % rbp
    f : c3                   	retq
    [root@luckily day01]# nm 042401.o
    0000000000000000 T main
    U puts
    [root@luckily day01]# ls
    042401.c  042401.i  042401.o  042401.s
    [root@luckily day01]# gcc 042401.o
    [root@luckily day01]# ls
    042401.c  042401.i  042401.o  042401.s  a.out
    [root@luckily day01]# ls
    042401.c  042401.i  042401.o  042401.s  a.out
    [root@luckily day01]# ls - l
    总用量 44
    - rw - r--r--. 1 root root   174 4月  24 22:01 042401.c
    - rw - r--r--. 1 root root 16875 4月  24 22 : 01 042401.i
    - rw - r--r--. 1 root root  1504 4月  24 22 : 27 042401.o
    - rw - r--r--. 1 root root   442 4月  24 22 : 11 042401.s
    - rwxr - xr - x. 1 root root  8360 4月  24 22 : 41 a.out
    [root@luckily day01]# rm 042401.i 042401.i 042401.s a.out
    rm：是否删除普通文件 "042401.i"？y
    rm : 无法删除"042401.i" : 没有那个文件或目录
    rm：是否删除普通文件 "042401.s"？y
    rm：是否删除普通文件 "a.out"？y
    [root@luckily day01]# y
    bash : y: 未找到命令...
    [root@luckily day01]# rm 042401.o
    rm：是否删除普通文件 "042401.o"？y
    [root@luckily day01]# ls
    042401.c
    [root@luckily day01]# gcc 042401.c
    [root@luckily day01]# ls
    042401.c  a.out
    [root@luckily day01]# gcc - v 042401.c 
    //看每一步编译得过程
