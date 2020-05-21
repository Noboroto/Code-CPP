#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int N = 100 + 1;
const int Step = 8;
const int Dx[Step] = {-1,-1,-1, 0, 0, 1, 1, 1};
const int Dy[Step] = {-1, 0, 1, -1, 1,-1, 0,1};

int n, a[N][N];


void Input ()
{
    int tmp = 0;
    cin >> n;
    for (int i = 0; i <= n + 1; ++i)
    {
        a[0][i] = -1;
        a[i][0] = -1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            tmp = max (tmp, a[i][j]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            ans += (tmp - a[i][j]);
        }
    }
    cout << ans;
}

int main()
{
    freopen("RESERVES.INP", "r", stdin);
    freopen("RESERVES.OUT", "w",stdout);
    Input();
    return 0;
}
