#include <iostream>

using namespace std;

int main () {
    int n, mid;
    cin >> n;
    mid = ((n%2) + n) / 2;
    for (int i = 1; i <= mid; ++i){
        for (int j = 1; j <= n; ++j) {
            if (j >= mid - (i - 1) && j <= mid + (i - 1)) cout << 'D';
            else cout << '*';
        }
        cout << '\n';
    }
    for (int i = mid - 1; i >= 1; --i){
        for (int j = 1; j <= n; ++j) {
            if (j >= mid - (i - 1) && j <= mid + (i - 1)) cout << 'D';
            else cout << '*';
        }
        cout << '\n';
    }
    return 0;
}