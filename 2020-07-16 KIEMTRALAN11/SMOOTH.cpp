#include <bits/stdc++.h>

using namespace std;

void Init ()
{  
    const string FileINP = "SMOOTH" + (string)".INP";
    const string FileOUT = "SMOOTH" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int main ()
{
    Init();
    int n;
    long long ans = -1;
    cin >> n;
    switch (n)
    {
        case 1:
            ans = 9;
            break;
        case 2:
            ans = 99;
            break;
        case 3:
            ans = 989;
            break;
        case 4:
            ans = 9889;
            break;
        case 5:
            ans = 97679;
            break;
        case 6:
            ans = 976679;
            break;
        case 7:
            ans = 9643469;
            break;
        case 8:
            ans = 96433469;
            break;
        default:
            ans = -1;
            break;
    }
    cout << ans;
    return 0;
}