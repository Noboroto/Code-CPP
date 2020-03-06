#include <iostream>
#include <cstring>

using namespace std;

int main () {
    string a, b;
    cin >> a;
    b = a;
    for (int i = 0; i < a.size(); ++i) b[i] = a[a.size() - i - 1];
    cout << b << endl;
    return 0;
}