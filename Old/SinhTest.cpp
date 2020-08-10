#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <random>       
#include <chrono>  

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

const ll N = 10;
const ll lN = 1;
const ll A  = 1000;

int main ()
{
    srand(time(NULL));
    freopen ("GAMENUM.INP", "w", stdout);
    ll n = Rand (lN, N);
    cout << n << endl;
    for (int i = 0; i < n; ++i){
        ll a = Rand (-A, A);
        cout << a << endl;
    }
    Sleep (1000);
    return 0;    
}
