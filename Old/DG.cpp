#include <bits/stdc++.h>
using namespace std;
struct Oxy
    {
        int64_t x,y;
    };
Oxy aa[1000000],bb[1000000];
int64_t o,x1,x2,yA,y2,a,b,i,j,d,t;
double goc,xycos,PI=2*acos(0);
int main()
    {
        freopen ("DG.INP", "r", stdin);
        freopen ("DG.OUT", "w", stdout);
        cin>>t;
        for (o=1;o<=t;++o)
        {
            cin>>a;
            for (i=1;i<=a;++i) cin>>aa[i].x>>aa[i].y;
            cin>>b;
            for (i=1;i<=b;++i) cin>>bb[i].x>>bb[i].y;
            for (i=1;i<=b;i++)
            {
                for (j=1;j<=a;j++)
                {
                    x1=bb[i].x-aa[j].x;
                    if (j+1<=a) x2=bb[i].x-aa[j+1].x; else x2=bb[i].x-aa[1].x;
                    yA=bb[i].y-aa[j].y;
                    if (j+1<=a) y2=bb[i].y-aa[j+1].y; else y2=bb[i].y-aa[1].y;
                    xycos=(x1*x2+yA*y2)/(sqrt(x1*x1+yA*yA)*sqrt(x2*x2+y2*y2));
                    goc=goc+acos(xycos);
                }
                if (abs(goc-2*PI)<=10e-13) d++;
                goc=0;
            }
            if (d==b) cout<<"YES"; else cout<<"NO";
            d=0;
            if (o < t)cout << endl;
        }
        return 0;
    }
