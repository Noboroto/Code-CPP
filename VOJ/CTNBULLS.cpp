#include <bits/stdc++.h>

using namespace std;
/*
    AC  
    https://codeforces.com/group/FLVn1Sc504/contest/274811/problem/C
*/

const int N = 1e5 + 1;
const int oo = 2111992;
typedef long long ll;

int n, k;
ll f[N][2];

void Init ()
{
    cin >> n >> k;
    k++;
}

int main ()
{
    Init();
    f[0][0] = 1;
    f[0][1] = 1;
    for (int i = 1; i < n; ++i)
    {
        f[i][0] = (f[i - 1][0] + f[i - 1][1]) % oo;
        if (i < k)
        {
            f[i][1] = 1;
        }
        else
        {
            f[i][1] = (f[i - k][0] + f[i - k][1]) % oo;
        }
    }
    n--;
    cout << (f[n][0] + f[n][1]) % oo;
    return 0;
}