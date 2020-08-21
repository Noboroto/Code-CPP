#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
int n, f[N], index[N], tmp[N], x, k, fsize = 1;
int trace[N];

int main()
{
    const string FileINP = "LIStrace" + (string)".INP";
    const string FileOUT = "LIStrace" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
    cin >> n;
    f[0] = -1e9 - 7;
    index[0] = -1;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        k = lower_bound(f ,f + fsize, x) - f;
        f[k] = x;
        index[k] = i + 1;
        trace[i + 1] = index[k - 1];
        fsize += (k >= fsize);
    }
    fsize--;
    cout << fsize << '\n';
    tmp[fsize] = index [fsize];
    x = trace[tmp[fsize]];
    k = fsize;
    while (x != -1)
    {
        fsize--;
        tmp[fsize] = x;
        x = trace[x];
    }
    for (int i = 1; i <= k; ++i) cout << tmp[i] << ' ';
    return 0;
}
