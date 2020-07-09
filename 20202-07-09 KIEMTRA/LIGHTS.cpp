#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "LIGHTS" + (string)".INP";
    const string FileOUT = "LIGHTS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 35 + 1, M = 595 + 1;
int ans = 1e9 + 7, n, m,Head[N];
bool On_Off[N], Went[N];
pair <int, int> Path[M*2];

void GetData ()
{
    scanf ("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        scanf ("%d %d", &u, &v);
        Path[i] = make_pair(u, v);
        Path[i + m] = make_pair (v, u);
        Head[u]++;
        Head[v]++;
    }
    for (int i = 1; i <= n; ++i) Head[i] += Head[i - 1];
    sort (Path, Path + 2*m);
}

void Reverse (int counter, int i)
{
    if (counter == 0)
    {
        ans = min (ans, i + 1);
        return;
    }
    if (i >= n) return;
    for (int t = 1; t <= n; ++t)
    {
        if (Went[t]) continue;
        Went[t] = true;
        On_Off[t] = true;
        counter--;
        for (int j = Head[t - 1]; j < Head[t]; ++j) 
        {
            if (On_Off[Path[j].second])
            {
                On_Off[Path[j].second] = false;
                counter++;
            } 
            else
            {
                On_Off[Path[j].second] = true;
                counter--;
            }
        }
        Reverse (counter, i + 1);
        for (int j = Head[t - 1]; j < Head[t]; ++j) 
        {
            if (On_Off[Path[j].second])
            {
                On_Off[Path[j].second] = false;
                counter--;
            } 
            else
            {
                On_Off[Path[j].second] = true;
                counter++;
            }
        } 
        On_Off[t] = false;
        counter++;
    }
}

int main ()
{
    Init();
    GetData();
    Reverse (n, 0);
    printf("%d", ans);
    return 0;
}