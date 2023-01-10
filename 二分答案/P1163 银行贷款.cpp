#include<bits/stdc++.h>
using namespace std;

int sum,t,mon;
double sumt;

int check(double mid)
{
	sumt=sum;
	for(int i=1;i<=mon;i++){
		sumt=sumt+sumt*mid-t;
	}
	if(sumt > 0) return 1; 				
	return 0;
} 

int main(){
	cin>>sum>>t>>mon;
	
	double l=0,r=500; //答案范围尽量开大些
	while(r-l>1e-5)	//精度保证 
	{
		double mid=(l+r)/2;
		if(check(mid)) r=mid;	//如果最后还不完了，说明利率高了 	
		else l=mid;
	}
	printf("%.1f",l*100);
	return 0;
} 
