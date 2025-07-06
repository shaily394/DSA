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
    void f(TreeNode* root, int k, int &s,int &ans){
        if(root == NULL) return ;

        f(root->left,k,s,ans);
        s++;
        if(s==k) {
            ans = root->val;
            return;
        }
        f(root->right,k,s,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int s =0;
        int ans;
        f(root,k,s,ans);
        return ans;
    }
};