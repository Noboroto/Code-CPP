#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "Bai1-NhiPhan" + (string)".INP";
    const string FileOUT = "Bai1-NhiPhan" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n;
vector <int> NhiPhan;

int main ()
{
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i) NhiPhan.push_back(0);
    int i = n - 1;
    while (i >= 0)
    {
        for (int j = 0; j < n; ++j) cout << NhiPhan[j];
        cout << "\n";
        i = n - 1;
        while (i >= 0 && NhiPhan[i] == 1) i--;
        if (i >= 0)
        {
            NhiPhan[i] = 1;
            for (int j = i + 1; j < n; ++j) NhiPhan[j] = 0;
        }
    }
    return 0;
}