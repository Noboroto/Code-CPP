#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "OMEGA" + (string)".INP";
    const string FileOUT = "OMEGA" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int oo = 1e9 + 7;
const int N = 450 + 1;
const int M = 2e6 + 1;

struct Heap
{
    int Position[N];
    //First = index
    //Second = value
    pair <int, long long> Tree[N];
    int nHeap = 0;
    Heap(int n)
    {
        for (int i = 0; i <= n; ++i) 
        {
            Tree[i] = make_pair(0,0);
            Position[i] = 0;
        }
    }
    void Add (int index, long long value)
    {
        nHeap++;
        Tree[nHeap] = make_pair(index, value);
        Position[index] = nHeap;
        int p = Position[index];
        while (p / 2 > 0 && Tree[p / 2].second >= value)
        {
            int parent = p / 2;
            swap(Tree[parent], Tree[p]);
            swap(Position[Tree[parent].first], Position[Tree[p].first]);
            p = parent;
        }
    }
    void Update(int index, long long value)
    {
        int p = Position[index];
        int Compare = (value == Tree[p].second) ? 0 : ((value > Tree[p].second) ? 1 : -1);
        Tree[p].second = value;
        switch (Compare)
        {
        case -1:
            while (p / 2 > 0 && Tree[p / 2].second > value)
            {
                int parent = p / 2;
                swap(Tree[parent], Tree[p]);
                swap(Position[Tree[parent].first], Position[Tree[p].first]);
                p = parent;
            }
            break;
        case 1:
            while (p * 2 <= nHeap)
            {
                int child = p * 2;
                if (child < nHeap && Tree[child + 1].second < Tree[child].second) child++;
                if (Tree[p].second <= Tree[child].second) break;
                swap (Tree[child], Tree[p]);
                swap (Position[Tree[child].first], Position[Tree[p].first]);
                p = child;
            }
            break;
        }
    }
    bool Emty ()
    {
        return (nHeap == 0);
    }
    void Pop()
    {
        swap (Tree[1], Tree[nHeap]);
        swap(Position[Tree[1].first], Position[Tree[nHeap].first]);
        Tree[nHeap] = make_pair (0, 0);
        nHeap--;
        if (nHeap == 0) return;
        int p = 1;
        while (p * 2 <= nHeap)
        {
            int child = p * 2;
            if (child < nHeap && Tree[child + 1].second < Tree[child].second) child++;
            if (Tree[p].second <= Tree[child].second) break;
            swap (Tree[child], Tree[p]);
            swap (Position[Tree[child].first], Position[Tree[p].first]);
            p = child;
        }
    }
    pair <int, long long> Top ()
    {
        return Tree[1];
    }
    long long AtIndex (int index)
    {
        return Tree[Position[index]].second;
    }
};

struct Edge
{
    int u, v, c;
    Edge (int _u = 0, int _v = 0, int _c = 0)
    {
        u = _u;
        v = _v;
        c = _c;
    }
};

int m, n;
Edge EdgeList[M];

void GetData ()
{
    int u, v, c;
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf ("%d %d %d", &EdgeList[i].u, &EdgeList[i].v, &EdgeList[i].c);
        EdgeList[i + n] = Edge (EdgeList[i].v, EdgeList[i].u, EdgeList[i].c); 
    }
}

long long Dijkstra_Heap (int s, int t)
{
    Heap HeapTree (n);
    bool Free[N];
    pair <int, int> Trace[N];
    for (int i = 0; i <= n; ++i)
    { 
        if (i == s) HeapTree.Add(i, 0);
        else if (i > 0) HeapTree.Add(i, oo);
        Free[i] = true;
        Trace[i] = make_pair(0,0);
    }
    while (!HeapTree.Emty())
    {
        int u = HeapTree.Top().first;
        long long value = HeapTree.Top().second;
        Free[u] = false;
        if (u == t) break;
        HeapTree.Pop();
        for (int i = 0; i < 2*m; ++i)
        {
            if (EdgeList[i].u != u) continue;
            int v = EdgeList[i].v;
            long long c = value + EdgeList[i].c;
            if (!Free[v] || HeapTree.AtIndex(v) <= c) continue;
            HeapTree.Update(v, c);
            Trace[v] = make_pair (u, EdgeList[i].c);
        }
    }
    long long ans = 0;
    while (Trace[t].first != 0)
    {
        ans += Trace[t].second;
        t = Trace[t].first;
    }
    return ans;
} 

int main ()
{
    long long ans = 1e18 + 1, sum = 0, tmp;
    int counter = 0;
    Init();
    GetData();
    for (int i = 1; i <= n; ++i)
    {
        sum = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) continue;
            tmp = Dijkstra_Heap(i, j);
            //cout << i << ' ' << j << ' ' << tmp << '\n';
            sum+=tmp;
            if (tmp == 0) 
            {
                cout << 0;
                return 0;
            }
        }
        if (sum < ans) 
        {
            counter = 1;
            ans = sum;
        }
        else if (sum == ans) counter++;
    }
    cout << ans << ' ' << counter;
    return 0;
}