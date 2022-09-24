class Solution {
public:
    int powerOfTwo(int n)
    {
        return n && (!(n & (n-1)));
    }

    vector<int> countBits(int n) {
        if(n==0) return {0};
        if(n==1) return {0,1};
        if(n==2) return {0,1,1};
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            if(i%2) dp[i]=dp[i-1]+1;
            else if(powerOfTwo(i)) dp[i]=1;
            else {
                int mini = INT_MAX;
                for(int j=2;j<i;j*=2){
                    mini = min(mini,dp[j]+dp[i-j]);
                }
                dp[i]=mini;
            }
        }
        return dp;
    }
};
