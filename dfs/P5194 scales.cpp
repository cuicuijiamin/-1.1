#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[50],a[50];
ll ans=0;
int N,C;

void dfs(int i,long long cur)
{
	ans=max(ans,cur);
	if(cur+b[i]<=ans)//该状态后面全选也不行，直接不考虑 ————重要 
		return ;
	if(i==0)//选完了 
		return ;
	if(cur+a[i]<=C)
		dfs(i-1,cur+a[i]);//要选i物品 
	dfs(i-1,cur);//不选i物品 
}

int main()
{
	memset(b,0,sizeof(b));
	cin>>N>>C;
	for(int i=1; i<=N; ++i)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	dfs(N,0);
	cout<<ans<<endl;
	return 0;
}
