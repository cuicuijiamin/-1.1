#include<bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
int ma[1005][1005],vis1[1005][1005],vis2[1005][1005];
int d1[1005][1005],d2[1005][1005];
int cnt;
struct node{
	int x,y;
}sta,to,is[1000005];
void bfs(){
	queue<node>q1,q2;
	q1.push(sta),q2.push(to);
	memset(d1,INF,sizeof(d1)); memset(d2,INF,sizeof(d2));
	d1[sta.x][sta.y]=0; vis1[sta.x][sta.y]=1;
	d2[to.x][to.y]=0; vis2[to.x][to.y]=1;
	while(!q1.empty()){
		node u=q1.front();q1.pop();
		for(int i=0;i<4;++i){
			int xx=u.x+dx[i],yy=u.y+dy[i];
			if(vis1[xx][yy]||xx<1||yy<1||xx>n||yy>m||ma[xx][yy]==1) continue;
			//if(d1[u.x][u.y]+1>=d1[xx][yy])continue;
			vis1[xx][yy]=1;
			d1[xx][yy]=d1[u.x][u.y]+1;
			q1.push((node){xx,yy});
		}
	}
	while(!q2.empty()){
		node u=q2.front();q2.pop();
		for(int i=0;i<4;++i){
			int xx=u.x+dx[i],yy=u.y+dy[i];
			if(vis2[xx][yy]||xx<1||yy<1||xx>n||yy>m||ma[xx][yy]==1) continue;
			//if(d2[u.x][u.y]+1>=d2[xx][yy])continue;
			vis2[xx][yy]=1;
			d2[xx][yy]=d2[u.x][u.y]+1;
			q2.push((node){xx,yy});
		}
	}
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&ma[i][j]);
			if(ma[i][j]==2)sta.x=i,sta.y=j;
			if(ma[i][j]==3)to.x=i,to.y=j;
			if(ma[i][j]==4)is[++cnt].x=i,is[cnt].y=j;
		}
	}
	bfs();
	int ans=INF;
	for(int i=1;i<=cnt;++i){
		ans=min(ans,d1[is[i].x][is[i].y]+d2[is[i].x][is[i].y]);
	}
	cout<<ans;
	return 0;
}
