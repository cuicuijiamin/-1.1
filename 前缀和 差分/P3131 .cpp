#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[50005];
//f[i]表示[1,i]的和%7
int f[50005];
int first[8],last[8];
int main()
{
	int n;
	cin>>n;
	memset(f,0,sizeof(f));
	memset(first,0,sizeof(first));
	memset(first,0,sizeof(first));
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
		f[i]=(f[i-1]+a[i])%7;//获取前缀和%7的值 
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(f[i]==0)
		{
			last[0]=i;
			continue;
		}
		if(first[f[i]]==0)
			first[f[i]]=i;
		else 
			last[f[i]]=i;
	}
	for(int i=0;i<7;++i)
	{
		ans=max(ans,last[i]-first[i]);
	}
	cout<<ans<<endl;
	return 0;
}
