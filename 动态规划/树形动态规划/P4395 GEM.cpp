#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int INF=0x3f3f3f3f;
struct edge{
    int to,next;
    edge(int t=0,int n=0)
    {
        to=t;
        next=n;
    }
}a[2*N];
int head[N],tot,vis[N];
void add(int from,int to)
{
    a[++tot]=edge(to,head[from]);
    head[from]=tot;
}
int f[N][20];//f[i][j]表示以i为节点的子树  权值设置为j的全小值
void dfs(int x)
{
    for(int i=1;i<=15;++i)
    {
        f[x][i]=i;
    }//初始化操作

    for(int i=head[x];i;i=a[i].next){
        int v=a[i].to;//子节点
        if(!vis[v]){//之前算过就不算了
            vis[v]=1;
            dfs(v);
            for(int j=1;j<=15;++j)//能选择的情况 x节点权值为i
            {
                int mm=INF;
                for(int k=1;k<=15;++k)//子节点的权值的情况
                {
                    if(j!=k)mm=min(mm,f[v][k]);
                }
                f[x][j]+=mm;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    vis[1]=1;
    dfs(1);
    int ans=INF;
    for(int i=1;i<=15;++i)
    {
        ans=min(ans,f[1][i]);
    }
    cout<<ans<<endl;
}
