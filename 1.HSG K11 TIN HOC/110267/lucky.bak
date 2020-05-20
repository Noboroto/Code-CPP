const fi='lucky.inp';
      fo='lucky.out';

var n,i,j:longint;
    k,d:int64;
    f:array[1..10000,1..10000] of integer;
    a:array[1..100000] of int64;



procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;


BEGIN
assign(input,fi); reset(input);
assign(output,fo);rewrite(output);

read(n,k);
for i:=1 to n do
read(a[i]);
sort(1,n);
        for i:=1 to n do
        begin
                for j:=i+1 to n do
                begin
                //g:=(l+r) div 2;
                if ((a[j]+a[i]=k) and (f[i,j]=0)) then    begin
                                                                inc (d);
                                                                f[i,j]:=1;
                                                        end;
                end;
        end;

write(d);

END.