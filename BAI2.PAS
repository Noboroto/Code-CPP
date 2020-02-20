program BAI2;

var x: integer;
    f, g1, g2: text;

BEGIN
    assign (f, 'C:\f.txt');
    assign (g1, 'C:\g1.txt');
    assign (g2, 'C:\g2.txt');
    reset (f);
    rewrite (g1);
    rewrite (g2);
    while not eof (f) do begin
        read (f, x);
        if (x mod 2 <> 0) write (g1, x, ' ')
        else write (g2, x, ' ');
    end;
    close (f);
    clsoe (g1);
    close (g2);
END.