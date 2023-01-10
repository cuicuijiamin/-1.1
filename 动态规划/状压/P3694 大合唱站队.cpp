#include<bits/stdc++.h>
using namespace std;
int a[100005][25];//a[i][j]记录前i个人的j团队的人数
int num[23];
int f[1048580];//i状态排列的最少出列人数
int main()
{
    memset(f,0x3f,sizeof(f));//要求小值所以初始化为大值
    f[0]=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        num[x]++;//记录x队伍的总人数
        for(int j=1;j<=m;++j)//遍历队伍
        {
            if(j==x)a[i][j]=a[i-1][j]+1;
            else a[i][j]=a[i-1][j];
        }
    }
    int all=(1<<m)-1;
    for(int i=0;i<all;++i)//i：状态
    {
        //计算i状态已经排好的长度
        int length=0;
        for(int j=1;j<=m;++j)//乐队
        {
            if((1<<(m-j))&i) length+=num[j];
        }
        for(int j=1;j<=m;++j)//乐队
        {
            if((1<<(m-j))&i)continue;
            f[i+(1<<(m-j))]=min(f[i+(1<<(m-j))],f[i]+num[j]-a[length+num[j]][j]+a[length][j]);
        }
    }
    cout<<f[all]<<endl;
    return 0;
}
