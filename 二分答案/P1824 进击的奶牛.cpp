#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int a[N],n,m,maxa;
int check(int mid)
{
	int i=1,j=1,cnt=0; //第一个格子必放牛，才能使后面的间距尽可能大，从而保证最短距离mid最大化 
	while(j<n){
		j++;
		if(a[j]-a[i]>=mid){ //保证间距大于等于最短距离mid，才能把牛放进去 
			cnt++,i=j;
		}
	}
	if(cnt+1>=m) return 1; //放进的牛个数大于m，都能保证间距大于最短距离mid，那放进去m个，肯定还是大于最短距离mid 
	return 0;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxa) maxa=a[i];
	}
	sort(a+1,a+n+1);	//排序勿忘 
	
	int l=0,r=maxa;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
