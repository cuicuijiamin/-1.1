#include<bits/stdc++.h>
using namespace std;
int fen[360];//记录棋盘
int g[5];//记录棋子
int dp[41][41][41][41];
int n,m;

int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; ++i)
	{
		cin>>fen[i];
	}
	for(int i=1; i<=m; ++i)
	{
		int x;
		cin>>x;
		g[x]++;
	}
	dp[0][0][0][0]=fen[1];
	for(int a=0;a<=g[1];a++)
	{
		for(int b=0;b<=g[2];b++)
		{
			for(int c=0;c<=g[3];c++)
			{
				for(int d=0;d<=g[4];++d)
				{
					int pos=1+a+2*b+3*c+4*d;
					if(a>=1)dp[a][b][c][d]=max(dp[a-1][b][c][d]+fen[pos],dp[a][b][c][d]);
					if(b>=1)dp[a][b][c][d]=max(dp[a][b-1][c][d]+fen[pos],dp[a][b][c][d]);
					if(c>=1)dp[a][b][c][d]=max(dp[a][b][c-1][d]+fen[pos],dp[a][b][c][d]);
					if(d>=1)dp[a][b][c][d]=max(dp[a][b][c][d-1]+fen[pos],dp[a][b][c][d]);
				}
			}
		}
	}
	cout<<dp[g[1]][g[2]][g[3]][g[4]]<<endl;
	return 0;
} 
