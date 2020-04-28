#include <iostream>

using namespace std;

int n, a, b, tmp, count;

int main ()
{
    cin >> n >> a >> b;
    tmp = 1;
    count = 0;
    while (tmp < n)
    {
        count++;
        tmp = count * max(a,b);
    }
    while (tmp > n)
    {
        tmp -= (abs(a - b));
    }
    if (tmp == n) cout << count;
    else cout << -1;
    return 0;
}