var i, j: integer;
    IsPrime: array [1..100] of boolean;

BEGIN
    for i := 1 to 100 do IsPrime[i] := true;
    for i := 2 to 100 do begin
        if IsPrime[i] = true then begin
            j := 2;
            repeat
                IsPrime[i*j] := false;
                j := j + 1;
            until (i*j > 100);
        end;
    end;
    for i := 2 to 100 do if IsPrime[i] = true then write (i, ' ');
END.