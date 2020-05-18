#include <bits/stdc++.h>

#define deb(x) std::cout << #x << x << std::endl;
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long

int main()
{
    std::ofstream fout("SUADUONG.OUT",std::ios::out);
    std::ifstream fin("SUADUONG.INP",std::ios::in);

    int n,m,i,j,from,to;
    fin >> n >> m;
    ll times[n][n];
    ll longestTime[n];

    fo(i,n)
        fo(j,n)
            times[i][j] =0;

    fo(i,m)
    {
        fin >> from >> to;
        fin >> times[from][to];
    }
    fin.close();

    fo(i,n)
    {
        longestTime[i]=0;
    }

    fo(i,n)
    {
        fo(j,n)
        {
            ll sum = times[i][j];
            if (longestTime[i] < sum)
                longestTime[i] = sum;
        }
    }
    fout << longestTime[n-1];
    fout.close();
}
