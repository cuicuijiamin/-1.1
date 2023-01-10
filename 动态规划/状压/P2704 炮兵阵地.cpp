#include<bits/stdc++.h>
using namespace std;
//f[i][j][k]前i行，第i行的状态为j，第i-1行的状态为k的最多炮兵数
//f[i][j][x]=f[i-1][x][y]+sta[j]; 保证j与x  y 不冲突
int board[105];
int f[105][1100][1100];
int sit[1100];//存放全部是平原时的状态
int sta[1100];
int n,m,cnt,ans;
void dfs(int x,int num,int cur){
    if(cur>=m)
    {
        sit[++cnt]=x;
        sta[cnt]=num;
        return;
    }
    dfs(x+(1<<cur),num+1,cur+3);
    dfs(x,num,cur+1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;++j)
        {
            if(s[j]=='P')
                board[i]+=1*pow(2,m-1-j);//j的下标从0开始
        }
    }
    dfs(0,0,0);
    if(n==1)//下面都是两行以上才算的 特判
    {
        for(int i=1;i<cnt;++i)
            if(sit[i]&board[1]==sit[i])ans=max(ans,sta[i]);
        cout<<ans<<endl;
        return 0;
    }
    //初始化
    for(int i=1;i<=cnt;++i)//遍历第一行的情况
    {
        for(int j=1;j<=cnt;++j)
        {
            if((board[1]&sit[i])==sit[i]&&(board[2]&sit[j])==sit[j])//说明i,j状态可能存在
            {
                if(sit[i]&sit[j])continue;
                f[2][j][i]=sta[i]+sta[j];
            }
        }
    }
    //递推
    for(int i=3;i<=n;++i)//遍历行数
    {
        for(int j=1;j<=cnt;++j)//遍历该行的状态
        {
            for(int x=1;x<=cnt;++x)
            {
                for(int y=1;y<=cnt;++y)
                {
                    if((board[i]&sit[j])==sit[j]&&(board[i-1]&sit[x])==sit[x]&&(board[i-2]&sit[y])==sit[y])
                    {
                        if((sit[x]&sit[j])||(sit[j]&sit[y])||(sit[x]&sit[y]))continue;
                        f[i][j][x]=max(f[i][j][x],f[i-1][x][y]+sta[j]);
                        if(i==n)ans=max(ans,f[i][j][x]);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
