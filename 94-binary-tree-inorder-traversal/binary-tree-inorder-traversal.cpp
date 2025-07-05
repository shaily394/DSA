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
        f(root->left,res);
        res.push_back(root->val);
        f(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        f(root,res);
        
        return res;
    }
};*/

/*class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* node= root;
        vector<int> ans;
        while(true){
            if(node != NULL){
                st.push(node);
                node= node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};*/

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        TreeNode* curr = root;
        vector <int> inorder;
        while(curr!= NULL){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr= curr->left;
                }
                else {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }

};