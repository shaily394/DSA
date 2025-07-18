class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=1;
        int i =1;
        int n = ratings.size();
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i] >ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 0; //down will go in reverse so we are assigning 1 candy again to the last one in the down slope.
            while(i<n && ratings[i] <ratings[i-1]){
                down++;
                sum += down;
                i++;
                
            }
            down++;
            if(down >peak){
                sum += down - peak;
            }

        }
        return sum;

    }
};