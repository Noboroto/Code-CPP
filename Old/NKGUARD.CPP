#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Dx[8] = { 1, 0,-1, 0, 1,-1, 1,-1};
const int Dy[8] = { 0, 1, 0,-1,-1,-1, 1, 1};

vector < vector <int> > Heigh;
vector < vector <bool> > Free;


int m, n, ans = 0;

int DFS (int u, int v)
{
    int ans;
    
}

int main ()
{
    scanf ("%d %d", &n, &m);
    Heigh.push_back(vector<int>());
    Free.push_back(vector <bool> ());
    for (int i = 1; i <= n; ++i)
    {
        Heigh.push_back(vector<int>());
        Heigh[i].push_back(0);
        Free.push_back(vector<bool>());
        Free[i].push_back(false);
        for (int j = 1; j <=m; ++j)
        {
            int x;
            scanf("%d", &x);
            Heigh[i].push_back(x);
            Free[i].push_back(true);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (Free[i][j]) ans += DFS (i, j);
        }
    }
    printf("%d", ans);
    return 0;
}