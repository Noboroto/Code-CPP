program BAI5;

var f: text;

BEGIN
    assign (f,'C:\f.txt');
    append (f);
    write(f, 'end');
    close (f);
END.