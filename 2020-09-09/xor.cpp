#include <iostream>
 
using namespace std;
 
long long a, n;
 
int main ()
{
    freopen ("xor.INP", "r", stdin);
    freopen ("xor.OUT", "w", stdout);
    cin >> a >> n;
    long long x , y;
    x = (a / n) * n;
    y = x + n;
    cout << min (a ^ x, a ^ y);
    return 0;
}