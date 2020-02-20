#include <fstream>
#include <stdlib.h>
#include <time.h>

#define fi "AB.INP"

using namespace std;

long long random(long long n) {
    return rand()%n;
}

long long M = 1e18;

int main()
{
    srand(time(NULL));

    fstream f;
    f.open(fi,ios::out);
    long long a, b, c, d;
    c = random(1);
    d = random(1);
    a = random(M);
    b = random(M);
    if (c == 0) a = -a;
    if (d == 0){
        b = -b;
        f << a << b;
    }
    else f << a << '+' << b;
    f.close();
}


