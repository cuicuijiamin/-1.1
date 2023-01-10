#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
struct node
{
	int go, fee;
	node(int go, int fee) :go(go), fee(fee){}
};
vector<node>e[N];
int f[3005][3005];//f[i][j]表示以i为根的树中，挑选不超过j个节点
int n, m;
int dfs(int u)
{
	f[u][0]=0; 
	if(e[u].size()==0)//是叶子
	{
		return 1;
	}
	int leaf;
	for (int i = 0,len=e[u].size(); i<len; ++i)
	{
		int v = e[u][i].go;
		int w=e[u][i].fee;
		int t=dfs(v);
		leaf+=t;
		for (int j = leaf; j >= 1; --j)//遍历区间&关键 
		{
			for (int k = 1,kk=min(t,j); k<=kk; ++k)
			{
				if(u==0||v==0)cout<<"还真行"<<endl;
				f[u][j] = max(f[u][j], f[u][j - k] + f[v][k] - w);
			}
		}
	}
	return leaf;
}
int main()
{
	memset(f, -0x3f, sizeof(f));//0x8f:初始化为较小值 
	cin >> n >> m;
	for (int i = 1; i <= n - m; ++i)
	{
		int k;
		cin >> k;
		while (k--)
		{
			int a, c;
			cin >> a >> c;
			e[i].push_back(node(a, c));
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (e[i].size() == 0)//是叶子
		{
			cin >> f[i][1];
		}
	}
	dfs(1);
	for (int i = m; i >= 0; --i)
	{
		if (f[1][i] >= 0)
		{
			cout << i << endl;
			break;
		}
	}
	return 0; 
}
