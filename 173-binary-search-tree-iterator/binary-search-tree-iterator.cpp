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
class BSTIterator {
private: 
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
       fillStack(root); 
    }
    
    int next() {
        TreeNode* nextNode = st.top();
        st.pop();
        fillStack(nextNode->right);
        return nextNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void fillStack(TreeNode* root){
        TreeNode* curr = root;
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */