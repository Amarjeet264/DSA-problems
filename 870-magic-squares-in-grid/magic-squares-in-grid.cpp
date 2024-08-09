// class Solution {
// public:
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<m;j++){
                
//             }
//         }
//     }
// };
class Solution {
public:
    // Function to check if a 3x3 submatrix is a magic square
    bool isMagicSquare(const vector<vector<int>>& submatrix) {
        // Magic constant for a 3x3 magic square is always 15
        int magicSum = 15;

        // Check rows
        for (int i = 0; i < 3; i++) {
            if (submatrix[i][0] + submatrix[i][1] + submatrix[i][2] != magicSum) return false;
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (submatrix[0][j] + submatrix[1][j] + submatrix[2][j] != magicSum) return false;
        }

        // Check diagonals
        if (submatrix[0][0] + submatrix[1][1] + submatrix[2][2] != magicSum) return false;
        if (submatrix[0][2] + submatrix[1][1] + submatrix[2][0] != magicSum) return false;

        // Check if all numbers from 1 to 9 are present
        unordered_set<int> numbers;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (submatrix[i][j] < 1 || submatrix[i][j] > 9) return false;
                numbers.insert(submatrix[i][j]);
            }
        }
        return numbers.size() == 9; // Must have exactly 9 distinct numbers
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        // Iterate over all possible top-left corners for 3x3 submatrices
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                vector<vector<int>> submatrix(3, vector<int>(3));
                // Extract the 3x3 submatrix
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        submatrix[x][y] = grid[i + x][j + y];
                    }
                }
                // Check if the submatrix is a magic square
                if (isMagicSquare(submatrix)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

