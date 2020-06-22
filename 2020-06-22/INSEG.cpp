#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
int n;
pair <int, int>  Point [2*N];

void GetDate ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d %d", &Point[i].first, &Point[i + n].first);
        Point[i].second = -1, Point[i + n].second = 1;
    }
    sort (Point, Point + 2*n);
}

int Proccess (int &n)
{
    int Counter = 0, ans = 0;
    for (int i = 0; i < 2*n; ++i)
    {
        Counter += Point[i].second;
        ans = max (ans, abs (Counter));
    }
    return ((ans > 1) ? ans : 0);
}

int main ()
{
    const string FileINP = "INSEG" + (string)".INP";
    const string FileOUT = "INSEG" + (string)".OUT";
    //freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
    GetDate();
    printf ("%d", Proccess (n));
    return 0;
}