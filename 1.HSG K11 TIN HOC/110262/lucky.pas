var a:array[1..100000] of real;
    i,j,n:longint;
    k,s,d:real;
    f,g:text;
begin
     assign(f,'lucky.inp');
     reset(f);
     assign(g,'lucky.out');
     rewrite(g);
     readln(f,n,k);
     for i:=1 to n do read(f,a[i]);
     d:=0;
     for i:=1 to n do
        for j:=i+1 to n do
           if i<>j then
             begin
                  s:=abs(a[i]+a[j]);
                  if s=k then d:=d+1;
             end;
     writeln(g,d:0:0);
     close(g);
end.
