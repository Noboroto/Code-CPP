#include <cstdio>
#include <iostream>

using namespace std;

void Init ()
{
    const string FileINP = "FIB1" + (string)".INP";
    const string FileOUT = "FIB1" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 45 + 1;
long long Fibo[N];
char ans[1];
int t, n, k, ord;

void Fibonaci ()
{
    Fibo[0] = 1;
    Fibo[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        Fibo[i] = Fibo[i - 2] + Fibo[i - 1];
    }
    ans[0] = 'a';
    ans[1] = 'b';
}

char Result (int n, int k)
{
    while (n > 1)
    {
        if (k <= Fibo[n - 2]) n -= 2;
        else 
        {
            k -= Fibo[n - 2];
            n--;
        }
    }
    return ans[n];
}

int main ()
{
    Init();
    Fibonaci();
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> k;
        cout << Result (n, k) << '\n';
    }
    return 0;
}