#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("hanoi.INP", "r", stdin);
    freopen ("hanoi.OUT", "w", stdout);
}

const int N = 1e3 + 100;
int Data[N][N];
int n, m, k;
const int Dx[4] = {0, 1, 0, -1};
const int Dy[4] = {-1, 0, 1, 0};
vector < pair <int, int> > ans;
map <int, bool> Filled;

void GetData ()
{
    char c;
    cin >> n >> m >> k;
    for (int i = 0; i <= max (n, m) + 1; ++i)
    {
        if (i <= m + 1) 
        {
            Data[0][i] = 1;
            Data[n + 1][i] = 1;
        }
        if (i <= n + 1)
        {
            Data[i][0] = 1;
            Data[i][m + 1] = 1;
        }
    }
    string s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        for (int j = 1; j <= m; ++j)
        {
            if (s[j - 1] == '#')
            {
                Data[i][j] = -1;
            }
            else 
            {
                Data[i][j] = 1e9 + 7;
            }
        }
    }
}

    queue < pair <int, int> > q;

int Loang (pair <int, int> StartPoint, int Counter)
{    
    pair <int, int> u, v;
    q.push(StartPoint);
    int sum = 0;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        sum++;
        Data[u.first][u.second] = Counter;
        for (int i = 0; i < 4; ++i)
        {
            if (u.first + Dx[i] < 0 || u.second + Dy[i] < 0 || u.first + Dx[i] > n + 1 || u.second + Dy[i] > m + 1) continue;
            v = make_pair(u.first + Dx[i], u.second + Dy[i]);
            if (Data[v.first][v.second] <= Counter) continue;
            Data[v.first][v.second] = Counter;
            q.push(v);
        }
    }
    return sum;
}

int main ()
{
    Init();
    GetData();
    Loang (make_pair(0, 0), 0);
    int Counter = 1, sum = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (Data[i][j] != 1e9 + 7) continue;
            sum = Loang(make_pair(i, j), Counter);
            ans.push_back(make_pair(sum, Counter));
            Counter++;
        }
    }
    sort (ans.begin(), ans.end());
    int Result = 0;
    for (int i = 0; i < ans.size() - k; ++i)
    {
        Result += ans[i].first;
        Filled[ans[i].second] = true;
    }
    cout << Result << "\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (Data[i][j] == -1 || Filled[Data[i][j]]) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
    return 0;
}