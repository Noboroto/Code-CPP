#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "NKPALIN." + (string)"INP";
    const string FileOUT = "NKPALIN." + (string)"OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

vector < vector <int> > f;
vector < vector <pair <int, int> > > c;

int main ()
{
    Init();
    string a, b;
    cin >> a;
    b = a;
    for (int i = 0; i < a.size (); ++i) b[i] = a[a.size() - i - 1];
    f.push_back (vector <int> ());
    c.push_back (vector < pair <int, int>>());
    for (int i = 0; i <= a.size();++i)  
    {
        f[0].push_back(0);
        c[0].push_back(make_pair(0,0));
    }
    for (int i = 1; i <= a.size(); ++i) 
    {
        f.push_back (vector<int>());
        c.push_back (vector<pair<int,int>>());
        f[i].push_back (0);
        c[i].push_back (make_pair(0,0));
        for (int j = 1; j <= a.size(); ++i) 
        {
            if (a[i] == b[j]) 
            {
                
            }
        }
    }
    return 0;
}