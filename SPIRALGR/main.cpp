#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

const int oo = 1e5+1, N = 150;
int a[N+1][N+1];
struct node {
    long long x, y, s, id;
    node (long long _x = 0, long long _y = 0,  long long _id = 0, long long _s = 0){
        x = _x;
        y = _y;
        s = _s;
        id = _id;
    }
    bool operator == (node b){
        if (x != b.x) return false;
        if (y != b.y) return false;
        return true;
    }
    node operator + (node b){
        node c;
        c.x = x + b.x;
        c.y = y + b.y;
        c.s = s + b.s;
        c.id = a[c.x][c.y];
        return c;
    }
};
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
bool isPrime [oo+1], ok [N*N+1];
node pos[N*N+1];
int trace[N*N+1];

void prime (){
    for (int i = 0; i <= oo; ++i) isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i*i < oo; ++i){
        if(isPrime[i]) {
             for(long long j = i * i; j < oo; j += i)
                 isPrime[j] = false;
        }
    }
}

void make (){
    int fm = N, fn = N, sm = 1, sn = 1;
    int id = N*N;
    while (id > 0){
        for (int i = sm; i <= fm; ++i){
            a[sn][i] = id;
            pos[id] = node(sn,i, id);
            id--;
            if (id <= 0) return;
        }
        sn++;
        for (int i = sn; i <= fn; ++i){
            a[i][fm] = id;
            pos[id] = node(i,fm,id);
            id--;
            if (id <= 0) return;
        }
        fm--;
        for (int i = fm; i >= sm; --i){
            a[fn][i] = id;
            pos[id] = node(fn,i, id);
            id--;
            if (id <= 0) return;
        }
        fn--;
        for (int i = fn; i >= sn; --i){
            a[i][sm] = id;
            pos[id] = node(i,sm,id);
            id--;
            if (id <= 0) return;
        }
        sm++;
    }
}

int BFS (int x, int y){
    queue <node> que;
    node v;
    que.push(pos[x]);
    for (int i = 1; i <= N*N; ++i) {
        ok[i] = true;
        trace[i] = 0;
    }
    ok[x] = false;
    while (!que.empty()){
        node u = que.front();
        que.pop();
        if (u.id == y) {
            return u.s;
        }
        for (int i = 0; i < 4; ++i){
            v = u + node (dx[i], dy[i], 0, 1);
           int c = v.id;
            if (v.x <= 0 || v.y <= 0 || v.x > N || v.y > N) continue;
            if (!ok[c] || isPrime[c]) continue;
            ok[v.id] = false;
            que.push(v);
            trace[v.id] = u.id;
        }
    }
    return -1;
}

int main(){
    prime();
    make();
    int x, y, i = 0;
    int n;
    for (cin >> x >> y){
        i++;
        int c = BFS(x, y);
        if (c == -1) cout << "Case " << i << ": impossible" << endl;
        else cout << "Case " << i << ": " << c << endl;
}
    return 0;
}
