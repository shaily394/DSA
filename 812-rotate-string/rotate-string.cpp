/*class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        for(int i =0;i<s.size();i++){
            string rot = s.substr(i) + s.substr(0,i);
            if(rot == goal) return true;
        }
        return false;
    }
};*/

class Solution {
public:
    bool rotateString(string s, string goal){
        if(s.size() != goal.size()){
            return false;
        }
        string temp= s+s;
        int find=temp.find(goal);
        if(find>=0)
        {
            return true;
        }
        return false;
    }
};