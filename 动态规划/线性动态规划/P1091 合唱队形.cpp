#include<bits/stdc++.h>
using namespace std;
int h[105];
int a1[105];
int a2[105];
int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>h[i];//身高
	}

	for(int i=1; i<=n; ++i)
	{
		//以i为最后一人的最长上升序列
		a1[i]=1;
		for(int j=1; j<i; ++j)
		{
			if(h[i]>h[j])	a1[i]=max(a1[i],a1[j]+1);
		}
	}
	for(int i=n; i>=1; --i)
	{
		a2[i]=1;
		for(int j=n; j>i; --j)
		{
			if(h[i]>h[j])	a2[i]=max(a2[i],a2[j]+1);
		}
	}
	int ans=0;
	for(int i=1; i<=n; ++i) //枚举中间
	{
		ans=max(ans,a1[i]+a2[i]-1);
	}
	cout<<n-ans<<endl;
	return 0;
}
