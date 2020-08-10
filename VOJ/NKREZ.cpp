#include <bits/stdc++.h>

using namespace std;

/*
    https://codeforces.com/group/FLVn1Sc504/contest/274825/problem/K
*/

const int N = 30000 + 1; // 30000

struct Meeting
{
    int Start, End;
    Meeting(int s = 0, int e = 0)
    {
        Start = s;
        End = e;
    }
    bool operator < (const Meeting &m)
    {
        if (End < m.End) return true;
        if (End > m.End) return false;
        if (Start < m.End) return true;
        return false;
    }
};

int n, f[N], ans = 0, mini = N, maxi = 0;
Meeting a[N];


int main ()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].Start >> a[i].End;
        mini = min (mini, a[i].End);
        maxi = max (maxi, a[i].End);
    }
    sort (a, a + n);
    int i = 0;
    for (int t = mini; t <= maxi; ++t)
    {
        f[t] = f[t - 1];
        while (t == a[i].End)
        {
            f[t] = max (f[t], a[i].End - a[i].Start + f[a[i].Start]);
            i++;
            if (i == n) break;
        }
    }
    cout << f[maxi];
    return 0;
}