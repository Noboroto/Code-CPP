#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

void Init ()
{
    const string FileINP = "GAME" + (string)".INP";
    const string FileOUT = "GAME" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

vector < vector <long long> > ansmin, ansmax;
long long n, m, origin;

int main ()
{
    Init();
    cin >> n >> m;
    cin >> origin;      
    ansmax.push_back(vector<long long>());
    ansmin.push_back(vector<long long>());
    for (long long i = 0; i <= n; ++i)
    {
        ansmin[0].push_back(origin);
        ansmax[0].push_back(origin);
    }
    for (long long i = 1; i <= n; ++i)
    {
        ansmax.push_back(vector<long long>());
        ansmin.push_back(vector<long long>());
        ansmin[i].push_back(-1);
        ansmax[i].push_back(-1);
        for (long long j = 1; j <= m; ++j)
        {
            long long x;
            cin >> x;
            long long tmpmin = min (ansmin[i-1][j], min ((j - 1 > 0) ? ansmin[i - 1][j - 1] : (long long)1e9 + 7, (j + 1 <= n) ? ansmin[i - 1][j + 1] : (long long)1e9 + 7));
            long long tmpmax = max (ansmax[i-1][j], max ((j - 1 > 0) ? ansmax[i - 1][j - 1] : (long long)-1e9 - 7, (j + 1 <= n) ? ansmax[i - 1][j + 1] : (long long)-1e9 - 7));
            if (x != 0)
            {
                ansmin[i].push_back(tmpmin + x);
                ansmax[i].push_back(tmpmax + x);
            }
            else
            {
                ansmin[i].push_back(trunc (tmpmax /2));
                ansmax[i].push_back(trunc (tmpmin /2));
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        cout << ansmin[n][i] << ' ';
    }
    cout << endl;
        for (int i = 1; i <= m; ++i)
    {
        cout << ansmax[n][i] << ' ';
    }
    return 0;
}