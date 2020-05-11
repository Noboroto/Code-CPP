#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "WELCOME" + (string)".INP";
    const string FileOUT = "WELCOME" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

struct Record 
{
    int Time, Num;
    long long Price;  
    bool operator < (const Record &b)
    {
        if (Time < b.Time) return true;
        if (Time == b.Time && Num < b.Num) return true;
        if (Time == b.Time && Num == b.Num && Price < b.Price) return true;
        return false;
    }
    bool Check (const Record &b)
    {
        if (abs (Time - b.Time) < abs (Num - b.Num)) return false;
        return true;
    }
    void Get (const Record &b)
    {
        Time = b.Time;
        Num = b.Num;
        Price += b.Price;
    }
};

const int N = 200 + 1;
int n;
Record Customers [N];
bool Free[N];
long long ans;
long long DP[N];

int main ()
{
    Init();
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int t, s, p;
        cin >> t >> s >> p;
        Customers [i] = {t, s, p};
    }
    sort (Customers, Customers + n);
    Record Root = {0, 0, 0};
    for (int i = 0; i < n; ++i)
    {
        if (Root.Check(Customers[i])) DP[i] = Customers[i].Price;
        for (int j = 0;j < i; ++j)
            if (Customers[i].Check(Customers[j])) DP[i] = max(DP[i], DP[j] + Customers[i].Price);
        ans = max (ans, DP[i]);
    }
    cout << ans;
    return 0;
}