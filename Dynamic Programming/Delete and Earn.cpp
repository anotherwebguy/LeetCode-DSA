//method 1
class Solution {
public:
    unordered_map<int,int> m;
    
    int recursive(int i,vector<int> &nums,int n){
        if(i==n) return 0;
        int del = m[nums[i]]*nums[i]+recursive(upper_bound(nums.begin(),nums.end(),nums[i]+1)-nums.begin(),nums,n);
        int notdel = recursive(i+1,nums,n);
        return max(del,notdel);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(auto i:nums) m[i]++;
        return recursive(0,nums,n);
    }
};

//method 2
class Solution {
public:
    unordered_map<int,int> m;
    
    int recursive(int i,vector<int> &nums,int n,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int del = m[nums[i]]*nums[i]+recursive(upper_bound(nums.begin(),nums.end(),nums[i]+1)-nums.begin(),nums,n,dp);
        int notdel = recursive(i+1,nums,n,dp);
        return dp[i]=max(del,notdel);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,-1);
        for(auto i:nums) m[i]++;
        return recursive(0,nums,n,dp);
    }
};

//method 3
class Solution {
public:
    unordered_map<int,int> m;
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n+1,-1);
        for(auto i:nums) m[i]++;
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int del = m[nums[i]]*nums[i]+dp[upper_bound(nums.begin(),nums.end(),nums[i]+1)-nums.begin()];
            int notdel = dp[i+1];
            dp[i] = max(del,notdel);
        }
        return dp[0];
    }
};
