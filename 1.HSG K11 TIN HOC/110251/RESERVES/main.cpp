#include <bits/stdc++.h>
using namespace std;
#define maxn 100
#define fii(i,a,b) for(i=a;i<=b;i++)
#define f first
#define s second
#define ll long long
#define pii pair<ll,ll>

int n,a[maxn][maxn],i,j,maxx,minn;
void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("RESERVES.INP","r",stdin);
    //freopen("RESERVES.OUT","w",stdout;)
}
int main()
{
    fast();
    cin >> n;
    fii(i,1,n)
        fii(j,1,n)
            cin >> a[i][j];
    minn = a[1][1];
    maxx = a[1][1];
    fii(i,1,n)
        fii(j,1,n){
            if (minn > a[i][j]) minn = a[i][j];
            if (maxx < a[i][j]) maxx = a[i][j];
        }
    fii(i,1,n)
        fii(j,1,n)
            a[i][j] = a[i][j] - minn;


    fii(i,1,n){
        fii(j,1,n) cout << a[i][j] << " ";
        cout << endl;
    }

}
