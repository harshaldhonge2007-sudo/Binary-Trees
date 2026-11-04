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

    vector<TreeNode*> node;

    void dfs(TreeNode* root) {
        if(root == nullptr) {
            return;
        }

        node.push_back(root);

        dfs(root->left);
        dfs(root->right);
    }

    void flatten(TreeNode* root) {

        node.clear();

        dfs(root);

        for(int i = 0; i < node.size(); i++) {

            node[i]->left = nullptr;

            if(i + 1 < node.size()) {
                node[i]->right = node[i + 1];
            }
            else {
                node[i]->right = nullptr;
            }
        }
    }
};
