#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;
int sd[55][55];
int a[55][55];//a为读入的方格地图 
int n,m;
int x11,y11;//起点 
int x2,y2;//终点 
int f[55][55];//f为格点地图 

int fx[5]={0,-1,1,0,0};//fx[i]表方向i(编号)的x情况  
int fy[5]={0,0,0,-1,1};//fy[i]表方向i(编号)的y情况 
int ft[5]={0,1,4,2,3};//ft[i]表示顺时针排列各个方向的编号(上1 右4 下2 左3) 
int fft[5]={0,1,3,4,2};//fft[i]表示数字i在ft[]数组中的下标 

int abc[5]={0,1,2,1,0};//abc[5]表示转到[顺时针转i次到达的那个方向]的最短次数 
struct node
{
	int x,y;//当前点的坐标 
	int t;//1=>N 2=>S 3=>W 4=>E 方向编号 
	int time;//从起点到当前点的最短时间 
};
queue<node> q;//队列q 
string ch;//读入起点的方向 
int cto;//起点的方向 

void fxto()
{
	switch(ch[0])
	{
		case 'N': cto=1;break;
		case 'S': cto=2;break;
		case 'W': cto=3;break;
		case 'E': cto=4;break;
	}
	return;
}
void change()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(sd[i][j]==1)//如果当前格为障碍物，则它的四个顶点都不能走 
			{
				a[i-1][j]=1;
				a[i][j-1]=1;
				a[i-1][j-1]=1;
				a[i][j]=1;
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&sd[i][j]);
		}
	}
	cin>>x11>>y11>>x2>>y2;
	cin>>ch;
	fxto();//判断ch代表的方向 
	change();//把方格地图转化为机器人可以走的格点地图 
	node first;//起点 
	first.x=x11;
	first.y=y11;
	first.t=cto;
	first.time=0;
	q.push(first);//起点入队 
	node u,d;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int i=1;i<=4;++i)
		{
			int zhuan=abc[i];//[顺时针转i下的那个方向]的最短旋转次数 
			
			//求出旋转完了以后方向的编号fangx(为了方便讨论，全部当做顺时针旋转) 
			int fangx=fft[u.t]+i;//此时fangx为下标 
			if(fangx==5) fangx=1;
			if(fangx==6) fangx=2;
			if(fangx==7) fangx=3;
			if(fangx==8) fangx=4;
			fangx=ft[fangx];//此时fangx为方向编号 
			//此时fangx存的是由当前点顺时针转了i次后到达的方向的编号
			 
			for(int j=1;j<=3;++j)//走1~3步 
			{
				int lsx=u.x+fx[fangx]*j;//计算按当前旋转方向走j步的坐标 
				int lsy=u.y+fy[fangx]*j;
				if(lsx>=n || lsx<=0 || lsy>=m || lsy<=0 || (lsx==x11&&lsy==y11) || a[lsx][lsy]==1)
				{
					//判断边界和障碍物 (特判：是否为起点)
					break;
				}
				if((u.time+zhuan+1<f[u.x+fx[fangx]*j][u.y+fy[fangx]*j] || f[u.x+fx[fangx]*j][u.y+fy[fangx]*j]==0) && a[u.x+fx[fangx]*j][u.y+fy[fangx]*j]==0)
				{//如果当前点可以刷新距离，就入队 
					d.x=u.x+fx[fangx]*j;
					d.y=u.y+fy[fangx]*j; 
					d.t=fangx;
					d.time=u.time+zhuan+1;
					f[u.x+fx[fangx]*j][u.y+fy[fangx]*j]=d.time;
					q.push(d);
				}
			}
		}
	}
	if(f[x2][y2]==0 && (x2!=x11 || y2!=y11))//如果为0，代表不能走到 
	{
		cout<<"-1"<<endl;
	}
	else//否则输出终点的距离 
	cout<<f[x2][y2]<<endl;
	return 0;
}
