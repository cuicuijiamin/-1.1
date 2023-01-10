#include<bits/stdc++.h>
using namespace std;
vector<int>beg[3000010];
//beg[i]里面存放的是以i为终点的区间段
int n,mx,dp[3000010];//mx 代表最大的 y，f 就是 dp 用的数组
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int x,y;
		cin>>x>>y;//输入区间
		beg[y].push_back(x);//这里保存的是 x-1，后面会比较方便
		mx=max(mx,y);
	}
	dp[0]=0;
	for(int i=1; i<=mx; i++)
	{
		dp[i]=dp[i-1];//以i为终止位置能吃到的草，不吃i位置那就直接等于f[i-1]
		for(int j=0; j<beg[i].size(); j++)//遍历所有以i为终止位置的草
		{
			int b=beg[i][j];//b为草的起点
			if(b!=0) dp[i]=max(dp[i],dp[b-1]+i-b+1);
			else dp[i]=max(dp[i],i-b+1);
		}
	}
	cout<<dp[mx]<<endl;
	return 0;
}
