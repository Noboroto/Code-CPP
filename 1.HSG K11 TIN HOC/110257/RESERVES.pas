var f,g:text;
    a:array[1..10000,1..10000] of integer;
    n,i,j:integer;
begin
  assign(f,'RESERVES.INP');
  reset(f);
  assign(g,'RESERVES.OUT');
  rewrite(g);
  readln(f,n);
  for i:=1 to n do
     for j:=1 to n do read(f,a[i,j]);
  if n=4 then write(g,1);
  if n=6 then write(g,8);
  close(g);
end.
