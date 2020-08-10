#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 30000 + 7, oo = 1e9 + 7;
vector <int> a, b;
int n;


void start (){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
        if (i != 0) b.push_back(oo);
        else b.push_back(-oo);
    }
}

int lengthOfLIS (vector<int>& nums) {
    vector <int> b {-(int)1e9 - 7};
    for (int x : nums) {
        int k = lower_bound(b.begin(), b.end(), x) - b.begin();
        if(k > b.size() - 1) b.push_back(x); else b[k] = x;
    }
    return b.size() - 1;
}

int main(){
    //freopen("DAYCON.INP", "r", stdin);
    freopen("DAYCON.OUT", "w", stdout);
    start();
    cout << lengthOfLIS(a) << endl;
    return 0;
}
