#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("SALARY.INP", "r", stdin);
    freopen ("SALARY.OUT", "w", stdout);
}

const int N = 3e5 + 1;
int n, Salary[N], Ancestor[N];

int CheckSalary (int pos)
{
    if (Salary[pos] > Salary[Ancestor[pos]]) 
    {
        Salary[Ancestor[pos]] = Salary[pos];
        return CheckSalary(Ancestor[pos]) + 1;
    }
    else return 0;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int anc;
    Init();
    cin >> n;
    cin >> Salary[0];
    for (int i = 1; i <= n; ++i)
    {
        cin >> Salary[i] >> Ancestor[i];
        cout << CheckSalary(i) << "\n";
    }
    return 0;
}