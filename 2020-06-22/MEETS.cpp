#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "MEETS" + (string)".INP";
    const string FileOUT = "MEETS" + (string)".OUT";
    //freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e6 + 1;
int n;
pair <int, int> Meet [N];

void GetDate ()
{
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> Meet[i].first >> Meet[i].second;
    }
    sort (Meet, Meet + n);
}

int Proccess (int &n)
{
    int Counter = n, ans = 0;
    bitset <N> Check;
    Check.set();
    
    while (Counter > 0)
    {
        ans++;
        stack <pair <int, int> > Stack;
        for (int i = 0; i < n; ++i)
        {
            if (Check[i] == 0) continue;
            if (Stack.empty())
            { 
                Stack.push (Meet[i]);
                Check[i] = 0;
                Counter--;
            }
            else if (Stack.top().second <= Meet[i].first)
            {
                Stack.push (Meet[i]);
                Check[i] = 0;
                Counter--;
            }
        }
    }
    return ans;
}

int Bruce (int &n)
{
    return n;
}

int main ()
{
    Init();
    GetDate();
    int ans = 0;
    if (n < -1000)
    {
        ans = Bruce (n);
    }
    else
    {
        ans = Proccess (n);
    }
    cout << ans;
    return 0;
}