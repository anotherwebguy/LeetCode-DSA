//Recursion
class Solution {
public:
    int rec(int e,int n){
        if(n==1 || n==0) return n;
        if(e==1) return n;
        int mini = INT_MAX;
        for(int k=1;k<=n;k++){
            int temp = 1+max(rec(e-1,k-1),rec(e,n-k));
            mini = min(mini,temp);
        }
        return mini;
    }
    
    int superEggDrop(int k, int n) {
        return rec(k,n);
    }
};

//Memoization
class Solution {
public:
    int rec(int e,int n,vector<vector<int>> &dp){
        if(n==1 || n==0) return n;
        if(e==1) return n;
        if(dp[e][n]!=-1) return dp[e][n];
        int mini = INT_MAX;
        for(int k=1;k<=n;k++){
            int temp = 1+max(rec(e-1,k-1,dp),rec(e,n-k,dp));
            mini = min(mini,temp);
        }
        return dp[e][n]=mini;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return rec(k,n,dp);
    }
};

//Memoization 2
class Solution {
public:
    int rec(int e,int n,vector<vector<int>> &dp){
        if(n==1 || n==0) return n;
        if(e==1) return n;
        if(dp[e][n]!=-1) return dp[e][n];
        int mini = INT_MAX;
        for(int k=1;k<=n;k++){
            int x,y;
            if(dp[e-1][k-1]!=-1) x=dp[e-1][k-1];
            else {
                x = rec(e-1,k-1,dp);
                dp[e-1][k-1]=x;
            }
            if(dp[e][n-k]!=-1) y = dp[e][n-k];
            else {
                y = rec(e,n-k,dp);
                dp[e][n-k]=y;
            }
            int temp = 1+max(x,y);
            mini = min(mini,temp);
        }
        return dp[e][n]=mini;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return rec(k,n,dp);
    }
};

//Tabulation + BS
class Solution {
public:
    int dp[101][10001];
    int func(int e,int f)
    {
        //base case
        if(dp[e][f] != -1)
            return dp[e][f];
        if(f <= 1)
            return dp[e][f] = f;
        if(e == 1)
            return dp[e][f] = f;
        int low = 1;
        int high = f;
        int ans = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high-low)/2 ;
            int by;
            if(dp[e-1][mid-1] != -1)
                by = dp[e-1][mid-1];
            else
            { 
                by = func(e-1,mid-1);
                dp[e-1][mid-1] = by;
            }    
            int bn;
            if(dp[e][f-mid] != -1)
                bn = dp[e][f-mid];
            else
            {
                bn = func(e,f-mid);
                dp[e][f-mid] = bn;
            }    
            int temp_ans = 1 + max(by,bn);
            ans = min(ans,temp_ans);
            if(by > bn)
                high = mid-1;
            else
                low  = mid+1;
        }
        return dp[e][f] = ans;
    }   
    
    int superEggDrop(int e, int f) 
    {
        memset(dp,-1,sizeof(dp));
        return func(e,f);
    }
};
