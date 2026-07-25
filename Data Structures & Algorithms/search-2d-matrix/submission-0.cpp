class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
       
        int smallest = matrix[0][0];
        int largest = matrix[m - 1][n - 1];

        if(target < smallest || target > largest) return false;

        int low = 0, high = m * n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int r = mid / n;
            int c = mid % n;
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] > target) high = mid - 1;
            else{
                low = mid + 1;
            }
        }
    
        return false;
    }
};
