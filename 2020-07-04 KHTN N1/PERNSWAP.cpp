#include <bits/stdc++.h>

using namespace std;

const int N = 10 + 1;
int n, c, a[N], u, v, Position[N];
bool Checked[N];

int Counter ()
{
    int ab[N],  ans = 0, pos[N];
    for (int i = 0; i <= n; ++i)
    {
        ab[i] = a[i];
        pos[ab[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {   
        if (ab[i] == i) continue;
        ans++;
        pos[ab[i]] = pos[i];
        swap (ab[i], ab[pos [i]]);
        pos[i] = i;
    }
    return ans;
}

void Solve ()
{

}

int main ()
{    
    scanf ("%d%d",&n, &c);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &a[i]);
    }
    if (n > 0)
    {
        for (int i = 0; i < c; ++i)
        {
            scanf ("%d%d", &u, &v);
            swap (a[u], a[v]);
            cout << Counter();
        }
    }
    else
    {
    }
    return 0;
}