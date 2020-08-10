#include <iostream>
#include <string>

using namespace std;

int a[20], n;

void start (){
    string s;
    cin >> s;
    n = 0;
    for (n = 0; n < (int)s.length (); ++n){
        switch (s[n]){
        case 'I': {
            a[n] = 1;
            break;
        }
        case 'V': {
            a[n] = 5;
            break;
        }
        case 'X':{
            a[n] = 10;
            break;
        }
        case 'L': {
            a[n] = 50;
            break;
        }
        case 'C': {
            a[n] = 100;
            break;
        }
        case 'D': {
            a[n] = 500;
            break;
        }
        case 'M': {
            a[n] = 1000;
            break;
        }
    }
    }
    n = (int)s.length();
}

void solve (){
    int ans = a[0];
    for (int i = 1; i < n; ++i){
        if (a[i - 1] < a[i]){
            ans += a[i] - 2*a[i - 1];
        }else ans += a[i];
    }
    cout << ans;
}

int main(){
    start();
    solve();
    return 0;
}
