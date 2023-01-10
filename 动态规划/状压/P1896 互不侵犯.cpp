//状压dp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[10][1000][90];//f[i][j][l]表示前i行，第i行状态为j(下面的cnt,代表的是状态的计数),放了l个国王 的摆放情况数量
int sit[1000];//记录状态：状态1放，0不放
int sta[1000];//记录每个状态的国王数目  
int n,k,cnt;
void dfs(int x,int num,int cur)//x表示状态 num表示该状态对应的国王数目 cur表示现在要处理的位置
{
    if(cur>=n)//表明n个位置全部处理完成
    {
        sit[++cnt]=x;
        sta[cnt]=num;
        return;
    }
    dfs(x,num,cur+1);//cur位置不放
    dfs(x+(1<<cur),num+1,cur+2);//cur位置放，那么cur+1位置就不妨
}
bool check(int j,int x){
    //两个状态分别是sit[j]  sit[x]
    if(sit[j]&sit[x]) return false;//按位与 非0说明存在一个位置都是1
    if((sit[j]>>1)&sit[x]) return false;
    if(sit[j]&(sit[x]>>1))return false;
    return true;
}
int main()
{
    cin>>n>>k;
    //初始化f[1][][]的情况 ————不能直接推导而来 因为上一行数全是0，没办法推导
    dfs(0,0,0);
    for(int j=1;j<=cnt;++j){//cnt表示的是每行的摆放最多有多少种
        f[1][j][sta[j]]=1;
    }
    for(int i=2;i<=n;++i)//推导
    {
        for(int j=1;j<=cnt;++j)//遍历要计算的第i行的状态
        {
            for(int x=1;x<=cnt;++x)//遍历前一行的摆放状态
            {
                if(!check(j,x)) continue;//不能这样放 
                for(int l=sta[j];l<=k;++l)//遍历放了的国王的数量
                {
                    f[i][j][l]+=f[i-1][x][l-sta[j]];
                }
            }
        }
    }
    long long ans=0;
    for(int j=1;j<=cnt;++j)
    {
        ans+=f[n][j][k];
    }
    cout<<ans<<endl;
    return 0;
}
