#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "LAND" + (string)".INP";
    const string FileOUT = "LAND" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e4 + 1;
long long n, X, Y, Z;
vector <long long> a, b;
long long f[N][N];

void Prepare ()
{
    cin >> n >> X >> Y >> Z;
    int x, y;
    a.push_back(0);
    b.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        for (int j = 0; j < x; ++j) a.push_back(i);
        for (int j = 0; j < y; ++j) b.push_back(i);
    }
    for (int i = 0; i < max (a.size(), b.size()); ++i)
    {
        f[0][i] = i * X;
        f[i][0] = i * Y;
    }
}

int main ()
{
    Init();
    Prepare();
    for (int i = 1; i < a.size(); ++i)
    {
        for (int j = 1; j < b.size(); ++j)
        {
            f[i][j] = min (Y + f[i - 1][j],
            min  (X + f[i][j - 1],
             f[i - 1][j - 1] + Z * abs (a[i] - b[j])));
        }
    }
    cout << f[a.size() - 1][b.size() - 1];
    return 0;
}