Level13 home is not empty, it contains a binary suid bit is set and owner is flag13

After executing the following prints in stdout 'UID 2013 started us but we expect 4242'

Let's debug the program using gdb

```
(gdb) set disassembly intel
(gdb) disas main
Dump of assembler code for function main:
   0x0804858c <+0>:	push   ebp
   0x0804858d <+1>:	mov    ebp,esp
   0x0804858f <+3>:	and    esp,0xfffffff0
   0x08048592 <+6>:	sub    esp,0x10
   0x08048595 <+9>:	call   0x8048380 <getuid@plt>
   0x0804859a <+14>:	cmp    eax,0x1092
   0x0804859f <+19>:	je     0x80485cb <main+63>
   0x080485a1 <+21>:	call   0x8048380 <getuid@plt>
   0x080485a6 <+26>:	mov    edx,0x80486c8
   0x080485ab <+31>:	mov    DWORD PTR [esp+0x8],0x1092
   0x080485b3 <+39>:	mov    DWORD PTR [esp+0x4],eax
   0x080485b7 <+43>:	mov    DWORD PTR [esp],edx
   0x080485ba <+46>:	call   0x8048360 <printf@plt>
   0x080485bf <+51>:	mov    DWORD PTR [esp],0x1
   0x080485c6 <+58>:	call   0x80483a0 <exit@plt>
   0x080485cb <+63>:	mov    DWORD PTR [esp],0x80486ef
   0x080485d2 <+70>:	call   0x8048474 <ft_des>
   0x080485d7 <+75>:	mov    edx,0x8048709
   0x080485dc <+80>:	mov    DWORD PTR [esp+0x4],eax
   0x080485e0 <+84>:	mov    DWORD PTR [esp],edx
   0x080485e3 <+87>:	call   0x8048360 <printf@plt>
   0x080485e8 <+92>:	leave
   0x080485e9 <+93>:	ret
End of assembler dump.
```

It's seems that the prorame compare the uid returned from getuid function with 4242
Let's try to change the return value of getuid to 4242 and bypass the comp check

```
(gdb) break *0x0804859a
Breakpoint 2 at 0x804859a
(gdb) run
Starting program: /home/user/level13/level13
Breakpoint 2, 0x0804859a in main ()
(gdb) i r
eax            0x7dd	2013
ecx            0xbffff794	-1073743980
edx            0xbffff724	-1073744092
ebx            0xb7fd0ff4	-1208152076
esp            0xbffff6e0	0xbffff6e0
ebp            0xbffff6f8	0xbffff6f8
esi            0x0	0
edi            0x0	0
eip            0x804859a	0x804859a <main+14>
eflags         0x200246	[ PF ZF IF ID ]
cs             0x73	115
ss             0x7b	123
ds             0x7b	123
es             0x7b	123
fs             0x0	0
gs             0x33	51
(gdb) set $eax=4242
(gdb) c
Continuing.
your token is 2A31L79asukciNyi8uppkEuSx
[Inferior 1 (process 2149) exited with code 050]
(gdb) 
```

$eax register holds the return of getuid call, we can write 4242 into `$eax and continue`
the execution of the program.