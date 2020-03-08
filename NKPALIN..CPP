#include <iostream>
#include <cstdio>

using namespace std;

const int N = 2000 + 7;
void Init ()
{
    const string FileINP = "NKPALIN." + (string)"INP";
    const string FileOUT = "NKPALIN." + (string)"OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int f [N][N];
int c[N][N]; 

int main ()
{
    Init();
    string a, b;
    cin >> a;
    b = a;
    for (int i = 0; i < a.size (); ++i) b[i] = a[a.size() - i - 1];
    for (int i = 0; i <= a.size();++i)  
    {
        f[0][i] = 0;
        c[0][i] = 0;
    }
    for (int i = 1; i <= a.size(); ++i) 
    {
        f[i][0] = 0;
        c[i][0] = 0;
        for (int j = 1; j <= a.size(); ++j) 
        {
            if (a[i - 1] == b[j - 1]) 
            {
                f[i][j] = f[i - 1][j - 1] + 1;
                c[i][j] = 1;
            }
            else if (f[i - 1][j] > f[i][j - 1]) 
            {
                f[i][j] =  f[i - 1][j];
                c[i][j] =  2;
            }
            else
            {
                f[i][j] =  f[i][j - 1];
                c[i][j] =  3;
            }
        }
    }
    string result = "";
    pair <int, int> tmp = make_pair(a.size(), a.size());
    while (tmp.first != 0 && tmp.second != 0)
    {
        if (a[tmp.first - 1] == b[tmp.second - 1]) result += a[tmp.first - 1];
        switch (c[tmp.first][tmp.second])
        {
        case 1:
            tmp.first--;
            tmp.second--;
            continue;
        case 2:
            tmp.first--;
            continue;
        case 3:
            tmp.second--;
            continue;
        default:
            break;
        }
    }
    cout << result;
    return 0;
}