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
 class BSTIterator{
    stack<TreeNode*> st;
    bool reverse; // true for reverse 
public:
    BSTIterator(TreeNode* root , bool isreverse){
        reverse = isreverse;
        pushall(root);
    }
    bool hasnext(){
        return !st.empty();

    }
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushall(temp->right); //for notreverse/next
        else pushall(temp->left); //for reverse/before
        return temp->val;

    }
    void pushall(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse) root= root->right; //for reverse/before
            else root= root->left; //not reverse/next
        }
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        //2 pointers
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k) return true;
            else if( i+j <k) i = l.next();
            else j = r.next();
        }
        return false;

    }
};