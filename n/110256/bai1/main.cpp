#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
typedef long long ll;
const int maxn=102;
int a[maxn][maxn];
int n,mx;
int rt[maxn*maxn];
int des[maxn*maxn];
int b[maxn*maxn],tr[maxn*maxn];
void enter()
{
    cin>>n;
    _for(i,0,n)
        _for(j,0,n) {
            rt[i*n+j]=-1;
            des[i*n+j]=1;
            cin>>a[i][j];
            mx=max(mx, a[i][j]);
            b[i*n+j]=a[i][j];
        }
}
typedef pair<int,int> pir;
#define fi first
#define se second
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int root(int u)
{
    if (rt[u]==-1) return u;
    else return root(rt[u]);
}
void unite(int aa,int bb)
{
    int rt1=root(aa), rt2=root(bb);
    if (des[rt1]>des[rt2])
    {
        rt[rt2]=rt1;
        des[rt1]+=des[rt2];
        b[rt1]=max(b[rt1], b[rt2]);
    }
    else
    {
        rt[rt1]=rt2;
        des[rt2]+=des[rt1];
        b[rt2]=max(b[rt2], b[rt1]);
    }
}
void _set()
{
    _for(i,0,n)
    {
        tr[i*n]=1;
        tr[i*n+n-1]=1;
        tr[i]=1;
        tr[(n-1)*n+i]=1;
    }
}
bool in_bound(int xx,int yy)
{
    if (xx>=0 && xx<n && yy>=0 && yy<n) return true;
    else return false;
}
void solve()
{
    priority_queue<pir,vector<pir>,greater<pir>> heap;
    _for(i,0,n)
        _for(j,0,n)
            heap.push(pir(a[i][j], i*n+j));
    _for(cnt,1, mx+1)
    {
        while(!heap.empty() && heap.top().fi==cnt)
        {
            pir q=heap.top();
            heap.pop();
            int x=q.se/n, y=q.se%n;
            _for(i,0,4)
            {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if (in_bound(xx,yy)&& a[xx][yy]<=a[x][y] && root(xx*n+yy)!=root(q.se) )
                {
                    int _rt=root(xx*n+yy);
                    if (tr[_rt]==0)
                    {
                        int t=tr[root(q.se)];
                        unite(_rt, q.se);
                        if (t==1)
                            tr[root(q.se)]=1;
                    }
                    else if (tr[_rt]==1)
                        tr[root(q.se)]=1;
                }
            }
        }
    }
    ll ans=0;
    _for(i,0,n)
        _for(j,0,n)
            ans+=ll(b[root(i*n+j)] - a[i][j]);
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("reserves.inp","r",stdin);
    freopen("reserves.out","w",stdout);
    enter();
    _set();
    solve();
}
