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
    int ans = -1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (mid < x) l = mid + 1;
        if (x <= mid)
        {
            if (check[mid] > 0) ans = min (ans, mid);
            r = mid - 1;
        }
    }
    sort (a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {

    }
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
    
    return 0;
}