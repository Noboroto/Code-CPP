#include <iostream>

using namespace std;

int main () {
    long long m, n;
    cin >> m >> n;
    long long ans = (m%2) * ((n % 2) + (n - n%2)/2);
    m -= (m%2);
    ans += (n%2) * ((m % 2) + (m - m%2)/2);
    n -= (n%2);
    ans += (m*n)/4;
    cout << ans;
    return 0;
}