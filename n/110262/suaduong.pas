type mang=array[1..1000] of longint;
var a,b,c,d:mang;
    i,n,m,x:longint;
    f,g:text;
procedure swt(var x,y:longint);
begin
     x:=x+y;
     y:=x-y;
     x:=x-y;
end;
procedure sort;
var i,j:longint;
begin
     for i:=1 to m-1 do
        for j:=i+1 to m do
           if a[i]>a[j] then
             begin
                  swt(a[i],a[j]);
                  swt(b[i],b[j]);
                  swt(c[i],c[j]);
             end;
end;
begin
     assign(f,'suoduong.inp');
     reset(f);
     assign(g,'suoduong.out');
     rewrite(g);
     readln(f,n,m);
     for i:=1 to m do readln(f,a[i],b[i],c[i]);
     sort;
     fillchar(d,sizeof(d),0);
     for i:=1 to m do
        begin
             x:=d[a[i]]+c[i];
             if x>d[b[i]] then d[b[i]]:=x;
        end;
     writeln(g,d[n]);
     close(g);
end.

