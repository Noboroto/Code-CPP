#include <iostream>
#include <string>
#include <queue>
#include <cstdio>

typedef long long ll;
using namespace std;

queue <ll> id;
const ll  dx[4] = { 0,-1, 1, 0};
const ll  dy[4] = {-1, 0, 0, 1};
const char go[4] = {'D', 'L', 'R', 'U'};
const ll N = 1e6 + 7;

string s;
ll fx, fy;
bool ok = false;

void solve (ll x, ll y){
    if (id.empty()) {
        if (x == fx && y == fy) {
            cout << s;
            ok = true;
        }
        return;
    }
    ll i = id.front();
    id.pop();
    for (ll k = 0; k < 4; ++k){
            s[i] = go[k];
            x = x + dx[k];
            y = y + dy[k];
            solve (x, y);
            if (ok) return;
            s[i] = '?';
            x = x - dx[k];
            y = y - dy[k];
    }
}


pair <ll, ll> found (){
    ll x = 0, y = 0;
    ll sa = (ll)s.size() - 1;
    for (ll i = 0; i < sa; ++i){
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
        if (s[i] == '?') id.push(i);
    }
    return make_pair(x,y);
}

int main() {
    //freopen("JOURNEY.INP", "r", stdin);
    //freopen("JOURNEY.OUT", "w", stdout);
    cin >> fx >> fy;
    cin >> s;
    pair <ll, ll> x = found();
    solve(x.first, x.second);
    if (!ok) cout << "IMPOSSIBLE";
    return 0;
}
