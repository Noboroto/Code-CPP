#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, result;
vector <int> a;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort (a.begin(), a.end());
    long long ans = 0;
    int j = n - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] + k <= a[j])j--;
        else ans += a[i];
    }
    cout << ans;
    return 0;
}