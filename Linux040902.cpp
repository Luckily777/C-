Linux �鿴 cat more tail head wc -l 

[root@localhost ����]# cat / etc / passwd
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
[root@localhost ����]# more / etc / passwd
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
[root@localhost ����]# head / etc / passwd
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
[root@localhost ����]# wc - l / etc / passwd
33 / etc / passwd
[root@localhost ����]# head / etc / passwd | wc - l
10
[root@localhost ����]# head - n 3 / etc / passwd
root : x:0 : 0 : root : / root : / bin / bash
bin : x:1 : 1 : bin : / bin : / sbin / nologin
daemon : x:2 : 2 : daemon : / sbin : / sbin / nologin
[root@localhost ����]# tail / etc / passwd
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
[root@localhost ����]# tail / etc / passwd | wc - l
10
[root@localhost ����]# touch heh
[root@localhost ����]# ls
heh
[root@localhost ����]# abc > heh
bash : abc: command not found
[root@localhost ����]# ls
heh
[root@localhost ����]# ls - l
������ 0
- rw - r--r--. 1 root root 0 4��  10 17:47 heh
[root@localhost ����]# ls - a
.  ..heh
[root@localhost ����]# ls - la
������ 8
drwxr - xr - x.  2 root root 4096 4��  10 17:47 .
dr - xr - x-- - . 29 root root 4096 4��  10 01 : 22 ..
- rw - r--r--.  1 root root    0 4��  10 17 : 47 heh
[root@localhost ����]# cat heh
[root@localhost ����]# ls
heh
[root@localhost ����]# cat / heh
cat : / heh : û���Ǹ��ļ���Ŀ¼
[root@localhost ����]# cd heh
bash : cd: heh: ����Ŀ¼
[root@localhost ����]# cat heh
[root@localhost ����]# pwd
/ root / ����
[root@localhost ����]# ls
heh
[root@localhost ����]# ls - l heh
ls : �޷����� - : û���Ǹ��ļ���Ŀ¼
ls : �޷�����l: û���Ǹ��ļ���Ŀ¼
heh
[root@localhost ����]# ls - l heh
- rw - r--r--. 1 root root 0 4��  10 17:47 heh
[root@localhost ����]# rm heh
rm���Ƿ�ɾ����ͨ���ļ� "heh"��y
[root@localhost ����]# ls
[root@localhost ����]# mkdir a / b / c
mkdir : �޷�����Ŀ¼"a/b/c" : û���Ǹ��ļ���Ŀ¼
[root@localhost ����]# mkdir - p a / b / c
[root@localhost ����]# ls
a
[root@localhost ����]# cd a
[root@localhost a]# ls
b
[root@localhost a]# pwd
/ root / ���� / a
[root@localhost a]# touch test.h
[root@localhost a]# ls
b  test.h
[root@localhost a]# cd test.h
bash : cd: test.h : ����Ŀ¼
[root@localhost a]# ls
b  test.h
[root@localhost a]# ls - l
������ 4
drwxr - xr - x. 3 root root 4096 4��  10 17:52 b
- rw - r--r--. 1 root root    0 4��  10 17 : 53 test.h
[root@localhost a]# abc > test.h
bash : abc: command not found
[root@localhost a]# 
