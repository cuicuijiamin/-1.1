#include<bits/stdc++.h>
using namespace std;
int dx[8]= {-2,-1,1,2,2,1,-1,-2}; //八方向数组
int dy[8]= {1,2,2,1,-1,-2,-2,-1};
queue<pair<int,int> >que;
int n,m,x,y;
int ans[410][410];//存放结果
void bfs(int x,int y)
{
	que.push(make_pair(x,y));
	while(!que.empty())
	{
		pair<int,int> t=que.front();
		que.pop();
		for(int i=0; i<8; ++i)
		{
			if(t.first+dx[i]>=1&&t.first+dx[i]<=n&&t.second+dy[i]>=1&&t.second+dy[i]<=m&&ans[t.first+dx[i]][t.second+dy[i]]==-1)
			{
				//该方向可以走
				//放心入队
				que.push(make_pair(t.first+dx[i],t.second+dy[i]));
				ans[t.first+dx[i]][t.second+dy[i]]=ans[t.first][t.second]+1;
			}
		}
	}
}
int main()
{
	memset(ans,-1,sizeof(ans));
	cin>>n>>m>>x>>y;
	ans[x][y]=0;
	bfs(x,y);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
			printf("%-5d", ans[i][j]);
		cout<<endl;
	}
	return 0;
}
