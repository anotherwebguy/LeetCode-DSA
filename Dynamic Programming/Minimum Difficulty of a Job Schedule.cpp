//Recursion
class Solution {
public:
    int recurr(int i, int d,int n, vector<int> &a){
        if(i==n && d==0) return 0;
        if(n-i<d) return (int)1e5;
        if(d<0) return (int)1e5;
        int maxi = 0;
        int res = INT_MAX;
        for(int j=i;j<n;j++){
            maxi = max(maxi,a[j]);
            res = min(res,maxi+recurr(j+1,d-1,n,a));
        }
        return res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        return recurr(0,d,jobDifficulty.size(),jobDifficulty);
    }
};


//Memoization
class Solution {
public:
    int recurr(int i, int d,int n, vector<int> &a,vector<vector<int>> &dp){
        if(i==n && d==0) return 0;
        if(n-i<d) return (int)1e5;
        if(d<0) return (int)1e5;
        if(dp[i][d]!=-1) return dp[i][d];
        int maxi = 0;
        int res = INT_MAX;
        for(int j=i;j<n;j++){
            maxi = max(maxi,a[j]);
            res = min(res,maxi+recurr(j+1,d-1,n,a,dp));
        }
        return dp[i][d]=res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n,vector<int> (d+1,-1));
        return recurr(0,d,n,jobDifficulty,dp);
    }
};

//3-D
class Solution {
public:
    int recurr(int i, int d,int mx,int n, vector<int> &a,vector<vector<vector<int>>> &dp){
        if(i==n) return (d==0)?mx:(int)1e5;
        if(n-i<d) return (int)1e5;
        if(d<0) return (int)1e5;
        if(dp[i][d][mx]!=-1) return dp[i][d][mx];
        long long take = INT_MAX, not_take = INT_MAX;
        if(d>0) take = max(mx,a[i])+recurr(i+1,d-1,0,n,a,dp);
        not_take = recurr(i+1,d,max(mx,a[i]),n,a,dp);
        return dp[i][d][mx]=min(take,not_take);
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        int n = jobDifficulty.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (d+1,vector<int> (1005,-1)));
        return recurr(0,d,0,n,jobDifficulty,dp);
    }
};
