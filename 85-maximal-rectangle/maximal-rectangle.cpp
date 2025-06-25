class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;
        int n = heights.size();
        int ele , nse , pse;
        for(int i =0 ; i<n ;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                ele = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ?-1:st.top();
                maxi = max(maxi , heights[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()) //stack is not empty but the array is traversed completely
        {
            nse = n; //array is traversed so there is no next element that can be nse
            ele = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top(); 
            maxi = max(maxi, heights[ele]*(nse-pse-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi =0;
        vector<vector<int>> psum(n,vector<int>(m));
        for(int j =0 ;j < m ; j++){
            int sum = 0;
            for(int i = 0 ; i < n ; i++){
                sum += matrix[i][j] - '0';
                if(matrix[i][j]== '0') sum = 0;
                psum[i][j] = sum;
            }
        }
        for(int i= 0 ; i<n ;i++){
            maxi = max(maxi , largestRectangleArea(psum[i]));
        }
        return maxi;

    }
};