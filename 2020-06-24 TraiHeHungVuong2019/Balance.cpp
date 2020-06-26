#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "Balance" + (string)".INP";
    const string FileOUT = "Balance" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 20 + 1;
int Stone_1[N/2], n, Stone_2[N/2], ans = 0, m;
int Type_1[N], Type_2[N];
vector <int> Sum_1, Sum_2;

void GetData()
{
    scanf ("%d", &n);
    scanf ("%d", &m);
    for (int i = 0; i < n; ++i)
    {
        if (i < n/2) scanf ("%d", &Stone_1[i]);
        else scanf ("%d", &Stone_2[i - n/2]);
    }
}

void Recursion (int n, int i, int *Stone, vector <int> &Sum, int *Type)
{
    if (i >= n)
    {
        int tmp = 0;
        for (i = 0; i < n; ++i)
        {
            tmp += Stone[i] * Type[i];
        }
        Sum.push_back(tmp);
        return;
    }
    for (int t = -1; t < 2; ++t)
    {
        Type[i] = t;
        Recursion (n, i + 1, Stone, Sum, Type);
    }
}

int Result ()
{
    sort (Sum_2.begin(), Sum_2.end());
    int ans = 0, qs = 0, tmp = 0;
    for (int i = 0; i < Sum_1.size(); ++i)
    {
        tmp = Sum_1[i] + m;
        if (binary_search(Sum_2.begin(), Sum_2.end(), -tmp))
        {
            int j = (int)(lower_bound (Sum_2.begin(), Sum_2.end (),-tmp) - Sum_2.begin());
            for (; j < Sum_2.size(); ++j)
            {
                if (Sum_2[j] != -tmp) break;
                ans++;
            }
        }
    }
    return ans;
}

int main ()
{
    Init();
    GetData();
    Recursion (n / 2, 0, Stone_1, Sum_1, Type_1);
    Recursion (n - (n / 2), 0, Stone_2, Sum_2, Type_2);
    printf ("%d", Result());
    return 0;
}