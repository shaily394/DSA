
/*class Solution {
public:
   
    string frequencySort(string s) {
       unordered_map<char,int> mpp;
        for(auto ch : s){
            mpp[ch]++;
        }
        sort(s.begin(),s.end(),[&] (char a , char b){
            if (mpp[a] == mpp[b]) return a < b;
            return mpp[a] > mpp[b];
        });
        return s;
    }
};*/
//bucket sort
class Solution{
public:
    string frequencySort(string s){
        unordered_map<char,int> mpp;
        for(auto ch : s){
            mpp[ch]++;
        }
        vector<vector<char>> freq(s.size()+1);
        for (auto it : mpp) {
            char ch = it.first;
            int count = it.second;
            freq[count].push_back(ch);  
        }
        string ans = "";
        for (int fq = s.length(); fq >= 1; fq--) {
            for (auto ch :freq[fq]) {
                ans.append(fq, ch);  
            }
        }

        return ans;
    }
};