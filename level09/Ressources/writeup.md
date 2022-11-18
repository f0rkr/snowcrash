Home folder of user level09 contains two files level09 binary and 
token writen in it 'f4kmm6p|=�p�n��DB�Du{��'

The binary takes an argument and writes back a string with the same length as the argument

It is a substitution cipher

[ e(x) = x + index_of(x) ]

[ d(y) = y - index_of(y) ]

The code in decrypt.c decrypts cipher and gives the password for flag09 user

```
*[main][~/snowcrash/level09/Ressources]$ gcc decrypt.c -o decrypt
*[main][~/snowcrash/level09/Ressources]$ ./decrypt token|cat -e  
f3iji1ju5yuevaus41q1afiuq$
*[main][~/snowcrash/level09/Ressources]$
```

Now we login to user flag09 and getflag it.

```
level09@SnowCrash:~$ su flag09
Password:
Don't forget to launch getflag !
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```