#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
    const string FileINP = "LADA" + (string)".INP";
    const string FileOUT = "LADA" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

struct Node 
{
    int value, index;
    Node (int _value = 0, int _index = 0)
    {
        value = _value;
        index = _index;
    }
};

const int N = 400 + 2;
int n, k;
Node Dx [N], Dy [N];

int main ()
{
    Init();
    cin >> n >> k;
    int x, y;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        Dx[i] = {x - 1, -i};
        
    }
    return 0;
}