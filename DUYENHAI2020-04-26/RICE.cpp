#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n, k, m;
vector <pair <int, int> > PictureLimit;
stack <int> Process;

void Init ()
{
    const string FileINP = "RICE" + (string)".INP";
    const string FileOUT = "RICE" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
    cin >> n >> m >> k;
}

int main ()
{
    Init();
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        PictureLimit.push_back(make_pair(x, 1));
        PictureLimit.push_back(make_pair(x + k - 1, -1));
    }
    sort (PictureLimit.begin(), PictureLimit.end());
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < PictureLimit.size(); ++i)
    {
        if (PictureLimit[i].second == 1) Process.push(PictureLimit[i].first);
        else 
        {
            if (tmp > 1) ans += (PictureLimit[i].first - Process.top() + 1);
            Process.pop();
        }
        tmp += PictureLimit[i].second;
    }
    cout << ans;
    return 0;
}