#include<bits/stdc++.h>
using namespace std;
int money[105];
int ti[105];
int dp[105][205][205];//dp[i][j]表示前i个物品使用了i分钟 j元的最多个数
int main()
{
	int n,m,t;
	cin>>n>>m>>t;
	for(int i=1; i<=n; ++i)
	{
		cin>>money[i]>>ti[i];
	}
	for(int i=1; i<=n; ++i) //遍历物品
	{
		for(int j=1; j<=m; ++j) //遍历金钱
		{
			for(int k=1; k<=t; ++k) //遍历时间
			{
				if(j>=money[i]&&k>=ti[i])dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-money[i]][k-ti[i]]+1);
				else dp[i][j][k]=dp[i-1][j][k];
			}
		}
	}
	cout<<dp[n][m][t];
	return 0;
}
