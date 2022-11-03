//recursion
class Solution {
public:
    int n;
    int recurr(int i,int j, vector<int> &nums){
        if(i > j)
			return 0;
        if(i == j){   
            int temp = nums[i];
            if(i - 1 >= 0)  
                temp *= nums[i - 1];
            if(i + 1 < n)
                temp *= nums[i + 1];
            return temp;
        }
        int ans = 0;
        for(int k=i;k<=j;k++){
            int temp = nums[k];
			
            if(j + 1 < n)  
                temp *= nums[j + 1];
				
            if(i - 1 >= 0) 
                temp *= nums[i - 1];
				
            temp += (recurr(i, k - 1,nums) + recurr(k + 1, j,nums));
			
            ans = max(ans, temp);
        }
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> arr = {1};
        for(int x: nums) 
			arr.push_back(x);
        arr.push_back(1);
        n = arr.size();
        return recurr(1, arr.size() - 2,arr);
    }
};

//memoization
class Solution {
public:
    int n;
    int recurr(int i,int j, vector<int> &nums,vector<vector<int>> &dp){
        if(i > j)
			return 0;
        if(i == j){   
            int temp = nums[i];
            if(i - 1 >= 0)  
                temp *= nums[i - 1];
            if(i + 1 < n)
                temp *= nums[i + 1];
            return temp;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        for(int k=i;k<=j;k++){
            int temp = nums[k];
			
            if(j + 1 < n)  
                temp *= nums[j + 1];
				
            if(i - 1 >= 0) 
                temp *= nums[i - 1];
				
            temp += (recurr(i, k - 1,nums,dp) + recurr(k + 1, j,nums,dp));
			
            ans = max(ans, temp);
        }
        return dp[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> arr = {1};
        for(int x: nums) 
			arr.push_back(x);
        arr.push_back(1);
        n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recurr(1, arr.size() - 2,arr,dp);
    }
};
