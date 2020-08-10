#include <iostream>

using namespace std;

int ans = 0;

void DFS (int x, int y, int count) 
{
    if (x > 6 || y > 5) return;
    if (x == 6 && y == 5)
    {
        if (count == 9) ans++;
        return;
    }
    DFS (x + 1, y, count + 1);
    DFS (x, y + 1, count + 1);
}

int main ()
{
    DFS (1, 1, 0);
    cout << ans;
    return 0;
}