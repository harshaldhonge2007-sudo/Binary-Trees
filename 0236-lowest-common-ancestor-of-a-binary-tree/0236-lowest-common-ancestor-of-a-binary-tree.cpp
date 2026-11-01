/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void dfs(TreeNode* root) {
        if(root == nullptr)
            return;

        if(root->left) {
            parent[root->left] = root;
            dfs(root->left);
        }

        if(root->right) {
            parent[root->right] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        parent[root] = nullptr;

        // Build parent map using DFS
        dfs(root);

        // Store ancestors of p
        unordered_set<TreeNode*> ancestors;

        while(p != nullptr) {
            ancestors.insert(p);
            p = parent[p];
        }

        // Find first common ancestor of q
        while(q != nullptr) {
            if(ancestors.count(q))
                return q;

            q = parent[q];
        }

        return nullptr;
    }
};