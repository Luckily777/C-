计算器（解析）

//add函数
#include "add.h"

int add(int a, int b) {
	return a + b;
}

//add头文件
#ifndef __ADD_H__
#define  __ADD_H__

int add(int a, int b);

#endif //__ADD_H__

//sub头文件
ine  __SUB_H__

int sub(int a, int b);

#endif //__SUB_H__

//sub函数
#include "sub.h"

int sub(int a, int b) {
	return a - b;
}

//mul头文件
#ifndef __MUL_H__
#define  __MUL_H__

int mul(int a, int b);

#endif //__MUL_H__

//mul函数

#include "mul.h"

int mul(int a, int b) {
	return a * b;
}

//parse头文件
#ifndef __PARSE_H__
#define __PARSE_H__

void parse(char* buf);

#endif //__PARSE_H__


//parse函数
#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include "add.h"
#include "sub.h"
#include "mul.h"

#define IN 1
#define OUT 0

typedef int FUNC(int, int);

FUNC* p_fun = NULL;
char op;


struct expr_t {
	FUNC* pFun;//add(int ,int )
	char* name;//add sub
	char op; //+ - fuhao
};

struct expr_t expr[] = {
	{add,"add",'+'},
	{sub,"sub",'-'},
	{mul,"mul",'*'},
	{NULL,NULL,0}
};

void do_action(int argc, char* argv[]) {
	int left = atoi(argv[1]);
	int right = atoi(argv[2]);

	int ret = p_fun(left, right);
	printf("%s%c%s=%d\n", argv[1], op, argv[2], ret);
}

void main_math(int argc, char* argv[]) {
	int i;
	p_fun = NULL;
	for (i = 0; ; i++) {
		if (expr[i].name == NULL) {
			printf("%s ciminglingbucunzai1n", argv[0]);
			return;
		}
		if (strcmp(expr[i].name, argv[0]) == 0) {
			p_fun = expr[i].pFun;
			op = expr[i].op;
			break;
		}
	}
	do_action(argc, argv);
}

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
		//ruguo zai danci nei ,bingqie dangqian zifu shi kongbaifu ,jiangdangqian zifuqingling ,zhicheng OUT zhuangtai 
		if (flag == IN && isspace(buf[i])) {
			buf[i] = '\0';
			flag = OUT;
		}
	}
	main_math(argc, argv);
}


//main函数
#include <stdio.h>
#include <string.h>

#include "parse.h"

int main(void) {
	char buf[512] = {};

	while (1) {
		printf("ji suan qi\n ");
		printf("please in you data:");
		memset(buf, 0x00, sizeof(buf));
		scanf("%[^\n]%*c", buf);
		//printf("buf=[%s]\n",buf);
		parse(buf);
	}
}

