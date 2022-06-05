class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 1;
        int n = arr.size();
        int l=0 ,r=0;
        int j = n-2;
        while(i<n ){
            if(arr[i]<=arr[i-1])break;
          
            i++;
        }
        
        while(j>=0){
            if(arr[j]<=arr[j+1])break;
            j--;
        }
        
        // so we are checking the fist indexes where the mountain contidtion fails  and cheking if the mountain element is just at one distance from each points. again if j< 0 means the mountain is like right skewed  and if i>=n then mountain is left skewed.
        if((i-1) == (j+1) and j>=0 and i<n)return true;
        return false;
        
    }
};
