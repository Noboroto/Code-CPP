#include <cstdio>
#include <stack>
#include <iostream>

using namespace std;

const int N = 1e6;
int m, n, h[N], l[N], r[N];
stack <int> s;

void start(){
    cin >> m >> n;
    for (int i = 1; i <= n; ++i){
        cin >> h[i];
    }
}

long long cal (){
    long long ans = 0;
    while (!s.empty()) s.pop();
    for (int i = 1; i <= n; ++i){
        int x = 0;
        if (!s.empty()) x = s.top();
        while (!s.empty() && h[s.top()] >= h[i]){
            s.pop();
            if (!s.empty()) x = s.top();
            else x = 0;
        }
        l[i] = x + 1;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i > 0; --i){
        int x = n + 1;
        if (!s.empty()) x = s.top();
        while (!s.empty() && h[s.top()] >= h[i]){
            s.pop();
            if (!s.empty()) x = s.top();
            else x = n + 1;
        }
        r[i] = x - 1;
        s.push(i);
    }
    for (int i = 1; i <= n; ++i){
        long long t = r[i] - l[i] + 1;
        t = t * h[i];
        ans = max (ans, t);
    }
    return ans;
}

int main (){
    freopen("RECT.INP", "r", stdin);
    freopen("RECT.OUT", "w", stdout);
    start();
    long long ans = cal();
    for (int i = 1; i <= n; ++i){
        h[i] = m - h[i];
    }
    ans = max (ans, cal());
    cout << ans;
    return 0;
}
