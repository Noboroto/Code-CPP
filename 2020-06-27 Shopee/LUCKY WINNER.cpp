#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int oo = 1e18;
int dp[1005][1005][8];
int a[1005][3]; 
int n,k;

void opti(int &a, int b)
{
    if (a < b) a = b;
}

int getbit(int x, int i)
{
    return (x >> i) & 1;
}

int solve(int i, int kk, int pre)
{   
    if (kk < 0) return -oo;
    int &res = dp[i][kk][pre];
    if (i > n) 
    {
        if (!kk) return 0;
        return -oo; 
    }
    if (res != -oo) return res;
    // khong chon
    opti(res, solve(i + 1, kk, 0));
    // 1 hang ngang
    for (int j = 0; j <= 1; j++)
    {
        int cur = (1 << j) + (1 << (j + 1));
        int bonus = a[i][j] + a[i][j + 1];
        opti(res, solve(i + 1, kk - 1, cur) + bonus);
    }
    // 1 hang doc 
    for (int j = 0; j <= 2; j++)
    {
        if (getbit(pre, j)) continue;
        int cur = 1 << j;
        int bonus = a[i][j] + a[i - 1][j];
        opti(res, solve(i + 1, kk - 1, cur) + bonus);
    }
    // 2 hang doc
    for (int j = 0; j <= 2; j++)
    for (int jj = j + 1; jj <= 2; jj++)
    {
        if (getbit(pre, j) || getbit(pre, jj)) continue;
        int cur = (1 << j) + (1 << jj);
        int bonus = a[i][j] + a[i - 1][j] + a[i][jj] + a[i - 1][jj];
        opti(res, solve(i + 1, kk - 2, cur) + bonus);
    }
    // 1 hang ngang 1 hang doc
    if (!getbit(pre, 0)) 
    {
        int cur = 7;
        int bonus = a[i][0] + a[i - 1][0] + a[i][1] + a[i][2];
        opti(res, solve(i + 1, kk - 2, cur) + bonus);
    }
    if (!getbit(pre, 2))
    {
        int cur = 7;
        int bonus = a[i][2] + a[i - 1][2] + a[i][1] + a[i][0];
        opti(res, solve(i + 1, kk - 2, cur) + bonus);
    }
    // 3 hang doc 
    if (!pre)
    {
        int cur = 7;
        int bonus = a[i][0] + a[i][1] + a[i][2] + a[i - 1][0] + a[i - 1][1] + a[i - 1][2];
        opti(res, solve(i + 1, kk - 3, cur) + bonus);
    }
    return res;
}

signed main ()
{
    const string FileINP = "file" + (string)".INP";
    const string FileOUT = "LUCKY WINNER" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 2; j++)
    {
        cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
    for (int k = 0; k <= 7; k++)
    {
        dp[i][j][k] = -oo;
    }
    cout << solve(1, k, 7);
    return 0;
}