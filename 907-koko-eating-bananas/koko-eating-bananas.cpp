class Solution {
public:
    int findmax(vector<int> &arr){
        int maxi= INT_MIN;
        int n  = arr.size();
        for(int i = 0 ; i<n ; i++){
            maxi= max(maxi, arr[i]);
        }
        return maxi;
    }
    long long totalhrs(vector<int> &arr , int h)
    {
    long long totalh=0;
        int  n = arr.size();
        for(int i =0; i<n ;i ++){
            totalh += ceil((double)arr[i]/(double)h);
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1, high = findmax(piles);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            long long totalh = totalhrs(piles , mid);
            if(totalh <=h){
                ans = mid;
                high = mid -1;
            }
            else low = mid+1;
        }
        return ans;
    }
};