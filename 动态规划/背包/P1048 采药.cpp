#include<bits/stdc++.h>
using namespace std;
const int MAXT=1005;
const int MAXM=105;
int t[MAXM];
int v[MAXM];
int dp[MAXM][MAXT];//dp[i][j]表示[1,i]物品在 j时间内   的价值 
int main()
{
	int T,M;
	cin>>T>>M;
	for(int i=1;i<=M;++i)
	{
		cin>>t[i]>>v[i];
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=M;++i)
	{
		for(int j=0;j<=T;++j)
		{
			if(j>=t[i])
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+v[i]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d\n",dp[M][T]);
	return 0;
}
