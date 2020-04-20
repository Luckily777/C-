Õ¯¬Á≈‰÷√

[root@luckily ~]# mii - tool eth0
eth0 : negotiated 1000baseT - FD flow - control, link ok
[root@luckily ~]# route - n
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
0.0.0.0         192.168.142.2   0.0.0.0         UG    100    0        0 eth0
192.168.122.0   0.0.0.0         255.255.255.0   U     0      0        0 virbr0
192.168.142.0   0.0.0.0         255.255.255.0   U     100    0        0 eth0
[root@luckily ~]# ifconfig
eth0 : flags = 4163 < UP, BROADCAST, RUNNING, MULTICAST > mtu 1500
inet 192.168.142.130  netmask 255.255.255.0  broadcast 192.168.142.255
inet6 fe80::170 : e2df : 6e6b : d335  prefixlen 64  scopeid 0x20 < link >
ether 00 : 0c : 29 : 74 : 60 : 70  txqueuelen 1000  (Ethernet)
RX packets 39  bytes 9356 (9.1 KiB)
RX errors 0  dropped 0  overruns 0  frame 0
TX packets 75  bytes 9858 (9.6 KiB)
TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo : flags = 73 < UP, LOOPBACK, RUNNING > mtu 65536
inet 127.0.0.1  netmask 255.0.0.0
inet6 ::1  prefixlen 128  scopeid 0x10 < host >
loop  txqueuelen 1000  (Local Loopback)
RX packets 48  bytes 4080 (3.9 KiB)
RX errors 0  dropped 0  overruns 0  frame 0
TX packets 48  bytes 4080 (3.9 KiB)
TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

virbr0: flags = 4099 < UP, BROADCAST, MULTICAST > mtu 1500
inet 192.168.122.1  netmask 255.255.255.0  broadcast 192.168.122.255
ether 52 : 54 : 00 : 08 : 1a : 39  txqueuelen 1000  (Ethernet)
RX packets 0  bytes 0 (0.0 B)
RX errors 0  dropped 0  overruns 0  frame 0
TX packets 0  bytes 0 (0.0 B)
TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

[root@luckily ~]# 
