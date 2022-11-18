At first we find a pcap file in the home folder

`level02@SnowCrash:~$ ls`

# level02.pcap

`level02@SnowCrash:~$`

Downloading the pcap file using scp command

```
[~]$ scp -P 4242  level02@10.12.177.116:level02.pcap .
#	   _____                      _____               _
#	  / ____|                    / ____|             | |
#	 | (___  _ __   _____      _| |     _ __ __ _ ___| |__
#	  \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
#	  ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
#	 |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|
#
#  Good luck & Have fun

#         10.12.177.116


level02@10.12.177.116's password:

level02.pcap                                         100% 8302     9.4MB/s   00:00

[~]$ ls
level02.pcap
[~]$
```

Opening pcap file with wireshark. After following a sus TCP stream we ended up with this data 
It's obvious that it's successful login attemp with clear text password

```
Linux 2.6.38-8-generic-pae (::ffff:10.1.1.2) (pts/10)

wwwbugs login: lleevveellXX

Password: ft_waNDReL0L

Login incorrect

wwwbugs login:
```


Trying to login to flag02 with this password 

```
level02@SnowCrash:~$ su flag02

Password: `ft_waNDReL0L`

flag02@SnowCrash:~$ getflag

Check flag.Here is your token : kooda2puivaav1idi4f57q8iq

flag02@SnowCrash:~$
```