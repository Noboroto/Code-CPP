#include <iostream>
using namespace std;

const int n=9;
bool b[3][3][10],bh[9][10],bc[9][10];
int a[9][9],x[9][9];


void boid()
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++) cout<<x[i][j]<<' ';
        cout<<endl;
    }
    exit (0);
}


void tryyy(int i,int j)
{
    if (a[i][j]==0)
    {
        for (int z=1;z<=9;z++)
        if (bh[i][z] && bc[j][z] && b[i/3][j/3][z])
        {
            bh[i][z]=false;
            bc[j][z]=false;
            b[i/3][j/3][z]=false;
            x[i][j]=z;
            if (i==n-1 && j==n-1)
            {
                boid();
            }
            else
            {
                if (j==n-1) tryyy(i+1,0);
                else tryyy(i,j+1);
            }
            bh[i][z]=true;
            bc[j][z]=true;
            b[i/3][j/3][z]=true;
        }
    }
    else
    {
        x[i][j]=a[i][j];
        if (i==n-1 && j==n-1)
        {
            boid();
        }
        else
        {
            if (j==n-1) tryyy(i+1,0);
            else tryyy(i,j+1);
        }
    }
}



int main()
{

    for (int i=0;i<3;i++)
    for (int j=0;j<3;j++)
    for (int z=0;z<10;z++)b[i][j][z]=true;
    for (int i=0;i<n;i++)
    for (int j=0;j<10;j++)
    {
        bh[i][j]=true;
        bc[i][j]=true;
    }
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
    {
        cin>>a[i][j];
        if (a[i][j]!=0)
        {
            b[i/3][j/3][a[i][j]]=false;
            bh[i][a[i][j]]=false;
            bc[j][a[i][j]]=false;
        }
    }
    cout<<endl<<endl;
    tryyy(0,0);
    return 0;
}
