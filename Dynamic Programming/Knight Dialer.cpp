//method 1 Recursion
class Solution {
public:
    int MOD = (int)1e9+7;
    int knightDialer(int n) {
        long res=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                res = (res+paths(i,j,n))%MOD;
            }
        }
        return (int)res;
    }
    
    int paths(int i,int j,int n){
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) return 0;
        if(n == 1) return 1;
        long s = paths(i-1,j-2,n-1)%MOD +
                 paths(i-1,j+2,n-1)%MOD +
                 paths(i+1,j-2,n-1)%MOD +
                 paths(i+1,j+2,n-1)%MOD +
                 paths(i-2,j-1,n-1)%MOD +
                 paths(i-2,j+1,n-1)%MOD +
                 paths(i+2,j-1,n-1)%MOD +
                 paths(i+2,j+1,n-1)%MOD;
        return s%MOD;
    }
};

//method 2 Memoization
class Solution {
public:
    int MOD = (int)1e9+7;
    int knightDialer(int n) {
        long res=0;
        vector<vector<vector<long>>> dp(n+1,vector<vector<long>>(4,vector<long>(3,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                res = (res+paths(i,j,n,dp))%MOD;
            }
        }
        return (int)res;
    }
    
    long paths(int i,int j,int n,vector<vector<vector<long>>> &dp){
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) return 0;
        if(n == 1) return 1;
        if(dp[n][i][j]!=-1) return dp[n][i][j];
        dp[n][i][j] = paths(i-1,j-2,n-1,dp)%MOD +
                 paths(i-1,j+2,n-1,dp)%MOD +
                 paths(i+1,j-2,n-1,dp)%MOD +
                 paths(i+1,j+2,n-1,dp)%MOD +
                 paths(i-2,j-1,n-1,dp)%MOD +
                 paths(i-2,j+1,n-1,dp)%MOD +
                 paths(i+2,j-1,n-1,dp)%MOD +
                 paths(i+2,j+1,n-1,dp)%MOD;
        return dp[n][i][j];
    }
};
