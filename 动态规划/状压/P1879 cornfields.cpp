#include<bits/stdc++.h>
using namespace std;
int board[13];//记录地图状态
int sta[5000],sit[5000];
int f[13][5000];//前i行，第i行状态为j  的最多方案数
const int MOD=100000000;
int n,m,cnt;
void dfs(int x,int num,int cur)
{
    if(cur>=m){//处理完毕
        sit[++cnt]=x;
        sta[cnt]=num;
        return;
    }
    dfs(x,num,cur+1);//不选cur位置
    dfs(x+(1<<cur),num+1,cur+2);//选cur位置
}
int main()
{
    cin>>n>>m;//n行m列
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int x;
            cin>>x;
            if(x)board[i]+=pow(2,m-1-j);
        }
    }
    dfs(0,0,0);
    for(int j=1;j<=cnt;++j)
    {
        if((board[1]&sit[j])==sit[j])
            f[1][j]=1;
    }
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=cnt;++j)//遍历第i行的状态
        {
            for(int x=1;x<=cnt;++x)//遍历i-1行的状态
            {
                if((board[i]&sit[j])==sit[j]&&(board[i-1]&sit[x])==sit[x])//能这么放
                {
                    if(sit[j]&sit[x])continue;//冲突
                    f[i][j]=(f[i][j]+f[i-1][x])%MOD;
                }
            }
        }
    }
    int ans=0;
    for(int j=1;j<=cnt;++j)
    {
        ans=(ans+f[n][j])%MOD;
    }
    cout<<ans<<endl;
}
