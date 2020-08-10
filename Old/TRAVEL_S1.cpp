#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

const ll N = 20;
const ll S = 1e5;
const ll A = 1e9;

int main ()
{
    srand(time(NULL));
    freopen ("TRAVEL.INP", "w", stdout);
    ll n = Rand (0, N);
    ll s = Rand (0, S);
    cout << n << ' ' << s;
    for (int i = 0; i < n; ++i){
        ll a = Rand (-A, A);
        cout << a << endl;
    }
    Sleep (1000);
    return 0;    
}
