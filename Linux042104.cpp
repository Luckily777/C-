软硬链接


[root@luckily ~]# du test.txt
4	test.txt
[root@luckily ~]# du - h test.txt
4.0K	test.txt
[root@luckily ~]# cat test.txt
123
[root@luckily ~]# echo "haskjnsndkjsnfjkdsbfjksdfnjksdf" > test.txt
[root@luckily ~]# ls - l test.txt
- rw - r--r--. 1 root root 32 4月  21 19:31 test.txt
[root@luckily ~]# du - h test.txt
4.0K	test.txt
[root@luckily ~]# ls - i
12583041 anaconda - ks.cfg                             27422054 视频
12583334 mysql57 - community - release - el7 - 8.noarch.rpm  25166669 图片
12583055 passwd                                      20971939 文档
12583053 test.txt                                    15058350 下载
19064352 公共                                        23940576 音乐
17093162 模板                                        12583045 桌面
[root@luckily ~]# ls
anaconda - ks.cfg                             passwd    公共  视频  文档  音乐
mysql57 - community - release - el7 - 8.noarch.rpm  test.txt  模板  图片  下载  桌面
[root@luckily ~]# cp test.txt test.txt.bak
[root@luckily ~]# ls - i
12583041 anaconda - ks.cfg                             27422054 视频
12583334 mysql57 - community - release - el7 - 8.noarch.rpm  25166669 图片
12583055 passwd                                      20971939 文档
12583053 test.txt                                    15058350 下载
12589629 test.txt.bak                                23940576 音乐
19064352 公共                                        12583045 桌面
17093162 模板
[root@luckily ~]# mv test.txt test.txt2
[root@luckily ~]# ls - i
12583041 anaconda - ks.cfg                             27422054 视频
12583334 mysql57 - community - release - el7 - 8.noarch.rpm  25166669 图片
12583055 passwd                                      20971939 文档
12583053 test.txt2                                   15058350 下载
12589629 test.txt.bak                                23940576 音乐
19064352 公共                                        12583045 桌面
17093162 模板


硬链接
[root@luckily ~]# ln test.txt hehe.txt
ln : failed to access "test.txt" : 没有那个文件或目录
[root@luckily ~]# ln mmc.txt test.hehe
ln : failed to access "mmc.txt" : 没有那个文件或目录
[root@luckily ~]# vim mmc.txt
[root@luckily ~]# ln mmc.txt test.heh
[root@luckily ~]# cat mmc.txt
ddsss

[root@luckily ~]# ls - i mmc.txt
12589631 mmc.txt
[root@luckily ~]# ls - i mmctxt test.heh
ls : 无法访问mmctxt: 没有那个文件或目录
12589631 test.heh
[root@luckily ~]# ls - i mmc.txt test.heh
12589631 mmc.txt  12589631 test.heh
[root@luckily ~]# rm mmc.txt
rm：是否删除普通文件 "mmc.txt"？y
[root@luckily ~]# ls - i test.heh
12589631 test.heh
[root@luckily ~]# cat test.heh
ddsss

[root@luckily ~]# ln test.heh haha
[root@luckily ~]# ls - li test.heh haha
12589631 - rw - r--r--. 2 root root 7 4月  21 19:53 haha
12589631 - rw - r--r--. 2 root root 7 4月  21 19 : 53 test.heh
[root@luckily ~]# rm haha
rm：是否删除普通文件 "haha"？y
[root@luckily ~]# rm test.heh
rm：是否删除普通文件 "test.heh"？y
[root@luckily ~]# ls
anaconda - ks.cfg                             test.txt2     模板  文档  桌面
mysql57 - community - release - el7 - 8.noarch.rpm  test.txt.bak  视频  下载
passwd                                      公共          图片  音乐
[root@luckily ~]# cat test.txt
cat : test.txt : 没有那个文件或目录


软连接
[root@luckily ~]# cat test.txt2
haskjnsndkjsnfjkdsbfjksdfnjksdf
[root@luckily ~]# ln - s test.txt2 hehe
[root@luckily ~]# ls - il test.txt2 hehe
12583054 lrwxrwxrwx. 1 root root  9 4月  21 19:58 hehe->test.txt2
12583053 - rw - r--r--. 1 root root 32 4月  21 19 : 31 test.txt2
[root@luckily ~]# cat hehe
haskjnsndkjsnfjkdsbfjksdfnjksdf
[root@luckily ~]# readlink hehe
test.txt2
