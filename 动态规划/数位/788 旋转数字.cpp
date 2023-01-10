class Solution {
public:
    int dp[5][2];
    string s;
    int solve(int i,bool dif,bool limit,bool isnum){//mask表示挑了哪些数字
        if(i==s.size()){
            if(isnum&&((mask>>2&1)||(mask>>5&1)||(mask>>6&1)||(mask>>9&1)))return 1;
            else return 0;
        }
        if(!limit&&isnum&&dp[i][mask]>=0) return dp[i][mask];
        int res=0;
        if(!isnum) res+=solve(i+1,0,false,false);
        int up=limit?s[i]-'0':9;
        for(int j=1-isnum;j<=up;++j){
            if(j==3||j==4||j==7)continue;
            res+=solve(i+1,mask|1<<j,limit&&j==up,true);
        }
        if(!limit&&isnum) dp[i][mask]=res;
        return res;
    }
    int rotatedDigits(int n) {
        s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,0,true,false);
    }
};
