#include<bits/stdc++.h>
using namespace std;
int g[205][205];
int w[1005],v[1005];
int b[1005];
int dp[1005][1005];
int main()
{
	int m,n;
	cin>>m>>n;
	int x;//输入的临时变量 
	int t=0;//记录组数 
	memset(b,0,sizeof(b)); 
	for(int i=1; i<=n; i++)
	{
		cin>>w[i]>>v[i]>>x;
		t=max(t,x);//获取组数 
		b[x]++;
		g[x][b[x]]=i;//第i组的第j件物品 对应的下标为值的大小 
	}
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=t; i++)//遍历小组 
	{
		for(int j=0; j<=m; j++)//遍历总承重 
		{
			dp[i][j]=dp[i-1][j];
			for(int k=1; k<=b[i]; k++)//遍历小组的 所有组员 
			{
				int temp=g[i][k];
				if(j>=w[temp])
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j-w[temp]]+v[temp]);
				}
			}
		}
	}
	cout<<dp[t][m];
	return 0;
}
