class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans;
        bool skip = false;

        for(int i = 0; i < m; i++) {

            if(i % 2 == 0) {
                for(int j = 0; j < n; j++) {

                    if(!skip)
                        ans.push_back(grid[i][j]);

                    skip = !skip;
                }
            }
            else {
                for(int j = n - 1; j >= 0; j--) {

                    if(!skip)
                        ans.push_back(grid[i][j]);

                    skip = !skip;
                }
            }
        }

        return ans;
    }
};