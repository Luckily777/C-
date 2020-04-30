#我 的 第 一 个 makefile
# $@ 目标
# $^ 所有依赖文件
# $ < 第一个依赖文件
# .PHONY 后面写的目标，不论是否是最新的，都强制执行
    .PHONY : clean main

    CC = gcc
    SRCS = $(wildcard * .c) #wildcard 过滤（通配）函数 当前目录下的所有.c文件
    OBJS = $(SRCS:.c = .o) #将SRCS对应的.c换乘.o
    main : $(OBJS)
    $(CC) - o $@ $ ^
# %通配符
    % .o : % .c
    $(CC) - c $ < -o $@

    clean :
    rm - rf $(OBJS)
    ~