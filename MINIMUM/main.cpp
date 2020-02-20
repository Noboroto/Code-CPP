#include <cstdio>
#include <queue>

using namespace std;

const int N = 1e6, oo = 1e9 + 7;
int a[N], n, k;
queue <int> q, s;

int main() {
    freopen("MINIMUM.INP", "r", stdin);
    freopen("MINIMUM.OUT", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int mina = oo;
    for (int i = 1; i <= n; ++i){
        q.push(a[i]);
        mina = min (mina, a[i]);
        if (q.size() < k || q.empty()) continue;
        printf("%d\n", mina);
        int x = q.front();
        q.pop();
        if (x == mina){
            s = q;
            mina = oo;
            while (!s.empty()){
                x = s.front();
                mina = min (mina, x);
                s.pop();
            }
        }
    }
    return 0;
}
