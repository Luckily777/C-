#�� �� �� һ �� makefile
# $@ Ŀ��
# $^ ���������ļ�
# $ < ��һ�������ļ�
# .PHONY ����д��Ŀ�꣬�����Ƿ������µģ���ǿ��ִ��
    .PHONY : clean main

    CC = gcc
    SRCS = $(wildcard * .c) #wildcard ���ˣ�ͨ�䣩���� ��ǰĿ¼�µ�����.c�ļ�
    OBJS = $(SRCS:.c = .o) #��SRCS��Ӧ��.c����.o
    main : $(OBJS)
    $(CC) - o $@ $ ^
# %ͨ���
    % .o : % .c
    $(CC) - c $ < -o $@

    clean :
    rm - rf $(OBJS)
    ~