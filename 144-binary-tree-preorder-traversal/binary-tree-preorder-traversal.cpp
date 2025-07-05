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

/*class Solution {
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
};*/

class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        TreeNode* curr = root;
        vector <int> preorder;
        while(curr!= NULL){
            if(curr->left == NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr= curr->left;
                }
                else {
                    prev->right = NULL;
                   
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }

};