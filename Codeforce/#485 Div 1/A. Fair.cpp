#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "A. Fair" + (string)".INP";
    const string FileOUT = "A. Fair" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 1e5 + 1;
int n, m, s, k, ProductOf[N];
vector < vector <int> > Adjacency;

void Input ()
{
    cin >> n >> m >> s >> k;
    for (int i = 0; i < n; ++i)
    {
        Adjacency.push_back(vector<int>());
        cin >> ProductOf[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        Adjacency[u].push_back(v);
        Adjacency[v].push_back(u);
    }
}

int main ()
{
    Init();
    return 0;
}
