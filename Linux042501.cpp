gcc �������


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
gcc : ����042401.C��û���Ǹ��ļ���Ŀ¼
gcc : ��������û�������ļ�
�����жϡ�
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

042401.o��     �ļ���ʽ elf64 - x86 - 64


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
    ������ 44
    - rw - r--r--. 1 root root   174 4��  24 22:01 042401.c
    - rw - r--r--. 1 root root 16875 4��  24 22 : 01 042401.i
    - rw - r--r--. 1 root root  1504 4��  24 22 : 27 042401.o
    - rw - r--r--. 1 root root   442 4��  24 22 : 11 042401.s
    - rwxr - xr - x. 1 root root  8360 4��  24 22 : 41 a.out
    [root@luckily day01]# rm 042401.i 042401.i 042401.s a.out
    rm���Ƿ�ɾ����ͨ�ļ� "042401.i"��y
    rm : �޷�ɾ��"042401.i" : û���Ǹ��ļ���Ŀ¼
    rm���Ƿ�ɾ����ͨ�ļ� "042401.s"��y
    rm���Ƿ�ɾ����ͨ�ļ� "a.out"��y
    [root@luckily day01]# y
    bash : y: δ�ҵ�����...
    [root@luckily day01]# rm 042401.o
    rm���Ƿ�ɾ����ͨ�ļ� "042401.o"��y
    [root@luckily day01]# ls
    042401.c
    [root@luckily day01]# gcc 042401.c
    [root@luckily day01]# ls
    042401.c  a.out
    [root@luckily day01]# gcc - v 042401.c 
    //��ÿһ������ù���
