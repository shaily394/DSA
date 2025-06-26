class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0 ,l=0 , r=0,zeroes = 0 , len=0;
        while(r<nums.size()){
            if(nums[r] == 0) zeroes++;
            while(zeroes >k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            if(zeroes<=k){
                len = r- l+1;
                maxlen = max(maxlen , len);
                r++;
            }
        
    }
    return maxlen;
    }
};