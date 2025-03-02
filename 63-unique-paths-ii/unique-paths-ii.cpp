class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<int> prev(cols, -1), curr(cols, -1);
        
        int i = 0;
        while(i < cols && obstacleGrid[0][i] != 1) {
            prev[i] = 1;
            i++;
        }

        bool flag = false;
        if(obstacleGrid[0][0] == 1) flag = true;
        for(int i = 1 ; i < rows ; i++) {
            if(obstacleGrid[i][0] == 1) flag = true;
            if(flag == false) curr[0] = 1;
            for(int j = 1 ; j < cols ; j++) {
                int x = 0;
                if(curr[j - 1] != -1) x += curr[j - 1];
                if(prev[j] != -1) x += prev[j];
                if(obstacleGrid[i][j] != 1) curr[j] = x;
            }
            prev = curr;
            fill(curr.begin(), curr.end(), -1);
        }
        return prev[cols - 1] == -1 ? 0 : prev[cols - 1];
    }
};