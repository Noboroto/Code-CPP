#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
    const string FileINP = "SEQMAX" + (string)".INP";
    const string FileOUT = "SEQMAX" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int main ()
{
    Init();
    
    return 0;
}