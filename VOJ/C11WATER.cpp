#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void Init ()
{
    const string FileINP = "C11WATER" + (string)".INP";
    const string FileOUT = "C11WATER" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

struct Node
{
    int x, y;
    Node (int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
};

const int Dx[4] = {0, 1 , 0, -1};
const int Dy[4] = {1, 0, -1,  0};
int n, m, count = 0, wall = 0;
long long ans = 0;
vector < vector <int> > a;
vector < vector <bool> > Ok;

long long BFS (Node root)
{
    long long ans = 0;
    queue <Node> q;
    q.push(root);
    while (!q.empty())
    {
        Node u;
        u = q.front();
        q.pop();
        Ok[u.x][u.y] = false;
        for (int i = 0; i < 4; ++i)
        {
            Node v = {u.x + Dx[i], u.y + Dy[i]};
            if (v.x < 0 || v.y < 0 || v.x >= m || v.y >= n) 
            { 
                if (a[u.x][u.y] < a[root.x][root.y]) break;
                continue;
            }
            if (!Ok[v.x][v.y]) continue;
            if (a[u.x][u.y] > a[root.x][root.y]) continue;
            ans += (a[v.x][v.y] == a[root.x][root.y]) ? 0 : (a[root.x][root.y] - a[v.x][v.y]);
            Ok[v.x][v.y] = false;
            count++;
            q.push(v);
        }
    }
    return ans;
}

int main ()
{
    Init();
    cin >> m >> n;
    for (int j = 0; j < m; ++j)
    {
        a.push_back(vector<int>());
        Ok.push_back(vector<bool>());
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            a[j].push_back(x);
            Ok[j].push_back(true);
        }
    }
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (!Ok[j][i]) continue;
            int tmp = (wall == 0) ? 0 : abs (wall - a[j][i]);
            ans += count*tmp;
            ans += BFS ({i, j});
            wall = max (wall, a[j][i]);
        }
    }
    cout << ans;
    return 0;
}