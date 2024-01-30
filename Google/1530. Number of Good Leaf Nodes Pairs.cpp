class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        function<vector<int>(TreeNode*, int)> dfs = [&](TreeNode* node, int lv) -> vector<int> {
            if (!node || (!node->left && !node->right))
                return {lv};
            vector<int> left, right;
            if (node->left) left = move(dfs(node->left, lv + 1));
            if (node->right) right = move(dfs(node->right, lv + 1));
            if (!left.empty() && !right.empty()) {
                for (int l : left) {
                    for (int r : right) {
                        if (l + r - 2 * lv <= distance) ans++;
                    }
                }
            }
            left.insert(left.end(), right.begin(), right.end());
            return left;
        };
        dfs(root, 0); 
        return ans;
    }
};
