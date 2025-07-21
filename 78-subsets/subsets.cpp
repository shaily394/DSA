//recursion
/*class Solution {
public:
    void subset(vector<int> &nums , int index , vector<int> sub , vector<vector<int>> & subs){
        if (index == nums.size()) {
            subs.push_back(sub);
            return;
        }
        
        sub.push_back(nums[index]);
        subset(nums , index+1 , sub , subs);
        sub.pop_back();
        subset(nums , index+1 , sub , subs);
    
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subset(nums , 0 , sub , subs);
        return subs;
    }
};*/


//bit manipulation
class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        int n = nums.size();
        int subsets = 1<<n;
        vector<vector<int>> ans;
        for(int i = 0 ;i <subsets;i++){
            vector<int> l;
            for(int j =0;j<n;j++){
                if(i &(1<<j)){
                    l.push_back(nums[j]);
                }
                
            }
            ans.push_back(l);
        }
        return ans;
    }
};