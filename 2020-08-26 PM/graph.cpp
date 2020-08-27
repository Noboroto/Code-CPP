#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

void Init ()
{
    freopen ("graph.INP", "r", stdin);
    freopen ("graph.OUT", "w", stdout);
}

const int N = 1e6 + 1;
pair <bool, bool> State[N];
int Adjacent[N], Head[N];
int n, m, k, edge_size = 0, x = 0, ans = 0;
int Checked[N];
stack <int> s;

void GetGraph ()
{
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        scanf ("%d", &x);
        State[x].first = true;
    }
    for (int i = 0; i < k; ++i)
    {
        scanf ("%d", &x);
        State[x].second = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &x);
        for (int j = 0; j < x; ++j)
        {
            scanf ("%d", &Adjacent[edge_size]);
            edge_size++;
        }
        Head[i] = edge_size;
    }
}

struct Information
{
    int Good;
    int Pretty;
    Information()
    {
        Good = 0;
        Pretty = 0;
    }
};

Information DFS (int pos)
{
    Information Ans;
    Checked[pos] = 1;
    for (int i = Head[pos - 1]; i < Head[pos]; ++i)
    {
        x = Adjacent[i];
        if (Checked[x] > 0) continue;
        Information tmp = DFS (x);
        if (tmp.Good == 0 && tmp.Pretty == 0) 
        {
            Checked[x] = 2;
            continue;
        }
        else 
        {
            Ans.Good += tmp.Good;
            Ans.Pretty += tmp.Pretty;
        }
        if (Ans.Good > 0 && Ans.Pretty > 0) return Ans;
    }
    Ans.Good += State[pos].first;
    Ans.Pretty += State[pos].second;
    return Ans;
}

int main ()
{
    Init();
    GetGraph();
    DFS (1);
    bool Good = false, Pretty = false;
    for (int i = 2; i <= n; ++i)
    {
        if (Checked[i] != 1) continue;
        Good |= State[i].first;
        Pretty |= State[i].second;
        ans++;
    }
    if (State[1].first && State[1].second) printf ("0");
    else if (Good && Pretty) printf ("%d", ans);
    else printf ("impossible"); 
    return 0;
}