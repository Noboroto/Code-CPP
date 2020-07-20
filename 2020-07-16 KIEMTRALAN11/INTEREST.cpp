#include <bits/stdc++.h>

using namespace std;

void Init()
{
    const string FileINP = "INTEREST" + (string) ".INP";
    const string FileOUT = "INTEREST" + (string) ".OUT";
    freopen(FileINP.c_str(), "r", stdin);
    //freopen(FileOUT.c_str(), "w", stdout);
}

const int N = 10 + 1;
int n, s, pos[N];
pair <int,int> a[N];

int main()
{
    Init();
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &pos[i]);
        pos[i] += pos[i - 1];
        a[i] = make_pair (pos[i], -i);
    }
    sort (a, a + n + 1);
    for (long long i = 1; i <= n; ++i)
    {

    }
    return 0;
}