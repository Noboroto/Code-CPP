#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "A. Sum of Round Numbers" + (string)".INP";
    const string FileOUT = "A. Sum of Round Numbers" + (string)".OUT";
    //freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int t, n;

void Process (int n)
{
    vector <int> ans;
    ans.clear();
    int mod = 10;
    while (n > 0)
    {
        if (n%mod != 0) 
        {
            ans.push_back (n % mod);
            n -= ans.back();
        }
        mod*=10;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main ()
{
    //Init();
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        Process (n);
    }
    return 0;
}