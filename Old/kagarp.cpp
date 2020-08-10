#include <iostream>

using namespace std;

int n, a, b, tmp, count, ans = -1;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b;
    if (n < a && n < b)
    {
        cout << -1;
        return 0;
    }
    else if (n < a && n > b)
    {
        cout << ((n % b == 0) ? n/b : -1);
        return 0;
    }
    else if (n > a && n < b)
    {
        cout << ((n % a == 0) ? n/a : -1);
        return 0;
    }
    for (int i = (n / b); i >= 0; --i)
    {
        if ((n - i*b) % a == 0) 
        {
            ans = i + ((n - i * b) / a);
            break;
        }
    }
    cout << ((ans == 1e9 + 7) ? -1 : ans);
    return 0;
}