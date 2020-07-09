#include <bits/stdc++.h>

/*
kiem tra xem khi a[i] * a[i - 1] = max co bi sai ket qua khi chon pos bat ky ko
*/

using namespace std;

void Init ()
{
    const string FileINP = "EXPRESS" + (string)".INP";
    const string FileOUT = "EXPRESS_TRAU" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 10 + 1;
int n;
int a[N];
long long ans = 0;
pair <long long, int> MaxVal[N];

void GetData ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d",&a[i]);
    }
}

void Reverse (int counter, long long sum, int i)
{
    if (i == n)
    {
        if (counter > 0) return;
        ans = max (ans, sum);
        return;
    }
    if (i > n) return;
    Reverse (counter, sum + a[i], i + 1);
    Reverse (counter - 1, sum + a[i] * a[i + 1], i + 2);
}

int main ()
{
    Init();
    GetData();
    Reverse (2,0,0);
    printf ("%d", ans);
    return 0;
}