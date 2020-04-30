#�� �� �� һ �� makefile
# $@ Ŀ��
# $^ ���������ļ�
# $ < ��һ�������ļ�
# .PHONY ����д��Ŀ�꣬�����Ƿ������µģ���ǿ��ִ��
	.PHONY : clean main all

	CC = gcc
	SRCS = $(wildcard * .c) #wildcard ���ˣ�ͨ�䣩���� ��ǰĿ¼�µ�����.c�ļ�

# /root/study/day02/progress
	BASEDIR = $(shell pwd)

# /root/study/day02/progress/obj
	OBJDIR = $(BASEDIR) / obj
	$(shell mkdir - p $(OBJDIR))

	OBJS = $(SRCS:.c = .o) #��SRCS��Ӧ��.c����.o

#/root/study/day02/progress/obj/main.o
	OBJS : = $(addprefix $(OBJDIR) / , $(OBJS))

	BIN : = main

	all : $(BIN)

	main : $(OBJS)
	$(CC) - o $@ $ ^
# %ͨ���
	$(OBJDIR) / % .o : % .c
	$(CC) - c $ < -o $@

	clean :
	rm - rf $(OBJS)

	rebuild : clean main