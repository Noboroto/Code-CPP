#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define maxn 100
#define fii(i,a,b) for(i=a;i<=b;i++)
#define f first
#define s second
#define ll long long
#define pii pair<ll,ll>
int n,m,i,j,u,v,z,q,s,f,adj[maxn],head[maxn],trace[maxn],fre[maxn],x[maxn],y[maxn],t[maxn];

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("SUADUONG.INP","r",stdin);
    //freopen("SUADUONG.OUT","w",stdout);
    memset(adj,0,sizeof(adj));
    memset(head,0,sizeof(head));
    memset(trace,0,sizeof(trace));
    memset(fre,1,sizeof(fre));
}
void nhap()
{
    cin >> n >> m;
    fii(i,1,m){
        cin >> u >> v >> z;
        ++head[u];
            //++head[v];
        x[i]=u;y[i]=v;
    }
    fii(i,1,n-1)
        head[i]=head[i]+head[i-1];
    head[n]=m;
    fii(i,1,m){
        adj[head[x[i]]]=y[i];
        //adj[head[y[i]]]=x[i];
        --head[x[i]];
        //--head[y[i]];
    }
    fre[1]=0;

}
void DFS(int t)
{
    //fii(i,z,n-1)
    s=1;f=8;
    i=t;
        fii(z,head[i]+1,head[i+1])
            {
                fre[adj[z]]=0;
                trace[t]=adj[z];
                DFS(adj[z]);
            }
    while (s!=8)
    {
        cout << s;
        s = trace[s];
    }
    cout<<f;
}

int main()
{
    fast();
    nhap();
    DFS(1);

}
