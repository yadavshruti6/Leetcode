class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> effort(
            rows, vector<int>(cols, INT_MAX)
        );

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto current = pq.top();
            pq.pop();

            int currentEffort = current.first;
            int row = current.second.first;
            int col = current.second.second;

            if (row == rows - 1 && col == cols - 1)
                return currentEffort;

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols) {

                    int difference = abs(
                        heights[row][col] -
                        heights[newRow][newCol]
                    );

                    int newEffort = max(
                        currentEffort,
                        difference
                    );

                    if (newEffort < effort[newRow][newCol]) {

                        effort[newRow][newCol] = newEffort;

                        pq.push({
                            newEffort,
                            {newRow, newCol}
                        });
                    }
                }
            }
        }

        return 0;
    }
};