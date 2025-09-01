class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int n = 0;

        for(int i = 0; i < nums.size() ; i ++){
           
                if(nums[i] == 1) {
                    n++;
                    maxi = max(n , maxi);
                }
                else{
                    n = 0;
                }
            
        }
        return maxi;
    }
};