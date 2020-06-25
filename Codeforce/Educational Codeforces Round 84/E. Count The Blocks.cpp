#include <iostream>

using namespace std;

const int oo = 998244353;
const int N = 50;
long long Blocks [N];

bool Check_Blocks (int Value)
{
    bool Check = true;
    int Seed = Value % 10;
    while (Value > 0)
    {
        Check = (Value % 10) == Seed;
        Value /= 10;
    }
    return Check;
}

int Blocks_One_Num (int Value)
{
    if (Value < 10) return 1;
    int ans = 1;
    int Seed = Value % 10;
    Value /= 10;
    while (Value > 0)
    {
        ans += (Value % 10) != Seed;
        Seed = Value % 10;
        Value /= 10;
    }
    return ans;
}

void Add_Blocks ()
{

}

void Test ()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << Blocks[i] << ' ';
    }
}

long long Count_Blocks (int &n)
{
    long long ans = 0, multiple = 1;
    for (int i = 0; i <= n; ++i) Blocks[i] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i % 10 == 0) 
        { 
            multiple *= 10;
        }
        Blocks[i] += Blocks_One_Num(i);
        if (i < 10) continue;
        if ((i - 1) % 10 == i / multiple) Blocks[i]--; 
    }
    for (int i = 1; i < n; ++i)
    {
        ans += Blocks[i];
    }
    //Test();
    return ans;
}

int main ()
{    
    int n, tmp = 10;
    cin >> n;
    
    cout << Count_Blocks (n);
    return 0;
}