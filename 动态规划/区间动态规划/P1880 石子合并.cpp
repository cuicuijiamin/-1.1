//区间dp————石子合并
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int a[205];
int sum[205];
int dp1[205][205];//i到j的合并的最小值 
int dp2[205][205];//i到j的合并的最大值 
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		//2*n堆
		a[i+n]=a[i]; 
	}
	for(int i=1;i<=2*n;++i)
	{
		//计算前缀和sum
		sum[i]=a[i]+sum[i-1]; 
	}
	//dp数组的初始化 
	memset(dp1,0x3f,sizeof(dp1));
	for(int i=1;i<=2*n;++i)
		dp1[i][i]=0;
	memset(dp2,0,sizeof(dp2));
	for(int len=1;len<=n;++len)//枚举区间的长度
	{
		for(int i=1;i<=2*n;++i)//枚举起点
		{
			int j=len+i-1;//终点
			for(int k=i;k<j&&k<2*n;++k)//枚举分割点
			{
				dp1[i][j]=min(dp1[i][j],dp1[i][k]+dp1[k+1][j]+sum[j]-sum[i-1]); 
				dp2[i][j]=max(dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]); 
			 } 
		 } 
	 } 
	 int ans1=INF,ans2=0;
	 for(int i=1;i<=n;++i)
	 {
	 	ans1=min(ans1,dp1[i][i+n-1]);
	 	ans2=max(ans2,dp2[i][i+n-1]);
	 }
	 cout<<ans1<<endl<<ans2<<endl;
 } 
