#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int n, q, i, j;
int A[100005], B[100005];

int main()
{
    //freopen("LAMP.inp", "r", stdin);
    //freopen("LAMP.out", "w", stdout);
    cin>>n>>q;
    for(int i=1; i<=q; i++) cin>>A[i]>>B[i];
    sort(A+1, A+1+q);
    sort(B+1, B+1+q);
    i=0; j=0;
    A[q+1]=n+1;
    B[q+1]=n+1;
    for(int a=1; a<=n; a++)
    {
        while(A[i+1]<=a) i++;
        while(B[j+1]<a) j++;
        cout<<min(i, q-j)%2<<" ";
    }
    return 0;
}
