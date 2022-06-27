class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        
        for(int i= 0 ;i+1<heights.size();i++){
            int d = heights[i+1]-heights[i];
            if(d>0){
                pq.push(-d);// -ve to maintain min heap
            }
            // if we don't have any ladders then use bricks for the smallest diff so far.
            if(pq.size()>ladders){
                bricks+=pq.top();//we're reducing bricks as values stored in pq are -ve
                pq.pop();
            }
            // if don't have enough bricks to make the next jump from current index.
            // we've already subtracted the diff but check if the bricks are <0 or not.if <0 then it's invalid jump and we've to return from here .
            if(bricks<0){
                return i;
            }
            
        }
        // if didn't run out of bricks in loop i.e. if we didn't returned from loop.we've reached the end.
        return heights.size()-1;
    }
};
