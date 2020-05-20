var f,g:text;
    a,b:array[1..100000] of string;
    n,i,j,d:integer;
    p,q,k,dem:longint;
    x:char;
    t:string;
begin
   assign(f,'LUCKY.INP');
   reset(f);
   assign(g,'LUCKY.OUT');
   rewrite(g);
   readln(f,n,k);
   i:=0;
   while not eof(f) do
      begin
        read(f,x);
        t:=t+x;
        if x=' ' then
          begin
           inc(i);
           delete(t,pos(' ',t),1);
           a[i]:=t;
           t:='';
          end;
      end;
   a[n]:=copy(t,1,length(t)-2);
   dem:=0;
   for i:=1 to n-1 do
     for j:=i+1 to n do
       begin
           val(a[i],p,d);
           val(a[j],q,d);
           if p+q=k then inc (dem);
       end;
   write(g,dem);
   close(g);
end.
