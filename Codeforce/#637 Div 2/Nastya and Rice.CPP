#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
}

int t, a, b, c, d, n;

int main ()
{
    Init();
    cin >> t;
    for (; t > 0; --t)
    {
        cin >> n >> a >> b >> c >> d;
        int mina = n *(a - b);
        int maxa = n *(a + b);
        int minc = c - d;
        int maxc = c + d;
        if (max (mina, minc) <= min (maxa, maxc)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}