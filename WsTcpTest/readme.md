# Websocket & TCP/IP Test

Start the http server and run in background

```bash
$ http-server&
[1] 41355
Starting up http-server, serving ./public
Available on:
  http://127.0.0.1:8080
  http://10.148.85.236:8080
  http://10.211.55.2:8080
  http://10.37.129.2:8080
  http://169.254.19.45:8080
Hit CTRL-C to stop the server
```

Start tcpdump to listen

```bash
$ sudo tcpdump dst host 10.148.85.236
tcpdump: data link type PKTAP
tcpdump: verbose output suppressed, use -v or -vv for full protocol decode
listening on pktap, link-type PKTAP (Apple DLT_PKTAP), capture size 262144 bytes
```

Use your phone to visit 10.148.85.236

```
10:51:10.230455 ARP, Request who-has 10.148.85.236 tell 10.148.85.44, length 42
10:51:10.237672 IP dns3.ccnu.edu.cn.domain > 10.148.85.236.62972: 33733 NXDomain* 0/1/0 (93)
10:51:10.241917 IP dns3.ccnu.edu.cn.domain > 10.148.85.236.65025: 22285 1/2/0 PTR dns3.ccnu.edu.cn. (126)
^C
3 packets captured
20 packets received by filter
0 packets dropped by kernel
```
