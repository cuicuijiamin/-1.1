//树形背包 
//f[now][j][k]=max(f[son][所有节点数][l]+f[now][j-1][k-l]);以now为根的树上，在前j个节点挑选不超过k 
//空间优化：！！！f[son][所有节点数][l]是已知的  f[now][j-1][k-l]是已知的  f[now][j-1][k]是已知的
//三维需要遍历 j,k,l  考虑滚动 
//压j   需要遍历k,l 
#include<bits/stdc++.h>
const int maxn=305;
using namespace std;
int n,m,f[maxn][maxn],head[maxn],cnt;
vector<int>e[maxn];
void dfs(int now)
{
    for(int i=0;i<e[now].size();i++)
    {
        int go=e[now][i];//go是now的子节点 
        dfs(go); 
        for(int k=m+1;k>=1;k--)//逆序遍历 
        {
            for(int l=0;l<k;l++)//子树最多只能弄k-1个节点 
            {
            	//f[i][j]表示 
                f[now][k]=max(f[now][k],f[go][l]+f[now][k-l]);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    f[0][1]=0;
    for(int i=1;i<=n;i++)
    {
    	int fa; 
        cin>>fa;
        cin>>f[i][1];
        e[fa].push_back(i);
    }
    dfs(0);
    cout<<f[0][m+1];
    return 0;
}
