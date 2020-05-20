const
fi='SUADUONG.inp';
fo='SUADUONG.out';
var d:array[1..100] of longint;
    free:array[1..100] of boolean;
    n,m:integer;
    c:array[1..100,1..100] of integer;

procedure nhap;
var f:text; i,u,v:integer;
begin
 assign(f,fi);
 reset(f);
 readln(f,n,m);
 for i:=1 to m do
  readln(f,u,v,c[u,v]);
 close(f);
end;

procedure init;
var i:integer;
begin
 for i:=1 to n do
  d[i]:=0;
 fillchar(free,sizeof(free),true);
end;

procedure dijkstra;
var kt:boolean; i,min,u,v:integer;
begin
 kt:=true;
 repeat
  u:=0; min:=maxint;
  for i:=1 to n do
   if (free[i]=true) and (d[i]<min) then
    begin
     u:=i;
     min:=d[i];
     break;
    end;
  if (u=0) or (u=n) then break;
  free[u]:=false;
  for v:=1 to n do
   if (free[v]=true) and (c[u,v]<>0) and (d[v]<d[u]+c[u,v]) then
    d[v]:=d[u]+c[u,v];
 until kt=false;
end;

procedure xuat;
var f:text;
begin
 assign(f,fo);
 rewrite(f);
 write(f,d[n]);
 close(f);
end;

BEGIN
 nhap;
 init;
 dijkstra;
 xuat;
END.
