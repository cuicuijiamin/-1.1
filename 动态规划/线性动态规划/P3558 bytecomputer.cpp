#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int dp[MAXN][3];//dp[i][j]表示前i个数，以j结尾的最少改变次数  j=0表示以-1结尾 1表示0 2表示1
const int INF=0x3f3f3f3f;
int a[MAXN];
int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
	}
	//dp数组的初始化
	memset(dp,0x3f,sizeof(dp));
	dp[1][a[1]+1]=0;
	for(int i=2; i<=n; ++i)
	{
		//正式
		if(a[i]==-1)
		{

			dp[i][0]=dp[i-1][0];//以-1结尾
			//以0结尾  不可能出现这种情况
			dp[i][2]=dp[i-1][2]+2; //以1结尾
		}
		if(a[i]==0)
		{
			dp[i][0]=dp[i-1][0]+1;	//以-1结尾
			dp[i][1]=min(dp[i-1][0],dp[i-1][1]);//以0结尾
			dp[i][2]=dp[i-1][2]+1;//以1结尾 
		}
		if(a[i]==1)
		{
			dp[i][0]=dp[i-1][0]+2;
			dp[i][1]=dp[i-1][0]+1;
			dp[i][2]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
		}
	}
	int tmp=min(dp[n][0],min(dp[n][1],dp[n][2]));
	if(tmp<INF) cout<<tmp<<endl;
	else cout<<"BRAK"<<endl;
	return 0;
}
