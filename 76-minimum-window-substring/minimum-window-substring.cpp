class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0};
        int n = s.size();
        int m = t.size();
        int minlen=INT_MAX;
        int sin=-1 ,l=0 , r=0 ,cnt=0;
        for(int i =0; i<m ;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sin=l;
                }
                hash[s[l]]++;
                if(hash[s[l]] >0) cnt--;
                l++;
            }
            r++;
        }
       return (minlen == INT_MAX) ? "" : s.substr(sin, minlen);

    }
};