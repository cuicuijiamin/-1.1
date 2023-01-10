#include<bits/stdc++.h>
using namespace std;

const int N=200010;
long long a[N],n,c,cnt,st;

int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);	//先排序 
	
	for(int i=1;i<n;i++)	//遍历每一个B 
	{
		int l=i+1,r=n;	//寻找A第一次出现的位置，使得A-B=C 
		while(l<r) //因为是第一次出现，尽量往左，模板1
		{
			int mid=l+r>>1;
			if(a[mid]-a[i]>=c) r=mid;	//判断：在目标值的右边，满足，往左来
			else l=mid+1;
		}
		if(a[l]-a[i]==c) st=l; //能找到C就继续 
		else continue;
		
		l=st,r=n;	//查找A最后出现的位置 
		while(l<r) //因为是最后一次出现，尽量往右，模板2
		{
			int mid=l+r+1>>1;
			if(a[mid]<=a[st]) l=mid; //判断：在目标值的左边，满足，往右去
			else r=mid-1;
		}
		cnt+=l-st+1;	//最后出现的位置减首次出现的位置就是区间长度，即A的个数 
	}
	cout<<cnt;
	return 0;
} 


