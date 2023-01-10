#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, t;
int r1, c1, r2, c2;
char a[105][105];//地图
int vis[105][105][20];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int dfs(int x,int y,int time)
{
	if(vis[x][y][time]!=-1)
		return vis[x][y][time]; 
	if(time>t)
		return vis[x][y][time]=0;
	if(time+abs(r2-x)+abs(c2-y)>t)//剪枝
	{
		return vis[x][y][time]=0;
	}
	if(time==t)
	{
		if(x==r2&&y==c2) return vis[x][y][time]=1;
		else return vis[x][y][time]=0;
	}
		
	int ans=0;
	for(int i=0; i<4; ++i)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!='*')
			ans+=dfs(nx,ny,time+1);
	}
	return vis[x][y][time]=ans;
}
int main()
{
	memset(vis,-1,sizeof(vis));
	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", a[i]+1);
	}
	cin >> r1 >> c1 >> r2 >> c2;
	
	cout << dfs(r1,c1,0) << endl;
	return 0;
}
