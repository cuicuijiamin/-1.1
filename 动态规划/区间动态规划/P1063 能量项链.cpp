#include<bits/stdc++.h>
using namespace std;
//区间合并问题
int a[210];
//注意合并一定是按顺序的 如n,1,2,3,4...
//环状的 开头不确定   将数据量翻倍

//dp[i][j]表示i到j颗珠子连续合并的能量 
int dp[210][210];
int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int len=2; len<=n; ++len) //遍历区间长度
	{
		for(int i=1;i<=n;++i)//遍历起点 
		{
			int j=i+len-1;//终点
			for(int k=i;k<j&&k<2*n;++k)//遍历分割位 
			{
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]); 
				dp[i+n][j+n]=dp[i][j];
			 } 
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		ans=max(ans,dp[i][i+n-1]);
	}
	cout<<ans<<endl;
}
