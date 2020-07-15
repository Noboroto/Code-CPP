#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "BLOG" + (string)".INP";
    const string FileOUT = "BLOG" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e5 + 1;
int n, m, r, k, ansa = -1, ansb = -1;
int a, b, Ron[N], Harry[N];
bool Checked [N];

int main ()
{
    Init();
    scanf ("%d %d %d %d", &n, &m, &k, &r);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d %d", &a, &b);
        Ron[i] = Ron[i-1] + ((a != 0 && b != 0) ? 0 : a);
        Harry[i] = Harry[i-1] + ((a != 0 && b != 0) ? 0 : b);
        Checked [i] = (a != 0 && b != 0); 
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ansa != -1 && ansb != -1) break;
        if (m >= k) 
        {
            if (!Checked[i]) continue;
            for (int j = i + (m - k); j <= n && !Checked[j]; ++j)
            {
                if (Harry[j] - Harry[i - 1] > (m - k) && ansb == -1)
                {
                    ansb = j;
                    break;
                }
                if (Ron[j] - Ron[i - 1] > (m - k) && ansa == -1)
                {
                    ansa = j;
                    break;
                }
            }
        }
        if (m < k)
        {
            if (r - Ron[i] + Harry[i] > m && ansb == -1) ansb = i;
            if (r - Ron[i] + Harry[i] < -m && ansa == -1) ansa = i;
        } 
    }
    printf ("%d %d", ansb, ansa);
    return 0;
}