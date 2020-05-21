#include <bits/stdc++.h>
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long

int main()
{
    std::ofstream fout("RESERVES.OUT",std::ios::out);
    std::ifstream fin("RESERVES.INP",std::ios::in);
    int i,j,n;
    fin >> n;
    bool lowest[n][n];
    ll dirt[n][n];
    ll result = 0;

    fo(i,n) fo(j,n) lowest[i][j]=false;

    fo(i,n)
    {
        fo(j,n)
        {
            fin >> dirt[i][j];
        }
    }
    fin.close();

    fo(i,n)
    {
        if(i==0) continue;
        fo(j,n)
        {
            if(j==0) continue;
            if((dirt[i+1][j] > dirt[i][j] || lowest[i+1][j])
            && (dirt[i-1][j] > dirt[i][j] || lowest[i-1][j])
            && (dirt[i][j+1] > dirt[i][j] || lowest[i][j+1])
            && (dirt[i][j-1] > dirt[i][j] || lowest [i][j-1]))
            {
                lowest[i][j]=true;
                result+= dirt[i][j];
            }
        }
    }

    //solve again just for sure
    //it wont hurt anyone right ... :p
    fo(i,n)
    {
        if(i==0) continue;
        fo(j,n)
        {
            if(j==0) continue;
            if((dirt[i+1][j] > dirt[i][j] || lowest[i+1][j])
            && (dirt[i-1][j] > dirt[i][j] || lowest[i-1][j])
            && (dirt[i][j+1] > dirt[i][j] || lowest[i][j+1])
            && (dirt[i][j-1] > dirt[i][j] || lowest [i][j-1]))
            {
                lowest[i][j]=true;
                result+= dirt[i][j];
            }
        }
    }

    fout << result;
    fout.close();
    return 1;
}
