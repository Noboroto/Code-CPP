#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
typedef long long ll;
const int maxn=100002;
ll a[maxn];
int n;
ll K;
void enter()
{
    cin>>n>>K;
    _for(i,1,n+1) {
        cin>>a[i];
    }
}
void solve()
{
    ll ans=0;
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;)
    {
        int pos1=upper_bound(a+1,a+n+1, a[i]) - a, pos2=lower_bound(a+1,a+n+1, a[i]) - a;
        ll sum1=ll(pos1) - ll(pos2);
        int pos3=upper_bound(a+1,a+n+1, K - a[i]) - a, pos4= lower_bound(a+1,a+n+1, K - a[i]) - a;
        ll sum2=ll(pos3) - ll(pos4);
        if (pos3!=pos4){
            if (K-a[i]!=a[i])
                ans+=(sum1*sum2);
            else ans+=(sum1*(sum1-1));
        }
        pos3=upper_bound(a+1,a+n+1, (-1)*K - a[i]) - a;
        pos4=lower_bound(a+1, a+n+1, (-1)*K - a[i]) - a;
        sum2=ll(pos3) - ll(pos4);
        if (pos3!=pos4)
        {
            if ((-1)*K - a[i]!=a[i])
                ans+=(sum1*sum2);
            else ans+=(sum1*(sum1-1));
        }
        i=pos1;
    }
    if (K!=0) cout<<ans/2;
    else cout<<ans/4;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("lucky.inp","r",stdin);
    freopen("lucky.out","w",stdout);
    enter();
    solve();
}
