#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define maxn 10000005
#define fii(i,a,b) for(i=a;i<=b;i++)
#define f first
#define s second
#define ll long long
#define pii pair<ll,ll>

ll n,a[maxn],k,i,j,m,t;
void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("LUCKY.INP","r",stdin);
    //freopen("LUCKY.OUT","w",stdout);
    cin >> n >> k;
    fii(i,1,n)
        cin >> a[i];
}

void timx(int l,int r,int x)
{
    if (l<=r)
    {
        m = a[(l+r)/2];
        if (x<m) timx(l,(l+r)/2-1,x);
        if (x>m) timx((l+r)/2+1,r,x);
        if (x=m) t=(l+r)/2;
    }
    else t=0;

}
void xuli(){
    sort(a+1,a+1+n);

}
int main()
{
    fast();
    timx(1,n,3);
    cout << t;
}
