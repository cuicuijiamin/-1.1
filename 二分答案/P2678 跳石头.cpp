#include<iostream>
using namespace std;
const int N=50010;
int a[N],n,len,m,mina=1e9+1,b[N];
int check(int mid)	//检查，是否最短距离为mid，如果两石头间距小于mid，不满足，移走 
{
	int cnt=0;
	int i=0,now=0;	//i表示目标位置，now为当前位置。
	while(i<n+1)
    {
		i++;
		if(a[i]-a[now]<mid){ //两石头间距离小于mid，mid不是最短距离，不满足，移走该石头 
			cnt++;
		}
		else{	//符合，跳过去 
			now=i;
		}
	}
	if(cnt<=m) return 1;	//移走的石头个数小于 M，就能保证了任意两剩下的石头间距大于等于最短距离mid，那移走M个，更能保证 
	return 0;
}
int main(){
	cin>>len>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<mina) mina=a[i];
	}
	a[0]=0,a[n+1]=len; //首尾都有石头
	
	if(n==0){ //特判掉起点和终点之间没有石头的情况，可以想一下为什么。评论区中有答案。感谢 luojias 同学的hack数据！
		cout<<len; return 0;
	}

	//二分答案：检查每一个答案（最短距离mid）是否符合要求 
	long long l=1,r=len;
	while(l<r) //模板2
	{
		int mid=l+r+1>>1;
		if(check(mid)) l=mid; //要的是距离的最大，所以尽可能地往右走 
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
