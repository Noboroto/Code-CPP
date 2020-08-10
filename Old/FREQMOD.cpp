#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 1e5, M = 100;
int n, a [N], f[N], t;
bool pri [N];

void prime () {
    for (int i = 0; i <= N; ++i) pri[i] = true;
    for (int i = 2; i <= N; ++i){
        if (!pri[i]) continue;
        for (int j = 2; j*i <= N; ++j){
            pri[i*j] = false;
        }
    }
}

int solve (){
    int ans = 0, m = 0;
    for (int k = 1; k < M; k++){
        srand(time(0));
        int l = rand()%n + 1;
        int r = l;
        while (l == r) r = rand()%n + 1;
        l = a[l];
        r = a[r];
        for (int i = 2; i <= max(l,r); ++i){
            if (pri[i]) {
                for (int j = 1; j <= n; ++j){
                    f[a[j]%i]++;
                    m = max (a[j] % i, m);
                    ans = max (ans, f[a[j]%i]);
                }
            }
        for (int i = 0; i <= m; ++i){
            f[i]=0;
        }
    }
}
    return ans;
}

int main()
{
    prime();
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        for (int j = 1; j <= n; ++j){
            cin >> a[j];
        }
       cout << solve() << endl;
    }
    return 0;
}
