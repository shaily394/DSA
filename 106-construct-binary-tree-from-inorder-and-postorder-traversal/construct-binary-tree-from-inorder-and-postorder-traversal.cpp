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
    TreeNode* f(vector<int>& postorder,int poststart,int postend ,vector<int>& inorder , int instart,int inend,map<int,int> &mpp){
        if(poststart > postend || instart>inend) return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mpp[root->val];
        int numsleft = inroot-instart;

        TreeNode* left = f(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,mpp);
        TreeNode* right = f(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,mpp);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //hashmap to store preorder,so it makes searching easier
        map <int,int> mpp;
        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]] =i;
        }
        TreeNode* root = f(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};