#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

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
int n, m, wall = -1;
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
                if (a[v.x][v.y] == wall) return -1;
                continue;
            }
            if (!Ok[v.x][v.y]) continue;
            if (a[u.x][u.y] > wall) continue;
            ans += (a[v.x][v.y] >= wall) ? 0 : (wall - a[v.x][v.y]);
            Ok[v.x][v.y] = false;
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
            wall = max (wall, x);
            a[j].push_back(x);
            Ok[j].push_back(true);
        }
    }   
    ans = BFS ({0, 0});
    ans = (ans == -1) ? 0 : ans;
    cout << ans;
    return 0;
}