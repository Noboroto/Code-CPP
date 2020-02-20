#include <iostream>

using namespace std;

const int N = 20;
int a[N], n, t;
bool ok [N];

bool start (){
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        s += a[i];
        ok [i] = true;
    }
    if (s % 2 != 0){
        cout << "Khong chia duoc";
        return false;
    }
    t = s / 2;
    return true;
}

void solve (int i, int s){
    if (s > t) return;
    if (s == t){
        for (int i = 0; i < n; ++i){
            if (ok[i]) cout << 'A' << ' ';
            else cout << 'B' << ' ';
        }
        cout << endl;
        return;
    }
    ok[i] = false;
    for (int j = 0; j < n; ++i){
        if (!ok[j]) continue;
        solve(i + 1, s + a[j]);
    }
    ok[i] = true;
}

int main(){
    if (start()) solve(0, 0);
    return 0;
}
