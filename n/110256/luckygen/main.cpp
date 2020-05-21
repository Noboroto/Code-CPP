#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn=100001;
typedef long long ll;
ll a[maxn];
int n;
ll K;
int main()
{
    srand(int(time(0)));
    K=rand()%100;
    n=100000;
    freopen("d:/chambai/lucky.inp","w",stdout);
    cout<<n<<" "<<K<<"\n";
    _for(i,1,n+1)
    {
        int sig=rand()%2;
        if (sig==0) cout<<rand()%100<<" ";
        else cout<<(-1)*rand()%100<<" ";
    }
}
