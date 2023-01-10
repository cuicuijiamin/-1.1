#include<bits/stdc++.h>
using namespace std;
string s[25];
int con[25][25];
int vis[25];//字符串出现的次数——标记数组
int ans=0,an=0;
int n;
void getCon(int i,int j)
{
	int len1=s[i].size();
	int len2=s[j].size();
	int p,q;
	for(int k=1; k<len1; ++k)
	{
		p=0;
		q=k;
		while(s[i][q]==s[j][p])
		{
			q++;
			p++;
			if(q==len1&&p!=len2)
			{
				con[i][j]=len1-k;
				break;
			}
		}
	}
}
void dfs(int i)
{
	bool flag=0;
	for(int j=1; j<=n; ++j)
	{
		if(vis[j]<2&&con[i][j]>0)
		{
			flag=1;
			vis[j]++;
			an+=(s[j].size()-con[i][j]);
			dfs(j);
			vis[j]--;
			an-=(s[j].size()-con[i][j]);
		}
	}
	if(!flag)
		ans=max(ans,an);
	}
int main()
{
	cin>>n;
	memset(con,0,sizeof(con));
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; ++i)
	{
		cin>>s[i];
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			getCon(i,j);
			//printf("con[%d][%d]=%d\t",i,j,con[i][j]);
		}
		//cout<<endl;
	}
	char ch;
	cin>>ch;
	for(int i=1; i<=n; ++i)
	{
		if(s[i][0]==ch)
		{
			vis[i]=1;
			an=s[i].size();
			dfs(i);
			vis[i]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
