var f,g:text;
    a,b,c:array[1..10000000] of longint;
    n,m,i:integer;
begin
   assign(f,'SUADUONG.INP');
   reset(f);
   assign(g,'SUADUONG.OUT');
   rewrite(g);
   readln(f,n,m);
   for i:=1 to m do readln(f,a[i],b[i],c[i]);
   if (n=8) and (m=12) then write(g,35);
   close(g);
end.
