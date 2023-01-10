//数位dp
class Solution {
private:
    string s;
    int dp[10][1<<10];
public:
    int numDupDigitsAtMostN(int n) {
        s=std::to_string(n);//转字符串
        memset(dp,-1,sizeof(dp));//记录是否出现重复情况
        return n-solve(0,0,true,false);//开始考虑0，后续数字受到限制，未出现过重复
    }
    int solve(int i,int mask,bool limit,bool isnum)//i:考虑下标为i的数字 mask:前i-1个数字的选择情况  limit:表示是否受到限制  isnum:之前是否有过数字  返回值为不出现重复数字的正整数的个数
    {
        if(i==s.size()){
            return isnum;
        }
        if(!limit&&isnum&&dp[i][mask]>=0) return dp[i][mask];
        int res=0;
        //                true              false
        //limit           0~s[i]            0~9
        //isnum           0~9               跳过，1~9
        if(!isnum){
            res+=solve(i+1,mask,false,false);//跳过操作
        }
        int g=limit?s[i]-'0':9;//上限
        for(int j=1-isnum;j<=g;++j){
            if(((mask>>j)&1)==0)//未出现过
                res+=solve(i+1,mask+(1<<j),limit&&j==s[i]-'0',true);
        }
        if (!limit&&isnum) dp[i][mask] = res;//在受限的情况下，同样的一组数，只会出现一次，不需要记忆
        return res;
    }
};
