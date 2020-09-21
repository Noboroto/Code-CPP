#include <bits/stdc++.h>

using namespace std;

const string NAME = "primelcm";
int n = 100;
fstream a, o, i;

int Check ()
{
    i.open(NAME + ".INP");
    a.open(NAME + ".ANS");
    o.open(NAME + ".OUT");
    long long n, an, on;
    i >> n;
    for (int j = 1; j <= n; ++j)
    {
        n--;
        a >> an;
        o >> on;
        if (an != on) return j;
    }
    return -1;
}

int main ()
{
    int tmp;
    clock_t b;
    freopen ("logs.txt", "w", stdout);
    for (int j = 1; j <= n; ++j)
    {
        b = clock();
        system((NAME + "_sinh.exe").c_str());
        system((NAME + "_trau.exe").c_str());
        system((NAME + ".exe").c_str());
        b = clock() - b;
        if ((double)b / CLOCKS_PER_SEC > 1) 
        {
            cout << "Time limit exceed!! " << (double)b / CLOCKS_PER_SEC << "s\n";
            continue;
        }
        tmp = Check();
        if (tmp == -1)
        {
            cout << "P" << j << " " << (double)b / CLOCKS_PER_SEC << "\n";
        }
        else
        {
            cout << "W" << j << " " << tmp << "\n";
            break;
        }
        i.close();
        a.close();
        o.close();
    }
    return 0;
}