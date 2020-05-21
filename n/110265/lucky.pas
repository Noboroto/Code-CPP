uses crt;
var f,g:text;
    a:array[1..100000] of integer;
    k,sl,qua:integer;
    i,n,j:integer;
begin
        assign(f,'lucky.inp');
        reset(f);
        assign(g,'lucky.out');
        rewrite(g);
        readln(f,n,k);
        read(a[i],a[j]);
        begin
        sl:=0;
        for i:=1 to n do
        for j:=i+1 to n do
          repeat
          if i<>j then qua:=abs(a[i]+a[j]);
          if qua=k then sl:=sl+1;
          until j=n;
          write(g,sl);
          close(g);
         end;
end.
