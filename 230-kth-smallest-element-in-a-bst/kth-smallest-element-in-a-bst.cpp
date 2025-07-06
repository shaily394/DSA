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
 //recursive
/*class Solution {
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
};*/

//morris

class Solution{
public:
    int kthSmallest(TreeNode* root, int k){
        
        TreeNode * cur = root;
        int s=0;
        int ans;
        while(cur != NULL){
            if(cur->left == NULL){
                s++;
                if(s==k) ans= cur->val;
                cur = cur->right;
                }
            else{
                TreeNode* prev = cur->left;
                while(prev->right != NULL && prev->right != cur){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    s++;
                    if(s==k) ans =cur->val;
                    cur = cur->right;
                }
            }
        }
       
        return ans;

    }

};

