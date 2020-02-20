program BAI_5;

const fi = 'C:\f.txt';

var f: text;

BEGIN
    assign (f, fi);
    append (f)
    writeln (f,'end');
    close (f);
END.