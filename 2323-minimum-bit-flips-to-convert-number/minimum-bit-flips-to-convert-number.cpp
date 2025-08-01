class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int cnt =0;
        while(ans > 0){
            if(ans&1 == 1) cnt++;
            ans = ans>>1;
        }
        return cnt;
    }
};