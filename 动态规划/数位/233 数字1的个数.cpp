//数位dp
class Solution {
public:
    int dp[10][1<<10];//dp[i][j]表示选到下标为i的数字，前i-1位的选择情况为j
    string s;
    int solve(int i,int cnt,bool limit){//返回值为该状态的1的个数 cnt表示此状态下的1的个数
        if(i==s.size())//退出
            return cnt;
        if(!limit&&dp[i][cnt]>=0) return dp[i][cnt];
        int res=0;
        int up=limit?s[i]-'0':9;
        for(int j=0;j<=up;++j){
            res+=solve(i+1,cnt+(j==1?1:0),limit&&j==s[i]-'0');
        }
        if(!limit) dp[i][cnt]=res;
        return res;
    }
    int countDigitOne(int n) {
        s=to_string(n);//转字符串
        memset(dp,-1,sizeof(dp));
        return solve(0,0,true);
    }
};
