//method 1 recursion
class Solution {
public:
    int recurr(int i,int prev,vector<int> &nums){
        if(i==nums.size()) return 0;
        int notTake = 0+recurr(i+1,prev,nums);
        int take = INT_MIN;
        if(prev==-1 || nums[i]>nums[prev]){
            take = 1+recurr(i+1,i,nums);
        }
        return max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return recurr(0,-1,nums);
    }
};

//method 2 Memoization
class Solution {
public:
    int recurr(int i,int prev,vector<int>& nums, vector<vector<int>> &dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int len = 0+recurr(i+1,prev,nums,dp);
        if(prev==-1 || nums[i]>nums[prev]){
            len = max(len,1+recurr(i+1,i,nums,dp));
        }
        return dp[i][prev+1]=len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recurr(0,-1,nums,dp);
    }
};

//method 3 Tabulation
class Solution {
public:   
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0]=1;
        int maxi = 1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};

//method 4 lower bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>res.back()) res.push_back(nums[i]);
            else {
                int ind = lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[ind] = nums[i];
            }
        }
        return res.size();
    }
};
