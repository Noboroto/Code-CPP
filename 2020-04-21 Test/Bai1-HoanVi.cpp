#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "Bai1-HoanVi" + (string)".INP";
    const string FileOUT = "Bai1-HoanVi" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n;
vector <int> HoanVi;

int main ()
{
    Init();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        HoanVi.push_back (i);
    }
    int i = n;
    while (i >= 0)
    {
        for (int j = 0; j < n; ++j) cout << HoanVi[j] << " ";
        cout << "\n";
        i = n - 2;
        while (i >= 0 && HoanVi[i] > HoanVi[i + 1]) i--;
        if (i >= 0)
        {
            int k = n - 1;
            while (HoanVi[k] < HoanVi[i]) k--;
            swap(HoanVi[k], HoanVi[i]);
            int a = i + 1, b = n - 1;
            while (a < b)
            {
                swap (HoanVi[a],HoanVi[b]);
                a++, b--;
            }
        }
    }
    return 0;
}