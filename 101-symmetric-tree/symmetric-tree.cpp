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
    bool isSymmetrichelper(TreeNode* leftNode,TreeNode* rightNode){
        if(leftNode==NULL && rightNode==NULL){
            return true;
        }
        if(leftNode==NULL || rightNode==NULL || leftNode->val!=rightNode->val){
            return false;
        }
        return isSymmetrichelper(leftNode->left,rightNode->right) && isSymmetrichelper(leftNode->right,rightNode->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return isSymmetrichelper(root->left,root->right);
    }
};