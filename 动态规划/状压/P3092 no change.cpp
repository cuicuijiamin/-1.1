#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[20],a[100005],sum[100005];
int f[65540];//f[i]标识状态为i最多能买到哪件物品
int search(int l,int r,int tar)
{
    //找最后一个sum[x]<=tar的位置
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(sum[mid]<=tar)l=mid;
        else r=mid-1;
    }
    return l;
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int k,n;
    cin>>k>>n;//k为硬币数 n为物品数
    for(int i=1;i<=k;++i)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int all=(1<<k)-1;//硬币的总情况数
    ll ans=-1;
    for(int i=0;i<=all;++i)//遍历每一个状态
    {
        if(f[i]==n){
            ll summ=0;
            for(int j=1;j<=k;++j)
            {
                if((1<<(k-j))&i)continue;
                summ+=w[j];
            }
            ans=max(ans,summ);//记录结果
        }
        for(int j=1;j<=k;++j)
        {
            if((1<<(k-j))&i)continue;
            //j为没有被选的物品
            int sta=i+(1<<(k-j));//sta为有了j物品对应的状态
            int x=search(f[i]+1,n,w[j]+sum[f[i]]);
            f[sta]=max(f[sta],x);//x为有了j物品能多买的
            //printf("f[%d]=%d\n",sta,f[sta]);
        }
    }
    if(ans==-1)cout<<ans<<endl;
    else cout<<ans<<endl;
    return 0;
}
