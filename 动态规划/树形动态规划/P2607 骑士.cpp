#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int INF=0x3f3f3f3f;
typedef long long ll;
struct edge{
    int to,next;
    edge(int t=0,int n=0){
        to=t;
        next=n;
    }
}a[MAXN];
int tot,head[MAXN];
void add(int f,int v)
{
    a[++tot]=edge(v,head[f]);
    head[f]=tot;
}
int n;
int val[MAXN],fa[MAXN],vis[MAXN];
ll f[MAXN][2],ans;
int root;

void dp(int now){
    vis[now]=1;
    f[now][0]=0;
    f[now][1]=val[now];//初始化
    for(int i=head[now];i;i=a[i].next)
    {
        int go=a[i].to;
        if(go!=root){//子节点如果是root
            dp(go);
            f[now][1]+=f[go][0];
            f[now][0]+=max(f[go][0],f[go][1]);
        }
        else{
            f[root][1]=-INF;
        }
    }
}
void fingCircle(int x){
    vis[x]=1;
    root=x;
    while(!vis[fa[root]])
    {
        root=fa[root];
        vis[root]=1;//记录这棵树中的每个节点
    }
    dp(root);//需要跑两次dp  
    ll t=f[root][0];//不选root
    vis[root]=1;
    root=fa[root];
    dp(root);
    ans+=max(t,f[root][0]);
    return;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>val[i];//输入每个骑士的价值
        cin>>fa[i];
        add(fa[i],i);//加边操作
    }
    for(int i=1;i<=n;++i)//遍历所有的节点，判断是否存在环
    {
        if(!vis[i])//vis[i]=1意味着i节点已经在某棵树中被记录过了
            fingCircle(i);
    }
    cout<<ans<<endl;
    return 0;
}
