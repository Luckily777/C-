��Ŀ���� ������

[root@luckily day02]# mkdir progress
[root@luckily day02]# cd progress /
[root@luckily progress]# touch add.h add.c suub.c sub.h main.c parse.c parse.h
[root@luckily progress]# ls
add.c  add.h  main.c  parse.c  parse.h  sub.h  suub.c
[root@luckily progress]# vim add.c
[root@luckily progress]# vim add.h
[root@luckily progress]# cp add.c sub.c
[root@luckily progress]# cp add.h sub.h
cp���Ƿ񸲸�"sub.h"�� y
[root@luckily progress]# ls
add.c  add.h  main.c  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# vim sub.c
[root@luckily progress]# vim sub.c
[root@luckily progress]# vim sub.h
[root@luckily progress]# cat add.c
#include <add.h>

int add(int a, int b) {
	return a + b;
}
[root@luckily progress]# cat add.h
#ifndef __ADD_H__
#define  __ADD_H__

int add(int a, int b);

#endif //__ADD_H__

[root@luckily progress]# cat sub.h
#ifndef __SUB_H__
#define  __SUB_H__

int sub(int a, int b);

#endif //__SUB_H__

[root@luckily progress]# cat sub.c
#include <sub.h>

int sub(int a, int b) {
	return a - b;
}


[root@luckily progress]# ls
add.c  add.h  main.c  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# vim parse.c
[root@luckily progress]# vim parse.h
[root@luckily progress]# ls
add.c  add.h  main.c  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# vim main.c
[root@luckily progress]# gcc main.c
main.c: �ں�����main����:
main.c : 11 : 3 : ���棺��ʽ�������ڽ�������memset��������[Ĭ������]
memset(buf, 0x00, sizeof(buf));
^
main.c:14 : 1 : ����expected declaration or statement at end of input
 }
 ^
     [root@luckily progress]# . / a.out
     bash : . / a.out : û���Ǹ��ļ���Ŀ¼
     [root@luckily progress]# vim main.c
     [root@luckily progress]# gcc main.c
     main.c: �ں�����main����:
 main.c : 14 : 1 : ����expected declaration or statement at end of input
 }
 ^
     [root@luckily progress]# vim main.c
     [root@luckily progress]# gcc main.c
     [root@luckily progress]# . / a.out
     ji suan qi3 + 4
     buf = [3 + 4]
     ji suan qi91 + 77
     buf = [91 + 77]
     ji suan qi ^ C
     [root@luckily progress]# vim main.c
     [root@luckily progress]# ls
     add.c  add.h  a.out  main.c  parse.c  parse.h  sub.c  sub.h  suub.c
     [root@luckily progress]# vim main.c
     [root@luckily progress]# vim parse.h
     [root@luckily progress]# vim parse.c
     [root@luckily progress]# gcc main.c
     / tmp / cccHPxCc.o���ں�����main���У�
     main.c:(.text + 0x80)���ԡ�parse��δ���������
     collect2 : ����ld ���� 1
     [root@luckily progress]# vim parse.c
     [root@luckily progress]# vim parse.h
     [root@luckily progress]# vim main.c
     [root@luckily progress]# vim parse.h
     [root@luckily progress]# vim main.c
     [root@luckily progress]# vim parse.c
     [root@luckily progress]# gcc main.c parse.c
     parse.c: �ں�����parse����:
 parse.c : 4 : 13 : ����expected ��; �� before numeric constant
#define OUT 0
     ^
     parse.c:19 : 9 : ��ע��in expansion of macro ��OUT��
     flag OUT;
 ^
     parse.c:23 : 3 : ���棺��ʽ�������ڽ�������printf��������[Ĭ������]
     printf("argv[%d] = %s\n", i, argv[i]);
 ^
     [root@luckily progress]# vim parse.c
     [root@luckily progress]# 
