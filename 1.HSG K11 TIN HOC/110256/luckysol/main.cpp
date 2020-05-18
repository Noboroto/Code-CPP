#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
typedef long long ll;
const int maxn=100001;
ll a[maxn],K;
int n;
void enter()
{
    cin>>n>>K;
    _for(i,1,n+1) cin>>a[i];
}
void solve()
{
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<i; ++j)
            if (abs(a[i] + a[j])==K) ++ans;
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("d:/chambai/lucky.inp","r",stdin);
    freopen("d:/chambai/lucky.ans","w",stdout);
    enter();
    solve();
}
