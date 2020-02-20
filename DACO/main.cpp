#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;
const int maxn = 10000 + 1;

struct node {
    int f, trace;
};

int a [maxn];
node f [maxn];

int start (int& n){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            f[i].f = 1;
            f[i].trace = i;
    }
    return 0;
}

int build (int&n){
    ofstream input;
    input.open("DACO.INP");
    srand(time(NULL));
    int n_to = 10000, a_to = 1000000000;
    n = rand() % n_to + 1;
    input << n << endl;
	for (int i = 1; i <= n; ++i){
        int c = rand() % a_to + 1;
        a[i] = c;
        input << c << ' ';
	}
	input.close();
    return 0;
}

int solve (int n){
    node maxa;
    maxa.f = 0;
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j < i; ++j){
            if (a[j] >= a[i]) continue;
            if (f[i].f < f[j].f + 1){
                f[i].f = f[j].f + 1;
                f[i].trace = j;
            }
        }
        if (f[i].f > maxa.f) {
            maxa.f = f[i].f;
            maxa.trace = i;
        }
    }
    int c [maxn];
    int i = 0;
    c[0] = a[maxa.trace];
    node x = f[maxa.trace];
    cout << maxa.f << endl;
    while (x.f > 1){
        c [++i] = a[x.trace];
        x = f[x.trace];
    }
    while (i >= 0) {
        cout << c[i] << ' ';
        i--;
    }
    return 0;
}

int main()
{
    int n;
    //build(n);
    freopen("DACO.INP", "r",stdin);
    freopen("DACO.OUT", "w", stdout);
    start(n);
    solve(n);
}
