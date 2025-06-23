class Solution {
public:
vector<int>pse(vector<int>&nums,int n)
{
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() and nums[st.top()]>nums[i]) st.pop();
        ans[i]=st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vector<int>pge(vector<int>&nums,int n)
{
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() and nums[st.top()]<nums[i]) st.pop();
        ans[i]=st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
vector<int>nse(vector<int>&nums,int n)
{
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() and nums[st.top()]>=nums[i]) st.pop();
        ans[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}
vector<int>nge(vector<int>&nums,int n)
{
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() and nums[st.top()]<=nums[i]) st.pop();
        ans[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

    long long subArrayRanges(vector<int>& nums) {
        long long mini=0;
        long long maxi=0;
        int n=nums.size();
        vector<int>lmin=pse(nums,n);
        vector<int>lmax=pge(nums,n);
        vector<int>rmin=nse(nums,n);
        vector<int>rmax=nge(nums,n);

        for(int i=0;i<n;i++)
        {
            int a=i-lmin[i];
            int b=i-lmax[i];
            int c=rmin[i]-i;
            int d=rmax[i]-i;

            mini+=1LL* a*c*nums[i];
            maxi+=1LL* b*d*nums[i];
            
        }
        return maxi-mini;
    }
};