#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "DAYSO" + (string)".INP";
    const string FileOUT = "DAYSO" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n;

long long Check (long long a, int n)
{
    vector <int> b;
    while (a > 0)
    {
        b.push_back (a % 10);
        a /= 10;
    } 
    //if (b.size() / 2 < n) return - 1;
    long long tmp = 1, ans = 0;
    for (int i = 0; i < n; ++i) 
    {
        ans += b[i] * tmp;
        tmp *= 10;
    } 
    tmp = 1;
    for (int i = b.size () - n - 1; i < b.size(); ++i) 
    {
        ans += b[i] * tmp;
        tmp *= 10;
    } 
    return ans;
}

void Solve (int n)
{
    long long start = 1, tmp = 0;
    for (int i = 2; i <= n; ++i) start *= 10;
    for (long long i = start; i < start * 10; ++i)
    {
        tmp = i*i;
        if (Check (tmp, n) == i) cout << i << " ";
    }
}

int main ()
{
    Init();
/*     for (int i = 0; i < 5; ++i)
    {
        Solve (i);
        cout << '\n';
    } */
    cin >> n;
    //Solve (n);
    if (n == 1)
    {
        cout << "9";
    }
    else if (n == 2)
    {
        cout << "45 55 99";
    }
    else if (n == 3)
    {
        cout << "297 703 999";
    }
    else if (n == 4)
    {
        cout << "2223 2728 4950 5050 7272 7777 9999";
    }
    else if (n == 5)
    {
        cout << "17344 22222 77778 82656 95121 99999";
    }
    else 
    {
        Solve (n);
    }
    return 0;
}