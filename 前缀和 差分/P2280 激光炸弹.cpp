#include <bits/stdc++.h>
using namespace std;
const int MAXX=5005,MAXY=5005;
int f[MAXX][MAXY];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; ++i) //遍历n个目标
	{
		int x,y,z;
		cin>>x>>y>>z;
		f[x+1][y+1]+=z;
	}
	for(int i=1; i<=5001; ++i) //求二维前缀和
	{
		for(int j=1; j<=5001; ++j)
		{
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+f[i][j];
		}
	}

	int ans=0;
	for(int i=m; i<=5001; ++i)
	{
		for(int j=m; j<=5001; ++j)
		{
			int x=f[i][j]-f[i-m][j]-f[i][j-m]+f[i-m][j-m];
			ans=max(ans,x);
		}
	}
	cout<<ans<<endl;
	return 0;
}
