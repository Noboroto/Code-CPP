#include <bits/stdc++.h>

using namespace std;

int n;

int main ()
{
    fstream inpstream, ansstream;
    inpstream.open("MAXV.INP", ios::out);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    n = uniform_int_distribution<int>(2,20)(rng);
    inpstream << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        inpstream << uniform_int_distribution<int>(0,1e2)(rng) << "\n";
    }
    inpstream.close();
    return 0;
}