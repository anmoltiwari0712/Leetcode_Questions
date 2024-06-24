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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;  // {node, {horizontal_distance, level}}
        q.push(make_pair(root, make_pair(0, 0)));

        while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            // insert the node's value into the map at the correct position
            nodes[hd][lvl].push_back(frontNode->val);

            // push the left and right children into the queue with updated positions
            if(frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }
            if(frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }   
        }

        // collect the results from the map
        for(auto i: nodes) { // i represents nodes at each horizontal distance
            vector<int> column;
            for(auto j: i.second) { // j represents nodes at each level
                // sort the values to handle the condition of nodes in the same row and same column
                sort(j.second.begin(), j.second.end());
                for(auto k: j.second) {
                    column.push_back(k);
                }
            }
            ans.push_back(column);
        }

        return ans;
    }
};