#include<bits/stdc++.h>
using namespace std;
int n,a[35][35];//全局变量自动初始化为0
stack<pair<int,int> >que;

void search(int x, int y)
{
	int dx[5] = { 0,-1,0,1,0 }, dy[5] = { 0,0,1,0,-1 };
	que.push(pair<int, int>(x, y)); //入队 
	while (!que.empty())
	{
		pair<int, int>t = que.top();//队头 
		que.pop();//出队 
		a[t.first][t.second] = 2;// 
		for (int i = 1; i <= 4; i++)//添加队头的相关位置 
		{
			if (t.first + dx[i] >= 0 && t.first + dx[i] <= n+1)//未越界 
			if (t.second + dy[i] >= 0 && t.second + dy[i] <= n+1)//未越界 
			if (a[t.first + dx[i]][t.second + dy[i]] == 0)//等于0
			que.push(pair<int, int>(t.first + dx[i], t.second + dy[i]));
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	search(0,0);//从边界开始搜索  只能找到与(0,0)联通的全部的0
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<2-a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
