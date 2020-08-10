#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "NDCCARD" + (string)".INP";
    const string FileOUT = "NDCCARD" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e4 + 1;
int a[N], n, m;

int Process (int &n, int &m)
{
    int ans = 0, k = 0;
    for (int i = 0; i < n; ++i)
    {
        k = n - 1;
        for (int j = i + 1; j < n; ++j)
        {
            while (a[i] + a[j] + a[k] > m)
            {
                k--;
            }
            if (k <= j) continue;
            ans = max (ans, a[i] + a[j] + a[k]);
        }
    }
    return ans;
}

int main ()
{
    int x = 0;
    //Init();
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d", &a[i]);
    }
    sort (a, a + n);
    printf ("%d", Process(n, m));
    return 0;
}