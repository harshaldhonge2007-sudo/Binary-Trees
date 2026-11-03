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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if(root == nullptr) return {};

        // Phase 1: Parent Mapping
        queue<TreeNode*> q1;
        unordered_map<TreeNode*, TreeNode*> parent;

        q1.push(root);
        parent[root] = nullptr;

        while(!q1.empty()) {

            TreeNode* node = q1.front();
            q1.pop();

            if(node->left) {
                parent[node->left] = node;
                q1.push(node->left);
            }

            if(node->right) {
                parent[node->right] = node;
                q1.push(node->right);
            }
        }

        // Phase 2: BFS from Target
        queue<TreeNode*> q2;
        unordered_set<TreeNode*> visited;

        q2.push(target);
        visited.insert(target);

        int distance = 0;

        while(!q2.empty() && distance < k) {

            int size = q2.size();

            for(int i = 0; i < size; i++) {

                TreeNode* node = q2.front();
                q2.pop();

                // Left neighbour
                if(node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q2.push(node->left);
                }

                // Right neighbour
                if(node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q2.push(node->right);
                }

                // Parent neighbour
                if(parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q2.push(parent[node]);
                }
            }

            distance++;
        }

        // Phase 3: Collect Answer
        vector<int> ans;

        while(!q2.empty()) {
            ans.push_back(q2.front()->val);
            q2.pop();
        }

        return ans;
    }
};
