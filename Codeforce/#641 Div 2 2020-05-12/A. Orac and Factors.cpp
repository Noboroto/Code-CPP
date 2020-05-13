#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e6 + 1;
int MinDiv[N];

void Init ()
{
    for (int i = 2; i < N; ++i)
    {
        if (MinDiv[i] != 0) continue;
        for (int j = i; j < N; j+= i)
        {
            if (MinDiv[j] != 0) continue;
            MinDiv[j] = i;
        }
    }
}

int n, k, t;

int main ()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);
    Init();
    cin >> t;
    for (int j = 0; j < t; ++j)
    {
        cin >> n >> k;    
        if (MinDiv[n] == n)
        {
            n += (n + (k - 1) * 2);
        }
        else 
        {
            n += (MinDiv[n] + (k - 1) * 2);
        }
        cout << n << '\n';
    }
    return 0;
}