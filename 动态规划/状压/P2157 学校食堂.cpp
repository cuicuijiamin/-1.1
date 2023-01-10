#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int INF=0x3f3f3f3f;
int f[N][1<<8][20];//f[i][j][k]:前i-1个人打好饭，i~i+7的打饭状态为j,当前最后一个人是i+k
//转移：
//i打好饭(j&1==1) f[i+1][j>>1][k-1]=f[i][j][k]
//else f[i][j][h]=f[i][j][k]+h打饭所用的时间   枚举h  
//首先这个h得是没打饭的，h打饭可能会激怒h前面的没打饭的人，需要判断
//初始化 较大值
//结果 f[n+1][0][]
int t[N],b[N];
int time(int a,int b)
{
    if(a<=0) return 0;
    return (t[a]|t[b])-(t[a]&t[b]);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(f,0x3f,sizeof(f));//初始化
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>t[i]>>b[i];
        }
        int all=(1<<8)-1;
        //初始化
        for(int k=-8;k<0;++k)
            f[1][0][k+8]=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=all;++j)//表示状态
            {
                for(int k=-8;k<=7;++k)//最后一个打饭的人
                {
                    if(f[i][j][k+8]==INF) continue;
                    if(j&1)
                        f[i+1][j>>1][k+7]=min(f[i+1][j>>1][k+7],f[i][j][k+8]);
                    else{
                        int limit=INF;
                        for(int h=0;h<=7;++h)
                        {
                            if((j>>h)&1)continue;
                            if(i+h>limit) break;//当前h都选不了 后面自然选不了 直接跳出循环
                            limit=min(limit,i+h+b[i+h]);//当前的忍耐尽头 limit用来判断h能不能选
                            //h还没选
                            f[i][j+(1<<h)][h+8]=min(f[i][j+(1<<h)][h+8],f[i][j][k+8]+time(i+k,i+h));
                        }
                    }
                   // printf("f[%d][%d][%d]=%d\n",i,j,k+8,f[i][j][k+8]);
                }
            }
        }
        int ans=INF;
        for(int k=-8;k<0;++k)
            ans=min(ans,f[n+1][0][k+8]);
        cout<<ans<<endl;
    }
    return 0;
}
