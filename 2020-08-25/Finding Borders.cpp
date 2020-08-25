/*
https://cses.fi/problemset/task/1732
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 1;
const ll oo[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9+ 9277};
const int BASE = 31;

string s;
ll hashnum[N][4], Pow[N][4];
int n;
bool AC;

void Init ()
{
    cin >> s;
    n = s.length();
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (i == 0)
            {
                Pow[i][j] = 1;
            }
            else
            {
                Pow[i][j] = (Pow[i - 1][j] * BASE) % oo[j];
            }
            if (i == 0) continue;
            hashnum[i][j] = (hashnum[i - 1][j] * BASE + (s[i - 1] - 'a' + 1)) % oo[j];
        }
    }
}

bool Check(const int left, const int &right, const int &j, const ll &t)
{
    return ((hashnum[right][j] - (hashnum[left - 1][j] * Pow[right - left + 1][j]) + oo[j] * oo[j]) % oo[j]) == t;
}

int main ()
{
    Init();
    for (int i = 1; i < n; ++i)
    {
        AC = true;
        for (int j = 0; j < 4; ++j)
        {
            AC &= (Check(n - i + 1, n, j, hashnum[i][j]));
        }
        if (AC) cout << i << " ";
    }
    return 0;
}