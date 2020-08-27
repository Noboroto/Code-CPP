/*
https://cses.fi/problemset/task/1678
*/
#include <bits/stdc++.h>

using namespace std;

stack <int> ans;
vector < vector <int> > adjacent;
stack <int> s;
map <int, int> State;
int n, m, tmp;

void Init ()
{
    scanf ("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i <= n; ++i)
    {
        adjacent.push_back(vector<int>());
    }
    for (int i = 0; i < m; ++i)
    {
        scanf ("%d%d", &u, &v);
        adjacent[u].push_back(v);
    }
}

bool DFS (int pos)
{
    s.push(pos);
    State[pos] = 2;
    for (int i = 0; i < adjacent[pos].size(); ++i)
    {
        tmp = adjacent[pos][i];
        if (State[tmp] == 2)
        {
            int r;
            ans.push(tmp);
            while (s.top() != tmp)
            {
                r = s.top();
                ans.push(r);
                s.pop();
            }           
            ans.push(s.top());
            return true;
        } 
        if (DFS (tmp)) return true;
    }
    State[pos] = 1;
    s.pop();
    return false;
}

int main ()
{
    Init();
    for (int i = 1; i <= n; ++i)
    {
        if (State[i] != 0) continue;
        if (DFS (i)) 
        {
            printf ("%d\n",ans.size());
            while (!ans.empty())
            {
                printf ("%d ", ans.top());
                ans.pop();
            }
            return 0;
        }
    }
    printf ("IMPOSSIBLE");
    return 0;
}