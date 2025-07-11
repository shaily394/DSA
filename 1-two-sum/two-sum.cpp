/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int , int> mpp;
       for (int i = 0; i<nums.size();i++){
        mpp[nums[i]] = i;
       }
    
    for(int i =0; i<nums.size();i++){
        int comp = target - nums[i];
        if(mpp.find(comp) != mpp.end() && mpp[comp] != i){
            return {i,mpp[comp]};

        }
    }
        return {};
    
    }
};*/



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<pair<int, int>> numbersWithIndices;
        for (int i = 0; i < numbers.size(); i++) {
            numbersWithIndices.push_back({numbers[i], i});
        }
        
        sort(numbersWithIndices.begin(), numbersWithIndices.end());
        
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbersWithIndices[left].first + numbersWithIndices[right].first;
            if (sum == target) {
                return {numbersWithIndices[left].second, numbersWithIndices[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {}; 
    }
};