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
    void inorder(TreeNode*  root,vector<int> &in){
        if(root==NULL){
            return ;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inord;
        inorder(root,inord);
        int i=0;
        int j=inord.size()-1;

        while(i<j){
            int sum=inord[i]+inord[j];
            if(sum==k){
                return true;
            }
            else if(sum>k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};