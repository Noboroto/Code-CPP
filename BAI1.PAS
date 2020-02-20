program BAI1;

var f, g: text;
    s: string;

BEGIN
    assign (f, 'C:\f.txt');
    assign (g, 'C:\g.txt');
    reset (f);
    rewrite (g);
    while not eof (f) do begin
        readln (f, s);
        writeln (g, s);
    end;
    close (f);
    close (g);
END.