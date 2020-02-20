var n, k, i, ans, mau: integer;
    giaithua: array [1..200] of integer;

BEGIN
    read (n);
    read (k);
    if (n <> k) then begin
    	giaithua[1] := 1;
    	for i := 2 to n do begin
        	giaithua[i] := giaithua[i-1]*i;
    	end;
    	mau := giaithua[n-k]*giaithua[k];
    	writeln ('So can tim la: ', (giaithua[n]/mau):4:0);
    end else writeln ('So can tim la: 1');
END.