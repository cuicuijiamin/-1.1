#include<bits/stdc++.h>
using namespace std;
const int MAXN=35005;
const int INF=0x3f3f3f3f;
int b[MAXN];
int f[MAXN];
//假设f[i]为长度为i的序列的i位置的最小值
int dp[MAXN];
//dp[i]为以i为结尾的最长长度
//第一问：求b[i]=a[i]-i的最长不降子序列的长度
vector<int>seq[MAXN];//记录序列			seq[i]表示长度为i的序列的可能的结尾下标
long long g[MAXN],pre[MAXN],suf[MAXN];
//g[i]表示以i为结尾的序列的最小代价  pre[i]表示在[a,b]的序列中，将[a,k]改成b[a]的代价和 
int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		int x;
		cin>>x;//输入序列
		b[i]=x-i;
	}
	b[n+1]=INF;//补的最后一个数 
	b[0]=-INF;//————很重要 
	memset(f,0,sizeof(f));
	//f[i]是单调不降的  用二分找i
	int t=0;
	for(int i=1; i<=n+1; ++i) //遍历  获得最长序列
	{
		//找b[i]>=f[x]的最大x
		int l=0;
		int r=t;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(b[i]<f[mid])r=mid-1;
			if(b[i]>=f[mid])l=mid;
		}
		//此时的l就满足b[i]>=f[l]
		t=max(t,l+1);//长度
		dp[i]=l+1;
		seq[dp[i]].push_back(i);
		f[l+1]=b[i];
	}
	seq[0].push_back(0);//初始序列————很重要 
	memset(g, INF, sizeof(g));
	g[0]=0;//初始化————很重要 
	for(int i=1; i<=n+1; ++i)
	{
		for(int j=0,size=seq[dp[i]-1].size(); j<size; ++j)//遍历：以i为序列终点的前驱 
		{
			int from=seq[dp[i]-1][j];
			if(from>=i||b[from]>b[i])continue;
			pre[from]=suf[i-1]=0;//赋初值 
			for(int k=from+1; k<=i-1; ++k)
			{
				pre[k]=pre[k-1]+abs(b[k]-b[from]);
			}
			for(int k=i-2; k>=from; --k)
			{
				suf[k]=suf[k+1]+abs(b[k+1]-b[i]);
			}
			for(int k=from; k<=i-1; ++k)
			{
				g[i]=min(g[i],g[from]+pre[k]+suf[k]);//获取以i为终点  的序列的最小代价 
			}
		}
	}
	cout<<n-t+1<<endl;//t为最多保留数
	cout<<g[n+1];
	return 0;
}
