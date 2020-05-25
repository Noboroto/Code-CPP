#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
}

int main ()
{
    int n;
    Init();
    cin >> n;
    long long tmp1, tmp2, x, ans;
    for (int i = 0; i < n - 1; ++i) 
    {
        cin >> x;
        if (i == 0) 
        {
            tmp1 = x;
            tmp2 = 0;
            ans = x;
            continue;
        }
        if (i == 1) 
        {
            ans = tmp1 + x;
            tmp2 = ans;
            continue;
        }
        ans = min (tmp1 + x, tmp2 + x);
        tmp1 = tmp2;
        tmp2 = ans;
    }
    cout << ans;
    return 0;
}