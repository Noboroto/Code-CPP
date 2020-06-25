#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "TRAPEZOIDIS" + (string)".INP";
    const string FileOUT = "TRAPEZOIDIS" + (string)".OUT";
    //freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 10000 + 1;
int n;
pair <int, int> Line[N];

void GetData ()
{
    scanf ("%d",&n);
    int x1, x2, y1, y2;
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 > x2) swap (x1, x2);
        if (y1 > y2) swap (y1, y2);
        Line[i].first = (x1 + y1) / 2;
        Line[i].second = (x2 + y2) / 2;
    }
    sort (Line, Line + n);
}

int Process (int &n)
{
    int Count = n, ans = 1;
    bitset <N> Check;
    Check.set();
    while (Count > 0)
    {
        int index = -1, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!Check[i]) continue;
            if (index == -1 || Line[index].second < Line[i].first)
            {
                index = i;
                Check [i] = 0;
                Count--;
                sum++;
            }
        }
        ans = max (ans, sum);
    }
    return ans;
}

int main ()
{
    Init();
    int t, ans = 0;
    scanf ("%d", &t);
    scanf ("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        GetData();
        ans = Process (n);
        printf ("%d \n", ans);
    }
    return 0;
}