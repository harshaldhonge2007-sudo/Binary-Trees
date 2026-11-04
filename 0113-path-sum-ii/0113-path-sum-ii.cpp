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
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int sum, int targetSum) {

        if(root == nullptr) return;

        path.push_back(root->val);
        sum += root->val;

        if(root->left == nullptr && root->right == nullptr) {
            if(sum == targetSum) {
                ans.push_back(path);
            }
        }

        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        ans.clear();
        path.clear();

        dfs(root, 0, targetSum);

        return ans;
    }
};
