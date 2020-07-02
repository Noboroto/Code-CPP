#include <bits/stdc++.H>

using namespace std;

void Init ()
{
    const string FileINP = "FROGS" + (string)".INP";
    const string FileOUT = "FROGS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int oo = 1e9 + 1;
const int N = 1e6 + 1;
int n, H[N], J[N];

void GetData ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &H[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &J[i]);
    }
}

void Bruce_Force_1e4 ()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (J[j] == 0) continue;
            if (H[i] <= H[j]) continue;
            H[j] = H[i];
            J[j]--;
        }
    }
}

int main ()
{
    Init();
    GetData();
    Bruce_Force_1e4();
    for (int i = 1; i <= n; ++i)
    {
        if (J[i] > 0) cout << -1 << ' ';
        else cout << H[i] << ' ';
    }
    return 0;
}