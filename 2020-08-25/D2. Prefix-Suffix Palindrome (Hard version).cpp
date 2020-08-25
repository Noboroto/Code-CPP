#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll oo[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9+ 9277};
const int BASE = 31;
const int N = 1e6 + 1;

ll hashsum[N][4], n, hashKey[N][4];

void Init ()
{
    
}

ll GetHash (const int left, const int right, const ll &hash,const ll &Pow, const ll &oo)
{
    return (hash[right] - (hash[left - 1] * Pow[right - left + 1]) + oo * oo) % oo;
}

int main ()
{
    Init();
    cout ;
    return 0;
};
