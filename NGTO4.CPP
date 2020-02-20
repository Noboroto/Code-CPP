#include <iostream>

using namespace std;

const int NGTO[4] = {2,3,5,7};

int main (){
    int t;
    cin >> t;
    int a[101];
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
    }
    for (int z = 0;z < t; z++){
        int x, ans = 0;
        x = a[z];
        int i = 3;
        while (i >= 0)
        {
            while (x >= NGTO[i])
            {
                x -= NGTO[i];
                ans++;
                if (x == 1) {
                    x += NGTO[i];
                    ans--;
                    break;
                }
            }
            if (x == 0) break;
            i--;
        }
        if (x == 0) cout << ans << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}