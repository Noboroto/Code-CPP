#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono; 

void Init ()
{  
    const string FileINP = "SMOOTH" + (string)".INP";
    const string FileOUT = "SMOOTH" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 15 + 1;
int n, b[N];

bool Check (long long a, long long n)
{
    int i = 0;
    while (a > 0 && i < n)
    {
        b[i] = a % 10;
        a /= 10;
        ++i;
    }
    for (int i = 1; i < n - 1; ++i)
    {
        if (b[i] * 2 >= b[i - 1] + b[i + 1]) return false;
    }
    return true;
}

long long Find (long long n)
{
    long long start = 1, ans = 0;
    for (long long i = 2; i <= n; ++i) start *= 10;
    for (long long i = start * 10 - 1; i >= start; --i)
    {
        if (Check(i, n)) return i;
    }
    return -1;
}

int main ()
{
    auto start = high_resolution_clock::now(); 
    Init();
    for (n = 3; n <= 9; ++n)
    {
        cout << Find (n) << '\n';
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() / (long double)(1e6);
    return 0;
}