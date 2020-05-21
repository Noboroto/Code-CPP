const
fi='RESERVES.inp';
fo='RESERVES.out';
dx:array[1..8] of integer = (-1,-1,-1,0,0,1,1,1);
dy:array[1..8] of integer = (-1,0,1,-1,1,-1,0,1);
var a:array[1..100,1..100] of integer;
    n:integer;
    d:longint;

procedure nhap;
var f:text; i,j:integer;
begin
 assign(f,fi);
 reset(f);
 readln(f,n);
 for i:=1 to n do
 for j:=1 to n do
  if j=n then readln(f,a[i,j]) else read(f,a[i,j]);
 close(f);
end;

function kt(i,j:integer):boolean;
var z:integer;
begin
 kt:=true;
 for z:=1 to 8 do
  if a[i+dx[z],j+dy[z]] <a[i,j] then begin kt:=false; break; end;
end;

function min(i,j:integer):integer;
var z:integer;
begin
 min:=maxint;
 for z:=1 to 8 do
  if a[i+dx[z],j+dy[z]] <min then min:=a[i+dx[z],j+dy[z]];
 if min>a[i,j] then min:=min-a[i,j];
end;

procedure xuli;
var i,j:integer;
begin
 d:=0;
 for i:=2 to n-1 do
 for j:=2 to n-1 do
  if kt(i,j)=true then d:=d+min(i,j);
end;

procedure xuat;
var f:text;
begin
 assign(f,fo);
 rewrite(f);
 write(f,d);
 close(f);
end;

BEGIN
 nhap;
 xuli;
 xuat;
END.