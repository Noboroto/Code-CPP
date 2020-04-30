#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int const N = 1e6;
int n, k, result, a[N];
map <int, int> check;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        check[a[i]]++;
    }
    sort (a, a + n);
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (check[a[i]] <= 0) continue;
        check[a[i]]--;
        int tmp = a[i];
        for (int j = i - 1; j >= 0; --j)
        {
            if (tmp < a[j] + k || check[a[j]] <= 0) continue;
            tmp = a[j];
            check[a[j]]--;
        }
        ans += a[i];
    }
    cout << ans;
    return 0;
}