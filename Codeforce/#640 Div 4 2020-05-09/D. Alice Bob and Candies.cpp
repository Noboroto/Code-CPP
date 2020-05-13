#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
    const string FileINP = "D. Alice Bob and Candies" + (string)".INP";
    const string FileOUT = "D. Alice Bob and Candies" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1000 + 1;
int t, Candy [N];

void Process (int n)
{
    int a = Candy[0], b = 0, Alice, Bob, previous = Candy[0], i = 1, j = n - 1;
    Candy[0] = 0;
    int CountCandy = n - 1;
    int CountMove = 1;
    while (CountCandy > 0)
    {
        Bob = 0;
        while (Bob <= previous)
        {
            Bob += Candy[j];
            CountCandy--;
            j--;
            if (CountCandy <= 0) break;
        }
        b += Bob;
        CountMove++;
        if (CountCandy <= 0) break;
        previous = Bob;
        Alice = 0;
        while (Alice <= previous)
        {
            Alice += Candy[i];
            CountCandy--;
            i++;
            if (CountCandy <= 0) break;
        }
        a += Alice;
        CountMove++;
    }
    cout << CountMove << ' ' << a << ' ' << b << '\n';
}

int main ()
{
    int t, n;
    //Init();
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        for (int j = 0; j < n; ++j) cin >> Candy[j];
        Process (n);
    }
    return 0;
}