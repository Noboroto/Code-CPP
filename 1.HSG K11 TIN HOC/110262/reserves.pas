var a:array[0..100,0..100] of integer;
    i,n,j:integer;
    v:longint;
    f,g:text;
function chk(x,y:integer):integer;
var b,u,d,l,r,min:integer;
begin
     b:=a[x,y];
     u:=a[x-1,y];
     min:=u;
     d:=a[x+1,y];
     if min>d then min:=d;
     l:=a[x,y-1];
     if min>l then min:=l;
     r:=a[x,y+1];
     if min>r then min:=r;
     if b<min then exit(min-b)
       else exit(0);
     end;
begin
     assign(f,'reserves.inp');
     reset(f);
     assign(g,'reserves.out');
     rewrite(g);
     fillchar(a,sizeof(a),0);
     readln(f,n);
     for i:=1 to n do
        begin
             for j:=1 to n do read(f,a[i,j]);
             readln(f);
        end;
     v:=0;
     for i:=1 to n do
        for j:=1 to n do
           v:=v+chk(i,j);
     writeln(g,v);
     close(g);
end.