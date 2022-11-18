Home is empty we'll try to reverse /bin/getflag

After the disassembly with gdb we notice <ptrace> returns -1, we will override the return by
setting a breakpoint at test instruction and set `eax` to 0



```
   0x08048989 <+67>:    call   0x8048540 <ptrace@plt>
=> 0x0804898e <+72>:    test   %eax,%eax 
```

```
(gdb) break ptrace
Breakpoint 1 at 0x8048540
(gdb) break getuid
Breakpoint 2 at 0x80484b0
(gdb) run
Starting program: /bin/getflag

Breakpoint 1, 0xb7f146d0 in ptrace () from /lib/i386-linux-gnu/libc.so.6
(gdb) fin
Run till exit from #0  0xb7f146d0 in ptrace () from /lib/i386-linux-gnu/libc.so.6
0x0804898e in main ()
(gdb) set $(eax)=0
(gdb) c
```

The next breakpoint will be at the instruction after <getuid> call and set the return to 3014
which is the uid of flag14

```
    0x08048afd <+439>:	call   0x80484b0 <getuid@plt>
=>  0x08048b02 <+444>:	mov    %eax,0x18(%esp)
```

```
(gdb) fin
Run till exit from #0  0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
0x08048b02 in main ()
(gdb) set $eax=3014
(gdb) c
Continuing.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
```
Continue and the flag of flag14 is printed
