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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key) return rearrange(root);

        TreeNode* curr = root;
        while(curr != NULL){
            //If key is smaller than the current node
            if(curr->val > key){
                //the current node's left is the key
                if(curr->left && curr->left->val == key){
                    //delete the key and return.
                    curr->left = rearrange(curr->left);
                    break;
                }
                //if current node's left isn't the key or if it's NULL, just go left.
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->right && curr->right->val == key){
                    curr->right = rearrange(curr->right);
                    break;

                }
                else{
                    curr= curr->right;
                }
            }
        }
        return root;
    }
    // this function deletes the node and return the child nodes
    TreeNode* rearrange(TreeNode * node){
        TreeNode* leftsubtree = node->left;
        TreeNode* rightsubtree = node->right;

        delete(node);
        if(leftsubtree == NULL) return rightsubtree;
        if(rightsubtree == NULL ) return leftsubtree;

        //if both exist ,join the right subtree to the largest value (rightmost) in the left subtree

        TreeNode* maxNode = maxi(leftsubtree);
        //rightSubtree has all bigger values than the leftsubtree, hence they go on the right
        maxNode->right = rightsubtree;
        
        return leftsubtree;
    }
    TreeNode* maxi(TreeNode* node){
        while(node->right) {
            node = node->right;
        }
        return node;
    }
};
