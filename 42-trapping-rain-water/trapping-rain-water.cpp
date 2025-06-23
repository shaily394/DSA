class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int leftmax = 0;   
        vector<int> suffix(n);
        suffix[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){

            suffix[i] = max(suffix[i+1],height[i]);
        }
        for(int i = 0; i < n; i++){
            if(i==0) leftmax = height[0];
            else leftmax = max(leftmax,height[i]);
            int rightmax = suffix[i];
            if(height[i] < leftmax && height[i]<rightmax){
                total += min(leftmax,rightmax) - height[i];
            }
        }

        return total;
    }
};