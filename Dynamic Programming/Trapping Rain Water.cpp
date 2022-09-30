//method 1 prefic and suffix max (dp)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n],right[n];
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
        }
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            res+=min(left[i],right[i])-height[i];
        }
        return res;
    }
};

//method 2 Two Pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res=0;
        int i=0,j=n-1,left_max=0,right_max=0;
        while(i<j){
            if(height[i]<height[j]){
                if(height[i]>left_max) left_max = height[i];
                else res+=left_max-height[i];
                i++;
            } else {
                if(height[j]>right_max) right_max = height[j];
                else res+=right_max-height[j];
                j--;
            }
        }
        return res;
    }
};
