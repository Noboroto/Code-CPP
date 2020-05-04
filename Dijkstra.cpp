#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Heap
{
    map <int, int> Position;
    //First = index
    //Second = value
    vector <pair <int, long long> > Tree;
    int nHeap = 0;
    Heap()
    {
        Tree.push_back(make_pair(0, 0));
    }
    void Add (int index, long long value)
    {
        nHeap++;
        Tree.push_back(make_pair(index, value));
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
        Tree.pop_back();
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
};

const long long oo = 1e18 + 7;
Heap HeapTree;
int n, m;
map <int, int> Track;
map <int, bool> Free;
vector < vector < pair <int, int> > > EdgeAdjacency ;

void Start ()
{
    const string FileINP = "Dijkstra" + (string)".INP";
    const string FileOUT = "Dijkstra" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
    cin >> n >> m;
    Track[1] = -1;
    for (int i = 0; i <= n; ++i)
    {
        EdgeAdjacency.push_back(vector <pair <int, int> >());
        if (i == 1) HeapTree.Add(i, 0);
        if (i > 1) HeapTree.Add(i, oo);
        Free[i] = true;
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeAdjacency[u].push_back(make_pair (v, c));
        EdgeAdjacency[v].push_back(make_pair (u, c));
    }
}

void Dijkstra ()
{
    while (!HeapTree.Emty())
    {
        int u = HeapTree.Top().first;
        int value = HeapTree.Top().second;
        Free[u] = false;
        HeapTree.Pop();
        for (int i = 0; i < EdgeAdjacency[u].size(); ++i)
        {
            int v = EdgeAdjacency[u][i].first;
            if (!Free[v]) continue;
            int c = value + EdgeAdjacency[u][i].second;
            HeapTree.Update(v, c);
            Track[v] = u;
        }
    }
}

void Finish ()
{
    if (Track[n] == 0)
    {
        cout << -1;
    }
    vector <int> d;
    d.clear();
    d.push_back(n);
    while (Track[n] != -1)
    {
        d.push_back(Track[n]);
        n = Track[n];
    }
    for (int i = d.size() - 1; i > 0; --i) cout << d[i] << ' ';    
}

int main ()
{
    Start();
    Dijkstra();
    Finish();
    return 0;
}
