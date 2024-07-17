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
    int solve(TreeNode* root,int &index,int k){
        if(root==NULL){
            return -1;
        }
        int left=solve(root->left,index,k);
        if(left!=-1){
            return left;
        }
        index++;
        if(index==k){
            return root->val;
        }
        return solve(root->right,index,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int index=0;
        int ans = solve(root,index,k);
        return ans;
    }
};