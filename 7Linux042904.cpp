
[root@luckily study]# cd day03
[root@luckily day03]# ls
Jindutiao  Jindutiao.c  process  process.c
[root@luckily day03]# cd ..
[root@luckily study]# ls
day01  day02  day03  Linux
[root@luckily study]# cd Linux /
[root@luckily Linux]# ls
Linux050201.c
[root@luckily Linux]# cd ..
[root@luckily study]# cd day03
[root@luckily day03]# size process
text	   data	    bss	    dec	    hex	filename
1568	    572	     16	   2156	    86c	process
[root@luckily day03]# file process
process : ELF 64 - bit LSB executable, x86 - 64, version 1 (SYSV), dynamically linked(uses shared libs), for GNU / Linux 2.6.32, BuildID[sha1] = 1d057160cb58b2156cf420280da3dd3da03304c2, not stripped
½ø³Ì
[root@luckily day03]# ps - ef
UID         PID   PPID  C STIME TTY          TIME CMD
root          1      0  0 16:16 ? 00 : 00 : 02 / usr / lib / systemd / systemd --switched - r
root          2      0  0 16 : 16 ? 00 : 00 : 00[kthreadd]
