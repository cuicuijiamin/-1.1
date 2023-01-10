#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int h[200005];

int f[200005];
int main()
{
	int cnt=0;
	while(cin>>h[cnt])
	{
		cnt++;
	}

	int t=0;
	memset(f,0,sizeof(f));
	f[0]=INF;
	/****************************第一问************************/
	for(int i=0; i<cnt; ++i)//计算以i为终点
	{
		int l=0;
		int r=t;
		while(l<r)//在f数组找最大的f[x]满足 f[x]>=h[i]
		{
			int mid=(l+r+1)>>1;
			if(f[mid]>=h[i])l=mid;
			else r=mid-1;
		}

		t=max(l+1,t);//最长长度
		f[l+1]=h[i];
	}
	cout<<t<<endl;

	/****************************第二问************************/
	memset(f,0,sizeof(f));//f[i]表示以i为长度的最终导弹的最小高度  i变大，f[i]一定会变大
	t=0;
	for(int i=0; i<cnt; ++i)//计算以i为终点
	{
		//计算dp[i]
		//dp[i]=max(dp[j]+1)  找dp[j]=x  fx<h[i]的最大x
		int l=0;
		int r=t;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(f[mid]<h[i])l=mid;
			else r=mid-1;
		}

		t=max(l+1,t);//最长长度
		f[l+1]=h[i];
	}
	cout<<t<<endl;
}

