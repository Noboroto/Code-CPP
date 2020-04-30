#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void Init ()
{
    const string FileINP = "BUBE " + (string)".INP";
    const string FileOUT = "BUBE " + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 1e6;
int n, k, result, check[N];
vector <int> a;

int FindUpper (int l, int r, int x)
{
    int ans = 1e9+7;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] < x) l = mid + 1;
        if (x <= a[mid])
        {
            if (check[a[mid]] > 0) ans = min (ans, mid);
            r = mid - 1;
        }
    }
    ans = (ans == 1e9 + 7) ? -1 : ans;
    return ans;
}

int main ()
{
    Init();
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
        check[x]++;
    }
    sort (a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int sum = a[i];
        check[a[i]]--;
        int tmp = FindUpper (i + 1 , n - 1, a[i] + k);
        while (tmp != -1)
        {
            check[a[tmp]]--;
            sum = a[tmp];
            tmp = FindUpper (tmp + 1, n - 1,a[tmp] + k);
        }
        ans += sum;
    }
    cout << ans;
    return 0;
}