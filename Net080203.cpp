//Makefile
.PHONY: clean all

TARGET = svr cli
CC = gcc
FLAGS = -g - lpthread

all : $(TARGET)

svr : chat_svr.o
$(CC) - o $@ $ ^ $(FLAGS)

cli : chat_client.o
$(CC) - o $@ $ ^ $(FLAGS)

% .o : % .c
$(CC) - c $ ^ $(FLAGS)

clean :
	rm - rf * .o $(TARGET)
