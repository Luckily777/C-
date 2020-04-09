Linux 查看 cat more tail head wc -l 

[root@localhost 桌面]# cat / etc / passwd
root : x:0 : 0 : root : / root : / bin / bash
bin : x:1 : 1 : bin : / bin : / sbin / nologin
daemon : x:2 : 2 : daemon : / sbin : / sbin / nologin
adm : x:3 : 4 : adm : / var / adm : / sbin / nologin
lp : x:4 : 7 : lp : / var / spool / lpd : / sbin / nologin
sync : x:5 : 0 : sync : / sbin : / bin / sync
shutdown : x:6 : 0 : shutdown : / sbin : / sbin / shutdown
halt : x:7 : 0 : halt : / sbin : / sbin / halt
mail : x:8 : 12 : mail : / var / spool / mail : / sbin / nologin
uucp : x:10 : 14 : uucp : / var / spool / uucp : / sbin / nologin
operator : x : 11 : 0 : operator : / root : / sbin / nologin
games : x:12 : 100 : games : / usr / games : / sbin / nologin
gopher : x:13 : 30 : gopher : / var / gopher : / sbin / nologin
ftp : x:14 : 50 : FTP User : / var / ftp : / sbin / nologin
nobody : x:99 : 99 : Nobody : / : / sbin / nologin
dbus : x:81 : 81 : System message bus : / : / sbin / nologin
usbmuxd : x:113 : 113 : usbmuxd user : / : / sbin / nologin
rpc : x:32 : 32 : Rpcbind Daemon : / var / cache / rpcbind : / sbin / nologin
rtkit : x:499 : 499 : RealtimeKit : / proc : / sbin / nologin
avahi - autoipd : x : 170 : 170 : Avahi IPv4LL Stack : / var / lib / avahi - autoipd : / sbin / nologin
vcsa : x:69 : 69 : virtual console memory owner : / dev : / sbin / nologin
abrt : x:173 : 173:: / etc / abrt : / sbin / nologin
rpcuser : x:29 : 29 : RPC Service User : / var / lib / nfs : / sbin / nologin
nfsnobody : x:65534 : 65534 : Anonymous NFS User : / var / lib / nfs : / sbin / nologin
haldaemon : x:68 : 68 : HAL daemon : / : / sbin / nologin
ntp : x:38 : 38:: / etc / ntp : / sbin / nologin
apache : x:48 : 48 : Apache : / var / www : / sbin / nologin
saslauth : x:498 : 76 : Saslauthd user : / var / empty / saslauth : / sbin / nologin
postfix : x:89 : 89:: / var / spool / postfix : / sbin / nologin
gdm : x:42 : 42:: / var / lib / gdm : / sbin / nologin
pulse : x:497 : 496 : PulseAudio System Daemon : / var / run / pulse : / sbin / nologin
sshd : x:74 : 74 : Privilege - separated SSH : / var / empty / sshd : / sbin / nologin
tcpdump : x:72 : 72:: / : / sbin / nologin
[root@localhost 桌面]# more / etc / passwd
root : x:0 : 0 : root : / root : / bin / bash
bin : x:1 : 1 : bin : / bin : / sbin / nologin
daemon : x:2 : 2 : daemon : / sbin : / sbin / nologin
adm : x:3 : 4 : adm : / var / adm : / sbin / nologin
lp : x:4 : 7 : lp : / var / spool / lpd : / sbin / nologin
sync : x:5 : 0 : sync : / sbin : / bin / sync
shutdown : x:6 : 0 : shutdown : / sbin : / sbin / shutdown
halt : x:7 : 0 : halt : / sbin : / sbin / halt
mail : x:8 : 12 : mail : / var / spool / mail : / sbin / nologin
uucp : x:10 : 14 : uucp : / var / spool / uucp : / sbin / nologin
operator : x : 11 : 0 : operator : / root : / sbin / nologin
games : x:12 : 100 : games : / usr / games : / sbin / nologin
gopher : x:13 : 30 : gopher : / var / gopher : / sbin / nologin
ftp : x:14 : 50 : FTP User : / var / ftp : / sbin / nologin
nobody : x:99 : 99 : Nobody : / : / sbin / nologin
dbus : x:81 : 81 : System message bus : / : / sbin / nologin
usbmuxd : x:113 : 113 : usbmuxd user : / : / sbin / nologin
rpc : x:32 : 32 : Rpcbind Daemon : / var / cache / rpcbind : / sbin / nologin
rtkit : x:499 : 499 : RealtimeKit : / proc : / sbin / nologin
avahi - autoipd : x : 170 : 170 : Avahi IPv4LL Stack : / var / lib / avahi - autoipd : / sbin / nolog
in
vcsa : x:69 : 69 : virtual console memory owner : / dev : / sbin / nologin
abrt : x:173 : 173:: / etc / abrt : / sbin / nologin
rpcuser : x:29 : 29 : RPC Service User : / var / lib / nfs : / sbin / nologin
nfsnobody : x:65534 : 65534 : Anonymous NFS User : / var / lib / nfs : / sbin / nologin
haldaemon : x:68 : 68 : HAL daemon : / : / sbin / nologin
ntp : x:38 : 38:: / etc / ntp : / sbin / nologin
apache : x:48 : 48 : Apache : / var / www : / sbin / nologin
saslauth : x:498 : 76 : Saslauthd user : / var / empty / saslauth : / sbin / nologin
postfix : x:89 : 89:: / var / spool / postfix : / sbin / nologin
gdm : x:42 : 42:: / var / lib / gdm : / sbin / nologin
pulse : x:497 : 496 : PulseAudio System Daemon : / var / run / pulse : / sbin / nologin
sshd : x:74 : 74 : Privilege - separated SSH : / var / empty / sshd : / sbin / nologin
tcpdump : x:72 : 72:: / : / sbin / nologin
[root@localhost 桌面]# head / etc / passwd
root : x:0 : 0 : root : / root : / bin / bash
bin : x:1 : 1 : bin : / bin : / sbin / nologin
daemon : x:2 : 2 : daemon : / sbin : / sbin / nologin
adm : x:3 : 4 : adm : / var / adm : / sbin / nologin
lp : x:4 : 7 : lp : / var / spool / lpd : / sbin / nologin
sync : x:5 : 0 : sync : / sbin : / bin / sync
shutdown : x:6 : 0 : shutdown : / sbin : / sbin / shutdown
halt : x:7 : 0 : halt : / sbin : / sbin / halt
mail : x:8 : 12 : mail : / var / spool / mail : / sbin / nologin
uucp : x:10 : 14 : uucp : / var / spool / uucp : / sbin / nologin
[root@localhost 桌面]# wc - l / etc / passwd
33 / etc / passwd
[root@localhost 桌面]# head / etc / passwd | wc - l
10
[root@localhost 桌面]# head - n 3 / etc / passwd
root : x:0 : 0 : root : / root : / bin / bash
bin : x:1 : 1 : bin : / bin : / sbin / nologin
daemon : x:2 : 2 : daemon : / sbin : / sbin / nologin
[root@localhost 桌面]# tail / etc / passwd
nfsnobody : x:65534 : 65534 : Anonymous NFS User : / var / lib / nfs : / sbin / nologin
haldaemon : x:68 : 68 : HAL daemon : / : / sbin / nologin
ntp : x:38 : 38:: / etc / ntp : / sbin / nologin
apache : x:48 : 48 : Apache : / var / www : / sbin / nologin
saslauth : x:498 : 76 : Saslauthd user : / var / empty / saslauth : / sbin / nologin
postfix : x:89 : 89:: / var / spool / postfix : / sbin / nologin
gdm : x:42 : 42:: / var / lib / gdm : / sbin / nologin
pulse : x:497 : 496 : PulseAudio System Daemon : / var / run / pulse : / sbin / nologin
sshd : x:74 : 74 : Privilege - separated SSH : / var / empty / sshd : / sbin / nologin
tcpdump : x:72 : 72:: / : / sbin / nologin
[root@localhost 桌面]# tail / etc / passwd | wc - l
10
[root@localhost 桌面]# touch heh
[root@localhost 桌面]# ls
heh
[root@localhost 桌面]# abc > heh
bash : abc: command not found
[root@localhost 桌面]# ls
heh
[root@localhost 桌面]# ls - l
总用量 0
- rw - r--r--. 1 root root 0 4月  10 17:47 heh
[root@localhost 桌面]# ls - a
.  ..heh
[root@localhost 桌面]# ls - la
总用量 8
drwxr - xr - x.  2 root root 4096 4月  10 17:47 .
dr - xr - x-- - . 29 root root 4096 4月  10 01 : 22 ..
- rw - r--r--.  1 root root    0 4月  10 17 : 47 heh
[root@localhost 桌面]# cat heh
[root@localhost 桌面]# ls
heh
[root@localhost 桌面]# cat / heh
cat : / heh : 没有那个文件或目录
[root@localhost 桌面]# cd heh
bash : cd: heh: 不是目录
[root@localhost 桌面]# cat heh
[root@localhost 桌面]# pwd
/ root / 桌面
[root@localhost 桌面]# ls
heh
[root@localhost 桌面]# ls - l heh
ls : 无法访问 - : 没有那个文件或目录
ls : 无法访问l: 没有那个文件或目录
heh
[root@localhost 桌面]# ls - l heh
- rw - r--r--. 1 root root 0 4月  10 17:47 heh
[root@localhost 桌面]# rm heh
rm：是否删除普通空文件 "heh"？y
[root@localhost 桌面]# ls
[root@localhost 桌面]# mkdir a / b / c
mkdir : 无法创建目录"a/b/c" : 没有那个文件或目录
[root@localhost 桌面]# mkdir - p a / b / c
[root@localhost 桌面]# ls
a
[root@localhost 桌面]# cd a
[root@localhost a]# ls
b
[root@localhost a]# pwd
/ root / 桌面 / a
[root@localhost a]# touch test.h
[root@localhost a]# ls
b  test.h
[root@localhost a]# cd test.h
bash : cd: test.h : 不是目录
[root@localhost a]# ls
b  test.h
[root@localhost a]# ls - l
总用量 4
drwxr - xr - x. 3 root root 4096 4月  10 17:52 b
- rw - r--r--. 1 root root    0 4月  10 17 : 53 test.h
[root@localhost a]# abc > test.h
bash : abc: command not found
[root@localhost a]# 
