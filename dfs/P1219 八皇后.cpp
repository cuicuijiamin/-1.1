#include<bits/stdc++.h>
using namespace std;
int n;
int vis[3][30];//标记数组 
int a[20];
int ans=0;
void dfs(int i)
{
	if(i==n+1)
	{
		ans++;
		if(ans<=3)
		{
			for(int i=1;i<=n;++i)
			{
				printf("%d%c",a[i],i==n?'\n':' ');
			}
		}
		return;
	}
	for(int j=1;j<=n;++j)
	{
		if(!vis[0][j]&&!vis[1][i+j]&&!vis[2][i-j+n])
		{
			vis[0][j]=vis[1][i+j]=vis[2][i-j+n]=1;
			a[i]=j;
			dfs(i+1); 
			vis[0][j]=vis[1][i+j]=vis[2][i-j+n]=0;
		}
	}
}
int main()
{
	memset(vis,0,sizeof(vis)); 
	cin>>n;//n皇后
	dfs(1);
	cout<<ans;
	return 0;
}
