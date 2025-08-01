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
private:
TreeNode* first = NULL;
TreeNode* prev = NULL;
TreeNode* middle = NULL;
TreeNode* last = NULL;
public:
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);

        if(prev != NULL && prev->val > root->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev= root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first && last ) swap(first->val , last->val);
        else if(first && middle) swap(first->val , middle->val);
    }
};