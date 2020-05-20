#include <bits/stdc++.h>
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define deb(x) std::cout << #x << x << std::endl;

int main()
{
    std::ofstream fout("LUCKY.OUT",std::ios::out);
    std::ifstream fin("LUCKY.INP",std::ios::in);

    int n,i,j;
    ll k;
    fin >> n >> k;
    ll a[n];
    fo(i,n)
    {
        fin >> a[i];
    }
    fin.close();
    int count=0;
    fo(i,n)
    {
        Fo(j,i,n)
        {
            if(i==j) continue;
            if(std::abs(a[i]+a[j]) == k)
                count++;
        }
    }
    fout << count;
    //deb(count);
    fout.close();
}
