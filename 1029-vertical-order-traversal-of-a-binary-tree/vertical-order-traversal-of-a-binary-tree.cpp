/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair <int,int>>> q;
        map <int , map<int,multiset<int>>> mpp;
        if(root==NULL) return ans;
        q.push({root,{0,0}});
        while(!q.empty()){
            int s=q.size();
            vector<int> level;
            for (int i=0;i<s;i++){
                auto it = q.front();
                q.pop();
                int x = it.second.first;
                int y = it.second.second;
                mpp[x][y].insert(it.first->val);
                if(it.first->left) q.push({it.first->left,{x-1,y+1}});
                if(it.first->right) q.push({it.first->right,{x+1,y+1}});
            }
            
        }
        for(auto p:mpp){
            vector<int> col;
            for(auto q:p.second){
                for(auto it : q.second){
                    col.push_back(it);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};