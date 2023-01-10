#include<bits/stdc++.h>
using namespace std;
int f[51][2550];//f[i][j]前i条木板 涂了j次的最大正确数目 
int sum[51][2550];
int g[51][2550][51];//g[i][j][k]第i条木板，粉刷j次， 涂了前k个格子 
int n,m,t;
char s[150];

int main()
{
	cin>>n>>m>>t;
	for(int i=1; i<=n; i++)
	{
		cin>>s;
		sum[i][0]=0; 
		for(int j=1; j<=m; j++)
		{
			if(s[j-1]=='1') sum[i][j]=sum[i][j-1]+1;
			else sum[i][j]=sum[i][j-1];//sum数组的赋值 
		}
	}
	for(int i=1; i<=n; i++)//遍历木板 
		for(int j=1; j<=m; j++)//遍历每条木板的粉刷次数 
			for(int k=j; k<=m; k++)//遍历刷好的格子数 
				for(int q=j-1; q<k; q++)//遍历异色的开始格子 
				{
					g[i][j][k]=max(g[i][j][k],g[i][j-1][q]+max(sum[i][k]-sum[i][q],k-q-sum[i][k]+sum[i][q]));
				}
	for(int i=1; i<=n; i++)//遍历木板 
		for(int j=1; j<=t; j++)//遍历前i条木板刷的次数 
			for(int k=0; k<=min(m,j); k++)//遍历少刷一条木板少刷的次数 
			{
				f[i][j]=max(f[i][j],f[i-1][j-k]+g[i][k][m]);
			}
	cout<<f[n][t]<<endl;
}
