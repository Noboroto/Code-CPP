#include <bits/stdc++.h>

using namespace std;

const int N = 10;
int n;
int c[N];

void Init ()
{
    int t, x, j = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> x;
        if (i == 0 || x != c[j - 1])
        {
            c[j] = x;
            j++;
        } 
    }
    n = j;
}

int main ()
{
    Init();
    for(int i : c) cout << i << ' ';
    return 0;
}