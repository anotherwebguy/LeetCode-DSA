//method 1
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0],curr=0;
        for(int i=0;i<nums.size();i++){
            curr = nums[i];
            maxi = max(maxi,curr);
            for(int j=i+1;j<nums.size();j++){
                curr+=nums[j];
                maxi = max(maxi,curr);
            }
        }
        return maxi;
    }
};

//method 2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN,curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            maxi = max(maxi,curr);
            if(curr<0) curr=0;
        }
        return maxi;
    }
};
