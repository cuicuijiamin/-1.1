#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[45];
vector<ll>ka;
vector<ll>kb;
int n;
ll m;

void dfs(int l,int r,ll sum,vector<ll>&k)
{
	if(sum>m)return;
	if(l>r)
	{
		k.push_back(sum);
		return;
	}
	dfs(l+1,r,sum+a[l],k);
	dfs(l+1,r,sum,k);
}
int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
	}
	int mid=(n+1)>>1;
	dfs(1,mid,0,ka);
	dfs(mid+1,n,0,kb);
	sort(ka.begin(),ka.end());//排好序
	ll ans=0;
	for(int i=0; i<kb.size(); ++i) //遍历kb
	{
		ans += upper_bound(ka.begin(), ka.end(), m-kb[i]) - ka.begin();
	}
	cout<<ans<<endl;
}
