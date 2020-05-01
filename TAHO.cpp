#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <string> ans;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    if (n + m < 3)
    {
        cout << 0;
        return 0;
    }
    while (n > 0 && m > 0 && n + m >= 3)
    {
        if (n < m) 
        {
            ans.push_back("1 2");
            n--;
            m-=2;
        }
        else
        {
            ans.push_back("2 1");
            n-=2;
            m--;
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}