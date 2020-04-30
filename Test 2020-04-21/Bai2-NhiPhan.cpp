#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "Bai2-NhiPhan" + (string)".INP";
    const string FileOUT = "Bai2-NhiPhan" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n, k;
vector <int> Root;
string quiz;
vector <int> Question;

void Transform (string s)
{
    Question.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        Question.push_back ((int)(s[i] - '0'));
    }
}

void Tim_Nhi_Phan(int k)
{
    vector <int> NhiPhan;
    for (int i = 0; i <= n;  ++i)
    {
        NhiPhan.push_back(0);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (k > Root[n - i])
        {
            NhiPhan[i - 1] = 1;
            k -= Root[n - i];
        }
    }
    for (int i = 1; i <= n; ++i) cout << NhiPhan [i];
    cout << endl;
}

int main ()
{
    Init();
    cin >> n;
    cin >> k;
    cin >> quiz;
    Transform (quiz);
    Root.push_back(1);
    for (int i = 1; i <= n; ++i)
    {
        Root.push_back(Root[i - 1] *2);
    }    
    int ans = 0;
    Tim_Nhi_Phan(k);
    for (int i = 1; i <= n; ++i) 
        if (Question[i] == 1) ans += Root[n - i];
    cout << ans + 1;
    return 0;
}