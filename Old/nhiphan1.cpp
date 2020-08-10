#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

void Init ()
{
    const string FileINP = "nhiphan1" + (string)".INP";
    const string FileOUT = "nhiphan1" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n, k;
vector <int> f;

long long FindLocation (string bit)
{
    long long ans = 0;
    for (int i = 0; i < bit.length(); ++i)
    {
        if (bit[i] == '1')
        {
            ans += f[n - i - 1];
        }
    }
    return ans + 1;
}

void FindBit (int k)
{
    cout << endl;
    for (int i = 1; i <= n; ++i)
    {
        if (k > f[n - i])
        {
            cout << 1;
            k -= f[n - i];
        }
        else cout << 0;
    }
}

int main ()
{
    string bit;
    Init();
    cin >> n;
    cin >> bit;
    cin >> k;
    f.push_back(1);
    for (int i = 1; i <= n; ++i)
    {
        f.push_back(2*f[i-1]);
    }
    cout << FindLocation(bit);
    FindBit(k);
    return 0;
}