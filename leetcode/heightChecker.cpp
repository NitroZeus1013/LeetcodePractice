class Solution {
public:
    int heightChecker(vector<int>& heights) {
        //counting sort
        int last = INT_MIN;
        for(int i:heights){
            last = max(last,i);
        }
        
        int maparr[101]={0};
        for(int i:heights){
            maparr[i]++;
        }
        for(int i = 1 ;i<=last;i++){
            maparr[i] = maparr[i]+maparr[i-1];
        }
        
        int ans  = 0;
        for(int h:heights){
            if(heights[maparr[h]-1] != h){
                ans++;
                maparr[h]--;
                // since we're done considering the element h and in both case found/not found we'll decrease it's count because now we've confirm for other same elements .
                //if they are on correct position or not
            }else{
                maparr[h]--;
            }
        }
        
        return ans;
    }
};
