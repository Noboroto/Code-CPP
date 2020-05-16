#include <iostream>

using namespace std;

int const N = 1e5 + 7;
long long a[N], k, m, n;

long long Get (long long x)
{
    long long ans = 0; 
    for (int i = 1; i <= m; ++i)
    {
        ans += min (x / i, n);
    }
    return ans;
}

long long Binary_search ()
{
    int first = 1, last = m*n, mid = (first + last) / 2;
    while (first < last)
    {
        mid = (first + last) / 2;
        if (Get (mid) >= k) last = mid;
        else first = mid + 1;
    }
    return first;
}

int main ()
{
    cin >> m >> n >> k;
    cout << Binary_search();
    return 0;
}