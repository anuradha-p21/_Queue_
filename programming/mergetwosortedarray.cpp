/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,4, 0,0,0], m = 4, nums2 = [2,5,6], n = 3
nums 3 : 
compare nums1[0] and nums2[0] --> nums3[0] = 1 and i++ 
nums1[1] and nums1[0] --> both nums3[1] and nums3[2] = 2 , i++ , j++
so now  nums3 = 1 2 2 3 4 and i is at 0 now , j is at 5 , HERE there is a problem
that zero padding gets attached , therefore we need to minus the lenght of the 0 padding, 
which essentially is length of nums2. therefore we take l = nums1.size() - nums2.size()
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1. 
https://leetcode.com/problems/merge-sorted-array/    */


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums3;
        int i = 0;
        /* we take the size like this because otherwise all the 0 appended elements will 
        stay  ex :  1 2 3 0 0 0 , 2 5 6 then it will append as
        1 2 2 3 0 0 0 5 6  */
        int l = nums1.size() - nums2.size();
        int j = 0;
        /* if first array is empty then just copy 2nd into 1 and return*/
         if(nums1.size() == 0)
          {
              nums1 = nums2;
             return ;
          }
        
    while (i < l && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            nums3.push_back(nums1[i]);
            nums3.push_back(nums2[j]);
            i++;
            j++;
        }
        else {


            if (nums1[i] < nums2[j])
            {
                nums3.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums3.push_back(nums2[j]);
                j++;
            }

        }
    }
        /* if arrays are unequal then copy the remaining at the end */
    while (i < l)
    {
        nums3.push_back(nums1[i]);
        i++;
    }
    while (j < nums2.size())
    {
        nums3.push_back(nums2[j]);
        j++;
    }
/* copy back the temp array into num1 and return ! */
   nums1 = nums3;
  

        
        
    }
};