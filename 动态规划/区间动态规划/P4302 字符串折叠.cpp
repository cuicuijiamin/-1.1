#include<bits/stdc++.h>
using namespace std;
int f[105][105];
int m[105];
	string s;
bool check(int l,int r,int len)
{
	for(int i=len+l; i<=r; i++)
		if(s[i]!=s[(i-l)%len+l])return false;
	return true;
}
int main()
{
	//求最短的折叠字符串
	//f[i][j]表示i~j的最短折叠字符串的长度
	//那么保底f[i][j]=f[i][k]+f[k+1][j]
	//不一定是简单的拼接，两部分连在一起可能也会重叠从而获得新的折叠字符串。
	cin>>s;
	int n=s.size();
	s=" "+s;//前面补一个空格一会好处理
	for(int i=1; i<=9; ++i)
	{
		m[i]=1;  //i(ABASJH) m[i]就是i的位数
	}
	for(int i=10; i<=99; ++i)
	{
		m[i]=2;  //i(ABASJH) m[i]就是i的位数
	}
	m[100]=3;

	memset(f,0x3f,sizeof(f));//初始化为较大值，因为一会要获取的是较小值
	for(int i=1; i<=n; ++i)f[i][i]=1;
	for(int len=2; len<=n; ++len)
	{
		for(int i=1,j=i+len-1; j<=n; ++i,++j) //i为起点 j为终点
		{
			for(int k=i; k<j; ++k)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
			}
			for(int k=i; k<j; ++k)
			{
				int l=k-i+1;
				if(len%l!=0)continue;
				if(check(i,j,l))f[i][j]=min(f[i][j],f[i][k]+2+m[len/l]);
			}
		}
	}
	cout<<f[1][n]<<endl;
}
