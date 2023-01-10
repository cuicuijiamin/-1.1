#include<iostream>
using namespace std;

const int N=1e6+10;
long long a[N],n,m,maxa,sum;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxa) maxa=a[i]; //找一下可能的最大高度 
	}
	long long l=0,r=maxa;
	while(l<r)	//查找最高的满足情况的高度 
	{
		long long mid=l+r+1>>1;
		sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>mid) sum+=a[i]-mid;
		}
		if(sum>=m) l=mid;	//低了
		else r=mid-1;
	}
	cout<<l<<endl;	//一定有解 
	
	return 0;
} 
