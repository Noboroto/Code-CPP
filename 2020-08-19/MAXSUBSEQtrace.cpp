#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "MAXSUBSEQtrace" + (string)".INP";
    const string FileOUT = "MAXSUBSEQtrace" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1000000 + 1;
int n, l, r;
int sum[N];
pair <int, pair <int, int> > ans;

struct MinSegmentTree
{
    private: 
        int Tree[4*N];
        int Count;
        int range;

        void PushToTree (int l,int r, int id)
        {
            if (l == r)
            {
                Tree[id] = l;
                return;
            }
            int mid = (l + r) / 2;
            PushToTree (l, mid, id * 2);
            PushToTree (mid + 1, r, id * 2 + 1);
            if (sum[Tree[id * 2]] < sum[Tree[id * 2 + 1]])
            {
                Tree[id] = Tree[id * 2];
            }
            else
            {
                Tree[id] = Tree[id * 2 + 1];
            }
        }

        int Get (int l,int r, int id, int u,int v)
        {
            if (v < l || r < u) return N - 1;
            if (u <= l && r <= v) 
                return Tree[id];
            int mid = (l + r) / 2;
            int left = Get (l, mid, id * 2, u, v);
            int right = Get (mid + 1, r, id * 2 + 1, u, v);
            if (sum[left] < sum[right]) return left;
            else return right;
        }

    public:
        MinSegmentTree (int n = 0)
        {
            range = n;
            for (int i = 0; i <= range * 4; ++i) Tree[i] = N - 1;
        }
        void Push ()
        {
            PushToTree(0, range, 1);
        }
        int GetRange (int l, int r)
        {
            return Get (0, range, 1, l, r);
        }
};

MinSegmentTree ST;

int main ()
{
    ios_base::sync_with_stdio(0);
    Init();
    scanf ("%d%d%d", &n, &l, &r);
    ST  = MinSegmentTree (n);
    ans.first = -1e9 - 7;
    sum[N - 1] = 1e9 + 7;
    for (int i = 1; i <= n; ++i) 
    {
        scanf ("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    ST.Push();
    for (int i = r; i <= n; ++i)
    {
        int tmp = ST.GetRange(i - r, i - l);
        if (ans.first < sum[i] - sum[tmp])
        {
            ans.first = sum[i] - sum[tmp];
            ans.second = make_pair(tmp + 1, i);
        }
    }
    printf("%d\n", ans.first);
    printf("%d %d", ans.second.first, ans.second.second);
    return 0;
}