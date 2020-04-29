一堆乱七八糟的计算器操作 无关紧要

[root@luckily ~]# cd study
[root@luckily study]# ls
day01  day02
[root@luckily study]# cd day2
bash : cd: day2: 没有那个文件或目录
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
parse.c: 在函数‘parse’中:
parse.c : 13 : 13 : 错误：expected expression before ‘ = ’ token
if (flag = = OUT && !isspace(buf[i])) {
    ^
        parse.c:17 : 18 : 错误：expected expression before ‘ = ’ token
else if (flag = = OUT) {
    ^
        parse.c:4 : 13 : 错误：expected ‘; ’ before numeric constant
#define OUT 0
        ^
        parse.c:19 : 9 : 附注：in expansion of macro ‘OUT’
        flag OUT;
    ^
        parse.c:23 : 3 : 警告：隐式声明与内建函数‘printf’不兼容[默认启用]
        printf("argv[%d] = %s\n", i, argv[i]);
    ^
        [root@luckily progress]# vim parse.c
        [root@luckily progress]# gcc main.c parse.c
        parse.c: 在函数‘parse’中:
    parse.c : 4 : 14 : 错误：expected ‘)’ before ‘; ’ token
#define OUT 0;
    ^
        parse.c:13 : 14 : 附注：in expansion of macro ‘OUT’
        if (flag == OUT && !isspace(buf[i])) {
            ^
                parse.c:4 : 14 : 错误：expected ‘)’ before ‘; ’ token
#define OUT 0;
                ^
                parse.c:17 : 18 : 附注：in expansion of macro ‘OUT’
        else if (flag == OUT) {
            ^
                parse.c:4 : 13 : 错误：expected ‘; ’ before numeric constant
#define OUT 0;
                ^
                parse.c:19 : 9 : 附注：in expansion of macro ‘OUT’
                flag OUT;
            ^
                parse.c:23 : 3 : 警告：隐式声明与内建函数‘printf’不兼容[默认启用]
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
                parse.c:18 : 1 : 错误：typedef‘expr’被初始化(改用 __typeof__)
        }expr[] = {
        ^
       parse.c:19 : 3 : 错误：‘add’未声明(不在函数内)
         {
       add,"add",'+'
    },
^
parse.c : 20 : 3 : 错误：‘sub’未声明(不在函数内)
  {
sub,"sub",'-'
},
^
parse.c : 在函数‘main_math’中 :
parse.c : 36 : 6 : 错误：expected expression before ‘expr’
   if (expr[i].name == NULL) {
      ^
parse.c:37 : 41 : 错误：subscripted value is neither array nor pointer nor vector
    printf("%s ciminglingbucunzai1n",argc[0]);
                                         ^
parse.c:40 : 13 : 错误：expected expression before ‘expr’
   if (strcmp(expr[i].name,argv[0]) == 0) {
             ^
parse.c:41 : 12 : 错误：expected expression before ‘expr’
    p_fun = expr[i].pFUn;
            ^
parse.c:42 : 8 : 错误：expected expression before ‘expr’
    op = expr[i].op;
        ^
parse.c:46 : 2 : 警告：传递‘do_action’的第 2 个参数时将整数赋给指针，未作类型转换[默认启用]
  do_action(argc,argc);
  ^
parse.c:24 : 6 : 附注：需要类型‘char * *’，但实参的类型为‘int’
 void do_action(int argc,char* argv[]) {
      ^
parse.c: 在函数‘parse’中:
parse.c : 66 : 21 : 错误：expected ‘)’ before ‘; ’ token
  main_math(argc,argv;
                     ^
parse.c:67 : 1 : 错误：expected ‘; ’ before ‘
}’ token
}
^
[root@luckily progress]# vim parse.c
[root@luckily progress]# gcc main.c parse.c add.c sub.c
parse.c: 在函数‘main_math’中:
parse.c : 39 : 41 : 错误：subscripted value is neither array nor pointer nor vector
    printf("%s ciminglingbucunzai1n",argc[0]);
                                         ^
parse.c:43 : 19 : 错误：‘struct expr_t’没有名为‘pFUn’的成员
    p_fun = expr[i].pFUn;
                   ^
parse.c:48 : 2 : 警告：传递‘do_action’的第 2 个参数时将整数赋给指针，未作类型转换[默认启用]
  do_action(argc,argc);
  ^
parse.c:26 : 6 : 附注：需要类型‘char * *’，但实参的类型为‘int’
 void do_action(int argc,char* argv[]) {
      ^
parse.c: 在函数‘parse’中:
parse.c : 68 : 21 : 错误：expected ‘)’ before ‘; ’ token
  main_math(argc,argv;
                     ^
parse.c:69 : 1 : 错误：expected ‘; ’ before ‘
}’ token
}
^
add.c:1 : 17 : 致命错误：add.h：没有那个文件或目录
 #include <add.h>
                 ^
编译中断。
sub.c : 1 : 17 : 致命错误：sub.h：没有那个文件或目录
 #include <sub.h>
                 ^
编译中断。
[root@luckily progress]# ls
add.c  add.h  a.out  main.c  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# vim subb.c
[root@luckily progress]# rm - rf subb.c
[root@luckily progress]# ls
add.c  add.h  a.out  main.c  parse.c  parse.h  sub.c  sub.h  suub.c
[root@luckily progress]# vim parse.c
[root@luckily progress]# gcc main.c parse.c add.c sub.c
add.c:1 : 17 : 致命错误：add.h：没有那个文件或目录
 #include <add.h>
                 ^
编译中断。
sub.c : 1 : 17 : 致命错误：sub.h：没有那个文件或目录
 #include <sub.h>
                 ^
编译中断。
[root@luckily progress]# vim parse.c
[root@luckily progress]# vim sub.h
[root@luckily progress]# vim sub.c
[root@luckily progress]# vim add.c
[root@luckily progress]# vim sub.h
[root@luckily progress]# vim sub.h
[root@luckily progress]# vim sub.c
[root@luckily progress]# gcc main.c parse.c add.c sub.c
/ tmp / ccNFcd5K.o：在函数‘do_action’中：
parse.c:(.text + 0x39)：对‘atio’未定义的引用
collect2 : 错误：ld 返回 1
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
bash : viim: 未找到命令...
[root@luckily progress]# viim mul.c
bash : viim: 未找到命令...
相似命令是： 'vim'
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
gcc : 致命错误：没有输入文件
编译中断。
[root@luckily progress]# gcc - c sub.c
[root@luckily progress]# gcc - c mul.c
[root@luckily progress]# ls
add.c  add.o  main.c  mul.h  parse.c  parse.o  sub.h  suub.c
add.h  a.out  mul.c   mul.o  parse.h  sub.c    sub.o
[root@luckily progress]# gcc main.c - c
[root@luckily progress]# gcc main.o parse.o add.o, ul.o sub.o - o  main
gcc : 错误：, ul.o：没有那个文件或目录
[root@luckily progress]# gcc main.o parse.o add.o, mul.o sub.o - o  main
gcc : 错误：, mul.o：没有那个文件或目录
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
