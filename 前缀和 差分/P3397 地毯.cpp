#include <bits/stdc++.h>
using namespace std;
int ans[1005][1005];
int main()
{
	memset(ans,0,sizeof(ans));
	int n,m;
	cin>>n>>m;
	int x1,y1,x2,y2;
	for(int i=1;i<=m;++i)
	{
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1;j<=x2;++j)
		{
			ans[j][y1]+=1;
			ans[j][y2+1]-=1;
		}
	}
	
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			ans[i][j]+=ans[i][j-1];
			printf("%d%c",ans[i][j],j==n?'\n':' ');
		}
	}
	return 0;
}
