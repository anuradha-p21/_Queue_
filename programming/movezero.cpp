/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
https://leetcode.com/problems/move-zeroes/
*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 1 , j = 0;
        while(i < nums.size())
        {
            if(nums[j] !=0)
            { 
                i++;
                j++;
            }
            else if((nums[j] == 0) && (nums[i] == 0))
            {
                i++;
            }
            else if( (nums[j] == 0) && (nums[i] !=0))
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else{}
        }
        
    }
  
};