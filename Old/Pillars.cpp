#include <iostream>
#include <algorithm>

using namespace std;

struct link {
    int v, id;
    link (int _v = 0, int _id = 0){
        v = _v;
        id = _id;
    }
    bool operator < (link b){
        return v < b.v;
    }
};

const int N = 2 * 1e5 + 7;
int n, a[N];
link b[N];

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        a[i] = x;
        b[i] = link (x, i);
    }
    sort(b + 1, b + 1 + n);
}

void solve (){
    int id = b[n].id;
    int l = id - 1;
    int r = id + 1;
    for (int i = n - 1; i > 0; --i){
        if (b[i].v != a[l] && b[i].v != a[r]){
            cout << "NO";
            exit(0);
        }
        if (b[i].v == a[l]) l--;
        if (b[i].v == a[r]) r++;
    }
    cout << "YES";
}

int main(){
    start();
    solve();
    return 0;
}
