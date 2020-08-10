#include <iostream>
#include <vector>

using namespace std;

struct edge{
    int u, v, c;
    edge (int _u = 0, int _v = 0, int _c = 0){
        u = _u;
        v = _v;
        c = _c;
    }
};
const int N = 2222*12;
int n, m;
vector <edge> a;
vector <int> tmp;

void start (){
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        for (int j = tmp.size() - 1; j > tmp.size() -  )
    }
}

int main (){
    start ();
    return 0;
}