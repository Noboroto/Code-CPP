#include <iostream>
#include <queue>

using namespace std;

void init ()
{
    const string FileINP = "C11WATER" + (string)".INP";
    const string FileOUT = "C11WATER" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

struct Node
{
    int x, y, z;
    Node (int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
};

const int N = 1e3 +1;
const int Dx[2] = {0, 1};
const int Dy[2] = {1, 0};
int n, m, Height[N][N];
long long ans = 0;
bool Free[N][N];

long long BFS (Node Root)
{
    long long ans = 0;
    Free[Root.x][Root.y] = false;
    int RootValue = Height[Root.x][Root.y];
    queue <Node> q;
    q.push(Root);
    bool Check = false;
    while (!q.empty())
    {
        Node u;
        u = q.front();
        q.pop();
        for (int i = 0; i < 2; ++i)
        {
            Node v = {u.x + Dx[i], u.y + Dy[i]};
            if (v.x >= n || v.y >= m)
            {
                if (Height[u.x][u.y] < RootValue) 
                {
                    
                    break;
                }
                continue;
            }
            if (Height[v.x][v.y] > RootValue || !Free[v.x][v.y]) continue;
            ans += RootValue - Height[v.x][v.y];
            Free[v.x][v.y] = false;
            q.push(v);
        }
        if (Check) break;
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << Free[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << ans << "\n\n";
    return ans;
}

int main ()
{
    init ();
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> Height[i][j];
            Free[i][j] = true;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!Free[i][j]) continue;
            ans += BFS ({i, j});
        }
    }
    cout << ans;
    return 0;
}