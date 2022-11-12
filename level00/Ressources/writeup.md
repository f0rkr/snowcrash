Searching for files that flag00 owns using the find command like this:

find / -user flag00 2>/dev/null 

`level00@SnowCrash:~$ find / -user flag00 2>/dev/null
/usr/sbin/john
/rofs/usr/sbin/john`

`level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt`

After trying to log in to flag00 with this password it results to Authentication failure. It’s seems that it’s encoded. Let’s try cesar cypher 

Then after trying multiple shifts we managed to crack the cyphered text cdiiddwpgswtgt —> nottoohardhere

`level00@SnowCrash:~$ su flag00
Password:nottoohardhere
Don't forget to launch getflag !
flag00@SnowCrash:~$`

Now executing the command getflag to get Level01 token 

***flag00@SnowCrash:~$ getflag
Check flag.Here is your token : `x24ti5gi3x0ol2eh4esiuxias`
flag00@SnowCrash:~$***