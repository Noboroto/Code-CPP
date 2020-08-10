#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef double db;

struct Point {
    int x, y;
    Point (int _x = 0, int _y = 0){
        x = _x;
        y = _y;
    }
};

db GetDistance (Point a, Point b){
    db ans = abs (a.x - b.x) + abs (a.y - b.y);
    return ans;
}
int n;
vector <Point> a;
vector <int> all_x;
vector <int> all_y;

db SumLength (Point A){
    db ans = 0;
    for (int i = 0; i < n; ++i){
        ans += GetDistance(A, a[i]);
    }
    return ans;
}

int main()
{
   // freopen("DISTANCE.INP", "r", stdin);
   // freopen("DISTANCE.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        a.push_back(Point(x, y));
        all_x.push_back(x);
        all_y.push_back(y);
    }
    sort(all_x.begin(), all_x.end());
    sort(all_y.begin(), all_y.end());
    Point A, B;
    int mid = n /2;
    A = Point (all_x[mid], all_y[mid]);
    B = Point (all_x[mid + 1], all_y[mid + 1]);
    db ans = min (SumLength(A), SumLength(B));
    cout << setprecision (2) << fixed << ans;
    return 0;
}
