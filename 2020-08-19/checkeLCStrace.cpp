#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define maxn 1000005
#define task "GOLDtrace"

typedef char NameFile[1000];

using namespace std;

NameFile input, output, answer;
ifstream fi, fo, fa;

long long n, m, a[maxn], L1, L2, sum, k, x, tmp;

int read()
{
	fi >> n;
	FOR(i,1,n) fi >> a[i];

}

int readInput()
{
    fi.open(input);
}

int readOutput()
{
    fo.open(output);
}

int readAnswer()
{
    fa.open(answer);
}

int check()
{
    long long ans, out;
    fo >> out;
    fa >> ans;

    if (out!=ans)
    {
        cout << " Ket qua sai!!\n";
      //cout << " Output is: " << out << endl;
      //cout << " Answer is: " << ans << endl;
        return 0;
    }
    // others here
    fi >> n >> L1 >> L2;
    FOR(i,1,n) fi >> a[i];

    fo >> k;
    fo >> x;
    sum = a[x];

    for(int i=2; i<=k; i++)
    {
        fo>>tmp;
        if(!(x+L1 <= tmp && tmp <= x+L2))
        {
            cout<<" Khoang cach khong dung! \n";
            return 2;
        }
        sum+=a[tmp];
        x = tmp;
    }
    if(sum!=out)
    {
        cout<<" Tong khong dung!! \n";
        return 2;
    }
    cout << " Ket qua dung!!! \n";
    return 1;
}

main()
{
    gets(input);
    gets(output);

    strcpy(answer, input);
    strcat(input,  task".inp");
    strcat(output, task".out");
    strcat(answer, task".out");

    readInput();
    readOutput();
    readAnswer();
  //read();

    int res = check();
    if(res == 0) cout<<"0.00";
    else if(res == 1) cout<<"1.00";
    else if(res == 2) cout<<"0.50";

    fi.close();
    fo.close();
    fa.close();
}
