#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
long long a[N],x,sum,n,m;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); //排序勿忘 
	a[0]=-1e12;a[n+1]=1e12;	 //最后再解释
	while(m--)
	{
		cin>>x;
		int l=1,r=n+1;	//r设为n+1 
		while(l<r) //寻找第一个超过估分的学校，那它或它前面的一个学校就是目标学校 
		{
			int mid=l+r>>1;
			if(a[mid]>=x) r=mid;
			else l=mid+1;
		}
		if(a[l]-x<=x-a[l-1]) sum+=a[l]-x;
		else sum+=x-a[l-1];
	}
	
	cout<<sum;
	return 0;
	//a[0]=-1e12: 所有分数先可能都比估分大，那么l就为1，n-1就为0，故设a[0]为无穷小，则第一个值就为解 
	//a[n+1]=1e12: 所有分数线可能都比估分小，那么l就为n,a[l]-x可能为负，则设a[n+1]为无穷大，
				//并将r设为n+1，如此，l最大为n+1，则最后一个就为解 
}
