#include <bits/stdc++.h>

using namespace std;

void Init ()
{
}

int main ()
{
    Init();
    string s1 = "", s2 = "", s = "";
    fstream f;
    f.open("ZERO.ANS");
    while (!f.eof())
    {
        getline(f, s);
        s1 += s;
    }
    f.close();
    f.open ("ZERO.ANS");
    while (!f.eof())
    {
        getline(f, s);
        s2 += s;
    }
    for (int i = 0; i < max (s1.length(), s2.length ()); ++i) if (s1[i] != s2[i]) cout << i << '\n';
    return 0;
}