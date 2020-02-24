
#include<bits/stdc++.h>
using namespace std;
const int p[]={-1,0,1,0};
const int q[]={0,1,0,-1};
char c[1000][1000];
bool vis[1000][1000];
int n,m,k,tot;

void dfs(int x,int y)
{
  vis[x][y]=true;
  for (int i=0;i<4;i++)
  {
  	int xx,yy;
  	xx=x+p[i];
	yy=y+q[i];
  	if (xx>=0&&xx<n&&yy>=0&&yy<m&&c[xx][yy]=='.'&&(!vis[xx][yy])) dfs(xx,yy);
  }
  if (tot<k)
  {
  	c[x][y]='X';
  	tot++;
  }
}
void print()
{
  for (int i=0;i<n;i++) printf("%s\n",c[i]);
}
int main()
{
  scanf("%d%d%d",&n,&m,&k);
  for (int i=0;i<n;i++) scanf("%s",c[i]);
  for (int i=0;i<n;i++)
  for (int j=0;j<m;j++)
  if (c[i][j]=='.') {dfs(i,j);print();return 0;}
  return 0;
}
