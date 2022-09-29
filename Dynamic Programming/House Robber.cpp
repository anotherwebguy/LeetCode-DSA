//method 1 recursion
class Solution {
public:
    int recursion(int i, vector<int> &nums){
        if(i>=nums.size()) return 0;
        int notTake = recursion(i+1,nums);
        int take = nums[i]+recursion(i+2,nums);
        return max(take,notTake);
    }
    
    int rob(vector<int>& nums) {
        return recursion(0,nums);
    }
};

//method 2 memoization
class Solution {
public:
    int recursion(int i, vector<int> &nums,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int notTake = recursion(i+1,nums,dp);
        int take = nums[i]+recursion(i+2,nums,dp);
        return dp[i]=max(take,notTake);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return recursion(0,nums,dp);
    }
};

//method 3 Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2,0);
        int n = nums.size();
        dp[n]=0,dp[n+1]=0;
        for(int i=n-1;i>=0;i--){
            dp[i] = max(dp[i+1],dp[i+2]+nums[i]);
        }
        return dp[0];
    }
};
