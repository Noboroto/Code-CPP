program c2;

uses crt;

var m,n,ans:integer;
    u:array[1..1000] of longint;
    i:array[1..1000] of longint;
    j:array[1..1000] of longint;
    a:integer;
/////////////////////////////////////
procedure input;
var f:text;
begin
        assign(f,'SUADUONG.INP');
        reset(f);
        readln(f,n,m);
        for a:=1 to m do
                begin
                read(f,i[a],j[a],u[a]);
                readln(f);
                end;
        close(f);
end;
/////////////////////////////////////
procedure output;
var f:text;
begin
        assign(f,'SUADUONG.OUT');
        rewrite(f);
        write(f,ans);
        close(f);
end;
//////////////////////////////////////
BEGIN
fillchar(u,sizeof(u),0);
fillchar(i,sizeof(i),0);
fillchar(j,sizeof(j),0);
input;
for a:=1 to n do ans:=ans+u[a];
output;
END.










