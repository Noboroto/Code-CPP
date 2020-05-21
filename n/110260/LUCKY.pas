var N,i,j,d,K:longint;
    a:array[1..100000] of longint;
    f,g:text;
begin
    assign(f,'LUCKY.INP');
    reset(f);
    assign(g,'LUCKY.OUT');
    rewrite(g);
    readln(f,N,K);
    for i:=1 to N do read(f,a[i]);
    d:=0;
    for i:=1 to N do
      if i<N then for j:=i+1 to N do
        if abs(a[i] + a[j]) = K then d:=d+1;
    writeln(g,d);
    close(f);
    close(g);
end.






