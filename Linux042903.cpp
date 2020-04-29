函数栈帧

[root@luckily day02]# vim 042803.c
[root@luckily day02]# gcc 042803.c
[root@luckily day02]# . / a.out
r = 55
[root@luckily day02]# gcc 042803.c - g
[root@luckily day02]# gdb a.out
(gdb) ls
Undefined command : "ls".Try "help".
(gdb)l
3	int sum(int n) {
    4		if (n < 1) {
        5			return n;
        6
    }
    7		else {
        8			return n + sum(n - 1);
        9
    }
    10
}
11	int main(void) {
    12		int i = 10;
    (gdb)l
        13		int r = sum(i);
    14		printf("r = %d \n", r);
    15
}
(gdb)b 13
Breakpoint 1 at 0x400566: file 042803.c, line 13.
(gdb)r
Starting program : / root / study / day02 / a.out

Breakpoint 1, main() at 042803.c : 13
13		int r = sum(i);
Missing separate debuginfos, use: debuginfo - install glibc - 2.17 - 292.el7.x86_64
(gdb) s
sum(n = 10) at 042803.c : 4
4		if (n < 1) {
    (gdb)n
        8			return n + sum(n - 1);
    (gdb)s
        sum(n = 9) at 042803.c:4
        4		if (n < 1) {
        (gdb)n
            8			return n + sum(n - 1);
        (gdb)s
            sum(n = 8) at 042803.c:4
            4		if (n < 1) {
            (gdb)n
                8			return n + sum(n - 1);
            (gdb)s
                sum(n = 7) at 042803.c:4
                4		if (n < 1) {
                (gdb)n
                    8			return n + sum(n - 1);
                (gdb)s
                    sum(n = 6) at 042803.c:4
                    4		if (n < 1) {
                    (gdb)n
                        8			return n + sum(n - 1);
                    (gdb)s
                        sum(n = 5) at 042803.c:4
                        4		if (n < 1) {
                        (gdb)n
                            8			return n + sum(n - 1);
                        (gdb)s
                            sum(n = 4) at 042803.c:4
                            4		if (n < 1) {
                            (gdb)n
                                8			return n + sum(n - 1);
                            (gdb)s
                                sum(n = 3) at 042803.c:4
                                4		if (n < 1) {
                                (gdb)n
                                    8			return n + sum(n - 1);
                                (gdb)s
                                    sum(n = 2) at 042803.c:4
                                    4		if (n < 1) {
                                    (gdb)n
                                        8			return n + sum(n - 1);
                                    (gdb)s
                                        sum(n = 1) at 042803.c:4
                                        4		if (n < 1) {
                                        (gdb)n
                                            8			return n + sum(n - 1);
                                        (gdb)bt
                                            #0  sum(n = 1) at 042803.c:8
                                            #1  0x0000000000400550 in sum(n = 2) at 042803.c:8
                                            #2  0x0000000000400550 in sum(n = 3) at 042803.c:8
                                            #3  0x0000000000400550 in sum(n = 4) at 042803.c:8
                                            #4  0x0000000000400550 in sum(n = 5) at 042803.c:8
                                            #5  0x0000000000400550 in sum(n = 6) at 042803.c:8
                                            #6  0x0000000000400550 in sum(n = 7) at 042803.c:8
                                            #7  0x0000000000400550 in sum(n = 8) at 042803.c:8
                                            #8  0x0000000000400550 in sum(n = 9) at 042803.c:8
                                            #9  0x0000000000400550 in sum(n = 10) at 042803.c:8
                                            #10 0x0000000000400570 in main() at 042803.c:13
                                          
                                         看栈
                                            (gdb)info frame
                                            Stack level 0, frame at 0x7fffffffdea0 :
                                            rip = 0x400543 in sum(042803.c:8); saved rip 0x400550
                                            called by frame at 0x7fffffffdec0
                                            source language c.
                                            Arglist at 0x7fffffffde90, args: n = 1
                                            Locals at 0x7fffffffde90, Previous frame's sp is 0x7fffffffdea0
                                            Saved registers :
                                        rbp at 0x7fffffffde90, rip at 0x7fffffffde98
                                            (gdb)
 看寄存器
 (gdb) info registers
                                            rax            0x1	1
                                            rbx            0x0	0
                                            rcx            0x400590	4195728
                                            rdx            0x7fffffffe0c8	140737488347336
                                            rsi            0x7fffffffe0b8	140737488347320
                                            rdi            0x1	1
                                            rbp            0x7fffffffde90	0x7fffffffde90
                                            rsp            0x7fffffffde80	0x7fffffffde80
                                            r8             0x7ffff7dd5e80	140737351868032
                                            r9             0x0	0
                                            r10            0x7fffffffdae0	140737488345824
                                            r11            0x7ffff7a2f410	140737348039696
                                            r12            0x400440	4195392
                                            r13            0x7fffffffe0b0	140737488347312
                                            r14            0x0	0
                                            r15            0x0	0
                                            rip            0x400543	0x400543 < sum + 22 >
                                            eflags         0x202[IF]
                                            cs             0x33	51
                                            ss             0x2b	43
                                            ds             0x0	0
                                            es             0x0	0
                                            fs             0x0	0
                                            gs             0x0	0


修改寄存器的值  ：（是函数的返回值存放在寄存器之中，因此修改了寄存器的值也就相当于直接修改了返回值）
这样的作法，也就是为何c语言不会使用 取地址（函数）赋值这样的方式来进行赋值，因为无法将一个值赋给寄存器的地址
(gdb) set $rax = 0
(gdb)info registers
rax            0x0	0
rbx            0x0	0
rcx            0x400590	4195728
rdx            0x7fffffffe0c8	140737488347336
rsi            0x7fffffffe0b8	140737488347320
rdi            0x1	1
rbp            0x7fffffffde90	0x7fffffffde90
rsp            0x7fffffffde80	0x7fffffffde80
r8             0x7ffff7dd5e80	140737351868032
r9             0x0	0
r10            0x7fffffffdae0	140737488345824
r11            0x7ffff7a2f410	140737348039696
r12            0x400440	4195392
r13            0x7fffffffe0b0	140737488347312
r14            0x0	0
r15            0x0	0
rip            0x400543	0x400543 < sum + 22 >
eflags         0x202[IF]
cs             0x33	51
ss             0x2b	43
ds             0x0	0
es             0x0	0
fs             0x0	0
gs             0x0	0
