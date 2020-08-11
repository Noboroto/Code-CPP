#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "LAND" + (string)".INP";
    const string FileOUT = "LAND" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 4 + 1;//100
int n, buy_cost, waste_cost, move_cost;
pair <int, int> soil[N];
vector<int>  Need, Redundancy;

int main ()
{
    //Init();
    cin >> n >> buy_cost >> waste_cost >> move_cost;
    for (int i = 0; i < n; ++i)
    {
        cin >> soil[i].first >> soil[i].second;
        if (soil[i].first > soil->second) Redundancy.push_back(i);
        else if (soil[i].first < soil[i].second) Need.push_back(i);
    }
    return 0;
}