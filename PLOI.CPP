#include <iostream>
#include <vector>

using namespace std;

int punish [12];

int main () {
    int n, m = 0;
    vector <int> out;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        punish[x]++;
        if (punish[x] % 3 == 0) {
            m++;
            out.push_back (x);
        }
    }
    cout << m << endl;
    for (int i = 0; i < out.size(); ++i) cout << out[i] << ' ';
    return 0;
}