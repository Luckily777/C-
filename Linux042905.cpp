һ�����߰���ļ��������� �޹ؽ�Ҫ

[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02
[root@luckily study]# cd day2
bash : cd: day2: û���Ǹ��ļ���Ŀ¼
[root@luckily study]# cd day02
[root@luckily day02]# ls
042801.c  042802.c  042803.c  a.out  progress
[root@luckily day02]# cd progress
[root@luckily progress]# ls
add.c  add.h  main.c  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# vim parse.c
[root@luckily progress]# vim parse.h
[root@luckily progress]# vim main.c
[root@luckily progress]# vim parse.c
[root@luckily progress]# gcc main.c parse.c
parse.c: �ں�����parse����:
parse.c : 13 : 13 : ����expected expression before �� = �� token
if (flag = = OUT && !isspace(buf[i])) {
    ^
        parse.c:17 : 18 : ����expected expression before �� = �� token
else if (flag = = OUT) {
    ^
        parse.c:4 : 13 : ����expected ��; �� before numeric constant
#define OUT 0
        ^
        parse.c:19 : 9 : ��ע��in expansion of macro ��OUT��
        flag OUT;
    ^
        parse.c:23 : 3 : ���棺��ʽ�������ڽ�������printf��������[Ĭ������]
        printf("argv[%d] = %s\n", i, argv[i]);
    ^
        [root@luckily progress]# vim parse.c
        [root@luckily progress]# gcc main.c parse.c
        parse.c: �ں�����parse����:
    parse.c : 4 : 14 : ����expected ��)�� before ��; �� token
#define OUT 0;
    ^
        parse.c:13 : 14 : ��ע��in expansion of macro ��OUT��
        if (flag == OUT && !isspace(buf[i])) {
            ^
                parse.c:4 : 14 : ����expected ��)�� before ��; �� token
#define OUT 0;
                ^
                parse.c:17 : 18 : ��ע��in expansion of macro ��OUT��
        else if (flag == OUT) {
            ^
                parse.c:4 : 13 : ����expected ��; �� before numeric constant
#define OUT 0;
                ^
                parse.c:19 : 9 : ��ע��in expansion of macro ��OUT��
                flag OUT;
            ^
                parse.c:23 : 3 : ���棺��ʽ�������ڽ�������printf��������[Ĭ������]
                printf("argv[%d] = %s\n", i, argv[i]);
            ^
                [root@luckily progress]# vim parse.c
                [root@luckily progress]# gcc main.c parse.c
                [root@luckily progress]# cat parse.c
#include "parse.h"
#include <stdio.h>

#define IN 1
#define OUT 0

                void parse(char* buf) {
                int i;
                int argc = 0;
                char* argv[8] = {};
                int flag = OUT;
                for (i = 0; buf[i] != 0; i++) {
                    //haizaidanciwaim ,bingqie dangqiande weizhibushi kongbaifu
                    if (flag == OUT && !isspace(buf[i])) {
                        argv[argc++] = buf + i;
                        flag = IN;
                    }
                    else if (flag == OUT) {
                        buf[i] = '\0';
                        flag = OUT;
                    }
                }
                for (i = 0; i < argc; i++) {
                    printf("argv[%d] = %s\n", i, argv[i]);
                }
            }
            [root@luckily progress]# . / a.out
                ji suan qi
                please in you data : 123 + 567
                argv[0] = 123 + 567
                ji suan qi
                please in you data : ^ C
                [root@luckily progress]# vim parse.c
                [root@luckily progress]# gcc main.c parse.c
                [root@luckily progress]# . / a.out
                ji suan qi
                please in you data : 123 + 456
                argv[0] = 123
                argv[1] = +
                argv[2] = 456
                ji suan qi
                please in you data : ^ C
                [root@luckily progress]# vim parse.c
                [root@luckily progress]# gcc main.c parse.c
                [root@luckily progress]# . / a.out
                ji suan qi
                please in you data : 123 + 456
                argv[0] = [123]
                argv[1] = [+]
                argv[2] = [456]
                ji suan qi
                please in you data : ^ C
                [root@luckily progress]# vim parse.c
                [root@luckily progress]# gcc main.c parse.c
                parse.c:18 : 1 : ����typedef��expr������ʼ��(���� __typeof__)
        }expr[] = {
        ^
       parse.c:19 : 3 : ���󣺡�add��δ����(���ں�����)
         {
       add,"add",'+'
    },
^
parse.c : 20 : 3 : ���󣺡�sub��δ����(���ں�����)
  {
sub,"sub",'-'
},
^
parse.c : �ں�����main_math���� :
parse.c : 36 : 6 : ����expected expression before ��expr��
   if (expr[i].name == NULL) {
      ^
parse.c:37 : 41 : ����subscripted value is neither array nor pointer nor vector
    printf("%s ciminglingbucunzai1n",argc[0]);
                                         ^
parse.c:40 : 13 : ����expected expression before ��expr��
   if (strcmp(expr[i].name,argv[0]) == 0) {
             ^
parse.c:41 : 12 : ����expected expression before ��expr��
    p_fun = expr[i].pFUn;
            ^
parse.c:42 : 8 : ����expected expression before ��expr��
    op = expr[i].op;
        ^
parse.c:46 : 2 : ���棺���ݡ�do_action���ĵ� 2 ������ʱ����������ָ�룬δ������ת��[Ĭ������]
  do_action(argc,argc);
  ^
parse.c:24 : 6 : ��ע����Ҫ���͡�char * *������ʵ�ε�����Ϊ��int��
 void do_action(int argc,char* argv[]) {
      ^
parse.c: �ں�����parse����:
parse.c : 66 : 21 : ����expected ��)�� before ��; �� token
  main_math(argc,argv;
                     ^
parse.c:67 : 1 : ����expected ��; �� before ��
}�� token
}
^
[root@luckily progress]# vim parse.c
[root@luckily progress]# gcc main.c parse.c add.c sub.c
parse.c: �ں�����main_math����:
parse.c : 39 : 41 : ����subscripted value is neither array nor pointer nor vector
    printf("%s ciminglingbucunzai1n",argc[0]);
                                         ^
parse.c:43 : 19 : ���󣺡�struct expr_t��û����Ϊ��pFUn���ĳ�Ա
    p_fun = expr[i].pFUn;
                   ^
parse.c:48 : 2 : ���棺���ݡ�do_action���ĵ� 2 ������ʱ����������ָ�룬δ������ת��[Ĭ������]
  do_action(argc,argc);
  ^
parse.c:26 : 6 : ��ע����Ҫ���͡�char * *������ʵ�ε�����Ϊ��int��
 void do_action(int argc,char* argv[]) {
      ^
parse.c: �ں�����parse����:
parse.c : 68 : 21 : ����expected ��)�� before ��; �� token
  main_math(argc,argv;
                     ^
parse.c:69 : 1 : ����expected ��; �� before ��
}�� token
}
^
add.c:1 : 17 : ��������add.h��û���Ǹ��ļ���Ŀ¼
 #include <add.h>
                 ^
�����жϡ�
sub.c : 1 : 17 : ��������sub.h��û���Ǹ��ļ���Ŀ¼
 #include <sub.h>
                 ^
�����жϡ�
[root@luckily progress]# ls
add.c  add.h  a.out  main.c  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# vim subb.c
[root@luckily progress]# rm - rf subb.c
[root@luckily progress]# ls
add.c  add.h  a.out  main.c  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# vim parse.c
[root@luckily progress]# gcc main.c parse.c add.c sub.c
add.c:1 : 17 : ��������add.h��û���Ǹ��ļ���Ŀ¼
 #include <add.h>
                 ^
�����жϡ�
sub.c : 1 : 17 : ��������sub.h��û���Ǹ��ļ���Ŀ¼
 #include <sub.h>
                 ^
�����жϡ�
[root@luckily progress]# vim parse.c
[root@luckily progress]# vim sub.h
[root@luckily progress]# vim sub.c
[root@luckily progress]# vim add.c
[root@luckily progress]# vim sub.h
[root@luckily progress]# vim sub.h
[root@luckily progress]# vim sub.c
[root@luckily progress]# gcc main.c parse.c add.c sub.c
/ tmp / ccNFcd5K.o���ں�����do_action���У�
parse.c:(.text + 0x39)���ԡ�atio��δ���������
collect2 : ����ld ���� 1
[root@luckily progress]# vim parse.c
[root@luckily progress]# gcc main.c parse.c add.c sub.c
[root@luckily progress]# . / a.out
ji suan qi
 please in you data : add 10 20
10 + 20 = 30
ji suan qi
 please in you data : sub 90 80
90 - 80 = 10
ji suan qi
 please in you data : ^ C
[root@luckily progress]# viim mul.c
bash : viim: δ�ҵ�����...
[root@luckily progress]# viim mul.c
bash : viim: δ�ҵ�����...
���������ǣ� 'vim'
[root@luckily progress]# vim mul.c
[root@luckily progress]# vim mul.h
[root@luckily progress]# vim parse.c
[root@luckily progress]# gcc main.c parse.c add.c sub.c mul.c
[root@luckily progress]# . / a.out
ji suan qi
please in you data : add 1 2
1 + 2 = 3
ji suan qi
please in you data : mul 5 4
5 * 4 = 20
ji suan qi
please in you data : ^ C
[root@luckily progress]# ls
add.c  add.h  a.out  main.c  mul.c  mul.h  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# 
[root@luckily progress]# ls
add.c  add.h  a.out  main.c  mul.c  mul.h  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# ls
add.c  add.h  a.out  main.c  mul.c  mul.h  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# gcc - c parse.c
[root@luckily progress]# ls
add.c  a.out   mul.c  parse.c  parse.o  sub.h
add.h  main.c  mul.h  parse.h  sub.c    suub.c
[root@luckily progress]# gcc - c add.c
[root@luckily progress]# gcc - d sub.c
gcc : ��������û�������ļ�
�����жϡ�
[root@luckily progress]# gcc - c sub.c
[root@luckily progress]# gcc - c mul.c
[root@luckily progress]# ls
add.c  add.o  main.c  mul.h  parse.c  parse.o  sub.h  suub.c
add.h  a.out  mul.c   mul.o  parse.h  sub.c    sub.o
[root@luckily progress]# gcc main.c - c
[root@luckily progress]# gcc main.o parse.o add.o, ul.o sub.o - o  main
gcc : ����, ul.o��û���Ǹ��ļ���Ŀ¼
[root@luckily progress]# gcc main.o parse.o add.o, mul.o sub.o - o  main
gcc : ����, mul.o��û���Ǹ��ļ���Ŀ¼
[root@luckily progress]# gcc main.o parse.o add.o mul.o sub.o - o main
[root@luckily progress]# ls
add.c  add.o  main    main.o  mul.h  parse.c  parse.o  sub.h  suub.c
add.h  a.out  main.c  mul.c   mul.o  parse.h  sub.c    sub.o
[root@luckily progress]# rm - f suub.c
[root@luckily progress]# ls
add.c  add.o  main    main.o  mul.h  parse.c  parse.o  sub.h
add.h  a.out  main.c  mul.c   mul.o  parse.h  sub.c    sub.o
[root@luckily progress]# rm - f * .o
[root@luckily progress]# ls
add.c  add.h  a.out  main  main.c  mul.c  mul.h  parse.c  parse.h  sub.c  sub.h
