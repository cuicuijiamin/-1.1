#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
const int INF=0x3f3f3f3f;
int a[MAXN][MAXN];
int dis[MAXN][MAXN];
int dx[]= {0,1,0,-1,1,1,-1,-1,0,2,0,-2};
int dy[]= {1,0,-1,0,1,-1,1,-1,2,0,-2,0};
int dw[]= {0,0,0,0,2,2,2,2,2,2,2,2};
typedef struct node
{
	int x,y,c,w;
	node(int xx,int yy,int cc,int ww)
	{
		x=xx;
		y=yy;
		c=cc;
		w=ww;
	}
	bool operator <(const struct node & oth)const
	{
		return w>oth.w;
	}
} node;
priority_queue<node>que;

int m,n;
void bfs(int x,int y)
{
	que.push(node(1,1,a[1][1],0));
	while(!que.empty())
	{
		node t=que.top();
		que.pop();
		if(t.w>dis[t.x][t.y]) continue;

		for(int i=0; i<12; ++i)
		{
			int nx=t.x+dx[i];
			int ny=t.y+dy[i];
			int nw=t.w+dw[i];
			int nc=a[nx][ny];
			if(nx>=1&&nx<=m&&ny>=1&&ny<=m&&nc!=-1)
			{
				if(nc!=t.c)nw++;
				if(dis[nx][ny]>nw)
				{
					dis[nx][ny]=nw;
					que.push(node(nx,ny,nc,nw));
				}
			}
		}
	}
}
int main()
{
	memset(a,-1,sizeof(a));
	memset(dis,INF,sizeof(dis));
	dis[1][1]=0;
	cin>>m>>n;
	for(int i=1; i<=n; ++i)
	{
		int x,y,c;
		cin>>x>>y>>c;
		a[x][y]=c;//a数组存放颜色
	}
	bfs(1,1);//从1，1点开始

	if(a[m][m]==-1)//没颜色 
	{
		int ans=min(dis[m-1][m],dis[m][m-1])+2;//从前一步施加魔法过来
		if(ans>=INF)
			cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
	else
	{
		int ans=dis[m][m];
		if(ans==INF)cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
