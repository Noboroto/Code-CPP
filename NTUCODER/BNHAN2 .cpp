#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
}

int const N = 1e5 + 7;
long long a[N], k, m, n;

long long Check (int last)
{
    
    return true;
}

long long Binary_search (long long first, long long last, long long)
{
    
}

int main ()
{
    Init();
    cin >> m >> n >> k;
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            a[count] = i*j;
            count++;
            if (count >= N) break;
        }
    }
    sort (a, a + min (count , N));
    cout << a[k - 1];
    return 0;
}