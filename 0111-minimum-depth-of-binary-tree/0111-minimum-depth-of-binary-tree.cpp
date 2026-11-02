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
    int minD = INT_MAX;

    void dfs(TreeNode* root, int cnt) {

        if(root == NULL)
            return;

        cnt++;

        // Check if current node is a leaf
        if(root->left == NULL && root->right == NULL) {
            minD = min(minD, cnt);
            return;
        }

        dfs(root->left, cnt);
        dfs(root->right, cnt);
    }

    int minDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        dfs(root, 0);

        return minD;
    }
};