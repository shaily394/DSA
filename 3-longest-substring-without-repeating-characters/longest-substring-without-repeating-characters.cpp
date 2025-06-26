class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int  hash[256] ;
    for(int i =0 ; i<256 ;i++){
        hash[i] = -1;
    }

      int l = 0 , r =0 ;
      int maxlen = 0;
      int len = 0;
      int n  = s.length();
      while(r<n)
      {
      if( hash[s[r]] != -1) {//in the map 
      if(hash[s[r]] >= l){
      l = hash[s[r]] +1;
      }
    }
    len = r-l+1;
    maxlen = max(len , maxlen);
      hash[s[r]] = r;
      r++;

      }
      return maxlen;
    }
};