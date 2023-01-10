#include<bits/stdc++.h>
using namespace std;
const int MOD=1e8;
int v[2005];
//dp表示组队数
int dp[2005][2005];//前i件物品且余数正好为j时的组数的最大值
//dp[i][j]=dp[i][j]+dp[i-1][j]+dp[i-1][j-v[i]]   说明，结果要对MOD取余，j-v[i]可能为负  (j-v[i]+F)%F 
int main()
{
	int n,F;//牛的数目  幸运数字
	cin>>n>>F;
	for(int i=1; i<=n; ++i)
	{
		cin>>v[i];
		v[i]%=F;
	}
	for(int i=1; i<=n; ++i)
	{
		dp[i][v[i]]=1;//初始化
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<=F-1; ++j) //列举余数 要的是余数为0的情况
		{
			//不选i物品 选i物品
			 dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i-1][(j-v[i]+F)%F])%MOD;//状态转移方程应用 
		}
	}
	cout<<dp[n][0]<<endl;
}
