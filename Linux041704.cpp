Õ¯¬Á≈‰÷√
[root@localhost ~]# L
bash : L: command not found
[root@localhost ~]# ping www.baidu.com
PING www.a.shifen.com(36.152.44.95) 56(84) bytes of data.
64 bytes from 36.152.44.95: icmp_seq = 1 ttl = 128 time = 45.3 ms
64 bytes from 36.152.44.95 : icmp_seq = 2 ttl = 128 time = 36.0 ms
64 bytes from 36.152.44.95 : icmp_seq = 3 ttl = 128 time = 52.2 ms
64 bytes from 36.152.44.95 : icmp_seq = 4 ttl = 128 time = 37.8 ms
64 bytes from 36.152.44.95 : icmp_seq = 5 ttl = 128 time = 42.6 ms
64 bytes from 36.152.44.95 : icmp_seq = 6 ttl = 128 time = 37.3 ms
64 bytes from 36.152.44.95 : icmp_seq = 7 ttl = 128 time = 36.7 ms
64 bytes from 36.152.44.95 : icmp_seq = 8 ttl = 128 time = 38.0 ms
64 bytes from 36.152.44.95 : icmp_seq = 9 ttl = 128 time = 41.1 ms
q64 bytes from 36.152.44.95 : icmp_seq = 10 ttl = 128 time = 41.0 ms
64 bytes from 36.152.44.95 : icmp_seq = 11 ttl = 128 time = 37.9 ms
^ [64 bytes from 36.152.44.95:icmp_seq = 12 ttl = 128 time = 34.6 ms
64 bytes from 36.152.44.95 : icmp_seq = 13 ttl = 128 time = 38.1 ms
64 bytes from 36.152.44.95 : icmp_seq = 14 ttl = 128 time = 73.8 ms
64 bytes from 36.152.44.95 : icmp_seq = 15 ttl = 128 time = 47.3 ms
64 bytes from 36.152.44.95 : icmp_seq = 16 ttl = 128 time = 45.6 ms
64 bytes from 36.152.44.95 : icmp_seq = 17 ttl = 128 time = 35.7 ms
64 bytes from 36.152.44.95 : icmp_seq = 18 ttl = 128 time = 36.0 ms
64 bytes from 36.152.44.95 : icmp_seq = 19 ttl = 128 time = 42.6 ms
64 bytes from 36.152.44.95 : icmp_seq = 20 ttl = 128 time = 37.7 ms
64 bytes from 36.152.44.95 : icmp_seq = 21 ttl = 128 time = 39.0 ms
    : 64 bytes from 36.152.44.95 : icmp_seq = 22 ttl = 128 time = 44.8 ms
    q
    64 bytes from 36.152.44.95 : icmp_seq = 23 ttl = 128 time = 38.8 ms
    64 bytes from 36.152.44.95 : icmp_seq = 24 ttl = 128 time = 35.9 ms
    64 bytes from 36.152.44.95 : icmp_seq = 25 ttl = 128 time = 42.9 ms
    64 bytes from 36.152.44.95 : icmp_seq = 26 ttl = 128 time = 39.2 ms
    64 bytes from 36.152.44.95 : icmp_seq = 27 ttl = 128 time = 45.3 ms
    64 bytes from 36.152.44.95 : icmp_seq = 28 ttl = 128 time = 43.5 ms
    64 bytes from 36.152.44.95 : icmp_seq = 29 ttl = 128 time = 97.3 ms
    64 bytes from 36.152.44.95 : icmp_seq = 30 ttl = 128 time = 38.0 ms
    64 bytes from 36.152.44.95 : icmp_seq = 31 ttl = 128 time = 55.9 ms
    64 bytes from 36.152.44.95 : icmp_seq = 32 ttl = 128 time = 34.4 ms
    64 bytes from 36.152.44.95 : icmp_seq = 33 ttl = 128 time = 44.2 ms
    64 bytes from 36.152.44.95 : icmp_seq = 34 ttl = 128 time = 49.1 ms
    64 bytes from 36.152.44.95 : icmp_seq = 35 ttl = 128 time = 42.9 ms
    64 bytes from 36.152.44.95 : icmp_seq = 36 ttl = 128 time = 37.3 ms
    64 bytes from 36.152.44.95 : icmp_seq = 37 ttl = 128 time = 46.1 ms
    64 bytes from 36.152.44.95 : icmp_seq = 38 ttl = 128 time = 40.1 ms
    64 bytes from 36.152.44.95 : icmp_seq = 39 ttl = 128 time = 44.8 ms
    64 bytes from 36.152.44.95 : icmp_seq = 40 ttl = 128 time = 41.0 ms
    64 bytes from 36.152.44.95 : icmp_seq = 41 ttl = 128 time = 41.0 ms
    ^ C
    -- - www.a.shifen.com ping statistics-- -
    42 packets transmitted, 41 received, 2 % packet loss, time 41105ms
    rtt min / avg / max / mdev = 34.471 / 43.437 / 97.399 / 10.951 ms
    [root@localhost ~]# clear

    [root@localhost ~]# ifconfig
    eth0      Link encap : Ethernet  HWaddr 00 : 0C : 29 : 00 : F8 : BA
    inet6 addr : fe80::20c : 29ff : fe00 : f8ba / 64 Scope : Link
    UP BROADCAST RUNNING MULTICAST  MTU : 1500  Metric : 1
    RX packets : 4473 errors : 0 dropped : 0 overruns : 0 frame : 0
    TX packets : 844 errors : 0 dropped : 0 overruns : 0 carrier : 0
    collisions : 0 txqueuelen : 1000
    RX bytes : 320587 (313.0 KiB)  TX bytes : 74362 (72.6 KiB)

    lo        Link encap : Local Loopback
    inet addr : 127.0.0.1  Mask : 255.0.0.0
    inet6 addr : ::1 / 128 Scope : Host
    UP LOOPBACK RUNNING  MTU : 65536  Metric : 1
    RX packets : 26 errors : 0 dropped : 0 overruns : 0 frame : 0
    TX packets : 26 errors : 0 dropped : 0 overruns : 0 carrier : 0
    collisions : 0 txqueuelen : 0
    RX bytes : 2170 (2.1 KiB)  TX bytes : 2170 (2.1 KiB)

    [root@localhost ~]# mii - tool eth0
    bash : mii - : command not found
    [root@localhost ~]# mii - tool eth0
    bash : mii: command not found
    [root@localhost ~]# mii--tool eth0
    bash : mii--tool : command not found
    [root@localhost ~]# mii - tool eth0
    bash : mii: command not found
    [root@localhost ~]# mii--tool eth0
    bash : mii--tool : command not found
    [root@localhost ~]# mii - tool eth0
    eth0 : negotiated 100baseTx - FD, link ok
    [root@localhost ~]# route - n
    Usage : route[-nNvee][-FC][<AF>]           List kernel routing tables
    route[-v][-FC]{ add | del | flush } ...  Modify routing table for AF.

    route{ -h | --help }[<AF>]              Detailed usage syntax for specified AF.
    route{ -V | --version }                  Display version / author and exit.

    - v, --verbose            be verbose
    - n, --numeric            don't resolve names
    - e, --extend             display other / more information
    - F, --fib                display Forwarding Information Base(default)
    - C, --cache              display routing cache instead of FIB

  < AF >= Use '-A <af>' or '--<af>'; default: inet
    List of possible address families(which support routing) :
    inet(DARPA Internet) inet6(IPv6) ax25(AMPR AX.25)
    netrom(AMPR NET / ROM) ipx(Novell IPX) ddp(Appletalk DDP)
    x25(CCITT X.25)
    [root@localhost ~]# route - n
    bash : route - n : command not found
    [root@localhost ~]# route - n
    Kernel IP routing table
    Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
    [root@localhost ~]# route - n
    Kernel IP routing table
    Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
    192.168.142.0   0.0.0.0         255.255.255.0   U     1      0        0 eth0
    0.0.0.0         192.168.142.2   0.0.0.0         UG    0      0        0 eth0
    [root@localhost ~]# ifconfig eth0
    eth0      Link encap : Ethernet  HWaddr 00 : 0C : 29 : 00 : F8 : BA
    inet addr : 192.168.142.129  Bcast : 192.168.142.255  Mask : 255.255.255.0
    inet6 addr : fe80::20c : 29ff : fe00 : f8ba / 64 Scope : Link
    UP BROADCAST RUNNING MULTICAST  MTU : 1500  Metric : 1
    RX packets : 4812 errors : 0 dropped : 0 overruns : 0 frame : 0
    TX packets : 882 errors : 0 dropped : 0 overruns : 0 carrier : 0
    collisions : 0 txqueuelen : 1000
    RX bytes : 342213 (334.1 KiB)  TX bytes : 78136 (76.3 KiB)

    [root@localhost ~]# ifconfig eth0 192.168.144.100
    [root@localhost ~]# ifconfig eht0
    eht0 : error fetching interface information : Device not found
    [root@localhost ~]# ifconfig eth0
    eth0      Link encap : Ethernet  HWaddr 00 : 0C : 29 : 00 : F8 : BA
    inet addr : 192.168.144.100  Bcast : 192.168.144.255  Mask : 255.255.255.0
    inet6 addr : fe80::20c : 29ff : fe00 : f8ba / 64 Scope : Link
    UP BROADCAST RUNNING MULTICAST  MTU : 1500  Metric : 1
    RX packets : 4818 errors : 0 dropped : 0 overruns : 0 frame : 0
    TX packets : 886 errors : 0 dropped : 0 overruns : 0 carrier : 0
    collisions : 0 txqueuelen : 1000
    RX bytes : 342663 (334.6 KiB)  TX bytes : 78466 (76.6 KiB)

    [root@localhost ~]# ifconfig eth0 192.168.142.129
    [root@localhost ~]# ifconfig eth0
    eth0      Link encap : Ethernet  HWaddr 00 : 0C : 29 : 00 : F8 : BA
    inet addr : 192.168.142.129  Bcast : 192.168.142.255  Mask : 255.255.255.0
    inet6 addr : fe80::20c : 29ff : fe00 : f8ba / 64 Scope : Link
    UP BROADCAST RUNNING MULTICAST  MTU : 1500  Metric : 1
    RX packets : 4828 errors : 0 dropped : 0 overruns : 0 frame : 0
    TX packets : 886 errors : 0 dropped : 0 overruns : 0 carrier : 0
    collisions : 0 txqueuelen : 1000
    RX bytes : 343263 (335.2 KiB)  TX bytes : 78466 (76.6 KiB)

    [root@localhost ~]# route - n
    Kernel IP routing table
    Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
    192.168.142.0   0.0.0.0         255.255.255.0   U     0      0        0 eth0
    [root@localhost ~]# ping www.baidu.com
    connect : Õ¯¬Á≤ªø…¥Ô
    [root@localhost ~]# route - n
    Kernel IP routing table
    Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
    192.168.142.0   0.0.0.0         255.255.255.0   U     1      0        0 eth0
    0.0.0.0         192.168.142.2   0.0.0.0         UG    0      0        0 eth0
    [root@localhost ~]# ping www.baidu.com
    PING www.a.shifen.com(36.152.44.95) 56(84) bytes of data.
    64 bytes from 36.152.44.95: icmp_seq = 1 ttl = 128 time = 37.0 ms
    64 bytes from 36.152.44.95 : icmp_seq = 2 ttl = 128 time = 40.0 ms
    c64 bytes from 36.152.44.95 : icmp_seq = 3 ttl = 128 time = 39.3 ms
    64 bytes from 36.152.44.95 : icmp_seq = 4 ttl = 128 time = 42.1 ms
    ^ C
    -- - www.a.shifen.com ping statistics-- -
    4 packets transmitted, 4 received, 0 % packet loss, time 3894ms
    rtt min / avg / max / mdev = 37.061 / 39.638 / 42.122 / 1.814 ms
    [root@localhost ~]# 
