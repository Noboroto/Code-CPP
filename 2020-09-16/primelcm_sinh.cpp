#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("primelcm.INP", "w", stdout);
}

long long GetRand (long long minval, long long maxval)
{
    return (rand () % (maxval - minval + 1) + minval);
}

int main ()
{
    Init();
    srand(time(0));
    long long n = GetRand(1, 1e5);
    cout << n << "\n"; 
    for (int i = 0; i < n; ++i)
        cout << GetRand(1, 1e7) << " ";
    return 0;
}