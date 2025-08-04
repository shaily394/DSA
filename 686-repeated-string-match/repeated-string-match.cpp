class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lena = a.length();
        int lenb = b.length();

        int n = lenb/lena;

        int cnt = n;
        string na = "";
        while(cnt--){
            na = na + a;
           
        }
        if(na.find(b) != std::string::npos){
                return n;
        }
        na = na + a;
        if(na.find(b) != std::string::npos){
                return n + 1;
        }
        na = na + a;
        if(na.find(b) != std::string::npos){
                return n + 2;
        }

        return -1;
    }
};