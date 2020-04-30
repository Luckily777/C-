#我 的 第 一 个 makefile
# $@ 目标
# $^ 所有依赖文件
# $ < 第一个依赖文件
# .PHONY 后面写的目标，不论是否是最新的，都强制执行
	.PHONY : clean main all

	CC = gcc
	SRCS = $(wildcard * .c) #wildcard 过滤（通配）函数 当前目录下的所有.c文件

# /root/study/day02/progress
	BASEDIR = $(shell pwd)

# /root/study/day02/progress/obj
	OBJDIR = $(BASEDIR) / obj
	$(shell mkdir - p $(OBJDIR))

	OBJS = $(SRCS:.c = .o) #将SRCS对应的.c换乘.o

#/root/study/day02/progress/obj/main.o
	OBJS : = $(addprefix $(OBJDIR) / , $(OBJS))

	BIN : = main

	all : $(BIN)

	main : $(OBJS)
	$(CC) - o $@ $ ^
# %通配符
	$(OBJDIR) / % .o : % .c
	$(CC) - c $ < -o $@

	clean :
	rm - rf $(OBJS)

	rebuild : clean main