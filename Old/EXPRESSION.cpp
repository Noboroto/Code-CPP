#include <string>
#include <stack>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

typedef long long ll;
using namespace std;

stack <ll> st;

ll gcd (ll a, ll b) {
    a = abs (a);
    b = abs (b);
    ll r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve (char c){
    ll a = st.top();
    st.pop();
    ll b = st.top();
    st.pop();
    ll ans = 0;
    if (c == 'N') ans = min (a, b);
    if (c == 'D') ans = gcd (a, b);
    if (c == 'M') ans = a + b;
    if (c == 'F') ans = a - b;
    if (c == 'X') ans = max (a, b);
    st.push(ans);
}

int main (){
    freopen("EXPRESSION.INP", "r", stdin);
    freopen("EXPRESSION.OUT", "w", stdout);
    string s;
    cin >> s;
    int i = (int)s.size() - 1;
    int x = 0, j = 0;
    while (i > 0) {
        char c = s[i];
        if (c == ')' || c == '(' || c == ','){
            x = 0;
            i--;
            continue;
        }
        j = i;
        while (s[i] - '0' >= 0 && s[i] - '0' <= 9)--i;
        if (j != i){
            ++i;
            for (int t = i; t <= j; ++t){
                x = x*10 + (s[t] - '0');
            }
            st.push(x);
        } else{
            solve(c);
            i -= 2;
        }
        --i;
    }
    cout << st.top();
    return 0;
}
