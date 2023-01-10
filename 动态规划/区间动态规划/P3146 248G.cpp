#include<bits/stdc++.h>
using namespace std;
int a[255];
int dp[255][255];//从i到j完全合并能达到的最大值 
int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
		dp[i][i]=a[i];
	}
	int ans=0;
	for(int len=1; len<=n; ++len) //遍历序列长度
	{
		for(int i=1; i<=n; ++i) //遍历起点
		{
			int j=len+i-1;
			for(int k=i;k<j&&k<n;++k)//枚举分割点 
			{
				if(dp[i][k]==dp[k+1][j])//可以合并 
				{
					dp[i][j]=max(dp[i][j],dp[i][k]+1);
					ans=max(ans,dp[i][j]);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
