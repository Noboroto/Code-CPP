#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3*1e5 + 7;
int a[N], f[N], n;

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        f[i] = a[i] + f[i - 1];
    }
}

void solve (){
    int ans = 0;
    int tmp=-INT_MAX;
    int ptr=INT_MAX;
    for (int i=4;i<=n;i+=2)
    {
        ptr=min(ptr,f[i-4]);
        tmp=max(tmp,f[i]-ptr);
    }
    ans=max(tmp,ans);
    cout << ans;
}

int main(){
    //freopen("BEAUTY.INP", "r", stdin);
    //freopen("BEAUTY.OUT", "w", stdout);
    start();
    solve();
    return 0;
}
