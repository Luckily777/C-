��Ӳ����


[root@luckily ~]# du test.txt
4	test.txt
[root@luckily ~]# du - h test.txt
4.0K	test.txt
[root@luckily ~]# cat test.txt
123
[root@luckily ~]# echo "haskjnsndkjsnfjkdsbfjksdfnjksdf" > test.txt
[root@luckily ~]# ls - l test.txt
- rw - r--r--. 1 root root 32 4��  21 19:31 test.txt
[root@luckily ~]# du - h test.txt
4.0K	test.txt
[root@luckily ~]# ls - i
12583041 anaconda - ks.cfg                             27422054 ��Ƶ
12583334 mysql57 - community - release - el7 - 8.noarch.rpm  25166669 ͼƬ
12583055 passwd                                      20971939 �ĵ�
12583053 test.txt                                    15058350 ����
19064352 ����                                        23940576 ����
17093162 ģ��                                        12583045 ����
[root@luckily ~]# ls
anaconda - ks.cfg                             passwd    ����  ��Ƶ  �ĵ�  ����
mysql57 - community - release - el7 - 8.noarch.rpm  test.txt  ģ��  ͼƬ  ����  ����
[root@luckily ~]# cp test.txt test.txt.bak
[root@luckily ~]# ls - i
12583041 anaconda - ks.cfg                             27422054 ��Ƶ
12583334 mysql57 - community - release - el7 - 8.noarch.rpm  25166669 ͼƬ
12583055 passwd                                      20971939 �ĵ�
12583053 test.txt                                    15058350 ����
12589629 test.txt.bak                                23940576 ����
19064352 ����                                        12583045 ����
17093162 ģ��
[root@luckily ~]# mv test.txt test.txt2
[root@luckily ~]# ls - i
12583041 anaconda - ks.cfg                             27422054 ��Ƶ
12583334 mysql57 - community - release - el7 - 8.noarch.rpm  25166669 ͼƬ
12583055 passwd                                      20971939 �ĵ�
12583053 test.txt2                                   15058350 ����
12589629 test.txt.bak                                23940576 ����
19064352 ����                                        12583045 ����
17093162 ģ��


Ӳ����
[root@luckily ~]# ln test.txt hehe.txt
ln : failed to access "test.txt" : û���Ǹ��ļ���Ŀ¼
[root@luckily ~]# ln mmc.txt test.hehe
ln : failed to access "mmc.txt" : û���Ǹ��ļ���Ŀ¼
[root@luckily ~]# vim mmc.txt
[root@luckily ~]# ln mmc.txt test.heh
[root@luckily ~]# cat mmc.txt
ddsss

[root@luckily ~]# ls - i mmc.txt
12589631 mmc.txt
[root@luckily ~]# ls - i mmctxt test.heh
ls : �޷�����mmctxt: û���Ǹ��ļ���Ŀ¼
12589631 test.heh
[root@luckily ~]# ls - i mmc.txt test.heh
12589631 mmc.txt  12589631 test.heh
[root@luckily ~]# rm mmc.txt
rm���Ƿ�ɾ����ͨ�ļ� "mmc.txt"��y
[root@luckily ~]# ls - i test.heh
12589631 test.heh
[root@luckily ~]# cat test.heh
ddsss

[root@luckily ~]# ln test.heh haha
[root@luckily ~]# ls - li test.heh haha
12589631 - rw - r--r--. 2 root root 7 4��  21 19:53 haha
12589631 - rw - r--r--. 2 root root 7 4��  21 19 : 53 test.heh
[root@luckily ~]# rm haha
rm���Ƿ�ɾ����ͨ�ļ� "haha"��y
[root@luckily ~]# rm test.heh
rm���Ƿ�ɾ����ͨ�ļ� "test.heh"��y
[root@luckily ~]# ls
anaconda - ks.cfg                             test.txt2     ģ��  �ĵ�  ����
mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  ��Ƶ  ����
passwd                                      ����          ͼƬ  ����
[root@luckily ~]# cat test.txt
cat : test.txt : û���Ǹ��ļ���Ŀ¼


������
[root@luckily ~]# cat test.txt2
haskjnsndkjsnfjkdsbfjksdfnjksdf
[root@luckily ~]# ln - s test.txt2 hehe
[root@luckily ~]# ls - il test.txt2 hehe
12583054 lrwxrwxrwx. 1 root root  9 4��  21 19:58 hehe->test.txt2
12583053 - rw - r--r--. 1 root root 32 4��  21 19 : 31 test.txt2
[root@luckily ~]# cat hehe
haskjnsndkjsnfjkdsbfjksdfnjksdf
[root@luckily ~]# readlink hehe
test.txt2
