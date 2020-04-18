#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        int F[ROWS][COLS];
        F[0][0] = grid[0][0];
        
        for(int i = 1; i < COLS; ++i)
            F[0][i] = F[0][i-1] + grid[0][i];
        
        for(int j = 1; j < ROWS; ++j)
            F[j][0] = F[j-1][0] + grid[j][0];
        
        for(int i = 1; i < ROWS; ++i) {
            for(int j = 1; j < COLS; ++j) {
                F[i][j] = std::min(F[i-1][j], F[i][j-1]) + grid[i][j];
            }
        }
        
        return F[ROWS-1][COLS-1];
    }
};