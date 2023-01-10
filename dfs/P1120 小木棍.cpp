#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
int ans=0,m=0,ok,len;
int a[70],vis[70],nest[70];
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int k,int last,int rest)//在拼第k个木棍 ,上一个挑选的木棍的下标 ,还得凑rest个长度
{
	if(rest==0)
	{
		//要凑下一个木棍了
		if(k==m)
		{
			ok=1;//弄好了
			return;
		}
		for(int i=1;i<=n;++i)
		{
			if(vis[i]==0)
			{
				vis[i]=1;
				dfs(k+1,i,len-a[i]);
				vis[i]=0;
				if(ok) return;
				break; 
			}
		}
	}
	int l=last+1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<=rest) r=mid;
		else l=mid+1;
	}
	for(int i=l;i<=n;++i)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(k,i,rest-a[i]);
			vis[i]=0;
			if(ok)return;
			if(rest==a[i]) return;//  
			//rest==a[i]  在上面我选择了a[i]的情况下，我剩下了更多短木棍的选择，但在这样的最优解下，我却仍然没有组件成功，说明前面选择出错
			//rest==len   在上面 
			i=nest[i];
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
	}

	sort(a+1,a+1+n,cmp);
	//设置nest数组
	nest[n]=n;
	for(int i=n-1;i>0;--i)
	{
		if(a[i]==a[i+1])
			nest[i]=nest[i+1];
		else 
			nest[i]=i;
	}
	for(len=a[1]; len<=sum/2; ++len) //遍历所有可能长度
	{
		if(sum%len!=0)continue;
		m=sum/len;//要拼成的木棍的数目
		vis[1]=1;
		ok=0;
		dfs(1,1,len-a[1]);
		vis[1]=0;
		if(ok)
		{
			cout<<len<<endl;
			return 0;
		}
	}

	cout<<sum<<endl;
	return 0;
}
