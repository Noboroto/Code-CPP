/* 
https://codeforces.com/contest/1133/problem/C
*/

#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
vector <int> a;

int main ()
{
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i) 
    {
        cin >> x;
        a.push_back(x);
    }
    sort (a.begin(), a.end(), greater<int>());
    int i = 0;
    for (int j = 0; j < n; ++j)
    {
        if (a[i] - a[j] > 5) i++;
        ans = max (ans, j - i + 1);
    }
    cout << ans;
    return 0;
}