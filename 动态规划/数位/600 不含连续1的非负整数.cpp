//二进制下的数位dp
class Solution {
public:

    int dp[30][2];//最多是30位数 (二进制表示)
    int m;
    int solve(int i,bool one,bool limit,int n){//one表示第i-1位是否为1
        if(i==m) return 1;
        if(!limit&&dp[i][one]>=0) return dp[i][one];
        int up=limit?((n>>(m-i-1))&1):1;
        int res=0;
        res+=solve(i+1,false,limit&&up==0,n);//第i位填0
        if(up==1&&!one)//这一位能选1，前一位不为1
            res+=solve(i+1,true,limit,n);
        if(!limit) dp[i][one]=res;
        return res;
    }
    int findIntegers(int n) {
        m=__lg(n)+1;//m表示的就是二进制数字的位数
        memset(dp,-1,sizeof(dp));
        return solve(0,false,true,n);
    }
};
