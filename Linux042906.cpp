makefile

[root@luckily progress]# vim Makefile
[root@luckily progress]# make
gcc - c main.c - o main.o
[root@luckily progress]# ls
add.c  a.out  main.c  Makefile  mul.h    parse.h  sub.h
add.h  main   main.o  mul.c     parse.c  sub.c
[root@luckily progress]# make
make : ��main.o�������µġ�
[root@luckily progress]# ls - l
������ 68
- rw - r--r--. 1 root root   57 4��  29 15:37 add.c
- rw - r--r--. 1 root root   82 4��  28 17 : 46 add.h
- rwxr - xr - x. 1 root root 9144 4��  29 15 : 47 a.out
- rwxr - xr - x. 1 root root 9144 4��  29 15 : 52 main
- rw - r--r--. 1 root root  275 4��  29 14 : 09 main.c
- rw - r--r--. 1 root root 1880 4��  29 16:22 main.o
- rw - r--r--. 1 root root   66 4��  29 16 : 22 Makefile
- rw - r--r--. 1 root root   58 4��  29 15 : 44 mul.c
- rw - r--r--. 1 root root   83 4��  29 15 : 45 mul.h
- rw - r--r--. 1 root root 1342 4��  29 15 : 46 parse.c
- rw - r--r--. 1 root root   86 4��  29 14 : 08 parse.h
- rw - r--r--. 1 root root   57 4��  29 15:38 sub.c
- rw - r--r--. 1 root root   82 4��  29 15 : 37 sub.h
[root@luckily progress]# vim Makefile
[root@luckily progress]# cd
[root@luckily ~]# yum  groupinstall  "fonts"
�Ѽ��ز����fastestmirror, langpacks
û�а�װ����Ϣ�ļ�
Maybe run : yum groups mark convert(see man yum)
Loading mirror speeds from cached hostfile
* base : mirrors.aliyun.com
* extras : mirrors.aliyun.com
* updates : mirrors.aliyun.com
base | 3.6 kB  00 : 00 : 00
extras | 2.9 kB  00 : 00 : 00
mysql - connectors - community | 2.5 kB  00 : 00 : 00
mysql - tools - community | 2.5 kB  00 : 00 : 00
mysql57 - community | 2.5 kB  00 : 00 : 00
updates | 2.9 kB  00 : 00 : 00
���棺���� fonts �������κοɰ�װ�������
Maybe run : yum groups mark install(see man yum)
ָ������û�пɰ�װ�������������
[root@luckily ~]# yum install  ibus - libpinyin
�Ѽ��ز����fastestmirror, langpacks
Loading mirror speeds from cached hostfile
* base: mirrors.aliyun.com
* extras : mirrors.aliyun.com
* updates : mirrors.aliyun.com
����� ibus - libpinyin - 1.6.91 - 4.el7.x86_64 �Ѱ�װ���������°汾
�����κδ���
[root@luckily ~]# clesr
bash : clesr: δ�ҵ�����...
[root@luckily ~]# clear

[root@luckily ~]# cd study /
[root@luckily study]# cd day02
[root@luckily day02]# cd progress /
[root@luckily progress]# ls
add.c  add.h  a.out  main  main.c  main.o  Makefile  mul.c  mul.h  parse.c  parse.h  sub.c  sub.h
[root@luckily progress]# vim Makefile
[root@luckily progress]# rm - f main.o
[root@luckily progress]# ls
add.c  a.out  main.c    mul.c  parse.c  sub.c
add.h  main   Makefile  mul.h  parse.h  sub.h
[root@luckily progress]# make
gcc - c main.c - o main.o
[root@luckily progress]# make parse.o
gcc - c parse.c - o parse.o
[root@luckily progress]# ls
add.c  a.out  main.c  Makefile  mul.h    parse.h  sub.c
add.h  main   main.o  mul.c     parse.c  parse.o  sub.h
[root@luckily progress]# vim Makefile
[root@luckily progress]# ls
add.c  a.out  main.c  Makefile  mul.h    parse.h  sub.c
add.h  main   main.o  mul.c     parse.c  parse.o  sub.h
[root@luckily progress]# rm main.o
rm���Ƿ�ɾ����ͨ�ļ� "main.o"��y
[root@luckily progress]# rm parse.o
rm���Ƿ�ɾ����ͨ�ļ� "parse.o"��y
[root@luckily progress]# ls
add.c  a.out  main.c    mul.c  parse.c  sub.c
add.h  main   Makefile  mul.h  parse.h  sub.h
[root@luckily progress]# make
gcc - c main.c - o main.o
gcc - c add.c - o add.o
gcc - c sub.c - o sub.o
gcc - c mul.c - o mul.o
gcc - c parse.c - o parse.o
gcc - o main main.o add.o sub.o mul.o parse.o
[root@luckily progress]# cat Makefile
#�� �� �� һ �� makefile

main : main.o add.o sub.o mul.o parse.o
gcc - o main main.o add.o sub.o mul.o parse.o
main.o : main.c
gcc - c main.c - o main.o
add.o : add.c
gcc - c add.c - o add.o
sub.o : sub.c
gcc - c sub.c - o sub.o
mul.o : mul.c
gcc - c mul.c - o mul.o
parse.o : parse.c
gcc - c parse.c - o parse.o
[root@luckily progress]# make
make : ��main�������µġ�
[root@luckily progress]# ls
add.c  add.o  main    main.o    mul.c  mul.o    parse.h  sub.c  sub.o
add.h  a.out  main.c  Makefile  mul.h  parse.c  parse.o  sub.h
[root@luckily progress]# ls - l add.c
- rw - r--r--. 1 root root 57 4��  29 15:37 add.c
[root@luckily progress]# touch add.c
[root@luckily progress]# ls - l add.c
- rw - r--r--. 1 root root 57 4��  29 16:55 add.c
[root@luckily progress]# make
gcc - c add.c - o add.o
gcc - o main main.o add.o sub.o mul.o parse.o
[root@luckily progress]# vim Makefile
[root@luckily progress]# rm - f main.o
[root@luckily progress]# rm - f * .o
[root@luckily progress]# make
gcc - c main.c - o main.o
gcc - c add.c - o add.o
gcc - c sub.c - o sub.o
gcc - c mul.c - o mul.o
gcc - c parse.c - o parse.o
gcc - o main main.o add.o sub.o mul.o parse.o
[root@luckily progress]# cp Makefile  makefile
[root@luckily progress]# vim makefile
[root@luckily progress]# vim Makefilr
[root@luckily progress]# ls
add.c  add.o  main    main.o    Makefile  mul.c  mul.o    parse.h  sub.c  sub.o
add.h  a.out  main.c  makefile  Makefilr  mul.h  parse.c  parse.o  sub.h
[root@luckily progress]# rm Makefilr
rm���Ƿ�ɾ����ͨ���ļ� "Makefilr"��y
[root@luckily progress]# vim Makefile
[root@luckily progress]# rm - f * .o
[root@luckily progress]# make
gcc - c main.c - o main.o
gcc - c add.c - o add.o
gcc - c sub.c - o sub.o
gcc - c mul.c - o mul.o
gcc - c parse.c - o parse.o
gcc - o main main.o add.o sub.o mul.o parse.o
[root@luckily progress]# vim Makefile
[root@luckily progress]# make clear
make : ***û�й�����Դ���Ŀ�ꡰclear���� ֹͣ��
[root@luckily progress]# make clean
make : ***û�й�����Դ���Ŀ�ꡰclean���� ֹͣ��
[root@luckily progress]# vim Makefile
[root@luckily progress]# make clean
make : ***û�й�����Դ���Ŀ�ꡰclean���� ֹͣ��
[root@luckily progress]# vim Makefile
[root@luckily progress]# ls
add.c  add.o  main    main.o    Makefile  mul.h  parse.c  parse.o  sub.h
add.h  a.out  main.c  makefile  mul.c     mul.o  parse.h  sub.c    sub.o
[root@luckily progress]# make clean
make : ***û�й�����Դ���Ŀ�ꡰclean���� ֹͣ��
[root@luckily progress]# vim Makefile
[root@luckily progress]# make clean
make : ***û�й�����Դ���Ŀ�ꡰclean���� ֹͣ��
[root@luckily progress]# rm makefile
rm���Ƿ�ɾ����ͨ�ļ� "makefile"��y
[root@luckily progress]# make clean
rm - rf * .o
[root@luckily progress]# ls
add.c  a.out  main.c    mul.c  parse.c  sub.c
add.h  main   Makefile  mul.h  parse.h  sub.h
[root@luckily progress]# vim Makefile
[root@luckily progress]# vim Makefile
[root@luckily progress]# make clean
rm - rf main.o add.o sub.o mul.o parse.o
[root@luckily progress]# vim Makefile
