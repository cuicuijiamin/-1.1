#include<iostream>
using namespace std;

const int N=100010;
long long a[N],n,m,len,x;

int check(int mid)
{
	int cnt=0;
	int now=0,i=0; 
	
	while(i<n)
	{
		i++;
		while(a[i]-a[now]>mid)
		{
			cnt++;
			a[now]=a[now]+mid;
		}
		a[now]=a[i];
	}
	if(cnt<=m) return 1; //增设不到m个就能满足 "间距小于最大距离或相等" ，那增设m个肯定也满足 
	return 0;
}
int main(){
	cin>>len>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=0;
	
	int l=1,r=len;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
} 
