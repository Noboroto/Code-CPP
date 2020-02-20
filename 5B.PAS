var i, n: longint;
    tmp, ans: double;
    giaithua: int64;
begin
    readln (n);
    i := 1;
    ans := 1;
    giaithua := 1;
    tmp := 1;
    while (tmp < 2*1000000) do begin
        giaithua := giaithua*i;
        tmp := 1 / giaithua;

    end;
end.