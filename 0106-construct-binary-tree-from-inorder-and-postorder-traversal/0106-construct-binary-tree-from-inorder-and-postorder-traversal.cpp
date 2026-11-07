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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int& idx, int start, int end,
                    unordered_map<int,int>& mp) {

        if(start > end) return nullptr;

        int rootval = postorder[idx--];

        TreeNode* root = new TreeNode(rootval);

        int pos = mp[rootval];

        // Construct right subtree first
        root->right = solve(inorder, postorder, idx,
                            pos + 1, end, mp);

        // Construct left subtree
        root->left = solve(inorder, postorder, idx,
                           start, pos - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int idx = postorder.size() - 1;

        return solve(inorder, postorder, idx,
                     0, inorder.size() - 1, mp);
    }
};
