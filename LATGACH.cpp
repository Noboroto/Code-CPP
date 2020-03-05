#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ll;

int n, t;
vector <ll> result;

ll GetAns (int n) {
    ll a1, a2, ans;
    a1 = 1;
    a2 = 2;
    if (n < 3) return n;
    for (int i = 3; i <= n; ++i) {
        ans = a1 + a2;
        a1 = a2;
        a2 = ans;
    }
    return ans;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i){
        int x;
        cin >> x;
        result.push_back(GetAns(x));
    }
    for (int i = 0; i < t; ++i) cout << result[i] << '\n';
    return 0;
}
