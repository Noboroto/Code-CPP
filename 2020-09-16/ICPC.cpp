#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("ICPC.INP", "r", stdin);
    freopen ("ICPC.OUT", "w", stdout);
}

string s;
int n, x, i, p;
vector <pair <int, int> > a;

int main ()
{
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        cin >> x;
        a.push_back(make_pair(x, i));
    }
    s = "";
    x = 0, i = 0;
    sort(a.begin(), a.end());
    while (i < n)
    {
        x += a[i].first;
        p += x;
        if (x > 300)
        {
            p -= x;
            x -= a[i].first;
            break;
        }
        s += (char)(a[i].second + 'A');
        ++i;
    }
    cout << i << " " << p << " " << x << "\n" << s;
    return 0;
}