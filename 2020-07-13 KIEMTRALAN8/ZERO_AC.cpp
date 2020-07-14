#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


const int maxn = 1e6;
int f[1000005];
bool c[1000005];
vector <int> d[1000005];
int n;


void pre()
{


    for (long long i = 1; i <= maxn; i++)
    {
        for (long long j = i*i; j <= maxn; j+=i)
            d[j].push_back(max(i,j/i));
    }
}


int tryyy(int x)
{
    if (x == 0) return 0;
    if (c[x]) return f[x];
    int tmp = x;
    for (int o:d[x])
    if (o != x)
        tmp = min(tmp,tryyy(o)+1);
    tmp = min(tmp,tryyy(x-1)+1);
    c[x] = true;
    f[x] = tmp;
    return tmp;
}


void inp()
{
    for (int i = 0; i <= 1e6; ++i) cout << tryyy(i) << '\n';
}


int main()
{
    freopen("zero.inp","r",stdin);
    freopen("zero.ans","w",stdout);
    pre();
    int q;
    inp();
    return 0;
}
