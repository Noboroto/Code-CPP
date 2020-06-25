#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "Bai2-HoanVi" + (string)".INP";
    const string FileOUT = "Bai2-HoanVi" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n, k;
vector <int> Root;
string quiz;
vector <int> Question;

void Transform (string s)
{
    for (int i = 0; i < n; ++i)
    {
        Question.push_back ((int)(s[i] - '0'));
    }
}

int Tim_K (int i)
{
    vector <bool> Free;
    for (int j = 0; j <= n; ++j) Free.push_back (false);
    for (int j = 0; j < i; ++j) Free[Question[j]] = true;
    int ans = 0;
    for (int j = 1; j <= n; ++j) 
    if (!Free[j] && j < Question[i - 1]) ans++;
    return ans;
}

void Tim_Hoan_Vi(int k)
{
    vector <int> HoanVi;
    vector <bool> Free;
    for (int i = 0; i <= n;  ++i)
        {
            HoanVi.push_back(0);
            Free.push_back(true);
        }
    for (int i = 1; i <= n; ++i)
    {
        int j;
        for (j = 1; j <= n; ++j)
        {
            if (Free[j]) 
            {
                if (k > Root[n - i]) k -= Root [n - i];
                else break;
            }
        }
        HoanVi[i] = j;
        Free[j] = false;
    }
    for (int i = 1; i <= n; ++i) cout << HoanVi [i] << " ";
    cout << endl;
}

int main ()
{
    //Init();
    cin >> n;
    cin >> k;
    //cin >> quiz;
    Transform (quiz);
    Root.push_back(1);
    for (int i = 0; i < n; ++i)
    {
        Root.push_back(Root[i] * (i + 1));
    }    
    int ans = 0;
    //for (int i = 1; i <= n; ++i) ans += Tim_K(i) * Root[n - i];
    Tim_Hoan_Vi(k);
    //cout << ans + 1;
    return 0;
}