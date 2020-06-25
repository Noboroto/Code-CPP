#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3000;

const long long oo = 1000000007;

int n , k, a[N + 1], b[N + 1];
long long C[N + 1][N + 1], nC[N + 1][N + 1];
long long S;

void Init()
{
    const string FileINP = "Bai2-ToHop" + (string)".INP";
    const string FileOUT = "Bai2-ToHop" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

void Prepare()
{
    C[1][0] = C[0][0] = C[1][1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            nC[i][j] = C[i][j] % oo;
        }
    }
}

void Tim_To_Hop()
{
    long long S = ::S - 1;
    for (int i = 1,rem = n-1, left = k - 1; i<=k; ++i)
    {
        for ( ; ; )
        {
            if (S >= C[rem][left])
            {
                S -= C[rem][left];
                --rem;
            }
            else break;
        }
        a[i] = n - rem;
        --rem;
        --left;
    }
    for (int i = 1; i <= k; ++i)
        cout << a[i] << " " ;
    cout << endl;
}

long long Tim_Vi_Tri()
{
    sort (b+1, b+k+1);
    long long Y = 0;
    for (int i=1,l=k-1; i<=k; ++i,--l)
    {
        int inc = b[i] - b[i-1] - 1, cnt = n - 1 - b[i-1];
        for (int j=1,z=cnt; j<=inc; ++j, --z)
        {
            Y += nC[z][l];
            Y %= oo;
        }
    }
    return Y + 1;
}

int main()
{    
    Init();
    cin >> n >> k >> S;
    for (int i = 1; i <= k; ++i) cin >> b[i];
    Prepare();
    Tim_To_Hop();
    cout << Tim_Vi_Tri();
    return 0;
}
