#include <stdio.h>
#include <stdlib.h>


ʱ��� 
	: data: δ�ҵ�����...
	[root@luckily ~]# date
	2020�� 04�� 22�� ������ 18:41 : 50 CST
	[root@luckily ~]# data + % s
	bash : data: δ�ҵ�����...
	[root@luckily ~]# date + % s
	1587552124
	[root@luckily ~]# touch `date + % s`.log
	[root@luckily ~]# ls
	1587552516.log   mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  ��Ƶ  ����
	anaconda - ks.cfg  passwd                                      ����          ͼƬ  ����
	hehe             test.txt2                                   ģ��          �ĵ�  ����
	[root@luckily ~]# data - d@1587552516
	bash: data: δ�ҵ�����...
	[root@luckily ~]# date - d@1587552516
	2020�� 04�� 22�� ������ 18:48 : 36 CST
	[root@luckily ~]# 
	[root@luckily ~]# cal
	���� 2020
	�� һ �� �� �� �� ��
	1  2  3  4
	5  6  7  8  9 10 11
	12 13 14 15 16 17 18
	19 20 21 22 23 24 25
	26 27 28 29 30

	[root@luckily ~]# cal 2020
	2020

	һ��                   ����                   ����
	�� һ �� �� �� �� ��   �� һ �� �� �� �� ��   �� һ �� �� �� �� ��
	1  2  3  4                      1    1  2  3  4  5  6  7
	5  6  7  8  9 10 11    2  3  4  5  6  7  8    8  9 10 11 12 13 14
	12 13 14 15 16 17 18    9 10 11 12 13 14 15   15 16 17 18 19 20 21
	19 20 21 22 23 24 25   16 17 18 19 20 21 22   22 23 24 25 26 27 28
	26 27 28 29 30 31      23 24 25 26 27 28 29   29 30 31

	����                   ����                   ����
	�� һ �� �� �� �� ��   �� һ �� �� �� �� ��   �� һ �� �� �� �� ��
	1  2  3  4                   1  2       1  2  3  4  5  6
	5  6  7  8  9 10 11    3  4  5  6  7  8  9    7  8  9 10 11 12 13
	12 13 14 15 16 17 18   10 11 12 13 14 15 16   14 15 16 17 18 19 20
	19 20 21 22 23 24 25   17 18 19 20 21 22 23   21 22 23 24 25 26 27
	26 27 28 29 30         24 25 26 27 28 29 30   28 29 30
	31
	����                   ����                   ����
	�� һ �� �� �� �� ��   �� һ �� �� �� �� ��   �� һ �� �� �� �� ��
	1  2  3  4                      1          1  2  3  4  5
	5  6  7  8  9 10 11    2  3  4  5  6  7  8    6  7  8  9 10 11 12
	12 13 14 15 16 17 18    9 10 11 12 13 14 15   13 14 15 16 17 18 19
	19 20 21 22 23 24 25   16 17 18 19 20 21 22   20 21 22 23 24 25 26
	26 27 28 29 30 31      23 24 25 26 27 28 29   27 28 29 30
	30 31
	ʮ��                  ʮһ��                 ʮ����
	�� һ �� �� �� �� ��   �� һ �� �� �� �� ��   �� һ �� �� �� �� ��
	1  2  3    1  2  3  4  5  6  7          1  2  3  4  5
	4  5  6  7  8  9 10    8  9 10 11 12 13 14    6  7  8  9 10 11 12
	11 12 13 14 15 16 17   15 16 17 18 19 20 21   13 14 15 16 17 18 19
	18 19 20 21 22 23 24   22 23 24 25 26 27 28   20 21 22 23 24 25 26
	25 26 27 28 29 30 31   29 30                  27 28 29 30 31

	[root@luckily ~]# cal - 3
	���� 2020             ���� 2020             ���� 2020
	�� һ �� �� �� �� ��  �� һ �� �� �� �� ��  �� һ �� �� �� �� ��
	1  2  3  4  5  6  7            1  2  3  4                  1  2
	8  9 10 11 12 13 14   5  6  7  8  9 10 11   3  4  5  6  7  8  9
	15 16 17 18 19 20 21  12 13 14 15 16 17 18  10 11 12 13 14 15 16
	22 23 24 25 26 27 28  19 20 21 22 23 24 25  17 18 19 20 21 22 23
	29 30 31              26 27 28 29 30        24 25 26 27 28 29 30
	31


find
	[root@luckily ~]# find / usr / include / -name "*.h" | grep "fork"
	[root@luckily ~]# find / usr / include / -name "*.h"
	/ usr / include / python2.7 / pyconfig - 64.h



��� ��ѹ
	[root@luckily ~]# mkdir program
	[root@luckily ~]# cd program /
	[root@luckily program]# vim test.c
	[root@luckily program]# ls
	test.c
	[root@luckily program]# tar - czvf test.tar.gz test.c
	test.c
	[root@luckily program]# ls
	test.c  test.tar.gz
	[root@luckily program]# rm test.c - rf
	[root@luckily program]# ls
	test.tar.gz
	[root@luckily program]# tar - xzvf test.tar.gz
	test.c
	[root@luckily program]# ls
	test.c  test.tar.gz
	[root@luckily program]# rm test.c - rf
	[root@luckily program]# ls
	test.tar.gz
	[root@luckily program]# cd
	[root@luckily ~]# cd program /























int main() {
	char str[] = "ABCD", * p = str;
	printf("%d\n", *(p + 4));
	system("pause");
	return 0;
}