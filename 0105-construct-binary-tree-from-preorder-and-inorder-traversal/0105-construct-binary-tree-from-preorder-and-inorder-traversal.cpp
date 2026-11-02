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

    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, int preStart,
                    int inStart, int inEnd) {

        // Base case
        if (inStart > inEnd)
            return nullptr;

        // First element of preorder is the root
        int rootVal = preorder[preStart];

        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int rootIndex = mp[rootVal];

        // Calculate left subtree size
        int leftSize = rootIndex - inStart;

        // Construct left subtree
        root->left = solve(preorder,
                           preStart + 1,
                           inStart,
                           rootIndex - 1);

        // Construct right subtree
        root->right = solve(preorder,
                            preStart + 1 + leftSize,
                            rootIndex + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder values and their indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, 0, 0, inorder.size() - 1);
    }
};