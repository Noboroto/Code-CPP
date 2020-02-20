#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

set <int> mod;
int t;

using namespace std;

int main()
{
    for (int i = 0; i < 10; ++i) mod.insert(i*i%10);
    scanf("%d\n", &t);

    return 0;
}
