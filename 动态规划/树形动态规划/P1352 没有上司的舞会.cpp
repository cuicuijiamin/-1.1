//树形dp
#include<bits/stdc++.h>
using namespace std;
const int N=6005;
int n;
int visited[N];
vector<int> T[N];
int dp[N][2]; // 从结点i往下所获最大value
// dp[i][0]表示i不参加时以i为根节点的树的maxValue，dp[i][1]表示i参加时子树的maxValue
void dfs(int k)   // 给定结点k，求以k为root的最大收益
{
	visited[k] = true;
	for (int i = 0; i < T[k].size(); ++i)//找k的子节点
	{
		int v = T[k][i];
		if(!visited[v])
		{
			visited[k]=1;
			dfs(v);
			dp[k][0] += max(dp[v][0],dp[v][1]);
			dp[k][1] += dp[v][0];
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> dp[i][1];
	}
	bool tmp[N] = {0};
	for (int i = 1; i <= n-1; ++i)
	{
		int l,k;
		cin >> l >> k;
		T[k].push_back(l);
		tmp[l] = 1; // 是孩子结点，标记为1
	}
	for (int i = 1; i <= n; ++i)
	{
		if (tmp[i] == 0)   // 寻找唯一的根节点，找到之后dfs
		{
			dfs(i);
			cout << max(dp[i][0],dp[i][1]) << "\n";
			break;
		}
	}
	return 0;
}
