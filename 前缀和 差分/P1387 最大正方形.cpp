#include <bits/stdc++.h>
using namespace std;
int a[101][101],f[101][101];//f[i][j]表示以i,j为右下角的最大正方形的边长 
int main()
{
	int n,m;
	cin>>n>>m;
	int ans;
    for (int i=1;i<=n;++i)
    {
		for (int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            if (a[i][j]==1) f[i][j]=min(min(f[i][j-1],f[i-1][j]),f[i-1][j-1])+1;
            ans=max(ans,f[i][j]);
        }
	}    
    cout<<ans<<endl;
    return 0;
}
