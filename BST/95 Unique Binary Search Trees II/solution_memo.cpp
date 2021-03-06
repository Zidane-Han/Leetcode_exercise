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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
        return helper(1, n, memo);
    };
    
    vector<TreeNode*> helper(int start, int end, vector<vector<vector<TreeNode*>>>& memo) {
        if (start > end)    return {nullptr};
        if (!memo[start-1][end-1].empty()) {
            return memo[start-1][end-1];
        }
        
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            auto left = helper(start, i-1, memo);
            auto right = helper(i+1, end, memo);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        
        memo[start-1][end-1] = res;
        return res;
    }
};
