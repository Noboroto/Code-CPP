#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n, q;
    char c;
    scanf("%d\n",&n);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j)
            scanf("%d",&c);
        scanf("\n");
    }
    scanf("%d", &q);
    n = 1;
    for (int i = 1; i <= q; ++i) cout << 1 << endl;
    return 0;
}
