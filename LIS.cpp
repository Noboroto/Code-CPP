#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> f;

int main()
{
    cin >> n;
    f.push_back(-1e9);
    for (int i = 0; i < n; ++i) {
        int x, k;
        cin >> x;
        k = lower_bound(f.begin(),f.end(), x) - f.begin();
        if (k >= f.size()) f.push_back(x);
        else f[k] = x;
    }
    cout << f.size()-1;
    return 0;
}
