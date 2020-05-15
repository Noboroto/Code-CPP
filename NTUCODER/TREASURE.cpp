#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Node {
    int x, y;
    Node (int _u = 0, int _v = 0){
        x = _u;
        y = _v;
    }
};

const int N = 1001;
const int dx[4] = {0, 1, 0,-1};
const int dy[4] = {1, 0,-1, 0};

int n, m, k = 0, previous = 0;
queue <Node> Smelt;
queue <Node> PrevPath;
bool Smelted[N][N], OK[N][N];
Node Go, Treasure;

void Start ()
{
    scanf ("%d %d",&n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int x;
            scanf ("%d",&x);
            OK[i][j] = true;
            if (x == 1) 
            {
                Smelted[i][j] = false;
            }
            else
            {
                Smelt.push({i, j});
                Smelted[i][j] = true;
            }
        }
    }
    previous = Smelt.size();
    cin >> Go.x >> Go.y >> Treasure.x >> Treasure.y;
    Smelt.push (Go);
    PrevPath.push (Go);
}

void Smelting ()
{
    while (previous > 0 && !Smelt.empty())
    {
        Node u;
        u = Smelt.front();
        Smelt.pop();
        for (int i = 0; i < 4; ++i)
        {
            Node v = {u.x + dx[i], u.y + dy[i]};
            if (v.x > n || v.y > m || v.x < 1 || v.y < 1 || Smelted[v.x][v.y]) continue;
            Smelt.push(v);
            Smelted[v.x][v.y] = true;
        }
        previous--;
    }
}

bool BFS ()
{
    queue <Node> Path;
    Path.swap(PrevPath);
    while (!Path.empty())
    {
        Node u;
        u = Path.front();
        Path.pop();
        if (!Smelted[u.x][u.y])
        {
            PrevPath.push(u);
            continue;
        }
        if (u.x == Treasure.x && u.y == Treasure.y) return true;
        for (int i = 0; i < 4; ++i)
        {
            Node v = {u.x + dx[i], u.y + dy[i]};
            if ((v.x > n || v.y > m || v.x < 1 || v.y < 1 || !OK[v.x][v.y])) continue;
            if (!Smelted[v.x][v.y])PrevPath.push(v);
            else Path.push(v);
            OK[v.x][v.y] = false;
        }
    }
    return false;
}

int main()
{
    Start();
    while (!BFS())
    {
        k++;
        Smelting();
        previous = Smelt.size();
    }
    printf ("%d", k);
    return 0;
}