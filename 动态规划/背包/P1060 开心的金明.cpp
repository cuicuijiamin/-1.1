#include<bits/stdc++.h>
using namespace std;
const int MAXM=28;
const int MAXN=30000;
int v[MAXM];
int p[MAXM];//下标从1开始
int dp[MAXM][MAXN];//dp[i][j]表示 [1,i]物品的选择value不超过j dp[1][v[1]]=    dp[1][0]=0
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=m; ++i)
	{
		cin>>v[i]>>p[i];
	}
	memset(dp,0,sizeof(dp));
	//j=0时 为0
	//i=1时
	for(int j=0; j<=n; ++j)
	{
		if(v[1]<=j)
			dp[1][j]=p[1]*v[1];
	}
	for(int i=2; i<=m; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(j>=v[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*p[i]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d\n",dp[m][n]);
	return 0;
}
