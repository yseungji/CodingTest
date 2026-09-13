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
            cout << row << ' ';
            column = (mid-1) % matrix[0].size();
            cout << column << ' ';
            if(matrix[row][column] > target) {
                right = mid - 1;
            }
            else if(matrix[row][column] < target) {
                left = mid + 1;
            }
            else {
                return true;
            }
        }
        
        return false;
    }
};