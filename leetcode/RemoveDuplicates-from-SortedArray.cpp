class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1 ;
        //starting from the 1st index as the element on the 0th is correct 
        // j indicates the position to insert next element. Now we find the element just greater than it's previous elemnts as it is sorted we can do this. Or else you can compare with element at j-1.
        for(int i = 1 ;i<nums.size();i++){
                
                if(nums[i]>nums[i-1]){
                    nums[j] = nums[i];
                    j++;
                }
                
            
        }
        // we return j as it the last index next to valid index.
        return j;
    }
};
