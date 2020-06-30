#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "CONTROL" + (string)".INP";
    const string FileOUT = "CONTROL" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e5 + 1;
string Command;
int n, m;
pair <int, int> DiNgang[N], DiDoc[N], Result;

void GetData ()
{
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> y >> x;
        DiNgang[i].first = x;
        DiDoc[i].second = x;
        DiNgang[i].second = y;
        DiDoc[i].first = y;
    }
    cin >> Command; 
    sort (DiDoc, DiDoc + n);
    sort (DiNgang, DiNgang + n);
}

pair <int, int> Solve ()
{
    pair <int, int>* k = 0;
    pair <int, int> Ans = {0 , 0};
    for (int i = 0; i < Command.size(); i++)
    {
        switch (Command[i])
        {
        case 'U':
            k = upper_bound (DiDoc, DiDoc + n, Ans);
            break;
        case 'D':
            k = lower_bound (DiDoc, DiDoc + n, Ans) - 1;
            break;
        case 'R':
            k = upper_bound (DiNgang, DiNgang + n, pair <int, int> {Ans.second, Ans.first});
            break;
        case 'L':
            k = lower_bound (DiNgang, DiNgang + n, pair <int, int> {Ans.second, Ans.first}) - 1;
            break;
        default:
            break;
        }
        switch (Command[i])
        {
        case 'U':
        case 'D':
            Ans = *k;
            break;
        case 'R':
        case 'L':
            Ans.second = (*k).first;
            Ans.first = (*k).second;
            break;
        }
    }
    return Ans;
}

int main ()
{
    Init();
    GetData();
    Result = Solve ();
    cout << Result.first << ' ' << Result.second;
    return 0;
}