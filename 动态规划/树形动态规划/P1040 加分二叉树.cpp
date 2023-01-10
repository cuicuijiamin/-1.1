#include<bits/stdc++.h>
using namespace std;
const int MAXN = 35;
typedef long long ll;
ll n;
ll f[MAXN][MAXN], root[MAXN][MAXN];//f[i][j]表示节点i到节点j所成树的最大价值   root[i][j]表示节点i到节点j的最大所成树的根 

void preorder(int l,int r)
{
	if(l>r) return;
	cout<<root[l][r]<<" ";
	if(l==r) return;//叶子节点 
	preorder(l,root[l][r]-1);//左
	preorder(root[l][r]+1,r); 
}
int main()
{
	int n;
	cin>>n;//节点总数
	for(int i=1;i<=n;++i)
	{
		cin>>f[i][i];//f[i][i]就是i号节点的价值
		root[i][i]=i;//初始化一下
		f[i][i-1]=1; 
	}
	for(int len=2;len<=n;++len)//遍历区间的长度
	{
		for(int i=1,j=i+len-1;j<=n;++i,++j)
		{
			for(int k=i;k<=j;++k)//遍历根的可能 
			{
				if(f[i][k-1]*f[k+1][j]+f[k][k]>f[i][j])
				{
					f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
					root[i][j]=k;
				}
			}
		 } 
	 } 
	 cout<<f[1][n]<<endl;
	 preorder(1,n); 
}
