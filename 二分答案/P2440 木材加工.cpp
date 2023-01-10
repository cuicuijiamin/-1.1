#include<iostream>
using namespace std;

const int N=1e5+10;
long long a[N],n,m,sum,maxa;

int check(int mid)
{
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i]/mid;
	}
	if(sum>=m) return 1; //总段数大于等于所需要的 
	return 0;
} 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],sum+=a[i];
		if(a[i]>maxa) maxa=a[i];  
	}
	//

	if(sum<m){cout<<0;return 0;} //先判断是否有解 
	
	int l=1,r=maxa;
	while(l<r) //模板2 
	{
		int mid=l+r+1>>1;
		if(check(mid)) l=mid; 
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
