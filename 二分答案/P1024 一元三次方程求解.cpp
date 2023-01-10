#include<iostream>
using namespace std;

double a,b,c,d;

int search_1(double l,double r)
{
	while(r-l>1e-5)
	{
		double mid=(l+r)/2;
		if(a*mid*mid*mid+b*mid*mid+c*mid+d<=0) l=mid;
		else r=mid;
	}
	printf("%.2f ",l);
}
int search_2(double l,double r)
{
	while(r-l>1e-5)
	{
		double mid=(l+r)/2;
		if(a*mid*mid*mid+b*mid*mid+c*mid+d>=0) l=mid;
		else r=mid;
	}
	printf("%.2f ",l);
}
int main(){
	cin>>a>>b>>c>>d;
	//注意根与根之差的绝对值>=1，故可以遍历每个点，看是否根在这个点附近，如果在的话，二分查找 
	for(double i=-100;i<=100;i++){
		if(a*i*i*i+b*i*i+c*i+d==0){
			printf("%.2f ",i);
		}
		else if(a*i*i*i+b*i*i+c*i+d<0&&a*(i+1)*(i+1)*(i+1)+b*(i+1)*(i+1)+c*(i+1)+d>0){
			search_1(i,i+1); 
		}
		else if(a*i*i*i+b*i*i+c*i+d>0&&a*(i+1)*(i+1)*(i+1)+b*(i+1)*(i+1)+c*(i+1)+d<0){
			search_2(i,i+1);
		}
	}
	return 0;
} 
