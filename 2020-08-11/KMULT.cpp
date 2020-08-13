#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "KMULT" + (string)".INP";
    const string FileOUT = "KMULT" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 1e4 + 1;
int n, k, h[N];
char ams[N];
bool AC = false;

void Prepare ()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
}

void Trau (int pos, long long sum)
{
    if (pos == n && sum != 0 && sum % k == 0)
    {
        cout << 1 << '\n';
        sum = 0;
        for (int i = 1; i < n; ++i)
        {
            cout << ams[i];
            if (ams[i] == '+') sum += h[i];
            else sum -= h[i];
        }
        AC = true;
        //cout << '\n' << sum << ' ' << sum % k;
        return;
    }
    if (pos >= n) return;
    if (AC) return;
    ams[pos] = '+';
    Trau (pos + 1, sum + h[pos]);
    if (AC) return;
    ams[pos] = '-';
    Trau (pos + 1, sum - h[pos]);
}

int main ()
{
    Init();
    Prepare();
    ams[0] = '+';
    Trau(1,h[0]);
    if (!AC) cout << 0;
    return 0;
}