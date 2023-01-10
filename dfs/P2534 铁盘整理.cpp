#include<bits/stdc++.h>
using namespace std;
int a[20],b[20];
int n;
int h()
{
	//估价函数
	int cnt=0;
	for(int i=1; i<=n; ++i)
	{
		if(abs(a[i+1]-a[i])>1) cnt++;
	}
	return cnt;
}
int judge=0,maxDep;
void IDA_star(int step, int pre)
{
	if (judge || step + h() > maxDep) return;//预估步数
	if (!h())
	{
		judge = 1;//找到答案
		return;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (i == pre) continue;//保证不与上一次翻转的长度相同
		reverse(a + 1, a + i + 1);//翻转
		IDA_star(step + 1,i);
		reverse(a + 1, a + i + 1);//回溯
	}
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1; i<=n; ++i)
	{
		a[i]=lower_bound(b+1,b+n+1,a[i])-b;//离散化
	}
	a[n+1]=n+1;
	for(maxDep=0;; maxDep++)
	{
		IDA_star(0,0);
		if(judge)
		{
			cout<<maxDep<<endl;
			return 0;
		}
	}
	return 0;
}
