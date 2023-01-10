#include<bits/stdc++.h>
//先想到最大深度，也就是最长链。如果给的步数很大，那么在中途可以选择多走两步去多走一个节点，这样就是最优的
//先考虑递归求解最大深度
using namespace std;
vector<int>e[105];
int dep[105];
int vis[105];
int getDepth(int u)
{
    if(e[u].size()==1&&u!=0)
    {
        return dep[u]=1;
    }
    int x=0;
    for(int i=0;i<e[u].size();++i)
    {
        int v=e[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            if(!dep[v])getDepth(v);//求子节点的深度
            x=max(x,dep[v]);
        }
    }
    return dep[u]=x+1;
}
int main()
{
    int v,n;
    cin>>v>>n;
    for(int i=1;i<v;++i)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }   
    vis[0]=1;
    int t=getDepth(0);
    if(n<=t-1) cout<<n+1<<endl;
    else cout<<min(v,t+(n-t+1)/2)<<endl;
}
