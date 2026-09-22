class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<tuple<int,int,int>> nodes;

        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty()) {

            auto [node, row, col] = q.front();
            q.pop();

            nodes.push_back({col, row, node->val});

            if (node->left) {
                q.push({node->left, row + 1, col - 1});
            }

            if (node->right) {
                q.push({node->right, row + 1, col + 1});
            }
        }

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;

        int prevCol = INT_MIN;

        for (auto [col, row, value] : nodes) {

            if (col != prevCol) {
                ans.push_back({});
                prevCol = col;
            }

            ans.back().push_back(value);
        }

        return ans;
    }
};