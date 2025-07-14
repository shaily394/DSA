class Solution {
public:
    int lengthOfLastWord(string s) {
        int l=0;
        int n = s.size();
        int i = n-1;
        while(s[i]== ' ') i--;
        while(i>=0){
            if(s[i] == ' ') break;
            l++;
            i--;
        }
        return l;
    }
};