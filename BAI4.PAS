program BAI4;

var s, s1: string;
    i, x: integer;
    Enter: array [1..300] of boolean; 
    f, g: text;

BEGIN
    for i := 1 to n do Enter [i] := false;
    assign (f, 'C:\f.txt');
    assign (g, 'C:\g.txt');
    reset (f);
    rewrite (g);
    s1 := '';
    x := 1;
    while not eof (f) do begin
        readln (f, s);
        s1 := s1 + s;
        Enter [length(s1)] := true;
    end;
    for i := length (s1) downto 1 do begin
        write (g, s1[i]);
        if (Enter [i] = true) then writeln (g);
    end;
    close (f);
    close (g);
END.