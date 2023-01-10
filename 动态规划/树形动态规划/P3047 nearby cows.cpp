#include <bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
//从节点i走k步能到达的点中，一种是在上面(父节点)  一种是在下面(子节点)
ll f[N][25], d[N][25];
//f[i][j]表示以i节点，往下走不超过j步的点权和
//d[i][j]表示以i节点，走不超过j步的点权和
int n, k, tot, head[N];
//head为顶点表 head[i]得到的是i节点的相连节点的下标x
struct edge
{
	int to, next;
	edge(int x=0, int y=0) { to = x; next = y; }
}a[N * 2];//边全部存储在a数组里
//邻接表存图

void add(int from, int to)
{
	a[++tot] = edge(to, head[from]);
	head[from] = tot;//类比头插
}

//第一次dfs————算出只往下走不超过k步的结果 算出子节点的值，进而去推父节点的值
void dfs(int x, int fa)
{
	for (int i = head[x]; i; i = a[i].next)//遍历x的子节点
	{
		int u = a[i].to;
		if (u != fa)
		{
			dfs(u, x);//先dfs到叶子节点，然后推父亲节点
			for (int i = 1; i <= k; i++)
				f[x][i] += f[u][i - 1];
		}
	}
}
//第二次dfs————算走不超过k步的值 已知父节点的值去算子节点的值
void dfs2(int x, int fa)
{
	for (int i = head[x]; i; i = a[i].next)//遍历x的子节点
	{
		int u = a[i].to;
		if (u != fa)
		{
			d[u][1] += f[x][0];
			for (int i = 2; i <= k; i++)
				d[u][i] += (d[x][i - 1] - f[u][i - 2]);
			dfs2(u, x);//先dfs父亲节点，更新完儿子后dfs儿子
		}
	}
}
int main()
{
	cin>>n>>k;
	for (int i = 1; i < n; i++)
	{
        int a1,a2;
		cin>>a1>>a2;
		add(a1, a2);//从a1连到a2的边
		add(a2, a1);//从a2连到a1的边
	}
	for (int i = 1; i <= n; i++)
    {
        int a;
		cin>>a;
        for (int j = 0; j <= k; j++) f[i][j] = a;
    }
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
			d[i][j] = f[i][j];//把f赋给d
	dfs2(1, 1);
	for (int i = 1; i <= n; i++)
		cout << d[i][k] << endl;//输出答案
	return 0;
}
