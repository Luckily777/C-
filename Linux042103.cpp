进程

[root@luckily ~]# ps
PID TTY          TIME CMD
2968 pts / 0    00:00 : 00 bash
4142 pts / 0    00 : 00 : 00 ps

[root@luckily ~]# ps
PID TTY          TIME CMD
2983 pts / 0    00:00 : 00 bash
3490 pts / 0    00 : 00 : 00 ps
[root@luckily ~]# tty
/ dev / pts / 0
[root@luckily ~]# ps - e
root@luckily ~]# ps - e | wc - l
242

[root@luckily ~]# ps - e | head
PID TTY          TIME CMD
1 ? 00 : 00 : 02 systemd
2 ? 00 : 00 : 00 kthreadd
4 ? 00 : 00 : 00 kworker / 0 : 0H
6 ? 00 : 00 : 00 ksoftirqd / 0
7 ? 00 : 00 : 00 migration / 0
8 ? 00 : 00 : 00 rcu_bh
9 ? 00 : 00 : 01 rcu_sched
10 ? 00 : 00 : 00 lru - add - drain
11 ? 00 : 00 : 00 watchdog / 0
[root@luckily ~]# ps - ef | head
UID         PID   PPID  C STIME TTY          TIME CMD
root          1      0  0 15:52 ? 00 : 00 : 02 / usr / lib / systemd / systemd --switched - root --system --deserialize 22
root          2      0  0 15 : 52 ? 00 : 00 : 00[kthreadd]
root          4      2  0 15 : 52 ? 00 : 00 : 00[kworker / 0:0H]
root          6      2  0 15 : 52 ? 00 : 00 : 00[ksoftirqd / 0]
root          7      2  0 15 : 52 ? 00 : 00 : 00[migration / 0]
root          8      2  0 15 : 52 ? 00 : 00 : 00[rcu_bh]
root          9      2  0 15 : 52 ? 00 : 00 : 01[rcu_sched]
root         10      2  0 15 : 52 ? 00 : 00 : 00[lru - add - drain]
root         11      2  0 15 : 52 ? 00 : 00 : 00[watchdog / 0]
[root@luckily ~]# 

[root@luckily ~]# ps aux | head
USER        PID % CPU % MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root          1  0.1  0.3 193772  6968 ? Ss   15 : 52   0 : 02 / usr / lib / systemd / systemd --switched - root --system --deserialize 22
root          2  0.0  0.0      0     0 ? S    15 : 52   0 : 00[kthreadd]
root          4  0.0  0.0      0     0 ? S < 15 : 52   0 : 00[kworker / 0:0H]
	root          6  0.0  0.0      0     0 ? S    15 : 52   0 : 00[ksoftirqd / 0]
	root          7  0.0  0.0      0     0 ? S    15 : 52   0 : 00[migration / 0]
	root          8  0.0  0.0      0     0 ? S    15 : 52   0 : 00[rcu_bh]
	root          9  0.0  0.0      0     0 ? S    15 : 52   0 : 01[rcu_sched]
	root         10  0.0  0.0      0     0 ? S < 15 : 52   0 : 00[lru - add - drain]
	root         11  0.0  0.0      0     0 ? S    15 : 52   0 : 00[watchdog / 0]


	进程树
    [root@luckily ~]# pstree
    systemd─┬─ModemManager───2* [{ModemManager}]
    ├─NetworkManager───2* [{NetworkManager}]
    ├─VGAuthService
    ├─2* [abrt - watch - log]
    ├─abrtd
    ├─accounts - daemon───2 * [{accounts - daemon}]
    ├─alsactl
    ├─at - spi - bus - laun─┬─dbus - daemon───{ dbus - daemon }
    │                 └─3 * [{at - spi - bus - laun}]
    ├─at - spi2 - registr───2 * [{at - spi2 - registr}]
    ├─atd
    ├─auditd─┬─audispd─┬─sedispatch
    │        │         └─{ audispd }
    │        └─{ auditd }
    ├─avahi - daemon───avahi - daemon
    ├─boltd───2 * [{boltd}]
    ├─colord───2* [{colord}]
    ├─crond
    ├─cupsd
    ├─2* [dbus - daemon───{ dbus - daemon }]
    ├─dbus - launch
    ├─dconf - service───2 * [{dconf - service}]
    ├─dmeventd───2* [{dmeventd}]
    ├─dnsmasq───dnsmasq
    ├─evolution - addre─┬─evolution - addre───5 * [{evolution - addre}]
    │                 └─4* [{evolution - addre}]
    ├─evolution - calen─┬─evolution - calen───8 * [{evolution - calen}]
    │                 └─4* [{evolution - calen}]
    ├─evolution - sourc───3 * [{evolution - sourc}]
    ├─firewalld───{ firewalld }
    ├─fwupd───4* [{fwupd}]
    ├─gdm─┬─X───5* [{X}]
    │     ├─gdm - session - wor─┬─gnome - session - b─┬─abrt - applet───2 * [{abrt - +
    │     │                 │                 ├─gnome - shell─┬─ibus - daem +
    │     │                 │                 │             └─20 * [{gnom +
    │     │                 │                 ├─gnome - software───3 * [{gn +
    │     │                 │                 ├─gsd - a11y - settin───3 * [{g +
    │     │                 │                 ├─gsd - account───3 * [{gsd - a +
    │     │                 │                 ├─gsd - clipboard───2 * [{gsd +
    │     │                 │                 ├─gsd - color───3 * [{gsd - col +
    │     │                 │                 ├─gsd - datetime───3 * [{gsd - +
    │     │                 │                 ├─gsd - disk - utilit───2 * [{g +
    │     │                 │                 ├─gsd - housekeepin───3 * [{g +
    │     │                 │                 ├─gsd - keyboard───3 * [{gsd - +
    │     │                 │                 ├─gsd - media - keys───3 * [{gs +
    │     │                 │                 ├─gsd - mouse───3 * [{gsd - mou +
    │     │                 │                 ├─gsd - power───3 * [{gsd - pow +
    │     │                 │                 ├─gsd - print - notif───2 * [{g +
    │     │                 │                 ├─gsd - rfkill───2 * [{gsd - rf +
    │     │                 │                 ├─gsd - screensaver───2 * [{g +
    │     │                 │                 ├─gsd - sharing───3 * [{gsd - s +
    │     │                 │                 ├─gsd - smartcard───4 * [{gsd +
    │     │                 │                 ├─gsd - sound───3 * [{gsd - sou +
    │     │                 │                 ├─gsd - wacom───2 * [{gsd - wac +
    │     │                 │                 ├─gsd - xsettings───3 * [{gsd +
    │     │                 │                 ├─nautilus - deskto───3 * [{n +
    │     │                 │                 ├─ssh - agent
    │     │                 │                 ├─tracker - extract───13 * [{+
    │     │                 │                 ├─tracker - miner - a───3 * [{t +
    │     │                 │                 ├─tracker - miner - f───3 * [{t +
    │     │                 │                 ├─tracker - miner - u───3 * [{t +
    │     │                 │                 └─3 * [{gnome - session - b}]
    │     │                 └─2* [{gdm - session - wor}]
    │     └─3* [{gdm}]
    ├─gnome - keyring - d───3 * [{gnome - keyring - d}]
    ├─gnome - shell - cal───5 * [{gnome - shell - cal}]
    ├─gnome - terminal - ─┬─bash───pstree
    │                 ├─gnome - pty - helpe
    │                 └─3 * [{gnome - terminal - }]
    ├─goa - daemon───3 * [{goa - daemon}]
    ├─goa - identity - se───3 * [{goa - identity - se}]
    ├─gsd - printer───2 * [{gsd - printer}]
    ├─gssproxy───5* [{gssproxy}]
    ├─gvfs - afc - volume───3 * [{gvfs - afc - volume}]
    ├─gvfs - goa - volume───2 * [{gvfs - goa - volume}]
    ├─gvfs - gphoto2 - vo───2 * [{gvfs - gphoto2 - vo}]
    ├─gvfs - mtp - volume───2 * [{gvfs - mtp - volume}]
    ├─gvfs - udisks2 - vo───2 * [{gvfs - udisks2 - vo}]
    ├─gvfsd─┬─gvfsd - burn───2 * [{gvfsd - burn}]
    │       ├─gvfsd - trash───2 * [{gvfsd - trash}]
    │       └─2* [{gvfsd}]
    ├─gvfsd - fuse───5 * [{gvfsd - fuse}]
    ├─gvfsd - metadata───2 * [{gvfsd - metadata}]
    ├─ibus - daemon─┬─ibus - dconf───3 * [{ibus - dconf}]
    │             └─2* [{ibus - daemon}]
    ├─ibus - portal───2 * [{ibus - portal}]
    ├─2* [ibus - x11───2 * [{ibus - x11}]]
    ├─imsettings - daem───3 * [{imsettings - daem}]
    ├─irqbalance
    ├─ksmtuned───sleep
    ├─libvirtd───16* [{libvirtd}]
    ├─lsmd
    ├─lvmetad───{ lvmetad }
    ├─master─┬─pickup
    │        └─qmgr
    ├─mcelog
    ├─mission - control───3 * [{mission - control}]
    ├─mysqld───26* [{mysqld}]
    ├─packagekitd───2* [{packagekitd}]
    ├─polkitd───6* [{polkitd}]
    ├─pulseaudio───2* [{pulseaudio}]
    ├─rngd
    ├─rpcbind
    ├─rsyslogd───2* [{rsyslogd}]
    ├─rtkit - daemon───2 * [{rtkit - daemon}]
    ├─smartd
    ├─sshd
    ├─systemd - journal
    ├─systemd - logind
    ├─systemd - udevd
    ├─tracker - store───7 * [{tracker - store}]
    ├─tuned───4* [{tuned}]
    ├─udisksd───4* [{udisksd}]
    ├─upowerd───2* [{upow



        [root@luckily ~]# top

        top - 16:56 : 12 up  1 : 03, 2 users, load average : 0.00, 0.01, 0.05
        Tasks : 240 total, 1 running, 239 sleeping, 0 stopped, 0 zombie
        % Cpu(s) : 0.6 us, 1.4 sy,



[root@luckily ~]# free
        total        used        free      shared  buff / cache   available
        Mem : 1863104      992320      129348       37620      741436      665568
        Swap : 2093052           0     2093052


查看磁盘
[root@luckily ~]# fdisk - l

磁盘 / dev / sda：21.5 GB, 21474836480 字节，41943040 个扇区
Units = 扇区 of 1 * 512 = 512 bytes
扇区大小(逻辑 / 物理)：512 字节 / 512 字节
I / O 大小(最小 / 最佳)：512 字节 / 512 字节
磁盘标签类型：dos
磁盘标识符：0x000bea2b

设备 Boot      Start         End      Blocks   Id  System
/ dev / sda1 * 2048      411647      204800   83  Linux
/ dev / sda2          411648    31903743    15746048   8e  Linux LVM

磁盘 / dev / mapper / centos - root：10.7 GB, 10737418240 字节，20971520 个扇区
Units = 扇区 of 1 * 512 = 512 bytes
扇区大小(逻辑 / 物理)：512 字节 / 512 字节
I / O 大小(最小 / 最佳)：65536 字节 / 65536 字节


磁盘 / dev / mapper / centos - swap：2143 MB, 2143289344 字节，4186112 个扇区
Units = 扇区 of 1 * 512 = 512 bytes
扇区大小(逻辑 / 物理)：512 字节 / 512 字节
I / O 大小(最小 / 最佳)：512 字节 / 512 字节


[root@luckily ~]# df - h
文件系统                 容量  已用  可用 已用 % 挂载点
devtmpfs                 893M     0  893M    0 % / dev
tmpfs                    910M     0  910M    0 % / dev / shm
tmpfs                    910M   11M  900M    2 % / run
tmpfs                    910M     0  910M    0 % / sys / fs / cgroup
/ dev / mapper / centos - root   10G  5.2G  4.9G   52 % /
/dev / sda1                197M  163M   34M   83 % / boot
tmpfs                    182M  4.0K  182M    1 % / run / user / 42
tmpfs                    182M   24K  182M    1 % / run / user / 0
/ dev / sr0                 4.4G  4.4G     0  100 % / run / media / root / CentOS 7 x86_64


创建文件后查看他到底又多大
[root@luckily ~]# touch test.txt
[root@luckily ~]# ls - l
总用量 20
- rw------ - . 1 root root 2038 4月  20 18:54 anaconda - ks.cfg
- rw - r--r--. 1 root root 9116 4月  11 2016 mysql57 - community - release - el7 - 8.noarch.rpm
- rw - r--r--. 1 root root 2268 4月  20 21 : 44 passwd
- rw - r--r--. 1 root root    0 4月  21 19 : 23 test.txt
drwxr - xr - x. 2 root root    6 4月  20 20 : 35 公共
drwxr - xr - x. 2 root root    6 4月  20 20 : 35 模板
drwxr - xr - x. 2 root root    6 4月  20 20 : 35 视频
drwxr - xr - x. 2 root root    6 4月  20 20 : 35 图片
drwxr - xr - x. 2 root root    6 4月  20 20 : 35 文档
drwxr - xr - x. 2 root root    6 4月  20 20 : 35 下载
drwxr - xr - x. 2 root root    6 4月  20 20 : 35 音乐
drwxr - xr - x. 2 root root    6 4月  20 20 : 35 桌面
[root@luckily ~]# echo "123" > test.txt
[root@luckily ~]# ls - l test.txt
- rw - r--r--. 1 root root 4 4月  21 19:24 test.txt
[root@luckily ~]# od - c test.txt
0000000   1   2   3  \n
0000004
