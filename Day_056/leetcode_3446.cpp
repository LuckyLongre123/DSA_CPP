class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int d = 0; d < n; d++) {
            if (d == 0) {
                sortDiagonal(grid, d, 0, n, false);
            } else {
                sortDiagonal(grid, d, 0, n, false);
                sortDiagonal(grid, 0, d, n, true);
            }
        }

        return grid;
    }

private:
    void sortDiagonal(vector<vector<int>>& grid, int row, int col, int n,
                      bool ascending) {
        vector<int> vals;

        for (int i = row, j = col; i < n && j < n; i++, j++) {
            vals.push_back(grid[i][j]);
        }

        if (ascending) {
            sort(vals.begin(), vals.end());
        } else {
            sort(vals.begin(), vals.end(), greater<int>());
        }

        int k = 0;
        for (int i = row, j = col; i < n && j < n; i++, j++) {
            grid[i][j] = vals[k++];
        }
    }
};