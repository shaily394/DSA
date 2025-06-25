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
};