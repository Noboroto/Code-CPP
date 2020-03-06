#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> f1, f2, ans;

vector <int> operator+ (const vector <int> &a, vector <int> &b){
    vector <int> result;
    int remember = 0;
    for (int i = 0; i < max (a.size(), b.size()); ++i) {
        int x = (i < a.size()) ? a[i] : 0;
        int y = (i < b.size()) ? b[i] : 0;
        result.push_back((x + y + remember) % 10);
        remember = (x + y + remember) / 10;
    }
    if (remember != 0) result.push_back(remember);
    return result;
}

void Process (int n) {
    f1.clear();
    f2.clear();
    ans.clear();
    f1.push_back (1);
    f2.push_back (2);
    if (n < 3) {
        cout << n << '\n';
        return;
    }
    for (int i = 3; i <= n; ++i) {
        ans = f1 + f2;
        f1.swap(f2);
        f2 = ans;
    }
    for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i];
    cout << '\n';
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        Process (n);
    }
    return 0;
}