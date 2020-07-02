#include <bits/stdc++.H>

using namespace std;

void Init ()
{
    const string FileINP = "FROGS" + (string)".INP";
    const string FileOUT = "FROGS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
}

const int oo = 1e9 + 1;
const int N = 10 + 1;
int n, H[N], J[N], tmh[N], tmj[N], pos[N];

void GetData ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &H[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &J[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        tmh[i] = H[i];
        tmj[i] = J[i];
    }
}

void Reset ()
{
    for (int i = 1; i <= n; ++i)
    {
        H[i] = tmh[i];
        J[i] = tmj[i];
    }
}

void Bruce_Force_1e4 ()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (J[j] == 0) continue;
            if (H[i] <= H[j]) continue;
            H[j] = H[i];
            J[j]--;
        }
    }
}

void Print_Result (int *H)
{
    for (int i = 1; i <= n; ++i)
    {
        if (J[i] > 0) cout << -1 << ' ';
        else cout << H[i] << ' ';
    }
    cout << "\n\n";
}

void Process ()
{
    H[n + 1] = oo;
    pos[n] = n + 1; 
    for (int i = n - 1; i > 0; --i)
    {
        for (int j = i; j <= n +; ++j)
        {
            if (H[i] < H[j])
            {
                J[i]--;
                pos[i] = j;
                break;
            }
        }
        int j = pos[i];
        while (J[i] > 0 && H[j] != -1)
        {
            j = pos[j];
            J[i]--;
        }
        pos[i] = j;
    }
    H[n + 1] = -1;
    for (int i = 1; i <= n; ++i)
    {
        cout << H[pos[i]] << ' ';
    }
}

int main ()
{
    Init();
    GetData();
    Bruce_Force_1e4();
    Print_Result(H);
    Reset ();
    Process();
    return 0;
}