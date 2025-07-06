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
    void inorder(TreeNode* root,bool &flag , long long & temp){
        if(root == NULL) return;

        inorder(root->left,flag,temp);
        if(temp < root->val) temp = root->val;
        else {
            flag = false;
            return;
        }
        inorder(root->right,flag,temp);
    }
    bool isValidBST(TreeNode* root) {
        
        bool flag = true;
        long long  temp = LLONG_MIN;
        inorder(root,flag,temp);
        return flag;
    }
};