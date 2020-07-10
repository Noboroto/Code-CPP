#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "DG" + (string)".INP";
    const string FileOUT = "DG" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e6 + 1;
pair <int, int> a[N], b[N], obj[2*N];
int n;
long long sum = 0;
bool Checked [N];

int main ()
{
    Init();
    scanf ("%d", &n);
    int u, v;
    for (int i = 0; i < 2*n; ++i)
    {
        scanf ("%d %d", &u, &v);
        a[i] = make_pair (u, i);
        b[i] = make_pair (v, i);
        obj[i] = make_pair (u, v);
    }
    sort (a, a + 2*n);
    sort (b, b + 2*n);
    for (int i = 0; i < n; ++i)
    {
        sum += a[i].first;
        Checked[a[i].second] = true;
    }
    int j = n - 1;
    int t = 0;
    for (int i = 0; i < 2*n; ++i)
    {
        if (Checked[b[i].second] && obj[b[i].second].first < b[i].first)
        {
            
        }
    }
    return 0;
}