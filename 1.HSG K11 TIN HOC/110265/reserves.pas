var a:array[1..100] of integer;
    f1,f2:text;
    i,n,j:byte;
    v:longint;
{function chk(a[i]+a[j]);
var
b,u,d,l,n,min:integer;
begin
b:=
u:=
d:=
l:=
n:=a[
end;}
begin
        assign(f1,'reserves.inp');
        reset(f1);
        assign(f2,'reserves.out');
        rewrite(f2);
        fillchar(a,sizeof(a),0);
        readln(f1,n);
        for i:=1 to n do
        begin
                for j:=1 to n do read(f1,a[i]);
                readln(f1);
        end;
                v:=0;
                for J:=1 to n do
                {v:=v+chk[i,j];}
                writeln(f2,v);
                close (f2);
end.