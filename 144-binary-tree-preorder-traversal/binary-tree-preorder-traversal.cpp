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
/*class Solution {
public:
    void f(TreeNode * root, vector<int> &res){
        if(root== NULL) return;

        res.push_back(root->val);
        f(root->left,res);
        f(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        f(root,res);
        
        return res;

    }
};*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            int s= st.size();
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right != NULL) st.push(node->right);
            if(node->left != NULL) st.push(node->left);
        }
        return ans;
    }
};