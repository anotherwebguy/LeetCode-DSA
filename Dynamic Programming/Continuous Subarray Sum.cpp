//method 1 hashmap
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp{{0, 0}};
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(!mp.count(rem)) mp[rem] = i+1;
            else if(mp[rem]<i) return true;
        }
        return false;
    }
};

