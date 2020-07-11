#include <bits/stdc++.h>

using namespace std;

int const N = 3e4 + 1;
long long a[N];
int n, t, l[N], r[N];
stack <int> tmp;

void GetData ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%lld", &a[i]);
    }
}

void Result ()
{
    while (!tmp.empty())
    {
        tmp.pop();
    }
    for (int i = 0; i < n; ++i)
    {
        while (!tmp.empty() && a[tmp.top()] >= a[i])
        {
            tmp.pop();
        }
        l[i] =(tmp.empty()) ? 0 : tmp.top() + 1;
        tmp.push(i);
    }
    while (!tmp.empty())
    {
        tmp.pop();
    }
    for (int i = n - 1; i >= 0; --i)
    {
        while (!tmp.empty() && a[tmp.top()] >= a[i])
        {
            tmp.pop();
        }
        r[i] =(tmp.empty()) ? n - 1 : tmp.top() - 1;
        tmp.push(i);
    }
    long long ans = 0;
    int postl, postr;
    for (int i = 0; i < n; ++i)
    {
        if (ans < (r[i] - l[i] + 1) * a[i])
        {
            ans = (r[i] - l[i] + 1) * a[i];
            postl = l[i] + 1;
            postr = r[i] + 1;
        }
    }
    printf ("%lld %d %d\n", ans, postl, postr);
} 

int main ()
{
    scanf ("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        GetData();
        Result();
    }
    return 0;
}