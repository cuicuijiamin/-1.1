#include<bits/stdc++.h>
using namespace std;
//dp定义为
//四维：dp[i][j][k]=A的前i个字符 与  B的前j个字符  选k个子串的匹配数目
//最后输出的就是 dp[n][m][k]

//关于递推
//dp[i][j][k][]   由于是A中的k个子串依次拼接，首先如果要选最后一个字符
//无论是单独拿出来作为字串，还是作为别的字串的一部分，它就必须是得和B的最后一个字符同
//那么如果A[i]！=B[j] ,就一定不选A[i]  就干脆不要了
//if(A[i]!=B[j])    
//dp[i][j][k][1]=0;
//dp[i][j][k][0]=dp[i-1][j][k][0]+dp[i-1][j][k][1]
//if(A[i]=B[j]) 
//选dp[i][j][k][1]=dp[i-1][j-1][k-1][0]+dp[i-1][j-1][k-1][1]+dp[i-1][j-1][k][1]
//不选dp[i][j][k][0]=dp[i-1][j][k][0]+dp[i-1][j][k][1]   四维会爆，加滚动 

const int MOD=1000000007;
int dp[2][205][205][2];//算[i]只用[i-1]就行  
char a[1005],b[205];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	memset(dp,0,sizeof(dp));//dp的初始化
	scanf("%s%s",a+1,b+1);
	int now=0,pre=1;
	dp[0][0][0][0]=1;
	dp[1][0][0][0]=1;
	for(int i=1; i<=n; ++i) //遍历A的所有字符
	{
		for(int j=1; j<=m; ++j) //遍历B的所有字符
		{
			for(int kk=1; kk<=k; ++kk) //遍历能选的字串的数目
			{
				if(a[i]==b[j]) 
				{ 
					dp[now][j][kk][1]=((long long)dp[pre][j-1][kk-1][0]+dp[pre][j-1][kk-1][1]+dp[pre][j-1][kk][1])%MOD;
					dp[now][j][kk][0]=((long long)dp[pre][j][kk][0]+dp[pre][j][kk][1])%MOD;
				}
				else 
				{
					dp[now][j][kk][1]=0;
					dp[now][j][kk][0]=((long long)dp[pre][j][kk][0]+dp[pre][j][kk][1])%MOD;
				}
			}
		}
		int t=now;
		now=pre;
		pre=t;
	}
	cout<<((long long)dp[pre][m][k][0]+dp[pre][m][k][1])%MOD<<endl;
	return 0;
}
