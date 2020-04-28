#include <iostream>

using namespace std;

int n, a, b, tmp, count, ans = 1e9 + 7;

int main ()
{
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
    while (tmp < n)
    {
        count++;
        tmp = count * b;
    }
    while (tmp > n)
    {
        tmp -= (b - a);
    }
    if (n % b == 0) ans = min (ans, n / b);
    if (tmp == n) ans = min (ans, count);
    if (n % a == 0) ans = min (ans, n/a);
    cout << ((ans == 1e9 + 7) ? -1 : ans);
    return 0;
}