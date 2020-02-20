#include <iostream>

using namespace std;

const int N = 10 + 2;
int  longness[N], ans[N], price [N];
int n;

int main (){
    cin >> n;
    for (int i = 1; i < n; ++i){
        cin >> longness[i];
        longness[i] += longness[i - 1];
    }
    for (int i = 1; i <= n; ++i){
        cin >> price[i];
    }
    ans[2] =  longness[1]*price[1];
    for (int i = 3; i <= n; ++i){
        ans[i] = longness[i - 1]*price[1];
        for (int j = 2; j < i; ++j){
            ans[i] = min (ans[j] + (longness[i - 1] - longness[j-1])*price[j], ans[i]);
        }
    }
    cout << ans[n];
    return 0;
}