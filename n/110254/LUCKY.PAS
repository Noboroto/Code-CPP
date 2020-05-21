VAR F1:TEXT;
VAR N,J,I,K,D:INTEGER;
A:ARRAY[1..200] OF INTEGER;
BEGIN
        ASSIGN(F1,'LUCKY.INP');
        RESET(F1);
        READ(F1,N,K);
        FOR I:=1 TO N DO
        READ(F1,A[I]);
        CLOSE(F1);
        FOR I:=1 TO N DO
        FOR J:=1 TO N-I DO
        IF A[I] + A[I+J] = K THEN D:=D+1;
        ASSIGN(F1,'LUCKY.OUT');
        REWRITE(F1);
        WRITELN(F1,D);
        CLOSE(F1);
END.