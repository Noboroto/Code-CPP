#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "CLIQUE" + (string)".INP";
    const string FileOUT = "CLIQUE" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 60 + 1;
int n, m, k,Degree[N];
bool Edge[N][N],CanMake, Checked[N];
stack <int> Graph;

void GetInput ()
{
    int u, v;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= n; ++i)
    {
        Checked[i] = false;
        Degree[i] = 0;
        for (int j = 0; j <= n; ++j)
            Edge[i][j] = false;
    }
    for (int i = 0; i < m; ++i)
    {
        scanf ("%d%d", &u, &v);
        Degree[u]++;
        Degree[v]++;
        Edge[u][v] = true;
        Edge[v][u] = true;
    }
    CanMake = false;
    while (Graph.size() > 0) Graph.pop();    
}

bool Connected (int i, stack <int> tmp, int k)
{
    if (Degree[i] < k - 1) return false;
    while (tmp.size() > 0)
    {
        if (!Edge[i][tmp.top()]) return false;
        tmp.pop();
    }
    return true;
}

void FindGraph (int t, int k)
{
    if (CanMake) return;
    if (t > k)
    {
        CanMake = true;
        while (Graph.size() > 0) 
        {
            printf("%d ", Graph.top());
            Graph.pop();
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (t > 1 && !Edge[Graph.top()][i]) continue;
        if (CanMake) return;
        if (!Connected(i, Graph, k)) continue;
        Graph.push(i);
        FindGraph (t + 1, k);
        if (!Graph.empty()) Graph.pop();
        if (CanMake) return;
    }
}

int main ()
{
    Init();
    int t;
    scanf ("%d", &t);
    while (t > 0)
    {
        t--;
        GetInput();
        FindGraph(1, k);
        if (!CanMake) printf ("-1\n");
    }
    return 0;
}