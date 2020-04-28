#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "Bai1-ToHop" + (string)".INP";
    const string FileOUT = "Bai1-ToHop" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n, k;
vector <int> ToHop;

int main ()
{
    Init();
    cin >> n >> k;
    for (int i = 0; i < k; ++i) ToHop.push_back (i + 1);
    int i = k;
    while (i >= 0)
    {
        for (int j = 0; j < k; ++j) cout << ToHop[j] << " "; 
        cout << "\n";
        i = k - 1;
        while (i >= 0 && ToHop[i] == n - k + i + 1) i--;
        if (i >= 0)
        {
            ToHop[i]++;
            for (int j = i + 1; j < k; ++j) ToHop[j] = ToHop[j - 1] + 1;
        }
    }
    return 0;
}