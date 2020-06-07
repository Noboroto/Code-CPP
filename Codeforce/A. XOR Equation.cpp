/*
Problems: https://codeforces.com/problemset/problem/627/A
*/

#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
}

long long GetBit (int position, long long input)
{
    return 1 & (input >> position);
}

int CountBit (long long input)
{
    int ans = 0;
    while (input > 0)
    {
        input = input >> 1;
        ans++;
    }
    return ans;
}

int main ()
{
    Init();
    int n;
    long long s, x, ans = 0;
    cin >> s >> x;
    n = CountBit(x);
    for (int i = 0; i < n; ++i)
    {
        long long a = 0, b = 0;
        switch (GetBit (i, x))
        {
        case 0:
            break;
        case 1:
            break;
        }
    }
    return 0;
}