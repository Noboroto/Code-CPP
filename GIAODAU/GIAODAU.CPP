#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    int n;
    vector <int> a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back (x);
    }
    sort (a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b.push_back (x);
    }
    sort (b.begin(), b.end());
    int ans = 0, i = 0, j = 0;
    while (i < n && j < n)
    {
        if (a[i] < b[j]) {
            ans++;
            i++;
            j++;
        } else j++;
    }
    cout << ans;
    return 0;
}