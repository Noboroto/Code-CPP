program BAI3;

var s: string;
    f1, f2, f3: text;

BEGIN
    assign (f1, 'C:\f1.txt');
    assign (f2, 'C:\f2.txt');
    assign (f3, 'C:\f3.txt');
    reset (f1);
    rewrite (f3);
    while not eof (f1) do begin
        readln (f1, s);
        writeln (f3, s);
    end;
    close (f1);
    close (f3);
    reset (f2);
    rewrite (f1);
    while not eof (f2) do begin
        readln (f2, s);
        writeln (f1, s);
    end;
    close (f1);
    close (f2);
    reset (f3);
    rewrite (f2);
    while not eof (f3) do begin
        readln (f3, s);
        writeln (f2, s);
    end;
    close (f2);
    erase (f3);
END.