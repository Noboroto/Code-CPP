program c3;

uses crt;
var n,i:longint;
    k:longint;
    count:longint;
    a:array[1..100000] of longint;
    b:array[-75000000..75000000]of longint;
procedure input;
var f:text;
begin
        assign(f,'LUCKY.INP');
        reset(f);
        read(f,n,k);
        readln(f);
        for i:=1 to n do begin read(f,a[i]);b[(a[i])]:=b[(a[i])]+1; end;
        close(f);
end;
//////////////////////////////////////////////
procedure output;
var f:text;
begin
        assign(f,'LUCKY.OUT');
        rewrite(f);
        write(f,count);
        close(f);
end;
BEGIN
fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),0);
input;
for i:=-10000000 to 10000000 do
        begin
        if (b[i]<>0) and (b[k-i]<>0) and (i<(k-i))then count:=count+(b[i]*b[k-i]);
        if (b[i]<>0) and (b[-k-i]<>0) and (abs(i)<abs(-k-i))then count:=count+(b[i]*b[-k-i]);
        if (i=k div 2) and (b[i]>1) then count:=count+(b[i]-1)*b[i] div 2 ;
        end;
output;
END.

