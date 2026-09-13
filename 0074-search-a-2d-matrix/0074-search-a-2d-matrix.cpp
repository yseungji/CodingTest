class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 1;
        int right= matrix.size() * matrix[0].size();
        cout << right << ' ';
        int row, column;
        while(left<=right) {
            int mid = (left + right)/2;
            row = (mid-1) / matrix[0].size();
            column = (mid-1) % matrix[0].size();
            if(matrix[row][column] == target) {
                return true;
            }
            else if(matrix[row][column] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};