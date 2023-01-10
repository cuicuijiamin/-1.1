#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};//方向数组 方便搜
int vis[MAXN][MAXN];
int h[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN];//l数组与r数组存放的是（i,j）能到达的左域和右域 

void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)//遍历四个方向 
	{
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if (x1 < 1 || x1 > n || y1 < 1 || y1 > m || h[x][y] <= h[x1][y1]) continue;
		if (!vis[x1][y1]) dfs(x1, y1);
		//注意  若(x1, y1)格子已经过就不用搜了
		//但    l和r还是要更新的
		l[x][y] = min(l[x][y], l[x1][y1]);//从x,y位置能搜到的 
		r[x][y] = max(r[x][y], r[x1][y1]);
	}
}

int main()
{
	cin>>n>>m;
	memset(l, 0x3f, sizeof(l));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin>>h[i][j];
			if (i == n) l[i][j] = r[i][j] = j;//最后一行初始化
		}
	}

	for (int i = 1; i <= m; i++)
	{
		if (!vis[1][i]) dfs(1, i);//若这格已经搜过了就不用搜了
	}
	bool check = true;
	int ans = 0;
	for (int i = 1; i <= m; i++)//判断有无解 
	{
		if (!vis[n][i])//说明无解
		{
			check = false; 
			ans++;
		}
	}
	if (!check)
	{
		cout << 0 << endl << ans << endl;
		return 0;
	}

	int left = 1, right = r[1][1];//初始化为第一个蓄水站能到达的l与r 
	//统计区间数
	while (left <= m)
	{
		for (int i = 1; i <= m; i++)
		{
			if (l[1][i] <= left)
			{
				right = max(right, r[1][i]);
			}
		}

		left = right + 1;
		ans++;
	}
	cout << 1 << endl << ans << endl;
	return 0;
}
