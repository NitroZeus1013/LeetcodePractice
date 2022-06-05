class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size()-1;
        // at last when i is just 1 less than j . i is pointing the last value!= val and j is pointing 1st value == val . so then we increament i . and now i == j both pointing to 1st value == val ,and thats our answer as we needed size . here a last swap will happen for same index and i becomes > j.
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
            }else{
                i++;
            }
        }
        return i;
    }
};
