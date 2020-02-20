#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1000 + 7;
pair <int, char> ans[N];
pair <int, int> b[N];
int k, n, a[N], ians;
char s[N];

void start(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        b[i].second = i;
        b[i].first = a[i];
    }
    scanf("\n");
    sort(b + 1, b + 1 + n);
    ians = 1;
    scanf("%s(N - 1)", s);
    ans[0] = make_pair(b[(1 + n) / 2].first, s[0]);
}

void solve (){
    pair <int, int> lr [2];
    if (ans[0].second == 'L') lr[0].first = ans[0].first;
    else lr[1].first = ans[0].first;
    lr[0].second = 1;
    lr[1].second = n;
    bool phai;
    for (int i = 1; i < k; ++i){
        char c = s[i];
        if (c == 'R') phai = true;
        else phai = false;
        int l = lr[0].second, r = lr [1].second;
        if (lr [phai] )
}

int main(){
    start();
    cout << "No solution";
    return 0;
}
