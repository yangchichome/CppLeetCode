class Coordinate {
public:
    int x;
    int y;

    Coordinate(int x, int y) : x(x), y(y) {}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void bfs(std::vector<std::vector<char>>& grid, int i, int j) {
        std::stack<Coordinate> stack;

        stack.push(Coordinate(i, j));
        std::vector<int> delx{0, 0, 1, -1};
        std::vector<int> dely{1, -1, 0, 0};

        while (!stack.empty()) {
            Coordinate c = stack.top();
            stack.pop();
            int x = c.x;
            int y = c.y;

            grid[x][y] = 'V';

            for (int k = 0; k < 4; k++) {
                int xnew = x + delx[k];
                int ynew = y + dely[k];

                if (xnew >= 0 && xnew < grid.size() && ynew >= 0 && ynew < grid[0].size() && grid[xnew][ynew] == '1') {
                    stack.push(Coordinate(xnew, ynew));
                }
            }
        }
    }
};