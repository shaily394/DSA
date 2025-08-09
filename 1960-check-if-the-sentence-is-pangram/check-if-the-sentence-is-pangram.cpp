class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> m;
        for(auto x : sentence)
        m[x]++;

        if(m.size() == 26)
        return true;
        return false;
    }
};