class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1 = nums2;
            return ;
        }
        //approach 1 : starting from the end of the arrays .
        int i = m-1,j=n-1,target=m+n-1;
    
        while(j>=0){
            if(i>=0 and nums1[i]>nums2[j]){
              nums1[target--] = nums1[i--];
            }else{
                nums1[target--] = nums2[j--];
            }
        }
        //approach 2 : starting from beggining of the arrays. 
        //both appoaches are correct but you need the extra operation if you insert at front to move the elements to right if you start from start of the arrays. whereas if you insert at end no need to move the elements 1: because of the O(1) insert at end and all of them will be sorted so need to move.
//         int i = 0,j=0;
//         while(i<m+n and j<n){
//             if(nums1[i]>nums2[j]){
//                 nums1[i+1] = nums1[i]; //out of bound for last index.
//                 nums1[i] = nums2[j];
//                 i++;
//                 j++;
//             }else{
//                 i++;
//                 if(i>=m){
//                     nums1[i] = nums2[j];
//                     j++;
//                 }
                 
//             }
            
         
//         }
        
        
        
    }
};
