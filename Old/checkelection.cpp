//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "election"
#define maxn 100000
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

typedef char NameFile[1000];

using namespace std;

NameFile input, output, answer;
ifstream fi, fo, fa;

int n, a[maxn], s = 0;

void read()
{
	fi >> n;
	for (int i = 1; i <= n; i++) fi >> a[i], s += a[i];
}

void readInput()
{
  fi.open(input);
}

void readOutput()
{
  fo.open(output);
}

void readAnswer()
{
  fa.open(answer);
}

bool check()
{
  int ans = 0, num, x, out = 0;
  fa >> num;
  for (int i = 1; i <= num; i++)
  {
      fa >> x;
      ans += a[x];
  }
  fo >> num;
  int xmin = 10000000;
  for (int i = 1; i <= num; i++)
  {
      fo >> x;
      out += a[x];
      xmin = min(xmin, a[x]);
  }
  if (ans != out)
  {
      cout << " Ket qua sai!!\n";
      cout << " Output is: " << out << endl;
      cout << " Answer is: " << ans << endl;
      return 0;
  }
    if (out - xmin > s/2)
    {
        cout << " Khong du \n";
        return 0;
    }
// others here


  cout << " Ket qua dung!!! \n";
  return 1;
}

int main()
{
  gets(input);
  gets(output);

  strcpy(answer, input);
  strcat(input,  Task".inp");
  strcat(output, Task".out");
  strcat(answer, Task".out");

  readInput();
  readOutput();
  readAnswer();
  read();
  cout << ((check()) ? "1.00" : "0.00");
  fi.close();
  fo.close();
  fa.close();
  return 0;
//  system("pause");
}
