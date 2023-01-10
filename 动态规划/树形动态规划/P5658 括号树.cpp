#include<bits/stdc++.h>
typedef long long ll;
const int maxn=500005;

using namespace std;

int n;
string s;
int fa[maxn],head[maxn];
ll lst[maxn],sum[maxn];
struct edge{
    int to,next;
    edge(int t=0,int n=0){
        to=t;
        next=n;
    }
}a[maxn];
int tot;
void add_edge(int u, int v)//u是父，v是子
{
    a[++tot]=edge(v,head[u]);
    head[u]=tot;
}
int top,k[maxn];
void dfs(int x)
{
    int tmp=0;
    if(s[x]==')')
    {
        if(top)
        {
            tmp=k[top];
            lst[x]=lst[fa[tmp]]+1;
            --top;//匹配掉一个
        }
    }
    else if(s[x]=='(')
    {
        k[++top]=x;//k数组记录前括号的位置
    }
    sum[x]=sum[fa[x]]+lst[x];
    for(int i=head[x];i;i=a[i].next)
        dfs(a[i].to);
    //回溯复原操作
    if(tmp!=0)k[++top]=tmp;
    else if(top)
        --top;
    
}

int main()
{
	cin>>n;
    cin>>s;
    s=" "+s;
    //scanf("%s",s+1);
	for(int i = 2; i <= n; i ++)
	{
		int f;
		cin>>f;
		add_edge(f, i);
		fa[i] = f;
	}
	dfs(1);
    ll ans=0;
	for(int i = 1; i <= n; i ++)
		ans ^= sum[i] * (ll)i;
    cout<<ans<<endl;
	return 0;
}
