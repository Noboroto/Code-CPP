#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
int n;
pair <int, int>  Meet [2*N];

void GetDate ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d %d", &Meet[i].first, &Meet[i + n].first);
        Meet[i].second = 1, Meet[i + n].second = -1;
    }
    sort (Meet, Meet + 2*n);
}

int Proccess (int &n)
{
    int Counter = 0, ans = 0;
    for (int i = 0; i < 2*n; ++i)
    {
        Counter += Meet[i].second;
        ans = max (ans, Counter);
    }
    return ans;
}

int main ()
{
    GetDate();
    printf ("%d", Proccess (n));
    return 0;
}