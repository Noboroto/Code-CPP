#include <bits/stdc++.h>

using namespace std;

struct Hit 
{
    long double T;
    int I, J;
    Hit (long double t = 0, int i = 0, int j = 0)
    {
        T = t;
        I = i;
        J = j;
    }
    bool operator < (Hit &b)
    {
        if (T < b.T) return true;
        else if (T == b.T && I < b.I) return true;
        else if (T == b.T && I == b.I && J < b.J) return true;
        else return false;
    }
};

const int N = 1e4  + 1;
vector <Hit> Ans;
int x[N], v[N], n, k;

long double Time (int i, int j)
{
    return abs ((long double)(x[i] - x[j]) / (long double)(v[j] - v[i]));
}

int main ()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> v[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        { 
            Ans.push_back(Hit(Time(i,j),i + 1,j + 1));
        }
    }
    sort (Ans.begin(), Ans.end());
    cout << Ans[k - 1].I << ' ' << Ans[k - 1].J;
    return 0;
}