#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main (){
    freopen ("DACO.INP", "r", stdin);
    freopen ("DACO.OUT", "w", stdout);
    int n, x, ans, k;
    ans = 0;
    int trace [1000], locate [1000];
    vector <int> a, tmp, b;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x;
        a.push_back (x);
        b.push_back (1e9 + 7);
    }
    for (int i = 0; i < n;++i){
        x = a[i];
        k = lower_bound (b.begin(),b.end(), x) - b.begin ();
        b[k] = x; 
        locate[k] = i;
        trace [i] = (k > 0) ? locate[k - 1] : -1;
        ans = max (ans, k + 1);
    }
    x = locate[ans - 1];
    tmp.push_back(x);
    while (x != -1)
    {
        x = trace [x];
        tmp.push_back (x);
    }
    cout << ans << endl;
    while (!tmp.empty())
    {
        cout << a [tmp.back()] << ' ';
        tmp.pop_back();
    }
    return 0;
}