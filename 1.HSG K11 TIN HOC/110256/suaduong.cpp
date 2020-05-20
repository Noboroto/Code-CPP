#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn=1001;
typedef pair<int,int> pir;
#define fi first
#define se second
vector<pir> g[maxn];
int n,m;
void enter()
{
    cin>>n>>m;
    int u,v,c;
    _for(i,0,m)
    {
        cin>>u>>v>>c;
        g[v].push_back(pir(u,c));
    }
}
int f[maxn];
bool _d[maxn];
int dp(int u)
{
    if (_d[u]==true) return f[u];
    else if (u==1) return 0;
    else
    {
        for(auto i:g[u])
            f[u]=max(f[u], dp(i.fi) + i.se);
        _d[u]=true;
        return f[u];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("suaduong.inp","r",stdin);
    freopen("suaduong.out","w",stdout);
    enter();
    cout<<dp(n);
}
