//formula used in the question is 
//area = min (left height,right height)*width 
// Algo covers in 6 steps and concept of this question is Two Pointers + Greedy Approach
// 1. Initialize two pointers at the beginning and end of the height array.
// 2. Calculate the width between the two pointers.
// 3. Find the smaller height and calculate the container area using minimum height multiplied by width.
// 4. Update the maximum area if the current area is greater than the previous maximum.
// 5. Move the pointer with the smaller height inward to search for a potentially larger area.
// 6. Repeat until both pointers meet and return the maximum area.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;

            maxWater = max(maxWater, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
  
