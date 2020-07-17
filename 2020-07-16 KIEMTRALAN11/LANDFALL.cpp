#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "LANDFALL" + (string)".INP";
    const string FileOUT = "LANDFALL" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 5e3 + 1;
int ans = 0, dis = 0;
int n, a[N], j;
map <int, int> Checked;

int main ()
{
    Init();
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d", &a[i]);
        Checked[a[i]] = 1;
    }
    sort (a, a + n);
    for (int i = 1; i < n; ++i)
    {
        if (Checked[a[i]] == -1) continue;
        dis = a[i] - 1;
        j = a[i] + dis;
        ans++;
        while (j <= a[n - 1] && Checked[j] != 0)
        {
            Checked[j] = -1;
            j += dis;
        }
    }
    printf ("%d", ans);
    return 0;
}