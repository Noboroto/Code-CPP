var Mx, My: array [1..100] of integer;
    i, n: integer;
    result: real;

function So_sanh(x, y: integer) : integer;
begin
    if (Mx[x] < Mx[y]) then exit 1
    else exit -1;
end;

procedure Doi_cho(x, y: intenger);
var a: integer;
begin
    a := Mx[x];
    Mx[x] := Mx[y];
    Mx[y] := a;
    a := My[x];
    My[x] := My[y];
    My[y] := a;
end;

procedure Sap_xep(n: integer);
var i, j: integer;
begin
    for i := 1 to n do begin
        for j := 1 to n do begin
            if (So_sanh(i, j) = -1) then Doi_cho(i, j); 
        end;
    end;
end;

function abs (x: integer): integer;
begin
    if (x >= 0) then exit x;
    else exit -x;
end;

function Dien_tich (x, y: integer): real;
var a, b, c, i, j: integer;
begin
    i := abs (Mx[x] - Mx[y]);
    j := abs (My[x] - My[y]);
    a := Mx[x]*Mx[x] + My[x]*My[x];
    b := Mx[y]*Mx[y] + My[y]*My[y];
    c := i*i + j*j;
    exit sqrt (2*(a*a*b*b + a*a*c*c + b*b*c*c) - (a*a*a*a + b*b*b*b + c*c*c*c)) / 4;
end;

BEGIN
    result := 0;
    write ('Co bao nhieu diem? ');
    read (n);
    writeln ('Moi nhap Mx: ');
    for i := 1 to n do begin
        write ('Diem thu ', i, ' co toa do x la: ');
        readln (Mx[i]);
    end;
    writeln ('Moi nhap My:')
    for i := 1 to n do begin
        write ('Diem thu ', i, ' co toa do y la: ');
        readln(My[i]);
    end;
    Sap_xep(n);
    for i := 2 to n do begin
        if (Mx[i] = 0) and (My[i] = 0) then continue;
        result := result + Dien_tich (i - 1, i);
    end;
    writeln ('Dien tich can tim la: ', result:4:4); 
END.