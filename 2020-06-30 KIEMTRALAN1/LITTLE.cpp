#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "LITTLE" + (string)".INP";
    const string FileOUT = "LITTLE" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 100 + 1;
int n, m, Trace[N], result = 0;
bool Ans[N], a[N][N];

void GetData ()
{
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        a[x][y] = true;
    }
}

void Reset (bool mode)
{
    for (int i = 1; i <= n; ++i)
    {
        if (mode) Ans[i] = false;
        Trace[i] = -1;
    }
}

void BFS (int s, int f)
{
    queue <int> Path;
    Path.push (s);
    Trace[s] = 0;
    while (!Path.empty())
    {
        int u = Path.front();
        Path.pop();
        if (u == f) break;
        for (int v = 1; v <= n; ++v)
        {
            if (v == u) continue;
            if (a[u][v] && Trace[v] == -1)
            {
                Trace[v] = u;
                Path.push(v);
            }
        }
    }
    int r = f;
    while (r != 0)
    {
        result += !Ans[r];
        Ans[r] = true;
        r = Trace[r];
    }
}

int main ()
{
    Init();
    GetData();
    Reset(true);
    BFS(1,2);
    Reset(false);
    BFS(2,1);
    cout << result;
    return 0;
}