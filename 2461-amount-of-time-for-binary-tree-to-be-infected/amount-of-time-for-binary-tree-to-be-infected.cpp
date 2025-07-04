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
    TreeNode* parent(TreeNode* root ,unordered_map <TreeNode* ,TreeNode* > &parent_track , int start){
        queue<TreeNode*>q;
        TreeNode* res;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            if(curr->val == start) res = curr;
            q.pop();
            if(curr->left){
                q.push(curr->left);
                parent_track[curr->left] = curr; 
            }
            if(curr->right){
                q.push(curr->right);
                parent_track[curr->right] = curr; 
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map <TreeNode* ,TreeNode* > parent_track;
        TreeNode* target = parent(root,parent_track,start);
        unordered_map<TreeNode* , int> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] =1;
        int time =0;
        while(!q.empty()){
            int size = q.size();
            
            for (int i =0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = 1;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = 1;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = 1;
                }
            }
            time++;
        }
        return (time-1); //as leaf nodes do not infect anything 
        
    }
};