It’s seems that there’s nothing we can learn from the level01 home folder since it’s empty. Let’s try and cat the /etc/passwd.

`level01@SnowCrash:~$ cat /etc/passwd`

..

..

`flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash`

Let’s try and decrypt it using john

`level01@SnowCrash:~$ echo “42hDRfypTqqnw” > hash.txt`

`level01@SnowCrash:~$ john hash`

**abcdefg**

`flag01@SnowCrash:~$ getflag`

`Check flag.Here is your token : f2av5il02puano7naaf6adaaf`

`flag01@SnowCrash:~$`