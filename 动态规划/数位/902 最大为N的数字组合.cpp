class Solution {
public:
    string s;
    int dp[10];
    map<char,int> vis;
    int solve(int i,bool limit,bool isnum)//需要考虑前导0，前面的0数组里没有也不用管，后面想写0就需要考虑数组中有没有
    {
        if(i==s.size()) return isnum;
        if(!limit&&isnum&&dp[i]>=0) return dp[i];
        int res=0;
        int up=limit?s[i]-'0':9;
        if(!isnum)//跳过操作
            res+=solve(i+1,false,false);
        for(int j=1-isnum;j<=up;++j)//遍历第i位的数字
        {
            if(vis.count(j+'0'))
                res+=solve(i+1,limit&&j==up,true);
        }
        if(!limit&&isnum) dp[i]=res;
        return res;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        s=to_string(n);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<digits.size();++i)
        {
            vis[digits[i][0]]=1;
        }
        return solve(0,true,false);
    }
};
