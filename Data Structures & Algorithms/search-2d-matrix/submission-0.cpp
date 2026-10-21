  /*
        Problem: Search a 2D Matrix
        Concept Used:
        Binary Search on a sorted 2D Matrix.
        Treat the matrix as a virtual sorted 1D array
        without actually converting it into an array.
        Algorithm:
        1. Let m = number of rows and n = number of columns.
        2. Initialize left = 0 and right = m * n - 1.
        3. While left <= right:
           - Calculate mid = left + (right - left) / 2.
           - Convert mid into matrix coordinates:
             row = mid / n, col = mid % n.
           - If matrix[row][col] == target, return true.
           - If matrix[row][col] < target, move left to mid + 1.
           - Otherwise, move right to mid - 1.
        4. If target is not found, return false.

        Time Complexity: O(log(m * n))
        Space Complexity: O(1)
        */
class Solution{
    public:
    bool searchMatrix(vector<vector<int>>&matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();
        int left=0;
        int right = m*n-1;
        while (left<=right){
            int mid = left+(right-left)/2;
            int row = mid/n;
            int col = mid%n;
            if (matrix[row][col]==target){
                return true;
            }
            if (matrix[row][col]<target){
                left=mid+1;

            }else{
                right = mid-1;
            }
        }
        return false;
    }
};
